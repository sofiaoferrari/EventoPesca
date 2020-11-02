#include "evento_pesca.h"
#include <stdlib.h>
#include <string.h>

#define FOFOS 10
#define PESO_MIN 45
#define VELOCIDAD_MIN 30
#define AZULES 5
#define SQUIRTLES 2
#define BOKITA 8
#define SHELLDERS 2

void imprimir_titulo(){
printf("\n\t\t\t\t                                  ,'\\");
printf("\n\t\t\t\t    _.----.        ____         ,'  _\\   ___    ___     ____      ");
printf("\n\t\t\t\t_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.");
printf("\n\t\t\t\t\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |");
printf("\n\t\t\t\t \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |");
printf("\n\t\t\t\t   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |");
printf("\n\t\t\t\t    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |");
printf("\n\t\t\t\t     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |");
printf("\n\t\t\t\t      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |");
printf("\n\t\t\t\t       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |");
printf("\n\t\t\t\t        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |");
printf("\n\t\t\t\t                                `'                            '-._|");
printf("\n");
}

void nos_calmamo(){
printf("\n\t\t\t\t\t               _,........__");
printf("\n\t\t\t\t\t            ,-'            `-.");
printf("\n\t\t\t\t\t          ,'                   `-.");
printf("\n\t\t\t\t\t        ,'                        \\");
printf("\n\t\t\t\t\t      ,'                           .");
printf("\n\t\t\tME CALMO CHAU\t      .'\\               ,"".       `");
printf("\n\t\t\t\t\t     ._.'|             / |  `       \\");
printf("\n\t\t\t\t\t     |   |            `-.'  ||       `.");
printf("\n\t\t\t\t\t     |   |            '-._,'||       | \\");
printf("\n\t\t\t\t\t     .`.,'             `..,'.'       , |`-.");
printf("\n\t\t\t\t\t     l                       .'`.  _/  |   `.");
printf("\n\t\t\t\t\t     `-.._'-   ,          _ _'   -' \\  .     `");
printf("\n\t\t\t\t\t`.''''''-.`-...,---------','         `. `....__.");
printf("\n\t\t\t\t\t.'        `'-..___      __,\\          \\  \\     \\");
printf("\n\t\t\t\t\t\\_ .          |   `''''    `.           . \\     \\");
printf("\n\t\t\t\t\t  `.          |              `.          |  .     L");
printf("\n\t\t\t\t\t    `.        |`--...________.'.        j   |     |");
printf("\n\t\t\t\t\t      `._    .'      |          `.     .|   ,     |");
printf("\n\t\t\t\t\t         `--,\\       .            `7""' |  ,      |");
printf("\n\t\t\t\t\t            ` `      `            /     |  |      |    _,-''''`-.");
printf("\n\t\t\t\t\t             \\ `.     .          /      |  '      |  ,'          `.");
printf("\n\t\t\t\t\t              \\  v.__  .        '       .   \\    /| /              \\");
printf("\n\t\t\t\t\t                 \\/    `''\''''''`.       \\   \\  /.''                |");
printf("\n\t\t\t\t\t                 `        .        `._ ___,j.  `/ .-       ,---.     |");
printf("\n\t\t\t\t\t                 ,`-.      \\         .'     `.  |/        j     `    |");
printf("\n\t\t\t\t\t               /    `.      \\       /         \\ /         |     /    j");
printf("\n\t\t\t\t\t               |       `-.   7-.._ .          |'          '         /");
printf("\n\t\t\t\t\t               |          `./_    `|          |            .     _,'");
printf("\n\t\t\t\t\t               `.           / `----|          |-............`---'");
printf("\n\t\t\t\t\t                \\          \\      |          |");
printf("\n\t\t\t\t\t               ,'           )     `.         |");
printf("\n\t\t\t\t\t                7____,,..--'      /          |");
printf("\n\t\t\t\t\t                                  `---.__,--.'");
printf("\n");
}

void mostrar_4(pokemon_t* pokemon) {
printf("\n\n");
printf("\n __| |____________________________________________| |__");
printf("\n(__   ____________________________________________   __)");
printf("\n   | |                                            | |");
printf("\n   | |  Especie: %-11sVelocidad: %-11i| |", pokemon->especie, pokemon->velocidad);
printf("\n   | |                                            | |");
printf("\n   | |                                            | |");
printf("\n   | |  Peso: %-12i Color: %-12s    | |", pokemon->peso, pokemon->color);
printf("\n   | |                                            | |");
printf("\n __| |____________________________________________| |__");
printf("\n(__   ____________________________________________   __)");
printf("\n   | |                                            | |");
}

void mostrar_5(pokemon_t* pokemon) {
printf("\n   _____________________________");
printf("\n / \\                            \\.");
printf("\n|   |                            |.");
printf("\n \\_ |                            |.");
printf("\n    |   Epecie: %-12s     |.",pokemon->especie);
printf("\n    |                            |.");
printf("\n    |                            |.");
printf("\n    |   Velocidad: %-12i  |.", pokemon->velocidad);
printf("\n    |                            |.");
printf("\n    |                            |.");
printf("\n    |   Peso: %-12i       |.", pokemon->peso);
printf("\n    |                            |.");
printf("\n    |                            |.");
printf("\n    |   Color: %-12s      |.", pokemon->color);
printf("\n    |                            |.");
printf("\n    |   _________________________|___");
printf("\n    |  /                            /.");
printf("\n    \\_/____________________________/.");
}

void formato_linea_3(int cantidad){
	for (int i = 0; i < cantidad; i++){
		printf("%s", "-");
	}
}

void mostrar_3(pokemon_t* pokemon){
	formato_linea_3(48);
	printf("\n|%-50s|\n", pokemon->especie);
	printf("|%-50i|\n", pokemon->velocidad);
	printf("|%-50i|\n", pokemon->peso);
	printf("|%-50s|\n", pokemon->color);
}

void mostrar_2(pokemon_t* pokemon){
	printf("\n/\n");
	printf("|%s%s\n", "Especie: ", pokemon->especie);
	printf("|%s%i km\\h\n", "Velocidad: ", pokemon->velocidad);
	printf("|%s%i kg\n", "Peso: ", pokemon->peso);
	printf("|%s%s\n", "Color: ", pokemon->color);
	printf("\\ \n");
}

void mostrar(pokemon_t* pokemon){
        printf("\nEspecie: %s  Velocidad: %d km\\h", pokemon->especie, pokemon->velocidad);
        printf("\nPeso: %d kg  Color: %s\n", pokemon->peso, pokemon->color);

}

bool exclusivos_shell(pokemon_t* poke) {
    bool shell = strcmp(poke->especie, "Shellder");
    return (!shell);
}

bool poke_de_bokita(pokemon_t* poke) {
    bool azul = strcmp(poke->color, "azul");
    bool amarillo = strcmp(poke->color, "amarillo");
    bool bokita = ((!azul) || (!amarillo));
    return (bokita);
}

bool vamo_a_calmarno(pokemon_t* poke){
    bool squirtle = strcmp(poke->especie, "Squirtle");
    return (!squirtle);
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
    const char ACUARIO[] = "acuario.txt";
    imprimir_titulo();
    arrecife_t* simulacion_arrecife = crear_arrecife(ARCHIVO); 
    if ((!simulacion_arrecife) || (simulacion_arrecife->cantidad_pokemon == 0))
        return -1;
    acuario_t* simulacion_acuario = crear_acuario();
    printf("\n\n\tTRASLADO 1:\n\n");
    int traslado_1 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*pokeveloz_azul),AZULES);
    censar_arrecife(simulacion_arrecife, (*mostrar));
    printf("\n\n\tTRASLADO 2:\n\n");
    int traslado_2 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*pokefofos),FOFOS);
    censar_arrecife(simulacion_arrecife,(*mostrar_2));
    printf("\n\n\tTRASLADO 3:\n\n");
    int traslado_3 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*vamo_a_calmarno),SQUIRTLES);
    printf("n");
    censar_arrecife(simulacion_arrecife, (*mostrar_3));
    formato_linea_3(48);
    printf("\n\n\tTRASLADO 4:\n\n");
    int traslado_4 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*poke_de_bokita),BOKITA);
    censar_arrecife(simulacion_arrecife, (*mostrar_4));
    printf("\n\n\tTRASLADO 5:\n\n");
    int traslado_5 = trasladar_pokemon(simulacion_arrecife,simulacion_acuario,(*exclusivos_shell),SHELLDERS);
    censar_arrecife(simulacion_arrecife, (*mostrar_5));
    if ((!traslado_1) && (!traslado_2) && (!traslado_3) && (!traslado_4) && (!traslado_5)){
        printf("\n\n\nSe han podido realizar todos los traslados :)");
    } else {
        printf("\n\n\nNo se han podido realizar todos los traslados :(");
    }
    int archivo_acuario = guardar_datos_acuario(simulacion_acuario, ACUARIO);
    if (!archivo_acuario){
        printf("\n\nYa esta lista la simulacion del acuario!");
    }
    liberar_arrecife(simulacion_arrecife);
    liberar_acuario(simulacion_acuario);
    nos_calmamo();
    return 0;
}