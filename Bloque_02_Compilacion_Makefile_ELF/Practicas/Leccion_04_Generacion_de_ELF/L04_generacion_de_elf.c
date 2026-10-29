/*
    Practica L04: Generacion de ELF y analisis del ejecutable

    Bloque 02: Compilacion, Makefile y generacion de ELF

    Objetivos:
    - Comprender el concepto de ELF.
    - Identificar los elementos principales del formato.
    - Diferenciar extension y compatibilidad.
    - Reconocer herramientas de inspeccion.
    - Comprender el flujo de construccion de ETN.

    IMPORTANTE:
    Esta practica utiliza GCC nativo en Linux.
    No genera un ELF destinado a PlayStation 2.
    El ejecutable producido por el Makefile es una aplicacion
    nativa para el entorno donde se ejecuta el compilador.
*/

#include <stdio.h>

/*
    1. FUNCION PRINCIPAL

    La funcion main presenta los conceptos relacionados
    con el formato ELF y su inspeccion.

    La practica explica los conceptos mediante mensajes.
    No analiza automaticamente ningun archivo ELF externo.
*/

int main(void) {

    printf("\n    - - - E J E M P L O   No.  1 : G E N E R A C I O N   D E   E L F - - -\n");

    /*
        1.1. PRESENTACION

        Explicamos el objetivo general de la practica.
    */

    printf("\nObjetivo de la practica:\n");
    printf("Comprender como se genera y analiza un ejecutable.\n");

    /*
        1.2. CONCEPTO DE ELF

        ELF significa Executable and Linkable Format.
        Es un formato utilizado para ejecutables y otros
        componentes binarios en distintos entornos.
    */

    printf("\nConcepto de ELF:\n");
    printf("ELF significa Executable and Linkable Format.\n");
    printf("La extension no garantiza la compatibilidad del archivo.\n");

    /*
        1.3. COMPONENTES PRINCIPALES

        La cabecera describe caracteristicas generales.
        Las secciones organizan distintos tipos de informacion.
        Los segmentos describen regiones relevantes para la carga.
        El punto de entrada indica la direccion de entrada declarada.
    */

    printf("\nComponentes principales:\n");
    printf("Cabecera: contiene informacion general del archivo.\n");
    printf("Secciones: organizan codigo, datos y otras tablas.\n");
    printf("Segmentos: describen regiones relevantes para la carga.\n");
    printf("Punto de entrada: indica la direccion de entrada del ejecutable.\n");

    /*
        1.4. HERRAMIENTAS DE INSPECCION

        file permite identificar el tipo de archivo.
        readelf permite examinar la estructura ELF.
        objdump permite inspeccionar informacion del ejecutable
        y, segun las opciones, mostrar instrucciones desensambladas.

        Esta practica presenta las herramientas, pero no las ejecuta.
    */

    printf("\nHerramientas de inspeccion:\n");
    printf("file: identifica el tipo de archivo.\n");
    printf("readelf: examina la estructura ELF.\n");
    printf("objdump: inspecciona informacion del ejecutable.\n");

    /*
        1.5. COMPATIBILIDAD CON PLAYSTATION 2

        Un ejecutable destinado a PS2 debe construirse
        con herramientas y configuraciones apropiadas.

        Tambien deben resolverse las dependencias necesarias
        y comprobarse el resultado en un entorno compatible.
    */

    printf("\nCompatibilidad con PlayStation 2:\n");
    printf("La extension .elf no demuestra compatibilidad.\n");
    printf("La arquitectura y el entorno deben ser adecuados.\n");
    printf("El resultado debe inspeccionarse y probarse.\n");

    /*
        1.6. RELACION CON ETN

        Para ETN necesitaremos organizar el codigo fuente,
        automatizar la construccion y utilizar las herramientas
        apropiadas de PS2SDK.

        Esta practica no ejecuta el compilador cruzado
        ni genera un ELF destinado a la consola.
    */

    printf("\nRelacion con ETN:\n");
    printf("Organizar el codigo fuente.\n");
    printf("Compilar y enlazar con las herramientas apropiadas.\n");
    printf("Inspeccionar el ELF generado.\n");
    printf("Probar el programa en un entorno compatible.\n");

    /*
        1.7. FINALIZACION

        La ejecucion de este programa demuestra que el
        ejecutable nativo se ha construido y puede iniciarse
        en el entorno actual.

        No demuestra compatibilidad con PlayStation 2.
    */

    printf("\nPractica finalizada correctamente.\n");
    printf("Este programa no genera ni verifica un ELF para PS2.\n");

    return 0;
}