
/*
    L02_punteros.c

    Los punteros permiten trabajar con direcciones de memoria
    y acceder a los objetos almacenados en esas direcciones.

    En esta practica veremos como declarar punteros, obtener
    direcciones, acceder a valores y modificar variables
    mediante punteros.
*/

#include <stdio.h>

/*
    Declaramos el prototipo de nuestra funcion.

    - void: Indica que la funcion no devuelve un valor.
    - aumentarPuntaje: Es el nombre de la funcion.
    - int *puntaje: Recibe un puntero a un entero.
*/
void aumentarPuntaje(int *puntaje);

/*
    Implementamos la funcion aumentarPuntaje.

    Recibe la direccion de una variable entera y aumenta
    su valor en 10 mediante el puntero.
*/
void aumentarPuntaje(int *puntaje) {
    /*
        Comprobamos que el puntero no sea nulo antes
        de intentar acceder al objeto apuntado.
    */

    if (puntaje == NULL) {
        printf("    - E R R O R. El puntero es nulo.\n");
        return;
    }

    *puntaje = *puntaje + 10;
}

/*
    Creamos la funcion main para ejecutar los ejemplos.
*/
int main(void) {
    /*
        1. Declaramos una variable entera.

        La variable puntaje almacena el valor 50.
    */

    int puntaje = 50;

    printf("\n    - - - E J E M P L O   No.  1 : V A R I A B L E S   Y   D I R E C C I O N E S - - -\n");

    printf("Valor de puntaje: %d\n", puntaje);

    /*
        Utilizamos el operador & para obtener la direccion
        de memoria de la variable puntaje.
    */

    printf("Direccion de puntaje: %p\n", (void *)&puntaje);

    /*
        2. Declaramos un puntero.

        - int *: Indica que el puntero apunta a un entero.
        - &puntaje: Obtiene la direccion de puntaje.

        El puntero almacena la direccion de la variable,
        no una copia independiente de su valor.
    */

    int *puntero = &puntaje;

    printf("\n    - - - E J E M P L O   No.  2 : P U N T E R O S - - -\n");

    printf("Direccion almacenada: %p\n", (void *)puntero);

    /*
        Utilizamos el operador * para acceder al valor
        del objeto al que apunta el puntero.

        Como puntero apunta a puntaje, ambas expresiones
        permiten acceder al mismo objeto.
    */

    printf("Valor mediante el puntero: %d\n", *puntero);

    /*
        3. Modificamos la variable mediante el puntero.

        La expresion *puntero permite acceder al objeto
        apuntado y asignarle un nuevo valor.

        Como el puntero apunta a puntaje, modificamos
        directamente la variable original.
    */

    printf("\n    - - - E J E M P L O   No.  3 : M O D I F I C A R   U N   V A L O R - - -\n");

    *puntero = 75;

    printf("Nuevo valor de puntaje: %d\n", puntaje);

    /*
        4. Pasamos la direccion de una variable a una funcion.

        La funcion recibe una copia de la direccion y utiliza
        el puntero para modificar la variable original.

        El operador & obtiene la direccion que enviamos
        como argumento.
    */

    printf("\n    - - - E J E M P L O   No.  4 : P U N T E R O S   Y   F U N C I O N E S - - -\n");

    aumentarPuntaje(&puntaje);

    printf("Puntaje despues de aumentar: %d\n", puntaje);

    /*
        5. Trabajamos con un puntero nulo.

        NULL representa un puntero que no apunta a un objeto
        valido.

        Podemos comprobar si un puntero es nulo, pero nunca
        debemos intentar acceder a un objeto mediante el
        operador * cuando no apunta a uno valido.
    */

    printf("\n    - - - E J E M P L O   No.  5 : P U N T E R O S   N U L O S - - -\n");

    int *punteroNulo = NULL;

    if (punteroNulo == NULL) {
        printf("El puntero no apunta a ningun objeto.\n");
    }

    /*
        6. Finalizamos el programa.

        No necesitamos liberar memoria dinamica porque todos
        los objetos de esta practica son variables locales.

        La memoria de estas variables deja de estar disponible
        cuando finaliza la ejecucion de main.
    */

    return 0;
}