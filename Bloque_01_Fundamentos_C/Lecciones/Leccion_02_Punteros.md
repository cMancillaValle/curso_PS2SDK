# Lección 02: Punteros en C

## 1. Objetivo

Comprender qué son los punteros, cómo se relacionan con las
direcciones de memoria y cómo permiten acceder y modificar
variables mediante sus direcciones.

Además, aprender a declarar punteros, utilizar los operadores
`&` y `*`, y comprender su importancia para el desarrollo
de ELFtation Navigator.

## 2. Variables y direcciones de memoria

Cuando declaramos una variable, el programa necesita espacio
en memoria para almacenar su valor.

Por ejemplo:

```c
int puntaje = 50;
```

En este caso:

- `int`: indica el tipo de dato.
- `puntaje`: es el nombre de la variable.
- `50`: es el valor almacenado.

Cada objeto tiene una ubicación en memoria mientras existe.
Podemos representar esa ubicación mediante una dirección.

En C utilizamos el operador `&` para obtener la dirección
de una variable.

### Ejemplo 1: Obtener una dirección

```c
#include <stdio.h>

int main(void) {
    int puntaje = 50;

    printf("Valor: %d\n", puntaje);
    printf("Direccion: %p\n", (void *)&puntaje);

    return 0;
}
```

En este ejemplo:

- `puntaje` permite acceder al valor de la variable.
- `&puntaje` obtiene su dirección de memoria.
- `%p` permite mostrar una dirección mediante `printf`.
- `(void *)` convierte la dirección al tipo esperado
  habitualmente por el especificador `%p`.

La dirección concreta depende de la ejecución del programa
y de dónde se encuentre el objeto en memoria.

## 3. ¿Qué es un puntero?

Un puntero es una variable que almacena una dirección
de memoria que permite localizar un objeto.

Por ejemplo:

```c
int puntaje = 50;

int *puntero = &puntaje;
```

En este caso:

- `puntaje` almacena el valor `50`.
- `puntero` almacena la dirección de `puntaje`.
- `&puntaje` obtiene esa dirección.
- `int *` declara un puntero a un objeto de tipo `int`.

El puntero no almacena una copia del valor `50`.
Almacena una dirección que permite acceder al objeto original.

### Tipos de punteros

Los punteros tienen tipos asociados.

Por ejemplo:

```c
float temperatura = 25.5f;
float *puntero = &temperatura;
```

Aquí, `puntero` es un puntero a `float`.

El tipo del puntero determina cómo se interpreta el objeto
al que apunta cuando accedemos a él.

Debemos utilizar punteros compatibles con los tipos de los
objetos a los que apuntan.

## 4. El operador de desreferenciación

El operador `*` tiene dos usos importantes en este contexto:

- En una declaración, permite declarar un puntero.
- En una expresión, permite acceder al objeto apuntado.

Por ejemplo:

```c
int puntaje = 50;
int *puntero = &puntaje;

printf("%d\n", *puntero);
```

El programa imprime:

```text
50
```

La expresión `*puntero` permite acceder al objeto al que
apunta `puntero`.

### Diferencias importantes

| Expresión | Significado |
|---|---|
| `puntaje` | Accede al valor de la variable. |
| `&puntaje` | Obtiene su dirección de memoria. |
| `puntero` | Accede a la dirección almacenada. |
| `*puntero` | Accede al objeto apuntado. |

## 5. Modificar variables mediante punteros

Un puntero permite modificar el objeto al que apunta.

Por ejemplo:

```c
#include <stdio.h>

int main(void) {
    int puntaje = 50;
    int *puntero = &puntaje;

    *puntero = 100;

    printf("Puntaje: %d\n", puntaje);

    return 0;
}
```

El resultado es:

```text
Puntaje: 100
```

La instrucción `*puntero = 100` modifica el objeto apuntado.

Como `puntero` apunta a `puntaje`, la modificación afecta
directamente a la variable original.

No estamos modificando una copia independiente.

## 6. Punteros y funciones

Cuando una función recibe un argumento por valor, recibe
una copia de ese valor.

Por ejemplo:

```c
void aumentarPuntaje(int puntaje) {
    puntaje = puntaje + 10;
}
```

Si llamamos a esta función con una variable de `main`,
la modificación afecta a la copia local del parámetro.

Por eso, la variable original no cambia.

### Utilizar un puntero como parámetro

Podemos modificar la variable original mediante un puntero:

```c
#include <stdio.h>

void aumentarPuntaje(int *puntaje) {
    *puntaje = *puntaje + 10;
}

int main(void) {
    int puntaje = 50;

    aumentarPuntaje(&puntaje);

    printf("Puntaje: %d\n", puntaje);

    return 0;
}
```

El resultado es:

```text
Puntaje: 60
```

La función recibe una copia de la dirección de `puntaje`.

Mediante ese puntero, accede al objeto original y modifica
su valor.

C continúa pasando los argumentos por valor. Lo que se copia
en este caso es la dirección almacenada en el puntero.

## 7. Punteros nulos y punteros sin inicializar

Un puntero debe contener una dirección válida antes de
utilizarse para acceder a un objeto.

### Puntero sin inicializar

```c
int *puntero;

*puntero = 50;
```

Este código es incorrecto porque el puntero no ha sido
inicializado con una dirección válida.

Intentar desreferenciarlo puede producir comportamiento
indefinido.

### Puntero nulo

Podemos inicializar un puntero con `NULL` cuando todavía
no apunta a un objeto:

```c
int *puntero = NULL;
```

`NULL` representa un puntero nulo.

Sin embargo, no podemos utilizarlo para acceder a un objeto:

```c
int *puntero = NULL;

*puntero = 50;
```

Este código también tiene comportamiento indefinido.

Primero debemos hacer que el puntero apunte a un objeto válido.

Por ejemplo:

```c
int puntaje = 50;
int *puntero = NULL;

puntero = &puntaje;

*puntero = 75;
```

Ahora `puntero` apunta a `puntaje` y podemos modificar
la variable mediante el puntero.

## 8. Aplicación en ETN

Los punteros serán importantes en ELFtation Navigator porque
nos permitirán trabajar con objetos y datos mediante sus
direcciones de memoria.

En futuras lecciones utilizaremos estructuras para representar
información, como los datos de un archivo o directorio.

Por ejemplo:

```c
struct Archivo {
    char nombre[64];
    int esDirectorio;
};
```

Podremos declarar una variable de este tipo y obtener
su dirección:

```c
struct Archivo archivo;
struct Archivo *puntero = &archivo;
```

Este puntero permitirá acceder al objeto `archivo`.

Los punteros también serán útiles al trabajar con funciones,
buffers de datos y bibliotecas del entorno PS2SDK.

## 9. Conceptos clave

- Un puntero almacena una dirección de memoria.
- El operador `&` obtiene la dirección de un objeto.
- El operador `*` permite declarar punteros o acceder
  al objeto apuntado, según el contexto.
- Podemos modificar una variable mediante un puntero
  que apunte a ella.
- Una función puede recibir un puntero para acceder
  a un objeto definido fuera de esa función.
- C pasa los argumentos por valor, incluidos los punteros.
- `NULL` representa un puntero nulo.
- Nunca debemos desreferenciar un puntero que no apunte
  a un objeto válido.

## 10. Relación con las siguientes lecciones

Los punteros serán la base para comprender cómo trabajar
con estructuras y cómo pasar objetos a funciones.

Estos conceptos nos permitirán organizar los datos de ETN
y avanzar progresivamente hacia el manejo de archivos.