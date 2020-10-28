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
#define FORMATO_ESCRITURA "%s;%i;%i;%s\n"
#define FORMATO_EXTENSION "%[^.].%s"


arrecife_t* crear_arrecife(const char* ruta_archivo) {
    char nombre_archivo[50];
    char extension[20];
    sscanf(ruta_archivo, FORMATO_EXTENSION, nombre_archivo, extension);
    
    arrecife_t* arrecife = malloc(sizeof(arrecife_t));
    if (!arrecife) return NULL;
    arrecife->cantidad_pokemon = 0;
    arrecife->pokemon = NULL;    

    pokemon_t* aux_pokemon = malloc(sizeof(pokemon_t));
    if (!aux_pokemon) return NULL;

    if (strcmp(extension, "txt") == 0) {
        FILE* archivo = fopen(ruta_archivo, "r");
        if (!archivo){
            printf("ERROR de lectura.");
            fclose(archivo);
            return NULL;
        }
        while (!EOF || !FORMATO_LECTURA){
            fscanf(archivo, FORMATO_LECTURA,
                    aux_pokemon->especie,
                    &aux_pokemon->peso,
                    &aux_pokemon->velocidad,
                    aux_pokemon->color);
            arrecife->cantidad_pokemon ++;
            realloc(pokemon_t* aux_pokemon, sizeof(arrecife->cantidad_pokemon +1));
            
        }
        fclose(archivo);    
    }

    


// strcpy(arrecife->pokemon, &pokemon);
    
    
    return arrecife;  
}

/*
} else {
            int leidos = fscanf(archivo, FORMATO_LECTURA,
                        arrecife->pokemon->especie,
                        &arrecife->pokemon->peso,
                        &arrecife->pokemon->velocidad,
                        arrecife->pokemon->color);
                
            while (leidos != EOF){
                fprintf(archivo, FORMATO_ESCRITURA,
                arrecife->pokemon->especie,
                arrecife->pokemon->peso,
                arrecife->pokemon->velocidad,
                arrecife->pokemon->color);
            }
            arrecife->cantidad_pokemon, &leidos;
*/