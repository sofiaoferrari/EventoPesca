#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

#define FOFOS 15
#define AZULES 5

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

bool pokeveloz_azul(pokemon_t* poke_veloz){
    
    bool azul = strcmp(poke_veloz->color, "azul");
    bool fofo = (poke_veloz->peso >= FOFOS); 
    if (azul && fofo){
        printf("%s es azul y fofo", poke_veloz->especie);
    }
    return (azul && fofo);
}


int main() {
    const char ARCHIVO[] = "arrecife.txt";
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    acuario_t* simulacion_acuario = crear_acuario();
    int traslado_1 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*pokeveloz_azul),AZULES);
    if (traslado_1){
        printf("se pudo realizar el primer traslado");
    } else if (traslado_1 == 0){
        printf("se pudo");
    }

    /*
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