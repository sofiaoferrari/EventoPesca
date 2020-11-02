#Algoritmos II - TP1

#Introduccion:

        Evento pesca es un programa que tiene como fin realizar una simulacion de un arrecife que contenga una
         cierta cantidad de pokemones de tipo agua, y una simulacion de un acuario que se encuentre vacio. 
        Una vez que ambas simulaciones fueron creadas se podran seleccionar una cierta cantidad de pokemones del 
        arrecife con ciertas caracteristicas, para que sean capturados y trasladados al acuario. Ambas acciones 
        solo pueden llevarse a cabo en el caso de que se cumpla la condicion de que la cantidad de pokemones 
        seleccionados con sus respectivas caracteristicas se encuentren en el arrecife, de lo contrario no se 
        realizara el tralado. 
    
    -Funcionamiento: 
        El programa comienza con la creacion de un arrecife, dado un archivo de texto con pokemones a agregar a 
        dicho arrecife. Una vez que se creo el arrecife con sus pokemones, se crea un acuario vacio.
        Luego se procede a trasladar pokemones del arrecife seleccionados por distintas funciones al acuario, lo 
        cual implica la eliminacion de dichos pokemones en el arrecife.
        Finalmente se guardan todos los datos del acuario de sus nuevos pokemones capturados, en un archivo txt 
        creado.

    -Compilacion: 
        El programa debe ser compilado mediante gcc con la siguiente linea de compilacion: 

         gcc *.c -Wall -Werror -Wconversion -std=c99 -o evento_pesca

    -Ejecucion:
        Una vez compilado se debe ejecutar con la siguiente linea de ejecuccion:

        ./evento_pesca


#Conceptos a saber:

1. Punteros

Los punteros son variables que pueden almacenar una direccion de memoria. Sus usos pueden ser para:
- Referenciar variables locales indirectamente.
- Permitir que las funciones puedan modificar variables externas a ellas.
- Apuntar a memoria gestionada con el sistema operativo (memoria dinamica).

2. Aritmetica de Punteros

Como cualquier otro tipo de variable, los punteros pueden ser referenciados y modificados mediante operadores. Los mas utilizados con punteros son:
- Operador de indireccion (*) -> declara un puntero, y por otro lado tambien permite la vision del valor guardado en dicha direccion de memoria asignada.
- Operador de direccion (&) -> permite acceder a la direccion de memoria de cierta variable.
- Operados de incrementacion (++) y decrecion (--) -> se utilizan en los casos que el puntero trata con un array.

3. Punteros a Funciones

Un puntero a una funcion es la direccion de memoria donde se encuentra la funcion. Algunas de sus ventajas son:
- La posibilidad de ejecutar dicha funcion desde cualquier parte del programa.
- Permiten pasar una funcion como parametro de otra.
- Permiten que una funcion sea devuelta por otra.
- Permiten utilizar una funcion como elemento de un vector.

4. Malloc y Realloc

Ambas son funciones brindadas por la biblioteca (stdlib.h) de C y se ocupan de reservar un bloque de memoria 
dinamico en el heap, pero realloc puede reajustar un bloque ya existente, agrandando o achicando la memoria 
reservada.

-Malloc: 
        void* malloc(size_t n);
        ~ n es la cantidad de bytes de memoria que se desean reservar.
        ~ si hay memoria devuelve la posiocion, si no la hay devuelve NULL.
-Realloc:
        void* realloc(void* cosa, size_t n);
        ~ si hay memoria realiza un memcpy() de la memoria vieja y despues libera a "cosa", devolviendo la memoria nueva. (si falla devuelve NULL)
        ~ siempre se debe reasignar el puntero.