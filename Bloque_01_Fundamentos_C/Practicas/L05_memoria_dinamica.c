/*
    L05_memoria_dinamica.c

    La memoria dinamica permite solicitar y liberar
    espacio durante la ejecucion del programa.

    En esta practica utilizaremos malloc(), free() y
    realloc() para gestionar memoria de forma controlada.
*/

#include <stdio.h>
#include <stdlib.h>

/*
    Definimos una enumeracion para representar
    los tipos de elementos del navegador.
*/
enum TipoArchivo {
    ARCHIVO,
    DIRECTORIO
};

/*
    Definimos una estructura para representar
    un archivo o directorio de ETN.

    El campo tipo utiliza la enumeracion TipoArchivo.
*/
struct Archivo {
    char nombre[64];
    int tamano;
    enum TipoArchivo tipo;
};

/*
    Creamos la funcion main para ejecutar los ejemplos.
*/
int main(void) {
    /*
        1. Reservamos memoria para un entero.

        - malloc(): Solicita un bloque de memoria.
        - sizeof(int): Calcula el tamano de un entero.
        - puntaje: Almacena la direccion del bloque.

        Comprobamos si malloc() devuelve NULL antes
        de intentar acceder a la memoria reservada.
    */

    printf("\n    - - - E J E M P L O   No.  1 : R E S E R V A R   M E M O R I A - - -\n");

    int *puntaje = malloc(sizeof(int));

    if (puntaje == NULL) {
        printf("    - E R R O R. No se pudo reservar memoria.\n");
        return 1;
    }

    /*
        La memoria reservada por malloc() no se inicializa.

        Asignamos un valor antes de leer el contenido.
    */

    *puntaje = 50;

    printf("Puntaje: %d\n", *puntaje);

    /*
        2. Liberamos la memoria reservada.

        free() indica que ya no necesitamos el bloque.
        Despues de liberarlo, no debemos acceder al objeto
        mediante la direccion que apuntaba a ese bloque.

        Asignamos NULL al puntero para dejar explicito
        que ya no conserva una direccion utilizable.
    */

    printf("\n    - - - E J E M P L O   No.  2 : L I B E R A R   M E M O R I A - - -\n");

    free(puntaje);
    puntaje = NULL;

    printf("La memoria del puntaje fue liberada.\n");

    /*
        3. Reservamos memoria para varios enteros.

        Solicitamos espacio para cinco elementos.
        La expresion cantidad * sizeof(int) calcula
        el tamano total de la reserva.
    */

    printf("\n    - - - E J E M P L O   No.  3 : R E S E R V A R   U N   A R R E G L O - - -\n");

    size_t cantidad = 5;

    int *puntajes = malloc(cantidad * sizeof(int));

    if (puntajes == NULL) {
        printf("    - E R R O R. No se pudo reservar memoria.\n");
        return 1;
    }

    /*
        Inicializamos todos los elementos antes de leerlos.

        El operador [] permite acceder a cada posicion
        del bloque como si fuera un arreglo.
    */

    for (size_t i = 0; i < cantidad; i++) {
        puntajes[i] = (int)((i + 1) * 10);
    }

    for (size_t i = 0; i < cantidad; i++) {
        printf("Puntaje %zu: %d\n", i, puntajes[i]);
    }

    /*
        4. Ampliamos el bloque con realloc().

        Solicitamos espacio para diez enteros.
        Guardamos el resultado en un puntero temporal
        para conservar la referencia original si falla.

        Si realloc() devuelve NULL, el bloque original
        sigue reservado y todavia podemos liberarlo.
    */

    printf("\n    - - - E J E M P L O   No.  4 : R E D I M E N S I O N A R   M E M O R I A - - -\n");

    size_t nuevaCantidad = 10;

    int *temporal = realloc(
        puntajes,
        nuevaCantidad * sizeof(int)
    );

    if (temporal == NULL) {
        printf("    - E R R O R. No se pudo ampliar la memoria.\n");

        free(puntajes);
        puntajes = NULL;

        return 1;
    }

    /*
        La operacion tuvo exito.

        Actualizamos el puntero para que apunte al bloque
        resultante, que puede estar en otra direccion.
    */

    puntajes = temporal;
    temporal = NULL;

    /*
        Los primeros cinco elementos conservan sus valores.

        Inicializamos las nuevas posiciones antes de
        intentar leerlas.
    */

    for (size_t i = cantidad; i < nuevaCantidad; i++) {
        puntajes[i] = (int)((i + 1) * 10);
    }

    for (size_t i = 0; i < nuevaCantidad; i++) {
        printf("Puntaje %zu: %d\n", i, puntajes[i]);
    }

    /*
        5. Liberamos el arreglo redimensionado.

        No debemos utilizar sus elementos despues de free().
    */

    printf("\n    - - - E J E M P L O   No.  5 : L I B E R A R   E L   A R R E G L O - - -\n");

    free(puntajes);
    puntajes = NULL;

    printf("El arreglo fue liberado.\n");

    /*
        6. Reservamos memoria para estructuras.

        Simulamos una pequena lista de elementos del navegador.
        La reserva tiene capacidad para dos estructuras Archivo.

        Antes de acceder a los campos, comprobamos que
        la reserva haya tenido exito.
    */

    printf("\n    - - - E J E M P L O   No.  6 : M E M O R I A   D I N A M I C A   Y   E S T R U C T U R A S - - -\n");

    size_t capacidad = 2;

    struct Archivo *archivos = malloc(
        capacidad * sizeof(struct Archivo)
    );

    if (archivos == NULL) {
        printf("    - E R R O R. No se pudo reservar memoria.\n");
        return 1;
    }

    /*
        Inicializamos los campos de las dos estructuras.

        Utilizamos strcpy() para copiar cadenas, pero para
        evitar una cabecera adicional asignamos los nombres
        mediante inicializadores en las propias estructuras.

        En este ejemplo utilizamos asignacion de campos
        excepto para los arreglos de caracteres, que no
        pueden recibir una cadena mediante asignacion directa.
    */

    snprintf(archivos[0].nombre, sizeof(archivos[0].nombre), "%s", "config.json");
    archivos[0].tamano = 2048;
    archivos[0].tipo = ARCHIVO;

    snprintf(archivos[1].nombre, sizeof(archivos[1].nombre), "%s", "SAVES");
    archivos[1].tamano = 0;
    archivos[1].tipo = DIRECTORIO;

    /*
        Mostramos los elementos reservados dinamicamente.
    */

    for (size_t i = 0; i < capacidad; i++) {
        printf("Nombre: %s\n", archivos[i].nombre);
        printf("Tamano: %d bytes\n", archivos[i].tamano);

        if (archivos[i].tipo == DIRECTORIO) {
            printf("Tipo: Directorio\n");
        } else {
            printf("Tipo: Archivo\n");
        }
    }

    /*
        Liberamos la memoria de la lista.

        Cada reserva exitosa debe tener una gestion clara
        de su ciclo de vida y su liberacion.
    */

    free(archivos);
    archivos = NULL;

    printf("\n    - - - F I N   D E   L A   P R A C T I C A - - -\n");

    return 0;
}