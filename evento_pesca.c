#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

#define FORMATO_LECTURA "%100[^;];%i;%i;%50[^\n]\n"
#define FORMATO_ESCRITURA "%12s;%12i;%12i;%12s\n"
#define CANT_CAMPOS 4

void liberar_arrecife(arrecife_t* arrecife){
    if((arrecife->pokemon) != NULL){
        free(arrecife->pokemon);
    }
    if (arrecife != NULL){
        free(arrecife);
    }
}

void liberar_acuario(acuario_t* acuario) {
    if((acuario->pokemon) != NULL){
        free(acuario->pokemon);
    }
    if (acuario != NULL){
        free(acuario);
    }
}

int chequear_info_traslado(arrecife_t* arrecife, int cant_seleccion, int pokes_total) {
     if ((!arrecife) && (cant_seleccion != 0)) {
         return -1;
     }
     if ((!arrecife) && (cant_seleccion == 0)) {
         return 0;
     }
     if (cant_seleccion > pokes_total){
         printf("\nBro no hay %d pokemones en el arrecife\n", cant_seleccion);
         return -1;
     }
    return 2;
}

void capturar_datos(pokemon_t* poke_agregado, pokemon_t* poke_datos){
    strcpy(poke_agregado->especie, poke_datos->especie);
    poke_agregado->peso = poke_datos->peso;
    poke_agregado->velocidad = poke_datos->velocidad;
    strcpy(poke_agregado->color, poke_datos->color);
}

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
    if (!eliminar_ultimo)
        return -1;
    arrecife->pokemon = eliminar_ultimo;
    return 0;
}

int trasladar_a_acuario(arrecife_t* arrecife, acuario_t* acuario, int cant_seleccion, int* pokes_a_trasladar){

    for (size_t i = 0; i < cant_seleccion; i++){
        int posicion = pokes_a_trasladar[i];
        pokemon_t* aux_pokemon = realloc(acuario->pokemon, sizeof(pokemon_t) * (i+1));
        if (!aux_pokemon)
            return -1;
        acuario->pokemon = aux_pokemon;
        acuario->cantidad_pokemon = (int)(i+1);
        capturar_datos(&(acuario->pokemon[i]), &arrecife->pokemon[posicion]);
    }
    int eliminar_poke = sacar_de_arrecife(arrecife, cant_seleccion, pokes_a_trasladar);
    return eliminar_poke;
}

bool verificar_traslado(arrecife_t* arrecife, int cant_seleccion, bool (*seleccionar_pokemon)(pokemon_t*), int* traslado) {
    int encontrados = 0;
    int pokes_total = arrecife->cantidad_pokemon;
    for (int i = 0; i < pokes_total ; i++){
        bool poke_cumple = seleccionar_pokemon(&arrecife->pokemon[i]);
        if (poke_cumple && (encontrados < cant_seleccion)){
            traslado[encontrados] = i;
            encontrados++;
            printf("Poke %d posicion: %d", encontrados, traslado[encontrados-1]);
        }
        if (encontrados == cant_seleccion){
            printf("\nHay suficientes pokes para trasladar :)\n");
            return true;  
        }
    }
    if (encontrados != cant_seleccion) {
        printf("\nNo hay suficientes pokemones para trasladar\n");
            return false;
    }
    return false;
}


int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion) {
    int pokes_total = arrecife->cantidad_pokemon;    
    int continuar = chequear_info_traslado(arrecife, cant_seleccion, pokes_total);
    if ((continuar == 0) || (continuar == -1)) 
        return continuar;
    size_t max_pokes = (size_t)cant_seleccion;
    int* pokes_a_trasladar = malloc(sizeof(int)*max_pokes);
    if (!pokes_a_trasladar)
        return -1;
    bool hay_suficientes = verificar_traslado(arrecife, cant_seleccion, (*seleccionar_pokemon), pokes_a_trasladar);
    if (hay_suficientes != 0) {
        int cambiazo = trasladar_a_acuario(arrecife, acuario, cant_seleccion, pokes_a_trasladar);
        if ((cambiazo == 0) && (acuario->cantidad_pokemon == cant_seleccion)){
            printf("\nEXITO! %d pokemones han sido trasladados al acuario!\n", cant_seleccion);
            printf("\nEl acuario contiene %d pokemones\n", acuario->cantidad_pokemon);
        } else if ((acuario->cantidad_pokemon != cant_seleccion) || (cambiazo == -1)) {
            printf("\nHubo un ERROR, los pokes no pudieron ser trasladados :(\n");
            free(pokes_a_trasladar);
            return -1;
        } 
    }   
    printf("\n Quedan %d pokes en el arrecife\n", arrecife->cantidad_pokemon);
    free(pokes_a_trasladar);
    return 0;
}


acuario_t* crear_acuario() {
    acuario_t* acuario = malloc(sizeof(acuario_t));
    if (!acuario)
        return NULL;
    acuario->pokemon = NULL;
    return acuario;
}


int leer_archivo(FILE* archivo, arrecife_t* arrecife){
    pokemon_t nuevo_poke;

    size_t i = 0;
    int campos = fscanf(archivo, FORMATO_LECTURA,
                        nuevo_poke.especie,
                        &nuevo_poke.peso,
                        &nuevo_poke.velocidad,
                        nuevo_poke.color);    

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
                        &nuevo_poke.peso,
                        &nuevo_poke.velocidad,
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
        fclose(archivo);
        return NULL;
    }

    int hay_pokes = leer_archivo(archivo, arrecife);
    fclose(archivo);
    if ((hay_pokes == 0) && (arrecife->cantidad_pokemon > 0)){
        printf("\nEXITO! El arrecife creado contiene %d pokemones :)\n", arrecife->cantidad_pokemon);
    } else if (arrecife->cantidad_pokemon == 0) {
        printf("\nHubo un ERROR, no se puedo crear el arrecife :(\n");
        return NULL;
    }
    return arrecife;  
}

