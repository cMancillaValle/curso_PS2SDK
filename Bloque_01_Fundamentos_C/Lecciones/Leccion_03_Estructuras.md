
# Lección 03: Estructuras en C

## Objetivos

Al finalizar esta lección, seremos capaces de:

- Comprender qué es una estructura (`struct`) y para qué sirve.
- Agrupar datos relacionados de diferentes tipos.
- Declarar estructuras e inicializar sus campos.
- Acceder y modificar los campos de una estructura.
- Pasar estructuras a funciones por valor.
- Utilizar punteros a estructuras mediante el operador `->`.
- Comprender cómo las estructuras permiten representar archivos y directorios en ELFtation Navigator.

## 1. ¿Qué es una estructura?

Una estructura es un tipo de dato compuesto que permite agrupar varias variables relacionadas bajo un mismo nombre.

Cada variable dentro de la estructura se denomina campo o miembro. Los campos pueden tener diferentes tipos de datos.

Por ejemplo, para representar un archivo en ELFtation Navigator, podríamos necesitar:

- Su nombre.
- Su tamaño.
- Una indicación de si es un archivo o un directorio.

En lugar de declarar variables independientes para cada propiedad, podemos agruparlas en una estructura.

```c
struct Archivo {
    char nombre[64];
    int tamano;
    int esDirectorio;
};
```

En esta definición:

- `struct`: palabra clave que permite declarar una estructura.
- `Archivo`: nombre de la estructura.
- `nombre`: campo que almacena el nombre.
- `tamano`: campo que almacena el tamaño en bytes.
- `esDirectorio`: campo que indica si el elemento es un directorio.

La definición establece la forma de la estructura. Por sí sola, no crea una variable llamada `archivo`.

## 2. Declarar e inicializar una estructura

Para crear una variable de esta estructura, utilizamos su nombre precedido por `struct`.

```c
struct Archivo archivo1;
```

También podemos inicializar sus campos al declarar la variable:

```c
struct Archivo archivo1 = {"config.json", 2048, 0};
```

En este ejemplo:

- `nombre` contiene `"config.json"`.
- `tamano` contiene `2048`.
- `esDirectorio` contiene `0`, que representa un archivo en nuestra convención.

Podemos crear otra estructura para representar un directorio:

```c
struct Archivo directorio1 = {"SAVES", 0, 1};
```

Aquí, `1` representa un directorio. Esta convención es una decisión de nuestro programa, no una regla propia de C.

## 3. Acceder a los campos con el operador punto

Cuando tenemos una variable de estructura, utilizamos el operador punto (`.`) para acceder a sus campos.

```c
printf("%s\n", archivo1.nombre);
printf("%d\n", archivo1.tamano);

archivo1.tamano = 4096;
```

La última instrucción modifica el campo `tamano` de `archivo1`.

El operador punto se utiliza cuando trabajamos directamente con la variable de estructura, no con un puntero a ella.

## 4. Pasar estructuras a funciones por valor

Podemos enviar una estructura como argumento de una función.

```c
void mostrarArchivo(struct Archivo archivo) {
    printf("Nombre: %s\n", archivo.nombre);
    printf("Tamano: %d bytes\n", archivo.tamano);
}
```

Podemos llamar a esta función de la siguiente manera:

```c
mostrarArchivo(archivo1);
```

En este caso, la función recibe una copia de la estructura.

Si modifica un campo de su parámetro `archivo`, no modifica directamente el campo correspondiente de `archivo1`.

Esta forma resulta útil cuando queremos consultar o procesar datos sin modificar la estructura original.

## 5. Punteros a estructuras

También podemos declarar un puntero que almacene la dirección de una estructura.

```c
struct Archivo *punteroArchivo = &archivo1;
```

En esta declaración:

- `struct Archivo *`: indica que es un puntero a una estructura de tipo `Archivo`.
- `punteroArchivo`: es el nombre del puntero.
- `&archivo1`: obtiene la dirección de la variable `archivo1`.

Los punteros permiten acceder a la estructura original sin necesidad de crear una copia completa para cada operación.

## 6. El operador flecha (`->`)

Cuando accedemos a un campo mediante un puntero a estructura, utilizamos el operador `->`.

```c
printf("%s\n", punteroArchivo->nombre);

punteroArchivo->tamano = 8192;
```

La segunda instrucción modifica el campo `tamano` de la estructura original.

Esta expresión:

```c
punteroArchivo->tamano
```

es equivalente a:

```c
(*punteroArchivo).tamano
```

Los paréntesis son importantes porque primero debemos desreferenciar el puntero y después acceder al campo.

### Diferencia entre `.` y `->`

| Operador | Cuándo se utiliza | Ejemplo |
|---|---|---|
| `.` | Con una variable de estructura | `archivo1.tamano` |
| `->` | Con un puntero a estructura | `punteroArchivo->tamano` |

## 7. Modificar estructuras mediante punteros

Si queremos que una función modifique la estructura original, podemos pasarle un puntero.

```c
void actualizarTamano(struct Archivo *archivo, int nuevoTamano) {
    if (archivo == NULL) {
        return;
    }

    if (nuevoTamano < 0) {
        return;
    }

    archivo->tamano = nuevoTamano;
}
```

La llamada sería:

```c
actualizarTamano(&archivo1, 8192);
```

La función recibe la dirección de `archivo1` y modifica directamente su campo `tamano`.

La comprobación `archivo == NULL` evita acceder a los campos cuando el puntero no apunta a una estructura válida.

La comprobación del tamaño negativo es una validación propia de nuestro ejemplo.

## 8. Estructuras y ELFtation Navigator

Las estructuras serán esenciales para construir el navegador de archivos.

Más adelante, podremos utilizar una estructura que represente los elementos encontrados en una tarjeta de memoria o una unidad USB.

Por ejemplo:

```c
struct Archivo {
    char nombre[64];
    int tamano;
    int esDirectorio;
};
```

Cada elemento encontrado podría representarse mediante una variable de este tipo.

Esto permitiría almacenar información de cada archivo o directorio y utilizarla para mostrar listados, consultar propiedades o decidir qué operaciones están permitidas.

Por ahora, nuestra estructura es una representación simplificada. El acceso real al sistema de archivos de PS2 se estudiará en bloques posteriores.

## 9. Práctica asociada

Archivo: `L03_estructuras.c`

La práctica desarrolla los siguientes puntos:

1. Crear e inicializar estructuras.
2. Consultar y modificar campos con el operador `.`.
3. Pasar estructuras a funciones por valor.
4. Declarar y utilizar punteros a estructuras.
5. Acceder a campos mediante el operador `->`.
6. Modificar la estructura original mediante un puntero.
7. Representar archivos y directorios.
8. Comprobar el comportamiento de una función ante un puntero nulo.

## 10. Resumen

- `struct` permite agrupar datos relacionados de diferentes tipos.
- El operador `.` accede a los campos de una variable de estructura.
- El operador `->` accede a los campos mediante un puntero.
- Pasar una estructura por valor proporciona una copia.
- Pasar un puntero permite trabajar con la estructura original.
- Antes de desreferenciar un puntero, debemos asegurarnos de que sea válido.
- Las estructuras nos permitirán modelar los archivos y directorios de ELFtation Navigator.