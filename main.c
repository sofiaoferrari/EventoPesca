#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

#define FOFOS 15
#define AZULES 16

/*
bool exclusivos_shellder_y_(){
    return encontrado;
}

bool pokeveloz_azul(){

}

bool pokefofos(arrecife_t* arrecife){
    const short PESO_MIN = 
    encontrado = false;
    
    return encontrado;
}
*/

bool pokeveloz_azul(arrecife_t* arrecife){
    int encontrados = 0;
    int pokes_total = arrecife->cantidad_pokemon;
    for (int i = 0; i > pokes_total ; i++){
        int distintas = strcmp(arrecife->pokemon[pokes_total].color, "azul");
        if (!distintas) {
            encontrados++;
            printf("\nVan %d encontrados", encontrados);
        }   
        if (encontrados == AZULES) {
            printf("Hay suficientes pokes azules p trasladar :)");
            return true;
        } 
    }

    return false;
}



int main() {
    const char ARCHIVO[] = "arrecife.txt";
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    acuario_t* simulacion_acuario = crear_acuario();
    bool seleccion = *(pokeveloz_azul(arrecife_t* arrecife))(simulacion_arrecife);
    if (seleccion){
        printf("\n%d pokes listos para ser trasladados", AZULES);
    } else if (!seleccion) {
        printf("\nNo se puede trasladar :(");
    }
    /*
    int traslado_1 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokeveloz_azul(simulacion_arrecife),AZULES);
    int traslado_2 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),4);
    int traslado_3 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),30);
    int traslado_4 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),45);
    int traslado_5 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),20);
    //Trasladar y listar pokes n-veces
    //Guardar los pokemon del acuario
    */
    liberar_arrecife(simulacion_arrecife);
    liberar_acuario(simulacion_acuario);
    
    return 0;
}