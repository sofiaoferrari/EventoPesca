#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

/*
bool poke_especie_especifica(){
    return encontrado;
}

bool pokefofos(){
    encontrado = false;
    
    return encontrado;
}
*/

void liberar_arrecife(arrecife_t* arrecife){
    free(arrecife->pokemon);
    free(arrecife);
}

int main() {
    const char ARCHIVO[] = "arrecife.txt";
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    acuario_t* simulacion_acuario = crear_acuario();
    if (!simulacion_arrecife || !simulacion_acuario){
        printf("Hubo un error de memoria");
    } else {
        printf("Memoria reservada");
    }

    /*
    //Trasladar y listar pokes n-veces
    //Guardar los pokemon del acuario
    //liberar memoria
    */
    liberar_arrecife(simulacion_arrecife);
   
    free(simulacion_acuario);
    return 0;
}