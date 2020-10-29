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

/*
int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion) {
    return 0; //si sale todo bien, sino -1
}
*/

acuario_t* crear_acuario() {
    acuario_t* acuario = malloc(sizeof(acuario_t));
    if (!acuario) {
        printf("ERROR de reserva de memoria.");
        free(acuario);
        return NULL;
    }
    return acuario;
}

int numero_de_pokes(arrecife_t* arrecife) {
    size_t n = (sizeof(*arrecife->pokemon)) / (sizeof(arrecife->pokemon[0]));
    printf("Pokemones en arrecife:\n");
    for (int i = 0; i > (int)n; i++) {
        printf(FORMATO_ESCRITURA,
                arrecife[i].pokemon->especie,
                arrecife->pokemon[i].peso,
                arrecife->pokemon[i].velocidad,
                arrecife->pokemon[i].color);
    }
   return n;
}

pokemon_t* insertar_pokes(FILE* archivo){
    pokemon_t* aux_pokemon = malloc(sizeof(pokemon_t));
    if (!aux_pokemon){
        free(aux_pokemon);
        printf("Problema cc memoria");
        return NULL;
    }
    int poke_datos = fscanf(archivo, FORMATO_LECTURA,
                    aux_pokemon->especie,
                    &aux_pokemon->peso,
                    &aux_pokemon->velocidad,
                    aux_pokemon->color);

    if (poke_datos != 4) {
        printf("Formato invalido");
        free(aux_pokemon);
        return NULL;
    }
    

    return aux_pokemon;

}

arrecife_t* crear_arrecife(const char* ruta_archivo) {
    
    arrecife_t* arrecife = malloc(sizeof(arrecife_t));
    if (!arrecife) {
        printf("ERROR de reserva de memoria.");
        return NULL;
    } 
    arrecife->cantidad_pokemon = 0;
    arrecife->pokemon = NULL;
   
    FILE* archivo = fopen(ruta_archivo, "r");
    if (!archivo){
        printf("ERROR de lectura.");
        fclose(archivo);
        return NULL;
    }

    arrecife->pokemon = insertar_pokes(archivo);
    fclose(archivo);
    arrecife->cantidad_pokemon = numero_de_pokes(arrecife->pokemon);
    
    printf("\nel primer poke es: %s\n", arrecife->pokemon[0].especie);
    if (arrecife->cantidad_pokemon > 0){
        printf("\nHay %d pokemones!\n", arrecife->cantidad_pokemon);
    } else {
        printf("\nNo hay pokes :(");
    }
    
    return arrecife;  
}

