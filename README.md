#Algoritmos II - TP1

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
