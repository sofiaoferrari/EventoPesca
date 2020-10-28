#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

bool poke_especie_especifica(){
    return encontrado;
}

bool pokefofos(){
    encontrado = false;
    
    return encontrado;
}

int main() {
    const char ARCHIVO[] = "arrecife.txt";
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    acuario_t* simulacion_acuario = crear_acuario();
    //Trasladar y listar pokes n-veces
    //Guardar los pokemon del acuario
    //liberar memoria
    free(simulacion_arrecife);
    return 0;
}