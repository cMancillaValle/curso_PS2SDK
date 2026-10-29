/*
    Practica L03: Makefile y automatizacion de la compilacion

    Bloque 02: Compilacion, Makefile y generacion de ELF

    Objetivos:
    - Comprender la funcion de make.
    - Reconocer las reglas de construccion.
    - Identificar los objetivos y las dependencias.
    - Comprender las ventajas de automatizar la compilacion.
    - Diferenciar una construccion nativa de una construccion para PS2.

    IMPORTANTE:
    Esta practica utiliza GCC nativo en Linux.
    No genera un ELF destinado a PlayStation 2.
*/

#include <stdio.h>

/*
    1. FUNCION PRINCIPAL

    La funcion main presenta los conceptos fundamentales
    de la automatizacion de la compilacion.

    El archivo se construira mediante un Makefile,
    evitando escribir manualmente el comando de GCC.
*/

int main(void) {

    printf("\n    - - - E J E M P L O   No.  1 : M A K E F I L E   Y   A U T O M A T I Z A C I O N - - -\n");

    /*
        1.1. PRESENTACION

        Mostramos el objetivo de la practica.
    */

    printf("\nObjetivo de la practica:\n");
    printf("Comprender como make automatiza la construccion de un programa.\n");

    /*
        1.2. FUNCION DE MAKE

        make lee las reglas definidas en un Makefile
        y ejecuta los comandos necesarios para construir
        los objetivos solicitados.
    */

    printf("\nFuncion de make:\n");
    printf("Lee las reglas del Makefile.\n");
    printf("Comprueba las dependencias declaradas.\n");
    printf("Ejecuta los comandos necesarios para construir el objetivo.\n");

    /*
        1.3. ELEMENTOS DE UNA REGLA

        Una regla contiene un objetivo y sus dependencias.
        El comando de construccion aparece en la siguiente linea
        y debe comenzar con un tabulador.
    */

    printf("\nElementos de una regla:\n");
    printf("Objetivo: elemento que queremos construir o ejecutar.\n");
    printf("Dependencias: archivos necesarios para construir el objetivo.\n");
    printf("Comando: instruccion que construye el objetivo.\n");

    /*
        1.4. AUTOMATIZACION

        El Makefile permite reutilizar los comandos de construccion.
        Esto reduce la necesidad de escribirlos manualmente
        cada vez que queremos compilar el programa.
    */

    printf("\nVentajas de la automatizacion:\n");
    printf("Evita repetir comandos de compilacion largos.\n");
    printf("Organiza las reglas de construccion.\n");
    printf("Permite reconstruir objetivos cuando cambian sus dependencias.\n");

    /*
        1.5. COMPILACION NATIVA Y PS2

        Esta practica se construye con GCC nativo de Linux.
        El uso de make no cambia el destino del compilador.

        Para generar un programa destinado a PlayStation 2
        debemos utilizar el compilador cruzado y la configuracion
        apropiada de PS2SDK.
    */

    printf("\nDestino de esta practica:\n");
    printf("GCC nativo genera un ejecutable para el entorno Linux.\n");
    printf("Esta practica no genera un ELF destinado a PS2.\n");

    /*
        1.6. FINALIZACION

        Si este mensaje aparece, el programa se ha ejecutado.
        La compilacion se ha automatizado mediante el Makefile.
    */

    printf("\nPractica finalizada correctamente.\n");

    return 0;
}