/*
    Practica L02: Compilar para PlayStation 2

    Bloque 02: Compilacion, Makefile y generacion de ELF

    Objetivos:
    - Comprender por que necesitamos herramientas especificas para PS2.
    - Identificar el papel de PS2SDK en nuestro proyecto.
    - Diferenciar las cabeceras de las bibliotecas.
    - Comprender la funcion del enlazador.
    - Reconocer el papel de Docker en el entorno de desarrollo.
    - Identificar las condiciones necesarias para generar un ELF adecuado.

    IMPORTANTE:
    Este programa es una practica conceptual.
    No utiliza directamente las herramientas de PS2SDK.
    Tampoco genera un ELF ni comprueba la compatibilidad con PS2.
*/

#include <stdio.h>
#include "funciones_ps2.h"

/*
    1. FUNCION PRINCIPAL

    La funcion main organiza la ejecucion de la practica.

    Las funciones auxiliares se encuentran implementadas
    en funciones_ps2.c y sus declaraciones estan en
    funciones_ps2.h.

    Esta separacion permite distribuir las responsabilidades
    entre varios archivos fuente.
*/

int main(void) {

    printf("\n    - - - E J E M P L O   No.  2 : C O M P I L A C I O N   P A R A   P S 2 - - -\n");

    /*
        1.1. PRESENTACION

        Mostramos el objetivo general de esta practica.
        El programa explica conceptos mediante mensajes.
    */

    printf("\nObjetivo de la practica:\n");
    printf("Comprender como se prepara un programa para PlayStation 2.\n");

    /*
        1.2. PRESENTACION DE LOS CONCEPTOS

        Cada funcion se encarga de explicar un aspecto
        del proceso de desarrollo para PlayStation 2.
    */

    mostrar_herramientas();
    mostrar_cabeceras_y_bibliotecas();
    mostrar_proceso_de_construccion();
    mostrar_entorno_de_desarrollo();

    /*
        1.3. FINALIZACION

        La practica describe conceptos de construccion.
        No ejecuta herramientas externas ni genera un ELF.
    */

    printf("\nPractica finalizada.\n");
    printf("Todavia no se ha generado ni comprobado ningun ELF.\n");

    return 0;
}