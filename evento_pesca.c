#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

#define FORMATO_LECTURA "%100[^;];%i;%i;%50[^\n]\n"
#define FORMATO_ESCRITURA "%s;%i;%i;%s\n"
#define CANT_CAMPOS 4

void liberar_arrecife(arrecife_t* arrecife){
    if((arrecife->pokemon) && (arrecife->cantidad_pokemon > 0)){
        free(arrecife->pokemon);
    }
    if (arrecife != NULL){
        free(arrecife);
    }
}

void liberar_acuario(acuario_t* acuario) {
    if((acuario->pokemon) && (acuario->cantidad_pokemon > 0)){
        free(acuario->pokemon);
    }
    if (acuario != NULL){
        free(acuario);
    }
}

/*
 * Funcion que dado un archivo y puntero al acuario, se ocupa de
 * completar dicho archivo con todos los pokemones que habitan
 * el acuario, con el mismo formato que el archivo "arrecife.txt".
 * Devuelve 0 si sale todo bien, -1 en caso de error.
 */
int crear_archivo(FILE* archivo, acuario_t* acuario){
    if (!acuario)
        return -1;
    int i = 0;      
    int pokes_total = acuario->cantidad_pokemon;
    printf("\n\nPOKES TOTAL EN El ACUARIO: %d\n", pokes_total);
    while (i < pokes_total) {
        fprintf(archivo, FORMATO_ESCRITURA,
                acuario->pokemon[i].especie,
                acuario->pokemon[i].velocidad,
                acuario->pokemon[i].peso,
                acuario->pokemon[i].color);
        i++;
    }
    return 0;
}

int guardar_datos_acuario(acuario_t* acuario, const char* nombre_archivo){
    if((!acuario) || (acuario->cantidad_pokemon == 0))
        return -1;
    FILE* archivo = fopen(nombre_archivo, "w");
    if (!archivo){
        printf("ERROR al crear el archivo %s.\n", nombre_archivo);
        return -1;
    }
    int creado = crear_archivo(archivo, acuario);
    fclose(archivo);
    if (creado == 0) {
        printf("\nEXITO! Se ha podido crear el archivo %s.\n",nombre_archivo);
    }
    return creado;
}


void censar_arrecife(arrecife_t* arrecife, void (*mostrar_pokemon)(pokemon_t*)){
    if (arrecife) {
        int pokes_total = arrecife->cantidad_pokemon;
        int i = 0;
        for (; i < pokes_total; i++) {
            mostrar_pokemon(&arrecife->pokemon[i]);
        }
    }
}

/*
 * Funcion que se ocupa de sacar los pokemones del arrecife, que fueron previamente 
 * agregados al acuario. Cada vez que elimina un pokemon dada su posicon en el 
 * vector pokes a trasladar, a partir de ese se reemplazan los pokemones por el 
 * pokemon que le sigue. A la vez debe ir reajustando el vector.
 * Devuelve 0 en caso de que salga todo bien y -1 en caso de error. 
*/
int sacar_de_arrecife(arrecife_t* arrecife, int cant_seleccion, int *pokes_a_trasladar) {
    int eliminados = 0;
    for (int j = 0; j < cant_seleccion; j++){
        for (int i = ((pokes_a_trasladar[j])-eliminados); i < (arrecife->cantidad_pokemon-1); i++){
            arrecife->pokemon[i] = arrecife->pokemon[i+1];
        }
        arrecife->cantidad_pokemon -= 1;
        eliminados++;
    }
    size_t nuevo_tamanio = (size_t)(arrecife->cantidad_pokemon);
    pokemon_t* eliminar_ultimo = realloc(arrecife->pokemon, sizeof(pokemon_t)*(nuevo_tamanio));
    if ((!eliminar_ultimo) && (arrecife->cantidad_pokemon > 0))
        return -1;
    arrecife->pokemon = eliminar_ultimo;
    return 0;
}

/*
 * Funcion que traslada la cantidad de pokemones dada del arrecife hacia el acuario,
 * reservando la memoria necesaria para el mismo.
 * Devuelve 0 en el caso de que salga todo bien (-1 en el caso de error).
*/
int trasladar_a_acuario(arrecife_t* arrecife, acuario_t* acuario, int cant_seleccion, int* pokes_a_trasladar){
    for (int i = 0; i < cant_seleccion; i++){
        int posicion = pokes_a_trasladar[i];
        pokemon_t* aux_pokemon = realloc(acuario->pokemon, sizeof(pokemon_t) * (size_t)(acuario->cantidad_pokemon+1));
        if (!aux_pokemon)
            return -1;
        acuario->pokemon = aux_pokemon;
        acuario->pokemon[acuario->cantidad_pokemon] = arrecife->pokemon[posicion];
        acuario->cantidad_pokemon += 1;
    }
    int eliminar_poke = sacar_de_arrecife(arrecife, cant_seleccion, pokes_a_trasladar);
    return eliminar_poke;
}

/*
 * Funcion que se ocupa de verificar que haya la cantidad precisada (cant_selecicion) 
 * de pokemones en el arrecife para trasladar al acuario. Cada vez que se encuentre
 * un pokemon que cumpla la condicion del puntero a la funcion seleccionar_pokemon
 * se agregara su posicion al vector traslado[].
 * Devuelve true si hay la cantidad necesaria para trasladar, de lo contrario 
 * devuelve false.
*/
bool verificar_traslado(arrecife_t* arrecife, int cant_seleccion, bool (*seleccionar_pokemon)(pokemon_t*), int* traslado) {
    int encontrados = 0;
    int pokes_total = arrecife->cantidad_pokemon;
    for (int i = 0; i < pokes_total ; i++){
        bool poke_cumple = seleccionar_pokemon(&arrecife->pokemon[i]);
        if (poke_cumple && (encontrados < cant_seleccion)){
            traslado[encontrados] = i;
            encontrados++;
        }
        if (encontrados == cant_seleccion){
            printf("\nHay suficientes pokes para trasladar :)\n");
            return true;  
        }
    }
    if (encontrados < cant_seleccion) {
        printf("\nNo hay suficientes pokemones para trasladar :(\n");
            return false;
    }
    return false;
}

/*
 * Funcion que dado un puntero al arrecife y la cantidad de pokemones a
 * trasladar, verifica que se pueda llevar a cabo el traslado.
 * Devuelve 0 en el caso de que el arrecife sea nulo y la cantidad
 * de pokemones a trasladar sea igual a cero, -1 si en caso de que no
 * se pueda llevar acabo el traslado.
 * Devuelve 2 en el caso de poder continuar con el traslado.
*/
int chequear_info_traslado(arrecife_t* arrecife, int cant_seleccion) {
     if ((!arrecife) && (cant_seleccion != 0)) {
         return -1;
     }
     if ((!arrecife) && (cant_seleccion == 0)) {
         return 0;
     }
     if (cant_seleccion > arrecife->cantidad_pokemon){
         printf("\nBro no hay %d pokemones en el arrecife\n", cant_seleccion);
         return -1;
     }
    return 2;
}

int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion) {   
    int continuar = chequear_info_traslado(arrecife, cant_seleccion);
    if ((continuar == 0) || (continuar == -1)) 
        return continuar;
    size_t max_pokes = (size_t)cant_seleccion;
    int* pokes_a_trasladar = malloc(sizeof(int)*max_pokes);
    if (!pokes_a_trasladar)
        return -1;
    bool hay_suficientes = verificar_traslado(arrecife, cant_seleccion, (*seleccionar_pokemon), pokes_a_trasladar);
    if (!hay_suficientes){
        printf("\n Quedan %d pokes en el arrecife\n", arrecife->cantidad_pokemon);
        free(pokes_a_trasladar);
        return -1;
    } else if (hay_suficientes) {
        int cambiazo = trasladar_a_acuario(arrecife, acuario, cant_seleccion, pokes_a_trasladar);
        if (cambiazo == 0){
            printf("\nEXITO! %d pokemones han sido trasladados al acuario!\n", cant_seleccion);
            printf("\nEl acuario contiene %d pokemones\n", acuario->cantidad_pokemon);
        } else if (cambiazo == -1) {
            printf("\nHubo un ERROR, los pokes no pudieron ser trasladados :(\n");
            free(pokes_a_trasladar);
            return -1;
        } 
    }   
    printf("\n Quedan %d pokes en el arrecife:\n", arrecife->cantidad_pokemon);
    free(pokes_a_trasladar);
    return 0;
}


acuario_t* crear_acuario() {
    acuario_t* acuario = malloc(sizeof(acuario_t));
    if (!acuario)
        return NULL;
    acuario->pokemon = NULL;
    acuario->cantidad_pokemon = 0;
    return acuario;
}

/*
 * Procedimiento que dado dos punteros a pokemones, uno le pasa los datos
 * del nuevo pokemon del arrecife.
*/
void capturar_datos(pokemon_t* poke_agregado, pokemon_t* poke_datos){
    strcpy(poke_agregado->especie, poke_datos->especie);
    poke_agregado->velocidad = poke_datos->velocidad;
    poke_agregado->peso = poke_datos->peso;
    strcpy(poke_agregado->color, poke_datos->color);
}


/*
 * Funcion que dado un archivo y un puntero a un arrecife, carga en el mismo los pokemon 
 * que viven en el, reservando la memoria necesaria para el mismo.
 * Se intenta leer la mayor cantidad posible de registros del archivo, e ir agregando
 * los pokemones al arrecife. Al encontrar el 1er registro erroneo o al finalizar de leer 
 * el archivo, se finaliza la lectura. En caso de no encontrar ningún registro con el 
 * formato correcto, se debe devolver error.
 * Devuelve 0 si sale todo bien o -1 en caso de error.
*/
int leer_archivo(FILE* archivo, arrecife_t* arrecife){
    pokemon_t nuevo_poke;
    size_t i = 0;
    int campos = fscanf(archivo, FORMATO_LECTURA,
                        nuevo_poke.especie,
                        &nuevo_poke.velocidad,
                        &nuevo_poke.peso,
                        nuevo_poke.color);    
    if (campos != CANT_CAMPOS)
        return -1;
    while (campos == CANT_CAMPOS) {
        pokemon_t* aux_pokemon = realloc(arrecife->pokemon, sizeof(pokemon_t) * (i+1));
        if (!aux_pokemon)
            return -1;
        arrecife->pokemon = aux_pokemon;
        i++;
        arrecife->cantidad_pokemon = (int)i;
        capturar_datos(&(arrecife->pokemon[i-1]), &nuevo_poke);
        campos = fscanf(archivo, FORMATO_LECTURA,
                        nuevo_poke.especie,
                        &(nuevo_poke.velocidad),
                        &(nuevo_poke.peso),
                        nuevo_poke.color);
        
    }
    
    return 0;
}

arrecife_t* crear_arrecife(const char* ruta_archivo) {
    arrecife_t* arrecife = malloc(sizeof(arrecife_t));
    if (!arrecife) 
        return NULL;
    arrecife->cantidad_pokemon = 0;
    arrecife->pokemon = NULL;
   
    FILE* archivo = fopen(ruta_archivo, "r");
    if (!archivo){
        printf("ERROR de lectura del archivo %s.\n", ruta_archivo);
        return NULL;
    } else if (archivo) {
        int contenido = fgetc(archivo);
        if (contenido == EOF) {
            printf("\nERROR. Archivo vacio.\n");
            fclose(archivo);
            free(arrecife);
            return NULL;
        } else ungetc(contenido, archivo);
    }
    int hay_pokes = leer_archivo(archivo, arrecife);
    fclose(archivo);
    if ((hay_pokes == 0) && (arrecife->cantidad_pokemon > 0)){
        printf("\nEXITO! El arrecife creado contiene %d pokemones :)\n", arrecife->cantidad_pokemon);
    } else if (arrecife->cantidad_pokemon == 0) {
        printf("\nHubo un ERROR, no se puedo crear el arrecife :(\n");
        free(arrecife);
        return NULL;
    }
    return arrecife;  
}