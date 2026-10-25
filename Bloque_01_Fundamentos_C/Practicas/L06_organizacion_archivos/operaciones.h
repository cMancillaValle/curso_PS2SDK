/*
    operaciones.h

    Este archivo contiene las declaraciones publicas de
    nuestra pequena biblioteca de operaciones.

    Otros archivos pueden incluir este encabezado para
    conocer las funciones disponibles sin necesitar
    conocer los detalles de su implementacion.

    Las protecciones de inclusion evitan que el contenido
    del encabezado se procese varias veces durante una
    misma compilacion.
*/

#ifndef OPERACIONES_H
#define OPERACIONES_H

/*
    Declaramos las funciones disponibles en nuestra
    biblioteca.

    - sumar: devuelve la suma de dos enteros.
    - restar: devuelve la diferencia entre dos enteros.
    - multiplicar: devuelve el producto de dos enteros.

    Estas son declaraciones, no implementaciones.
    Las implementaciones se encuentran en operaciones.c.
*/

int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);

#endif