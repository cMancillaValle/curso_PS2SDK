/*
    operaciones.c

    Este archivo contiene las implementaciones de las
    funciones declaradas en operaciones.h.

    Al separar las implementaciones de las declaraciones,
    podemos modificar la logica interna de las funciones
    sin obligar a otros archivos a conocer esos detalles.
*/

#include "operaciones.h"

/*
    Implementamos la funcion sumar.

    Recibe dos enteros y devuelve su suma.
*/
int sumar(int a, int b) {
    return a + b;
}

/*
    Implementamos la funcion restar.

    Recibe dos enteros y devuelve su diferencia.
*/
int restar(int a, int b) {
    return a - b;
}

/*
    Implementamos la funcion multiplicar.

    Recibe dos enteros y devuelve su producto.
*/
int multiplicar(int a, int b) {
    return a * b;
}