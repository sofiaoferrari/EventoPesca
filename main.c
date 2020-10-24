#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

int main() {
    const char ARCHIVO[] = "arrecife.txt";
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 

    free(simulacion_arrecife);
    return 0;
}