#include "evento_pesca.h"
#include <stdlib.h>

int main() {
    const char ARCHIVO[] = "arrecife.txt";
    
    void* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    return 0;
}