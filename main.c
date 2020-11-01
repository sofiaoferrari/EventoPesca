#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

#define FOFOS 10
#define PESO_MIN 30
#define VELOCIDAD_MIN 40
#define AZULES 8
#define SQUIRTLES 2

/*
bool exclusivos_shellder_y_(){
    return encontrado;
}
*/
bool vamo_a_calmarno(pokemon_t* poke){
    bool squirtle = strcmp(poke->especie, "squirtle");
    return !squirtle;
}

bool pokefofos(pokemon_t* poke){

    bool fofo = (poke->peso >= PESO_MIN);
    return fofo;
}


bool pokeveloz_azul(pokemon_t* poke){
    bool azul = strcmp(poke->color, "azul");
    bool veloz = (poke->velocidad >= VELOCIDAD_MIN);

    return (!azul && veloz);
}


int main() {
    const char ARCHIVO[] = "arrecife.txt";
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    acuario_t* simulacion_acuario = crear_acuario();
    int traslado_1 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*pokeveloz_azul),AZULES);

    int traslado_2 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*pokefofos),FOFOS);

    int traslado_3 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*vamo_a_calmarno),SQUIRTLES);
    /*
    int traslado_4 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),45);
    int traslado_5 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),20);
    //Trasladar y listar pokes n-veces
    //Guardar los pokemon del acuario
    */
    if (!traslado_1 && !traslado_2 && !traslado_3){
        printf("Se han podido realizar todos los traslados");
    }
    liberar_arrecife(simulacion_arrecife);
    liberar_acuario(simulacion_acuario);
    
    return 0;
}