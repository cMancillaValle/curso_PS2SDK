
/*
    L03_estructuras.c

    Las estructuras permiten agrupar datos relacionados
    dentro de un mismo objeto.

    En esta practica representaremos archivos y directorios
    mediante una estructura llamada Archivo.
*/

#include <stdio.h>

/*
    Definimos la estructura Archivo.

    - char nombre[64]: Almacena el nombre del elemento.
    - int tamano: Almacena el tamano en bytes.
    - int esDirectorio: Indica si es un directorio.

    En esta practica utilizamos 0 para archivos y 1 para
    directorios.
*/
struct Archivo {
    char nombre[64];
    int tamano;
    int esDirectorio;
};

/*
    Recibe una copia de la estructura y muestra sus datos.

    Como el parametro se recibe por valor, los cambios que
    hagamos sobre archivo no modificaran la estructura
    original.
*/
void mostrarArchivo(struct Archivo archivo) {
    printf("Nombre: %s\n", archivo.nombre);
    printf("Tamano: %d bytes\n", archivo.tamano);

    if (archivo.esDirectorio) {
        printf("Tipo: Directorio\n");
    } else {
        printf("Tipo: Archivo\n");
    }
}

/*
    Recibe un puntero constante a una estructura.

    El operador -> permite acceder a sus campos mediante
    el puntero.

    La palabra const impide modificar los campos mediante
    este puntero dentro de la funcion.
*/
void mostrarArchivoPorPuntero(const struct Archivo *archivo) {
    if (archivo == NULL) {
        printf("    - E R R O R. El puntero es nulo.\n");
        return;
    }

    printf("Nombre: %s\n", archivo->nombre);
    printf("Tamano: %d bytes\n", archivo->tamano);

    if (archivo->esDirectorio) {
        printf("Tipo: Directorio\n");
    } else {
        printf("Tipo: Archivo\n");
    }
}

/*
    Modifica el tamano del archivo original mediante
    un puntero a su estructura.

    - struct Archivo *archivo: Recibe la direccion
      de la estructura que queremos modificar.
    - int nuevoTamano: Recibe el nuevo tamano.

    Comprobamos que el puntero no sea nulo y que el tamano
    no sea negativo antes de realizar la modificacion.
*/
void actualizarTamano(struct Archivo *archivo, int nuevoTamano) {
    if (archivo == NULL) {
        printf("    - E R R O R. El puntero es nulo.\n");
        return;
    }

    if (nuevoTamano < 0) {
        printf("    - E R R O R. El tamano no puede ser negativo.\n");
        return;
    }

    archivo->tamano = nuevoTamano;
}

/*
    Creamos la funcion main para ejecutar los ejemplos.
*/
int main(void) {
    /*
        1. Creamos e inicializamos dos estructuras.

        archivo1 representa un archivo.
        directorio1 representa un directorio.

        Los valores se asignan siguiendo el orden de los
        campos declarados en la estructura.
    */

    struct Archivo archivo1 = {"config.json", 2048, 0};
    struct Archivo directorio1 = {"SAVES", 0, 1};

    printf("\n    - - - E J E M P L O   No.  1 : C R E A R   U N A   E S T R U C T U R A - - -\n");

    printf("Nombre: %s\n", archivo1.nombre);
    printf("Tamano: %d bytes\n", archivo1.tamano);
    printf("Es directorio: %d\n", archivo1.esDirectorio);

    /*
        2. Accedemos y modificamos los campos.

        El operador punto permite acceder directamente
        a los campos de una variable de estructura.
    */

    printf("\n    - - - E J E M P L O   No.  2 : A C C E D E R   A   L O S   C A M P O S - - -\n");

    archivo1.tamano = 4096;

    printf("Nuevo tamano de %s: %d bytes\n",
           archivo1.nombre, archivo1.tamano);

    /*
        3. Pasamos una estructura por valor.

        La funcion recibe una copia de archivo1.
        Por tanto, no puede modificar directamente
        los campos de la estructura original.
    */

    printf("\n    - - - E J E M P L O   No.  3 : P A S A R   U N A   E S T R U C T U R A   P O R   V A L O R - - -\n");

    mostrarArchivo(archivo1);

    /*
        4. Declaramos un puntero a una estructura.

        - struct Archivo *: Indica que es un puntero
          a una estructura de tipo Archivo.
        - &archivo1: Obtiene la direccion de archivo1.

        El puntero permite acceder a la estructura original.
    */

    printf("\n    - - - E J E M P L O   No.  4 : U T I L I Z A R   U N   P U N T E R O   A   U N A   E S T R U C T U R A - - -\n");

    struct Archivo *punteroArchivo = &archivo1;

    printf("Nombre mediante puntero: %s\n", punteroArchivo->nombre);
    printf("Tamano mediante puntero: %d bytes\n",
           punteroArchivo->tamano);

    /*
        5. Modificamos la estructura mediante un puntero.

        Enviamos la direccion de archivo1 a la funcion.
        La funcion modifica el campo tamano del objeto
        original mediante el operador ->.
    */

    printf("\n    - - - E J E M P L O   No.  5 : M O D I F I C A R   U N A   E S T R U C T U R A   M E D I A N T E   U N   P U N T E R O - - -\n");

    actualizarTamano(punteroArchivo, 8192);

    printf("Tamano actualizado: %d bytes\n", archivo1.tamano);

    /*
        6. Mostramos una estructura mediante un puntero.

        La funcion recibe la direccion de archivo1.
        Como el parametro utiliza const, la funcion
        puede consultar los campos, pero no modificarlos
        mediante ese puntero.
    */

    printf("\n    - - - E J E M P L O   No.  6 : M O S T R A R   U N A   E S T R U C T U R A   M E D I A N T E   U N   P U N T E R O - - -\n");

    mostrarArchivoPorPuntero(&archivo1);

    /*
        7. Representamos un directorio.

        Utilizamos la misma estructura Archivo para
        representar tanto archivos como directorios.
        El campo esDirectorio permite distinguirlos.
    */

    printf("\n    - - - E J E M P L O   No.  7 : R E P R E S E N T A R   U N   D I R E C T O R I O - - -\n");

    mostrarArchivo(directorio1);

    /*
        8. Comprobamos el comportamiento ante NULL.

        Enviamos un puntero nulo a la funcion para verificar
        que detecta el caso antes de acceder a los campos.
    */

    printf("\n    - - - E J E M P L O   No.  8 : V E R I F I C A R   U N   P U N T E R O   N U L O - - -\n");

    mostrarArchivoPorPuntero(NULL);

    /*
        Finalizamos el programa.

        Las estructuras utilizadas son variables locales.
        No reservamos memoria dinamica, por lo que no
        necesitamos utilizar free().
    */

    printf("\n    - - - F I N   D E   L A   P R A C T I C A - - -\n");

    return 0;
}