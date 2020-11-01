#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

#define FOFOS 10
#define PESO_MIN 30
#define VELOCIDAD_MIN 40
#define AZULES 5
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
/*
void mostrar(){
printf("    .-=~=-.                                                                 .-=~=-.");
printf("(__  _)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-(__  _)");
printf("( _ __)                                                                 ( _ __)");
printf("(__  _)                                                                 (__  _)");
printf("(_ ___)                                                                 (_ ___)");
printf("(__  _)                                                                 (__  _)");
printf("( _ __)                                                                 ( _ __)");
printf("(__  _)                                                                 (__  _)");
printf("(_ ___)                                                                 (_ ___)");
printf("(__  _)                                                                 (__  _)");
printf("( _ __)                                                                 ( _ __)");
printf("(__  _)                                                                 (__  _)");
printf("(_ ___)                                                                 (_ ___)");
printf("(__  _)                                                                 (__  _)");
printf("( _ __)                                                                 ( _ __)");
printf("(__  _)                                                                 (__  _)");
printf("(_ ___)                                                                 (_ ___)");
printf("(__  _)                                                                 (__  _)");
printf("( _ __)                                                                 ( _ __)");
printf("(__  _)                                                                 (__  _)");
printf("( _ __)                                                                 ( _ __)");
printf("(__  _)                                                                 (__  _)");
printf("(_ ___)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-(_ ___)");
printf("`-._.-'                                                                 `-._.-'");
}
*/
bool pokeveloz_azul(pokemon_t* poke){
    bool azul = strcmp(poke->color, "azul");
    bool veloz = (poke->velocidad >= VELOCIDAD_MIN);

    return (!azul && veloz);
}


int main() {
    const char ARCHIVO[] = "arrecife.txt";
    const char ACUARIO[] = "acuario.txt";
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    acuario_t* simulacion_acuario = crear_acuario();
    int traslado_1 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*pokeveloz_azul),AZULES);
    //void censar1 = censar_arrecife(simulacion_arrecife, (*mostrar));
    int traslado_2 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*pokefofos),FOFOS);
    //void censar2 = censar_arrecife(simulacion_arrecife,(*mostrar));
    int traslado_3 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*vamo_a_calmarno),SQUIRTLES);
    //void censar3 = censar_arrecife(simulacion_arrecife, (*mostrar));
    /*
    int traslado_4 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),45);
    int traslado_5 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,pokefofos(simulacion_arrecife),20);
    //Trasladar y listar pokes n-veces
    //Guardar los pokemon del acuario
    */
    int archivo_acuario = guardar_datos_acuario(simulacion_acuario, ACUARIO);
    if ((!traslado_1) && (!traslado_2) && (!traslado_3)){
        printf("Se han podido realizar todos los traslados");
    }
    if (!archivo_acuario){
        printf("Se creo el archivo de acuerio");
    }
    liberar_arrecife(simulacion_arrecife);
    liberar_acuario(simulacion_acuario);
    
    return 0;
}