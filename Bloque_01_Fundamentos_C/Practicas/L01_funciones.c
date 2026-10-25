/*
    L01_funciones.c

    Es de vital importancia repartir las responsabilidades
    del código a través de funciones.
*/

#include <stdio.h> // Biblioteca estándar de entrada y salida.

/*
    Creamos los prototipos de nuestras funciones.

    Los prototipos permiten declarar las funciones antes
    de utilizarlas.

    - void: Indica que la función no devuelve un valor.
    - (void): Indica que la función no recibe parámetros.
*/

void inicializar(void);
void mostrarMenu(void);
void procesarEntrada(void);

int sumar(int a, int b);

/*
    Ejemplo de una función:

    int sumar(int a, int b) {
        return a + b;
    }

    - int: Indica el tipo de valor de retorno de la función.
    - sumar: Es el nombre de la función.
    - int a, int b: Son los parámetros, es decir, los datos
                    que recibe la función.
    - return a + b: Devuelve el resultado al lugar desde
                    donde se llamó la función.

    Podemos utilizarla así:

    int resultado = sumar(10, 5);

    En este caso, resultado tendrá el valor 15.
*/

/*
    Implementamos nuestras funciones.

    Cada función se encarga de una responsabilidad diferente
    dentro del programa.
*/

void inicializar(void) {
    printf("    - Inicializando el programa...\n");
}

void mostrarMenu(void) {
    printf("\n");
    printf("    - - - M E N U   D E   E T N - - -\n");
    printf("1. Explorar archivos\n");
    printf("2. Configuración\n");
    printf("3. Salir\n");
}

void procesarEntrada(void) {
    printf("Procesando entrada del usuario...\n");
}

/*
    Implementamos la función sumar.

    Recibe dos números enteros y devuelve su suma.
*/

int sumar(int a, int b) {
    return a + b;
}

/*
    Creamos la función main para llamar las funciones
    creadas y poder utilizarlas.

    main es el punto de entrada del programa.
*/

int main(void) {
    inicializar();
    mostrarMenu();
    procesarEntrada();

    /*
        Llamamos a sumar y guardamos el resultado
        que devuelve la función.
    */

    int resultado = sumar(10, 5);

    printf("\nResultado de la suma: %d\n", resultado);

    return 0;
}