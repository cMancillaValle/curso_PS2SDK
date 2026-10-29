/*
    Practica L01: Proceso de compilacion

    Bloque 02: Compilacion, Makefile y generacion de ELF

    Objetivos:
    - Identificar la estructura basica de un programa en C.
    - Diferenciar la declaracion y la definicion de una funcion.
    - Comprender que el codigo fuente necesita un proceso de construccion.
    - Relacionar el codigo fuente con los archivos objeto y el ejecutable.
    - Recordar la diferencia entre compilacion nativa y compilacion cruzada.

    IMPORTANTE:
    Este archivo sirve para estudiar los conceptos de la leccion.
    El programa no ejecuta ni simula las etapas del compilador.
    Estas etapas corresponden a las herramientas de construccion.
*/

#include <stdio.h>

/*
    1. DECLARACION DE FUNCIONES

    Una declaracion informa al compilador sobre una funcion.

    En este caso indicamos que sumar:
    - Recibe dos parametros de tipo int.
    - Devuelve un valor de tipo int.

    La declaracion termina con punto y coma porque aqui no
    estamos escribiendo el cuerpo de la funcion.

    La implementacion se encuentra mas adelante en este archivo.
*/

int sumar(int a, int b);

/*
    2. FUNCION PRINCIPAL

    La funcion main constituye el punto de entrada habitual
    de un programa en C.

    Dentro de main utilizaremos la funcion sumar, cuya
    declaracion ya conoce el compilador.
*/

int main(void) {

    printf("\n    - - - E J E M P L O   No.  1 : P R O C E S O   D E   C O N S T R U C C I O N - - -\n");

    /*
        2.1. VARIABLES Y LLAMADAS A FUNCIONES

        Creamos dos variables y almacenamos el resultado
        de llamar a la funcion sumar.

        La llamada utiliza la declaracion que escribimos
        anteriormente.
    */

    int numero_a = 10;
    int numero_b = 20;

    int resultado = sumar(numero_a, numero_b);

    printf("\nValores utilizados:\n");
    printf("Primer numero: %d\n", numero_a);
    printf("Segundo numero: %d\n", numero_b);
    printf("Resultado de la suma: %d\n", resultado);

    /*
        2.2. RELACION CON EL PROCESO DE COMPILACION

        El programa que estamos escribiendo es codigo fuente.

        Antes de poder ejecutarse, debe pasar por las etapas
        de construccion correspondientes.

        En un flujo habitual podemos encontrar:

        1. Preprocesamiento.
        2. Compilacion.
        3. Ensamblado.
        4. Enlazado.

        Las herramientas pueden coordinar estas etapas
        mediante un solo comando.

        Este printf solo describe el proceso.
        No ejecuta ninguna herramienta de compilacion.
    */

    printf("\nProceso de construccion estudiado:\n");
    printf("1. Preprocesamiento.\n");
    printf("2. Compilacion.\n");
    printf("3. Ensamblado.\n");
    printf("4. Enlazado.\n");

    /*
        2.3. CODIGO FUENTE Y ARCHIVOS OBJETO

        Este programa se encuentra en un unico archivo .c.

        En una construccion habitual, las herramientas pueden
        generar un archivo objeto .o y enlazarlo para producir
        el ejecutable.

        Si el programa estuviera dividido en varios archivos,
        cada archivo fuente podria compilarse por separado.

        El enlazador tendria que resolver las referencias
        entre los archivos objeto y las dependencias necesarias.

        No todos los programas necesitan varios archivos .o.
    */

    printf("\nArchivos que debemos reconocer:\n");
    printf("main.c: codigo fuente.\n");
    printf("main.o: ejemplo de archivo objeto.\n");
    printf("Ejecutable: resultado del proceso de construccion.\n");

    /*
        2.4. COMPILACION CRUZADA

        Nuestro objetivo final es desarrollar ETN para PS2.

        Para ello utilizaremos un entorno de desarrollo
        que ejecuta las herramientas de PS2SDK.

        El ordenador donde se ejecutan las herramientas
        es el host.

        La PlayStation 2 para la que generamos el programa
        es el target.

        Docker nos proporciona un entorno para trabajar,
        pero no convierte automaticamente el codigo en
        un ejecutable compatible con la consola.
    */

    printf("\nCompilacion cruzada para ETN:\n");
    printf("Host: entorno de desarrollo con las herramientas.\n");
    printf("Target: PlayStation 2.\n");
    printf("Objetivo: generar un ejecutable adecuado para PS2.\n");

    /*
        2.5. EL FORMATO ELF

        En el desarrollo homebrew de PlayStation 2 es habitual
        utilizar archivos ejecutables con extension .elf.

        La extension no garantiza por si sola la compatibilidad.

        El archivo debe haberse generado para la arquitectura
        y el entorno de destino adecuados, y sus dependencias
        deben resolverse correctamente.

        Todavia no generamos un ELF en esta practica.
        Lo haremos cuando estudiemos las herramientas de PS2SDK.
    */

    printf("\nFormato de salida esperado en nuestro proyecto:\n");
    printf("Un ELF adecuado para PlayStation 2.\n");

    /*
        2.6. FINALIZACION

        Devolvemos cero para indicar que el programa finalizo
        correctamente.
    */

    return 0;
}

/*
    3. DEFINICION DE LA FUNCION SUMAR

    Aqui encontramos la implementacion de sumar.

    A diferencia de la declaracion, la definicion contiene
    las instrucciones que ejecuta la funcion.

    En este caso:
    - Recibe dos enteros.
    - Los suma.
    - Devuelve el resultado.

    La funcion esta en el mismo archivo que main para mantener
    esta primera practica sencilla.

    En una practica posterior estudiaremos como separar
    las funciones en archivos .c y las declaraciones
    compartidas en archivos .h.
*/

int sumar(int a, int b) {

    int resultado = a + b;

    return resultado;
}