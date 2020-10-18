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

#define FORMATO_LECTURA "%[^;];%i;%i;%[^\n]\n"

arrecife_t* crear_arrecife(const char* ruta_archivo[]) {
    FILE* archivo = fopen(*ruta_archivo, "r");
    arrecife_t* nuevo_poke = malloc(sizeof(arrecife_t));

    if (archivo == NULL) {
        printf("ERROR de lectura.");
        return -1;
    }

    int leidos = fscanf(archivo, FORMATO_LECTURA,
                        nuevo_poke->pokemon->especie,
                        &nuevo_poke->pokemon->peso,
                        &nuevo_poke->pokemon->velocidad,
                        nuevo_poke->pokemon->color);

//    int feof(FILE* archivo);
//    fread();
//    fscanf();

    while (leidos != EOF){
        fprintf(archivo, FORMATO_LECTURA,
                nuevo_poke->pokemon->especie,
                &nuevo_poke->pokemon->peso,
                &nuevo_poke->pokemon->velocidad,
                nuevo_poke->pokemon->color);
    }

// strcpy(nuevo_poke->pokemon, &pokemon);
    nuevo_poke->cantidad_pokemon, &leidos;
    
    fclose(archivo);
    free(nuevo_poke);
    return *arrecife_t;   //puntero arrecife
}