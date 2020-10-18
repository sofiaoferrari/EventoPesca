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

arrecife_t* crear_arrecife(const char* ruta_archivo[]) {
    FILE* archivo = fopen(*ruta_archivo, "r");

    if (archivo == NULL) {
//        printf("ERROR de lectura.");
    }

    arrecife_t* nuevo_pokemon = malloc(sizeof(arrecife_t));

    int feof(FILE* archivo);
/*
    while (!feof(archivo)){
        fread();
        fscanf();
    }*/

    strcpy(nuevo_pokemon->pokemon, &pokemon);
    nuevo_pokemon->cantidad_pokemon, &cantidad_pokemon;
    
    fclose(archivo);
    free(nuevo_pokemon);
    return *arrecife_t;   //puntero
}