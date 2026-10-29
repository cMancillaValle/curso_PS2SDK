/*
    Archivo de implementacion: funciones_ps2.c

    Practica L02: Compilar para PlayStation 2

    Contiene las implementaciones de las funciones declaradas
    en funciones_ps2.h.
*/

#include <stdio.h>
#include "funciones_ps2.h"

/*
    1. HERRAMIENTAS DE PS2SDK

    PS2SDK proporciona herramientas para construir programas
    destinados a PlayStation 2.

    Entre ellas encontramos ee-gcc, utilizado para compilar
    codigo C destinado al Emotion Engine.

    Esta funcion presenta informacion general.
    No comprueba si las herramientas estan instaladas.
*/

void mostrar_herramientas(void) {

    printf("\n    - - - E J E M P L O   No.  3 : H E R R A M I E N T A S - - -\n");

    printf("\nHerramientas relacionadas con PS2SDK:\n");
    printf("ee-gcc: compilador de C para el Emotion Engine.\n");
    printf("ee-g++: compilador de C++ para el Emotion Engine.\n");
    printf("ee-ld: herramienta de enlazado para el Emotion Engine.\n");

    printf("\nPS2SDK proporciona herramientas y bibliotecas.\n");
    printf("La configuracion debe corresponder al destino del programa.\n");
}

/*
    2. CABECERAS Y BIBLIOTECAS

    Las cabeceras contienen declaraciones que permiten conocer
    las interfaces de funciones, estructuras y otros elementos.

    Las bibliotecas proporcionan implementaciones que pueden
    necesitar los programas.

    Incluir una cabecera no garantiza que el enlazador encuentre
    todas las implementaciones necesarias.
*/

void mostrar_cabeceras_y_bibliotecas(void) {

    printf("\n    - - - E J E M P L O   No.  4 : C A B E C E R A S   Y   B I B L I O T E C A S - - -\n");

    printf("\nArchivos de cabecera:\n");
    printf(".h: permiten compartir declaraciones e interfaces.\n");

    printf("\nBibliotecas:\n");
    printf("Proporcionan implementaciones de funciones.\n");

    printf("\nEnlazador:\n");
    printf("Resuelve referencias necesarias para construir el programa.\n");
}

/*
    3. PROCESO DE CONSTRUCCION

    La construccion de un programa puede involucrar
    preprocesamiento, compilacion, ensamblado y enlazado.

    Las herramientas pueden coordinar varias de estas etapas
    mediante un solo comando.

    Para obtener un ejecutable destinado a PS2 debemos utilizar
    herramientas y opciones apropiadas para la consola.

    La extension .elf no garantiza por si sola la compatibilidad.

    Esta funcion describe el proceso, pero no lo ejecuta.
*/

void mostrar_proceso_de_construccion(void) {

    printf("\n    - - - E J E M P L O   No.  5 : P R O C E S O   D E   C O N S T R U C C I O N - - -\n");

    printf("\nEtapas habituales:\n");
    printf("1. Preprocesamiento.\n");
    printf("2. Compilacion.\n");
    printf("3. Ensamblado.\n");
    printf("4. Enlazado.\n");

    printf("\nResultado esperado en ETN:\n");
    printf("Un ELF construido para el entorno de PlayStation 2.\n");

    printf("\nLa compatibilidad debe comprobarse por separado.\n");
}

/*
    4. ENTORNO DE DESARROLLO

    En nuestro proyecto utilizamos VS Code y Docker.

    VS Code permite editar los archivos del proyecto.

    Docker proporciona el entorno donde se ejecutan
    las herramientas configuradas.

    PS2SDK aporta las herramientas y bibliotecas necesarias
    para construir el programa.

    Docker no es el compilador y no ejecuta automaticamente
    el programa en el hardware de la consola.

    Esta funcion presenta la relacion entre los componentes,
    pero no inspecciona el entorno real.
*/

void mostrar_entorno_de_desarrollo(void) {

    printf("\n    - - - E J E M P L O   No.  6 : E N T O R N O   D E   D E S A R R O L L O - - -\n");

    printf("\nComponentes del entorno:\n");
    printf("VS Code: edicion del codigo fuente.\n");
    printf("Docker: entorno de ejecucion de las herramientas.\n");
    printf("PS2SDK: herramientas y bibliotecas para PS2.\n");

    printf("\nFlujo general:\n");
    printf("1. Escribir el codigo fuente.\n");
    printf("2. Preparar las herramientas y dependencias.\n");
    printf("3. Compilar y enlazar el programa.\n");
    printf("4. Comprobar el resultado.\n");
    printf("5. Probarlo en un entorno compatible.\n");
}