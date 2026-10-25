/*
    L04_enumeraciones.c

    Las enumeraciones permiten asociar nombres legibles
    con valores enteros.

    En esta practica utilizaremos enum para representar
    tipos de archivos y estados de ELFtation Navigator.
*/

#include <stdio.h>

/*
    Declaramos una enumeracion para representar
    los tipos de elementos del navegador.

    - ARCHIVO: Representa un archivo normal.
    - DIRECTORIO: Representa un directorio.

    Por defecto, ARCHIVO vale 0 y DIRECTORIO vale 1.
*/
enum TipoArchivo {
    ARCHIVO,
    DIRECTORIO
};

/*
    Declaramos una enumeracion para representar
    estados de ELFtation Navigator.

    Asignamos valores explicitos para mostrar que
    las constantes no tienen que comenzar en cero.
*/
enum EstadoETN {
    ETN_INACTIVO = 0,
    ETN_NAVEGANDO = 1,
    ETN_ERROR = -1
};

/*
    Declaramos una estructura que utiliza una enumeracion.

    El campo tipo permite identificar si el elemento
    representa un archivo o un directorio.
*/
struct Archivo {
    char nombre[64];
    int tamano;
    enum TipoArchivo tipo;
};

/*
    Recibe una estructura por valor y muestra sus datos.

    El parametro es una copia de la estructura original.
*/
void mostrarArchivo(struct Archivo archivo) {
    printf("Nombre: %s\n", archivo.nombre);
    printf("Tamano: %d bytes\n", archivo.tamano);

    switch (archivo.tipo) {
        case ARCHIVO:
            printf("Tipo: Archivo\n");
            break;

        case DIRECTORIO:
            printf("Tipo: Directorio\n");
            break;

        default:
            printf("Tipo: Desconocido\n");
            break;
    }
}

/*
    Recibe un estado de ETN y muestra su descripcion.

    Utilizamos switch para ejecutar una accion diferente
    segun el estado recibido.
*/
void mostrarEstado(enum EstadoETN estado) {
    switch (estado) {
        case ETN_INACTIVO:
            printf("ETN esta inactivo.\n");
            break;

        case ETN_NAVEGANDO:
            printf("ETN esta navegando.\n");
            break;

        case ETN_ERROR:
            printf("ETN encontro un error.\n");
            break;

        default:
            printf("Estado desconocido.\n");
            break;
    }
}

/*
    Creamos la funcion main para ejecutar los ejemplos.
*/
int main(void) {
    /*
        1. Consultamos los valores predeterminados.

        ARCHIVO comienza en 0 y DIRECTORIO vale 1.
    */

    printf("\n    - - - E J E M P L O   No.  1 : V A L O R E S   D E   U N A   E N U M E R A C I O N - - -\n");

    printf("Valor de ARCHIVO: %d\n", ARCHIVO);
    printf("Valor de DIRECTORIO: %d\n", DIRECTORIO);

    /*
        2. Consultamos valores explicitos.

        Las constantes pueden tener valores definidos
        directamente en la declaracion de la enumeracion.
    */

    printf("\n    - - - E J E M P L O   No.  2 : V A L O R E S   E X P L I C I T O S - - -\n");

    printf("ETN_INACTIVO: %d\n", ETN_INACTIVO);
    printf("ETN_NAVEGANDO: %d\n", ETN_NAVEGANDO);
    printf("ETN_ERROR: %d\n", ETN_ERROR);

    /*
        3. Utilizamos una enumeracion en una estructura.

        Cada variable de tipo Archivo almacena un nombre,
        un tamano y un tipo de elemento.
    */

    printf("\n    - - - E J E M P L O   No.  3 : E N U M E R A C I O N E S   Y   E S T R U C T U R A S - - -\n");

    struct Archivo archivo1 = {"config.json", 2048, ARCHIVO};
    struct Archivo directorio1 = {"SAVES", 0, DIRECTORIO};

    mostrarArchivo(archivo1);
    mostrarArchivo(directorio1);

    /*
        4. Accedemos al campo tipo mediante un puntero.

        El operador -> permite consultar los campos
        de una estructura a traves de su direccion.
    */

    printf("\n    - - - E J E M P L O   No.  4 : A C C E D E R   A   U N   C A M P O   E N U M E R A D O - - -\n");

    struct Archivo *punteroArchivo = &directorio1;

    if (punteroArchivo->tipo == DIRECTORIO) {
        printf("%s es un directorio.\n", punteroArchivo->nombre);
    }

    /*
        5. Utilizamos switch para mostrar un estado.

        El valor de estado determina que caso se ejecuta.
    */

    printf("\n    - - - E J E M P L O   No.  5 : E S T A D O S   D E   E T N - - -\n");

    enum EstadoETN estado = ETN_NAVEGANDO;

    mostrarEstado(estado);

    estado = ETN_ERROR;

    mostrarEstado(estado);

    /*
        6. Comprobamos el caso default.

        C permite que una variable enumerada contenga
        un valor entero que no coincida con las constantes
        declaradas en esa enumeracion.

        Por eso es conveniente contemplar valores
        inesperados cuando el programa los puede recibir.
    */

    printf("\n    - - - E J E M P L O   No.  6 : V A L O R E S   N O   C O N T E M P L A D O S - - -\n");

    estado = 7;

    mostrarEstado(estado);

    /*
        Finalizamos el programa.

        En esta practica solo utilizamos variables locales.
        No necesitamos reservar ni liberar memoria dinamica.
    */

    printf("\n    - - - F I N   D E   L A   P R A C T I C A - - -\n");

    return 0;
}