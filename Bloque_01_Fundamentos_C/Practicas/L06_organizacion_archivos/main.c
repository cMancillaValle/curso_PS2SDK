/*
    main.c

    Este archivo contiene el punto de entrada del programa.

    Utiliza las funciones declaradas en operaciones.h
    y definidas en operaciones.c.

    Observa que main.c puede utilizar las operaciones
    sin implementar nuevamente sus logicas.
*/

#include <stdio.h>
#include "operaciones.h"

int main(void) {

    printf("\n    - - - E J E M P L O   No.  1 : B I B L I O T E C A   P R O P I A - - -\n");

    /*
        Declaramos los operandos que utilizaremos
        en las operaciones matematicas.
    */

    int a = 20;
    int b = 5;

    /*
        Llamamos a las funciones de nuestra biblioteca.

        No necesitamos conocer sus implementaciones
        para poder utilizarlas.
    */

    int resultadoSuma = sumar(a, b);
    int resultadoResta = restar(a, b);
    int resultadoMultiplicacion = multiplicar(a, b);

    /*
        Mostramos los resultados obtenidos.
    */

    printf("Primer numero: %d\n", a);
    printf("Segundo numero: %d\n", b);

    printf("Suma: %d\n", resultadoSuma);
    printf("Resta: %d\n", resultadoResta);
    printf("Multiplicacion: %d\n", resultadoMultiplicacion);

    return 0;
}