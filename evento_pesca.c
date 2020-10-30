#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

/*
typedef struct pokemon{
    char especie[MAX_ESPECIE];
    int velocidad;
    int peso;
    char color[MAX_COLOR];
} pokemon_t;

typedef struct acuario{
    pokemon_t* pokemon;
    int cantidad_pokemon;
} acuario_t;

typedef struct arrecife{
    pokemon_t* pokemon;
    int cantidad_pokemon;
} arrecife_t;
*/

#define FORMATO_LECTURA "%100[^;];%i;%i;%50[^\n]\n"
#define FORMATO_ESCRITURA "%s;%i;%i;%s\n"
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
    if (acuario != NULL){
        free(acuario);
    }
}

/*

int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion) {
    return 0; //si sale todo bien, sino -1

}
*/

acuario_t* crear_acuario() {
    acuario_t* acuario = malloc(sizeof(acuario_t));
    if (!acuario) {
        printf("ERROR de reserva de memoria.");
        return NULL;
    }
    return acuario;
}

void capturar_datos(pokemon_t* poke_agregado, pokemon_t* poke_datos){
    strcpy(poke_agregado->especie, poke_datos->especie);
    poke_agregado->peso = poke_datos->peso;
    poke_agregado->velocidad = poke_datos->velocidad;
    strcpy(poke_agregado->color, poke_datos->color);
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
        if (!aux_pokemon){
            printf("Problema cc realloc \n");
            return -1;
        }
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
    if (!arrecife) {
        printf("ERROR de reserva de memoria.\n");
        return NULL;
    } 
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
        printf("\nEXITO! El arrecife contiene %d pokemones :)\n", arrecife->cantidad_pokemon);
    } else if (arrecife->cantidad_pokemon == 0) {
        printf("\nHubo un ERROR, no se puedo crear el arrecife :(\n");
        return NULL;
    }
    
    printf("\nel primer poke es: %s\n", arrecife->pokemon[0].especie);
    
    return arrecife;  
}

