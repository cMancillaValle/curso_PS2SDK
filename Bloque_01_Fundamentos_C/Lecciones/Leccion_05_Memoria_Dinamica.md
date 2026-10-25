
# Lección 05: Ciclo de vida y memoria dinámica

## Objetivos

Al finalizar esta lección, seremos capaces de:

- Diferenciar la duración de las variables locales, estáticas y dinámicas.
- Comprender cómo funciona la reserva de memoria dinámica.
- Utilizar `malloc()` para reservar memoria.
- Utilizar `free()` para liberar memoria.
- Utilizar `realloc()` para cambiar el tamaño de un bloque.
- Reconocer fugas de memoria y accesos inválidos.
- Aplicar estas operaciones al almacenamiento de elementos de ETN.

## 1. Ciclo de vida de los objetos

En C, los objetos tienen una duración de almacenamiento que determina durante cuánto tiempo existe su almacenamiento.

Para esta lección nos interesan tres casos.

### Variables locales automáticas

```c
int puntaje = 50;
```

Una variable local como esta tiene duración automática. Su almacenamiento deja de estar disponible al finalizar el bloque que la contiene.

### Variables estáticas

```c
static int contador = 0;
```

Una variable estática conserva su almacenamiento durante toda la ejecución del programa, aunque esté declarada dentro de una función.

### Memoria dinámica

La memoria dinámica se solicita durante la ejecución del programa. Su duración depende de cuándo se reserve y se libere.

A diferencia de una variable local automática, un bloque dinámico puede continuar existiendo después de que termine la función que solicitó la reserva, siempre que no se haya liberado.

La memoria dinámica suele asociarse con el heap y las variables locales con la pila, aunque estos detalles físicos dependen de la implementación.

## 2. Reservar memoria con `malloc()`

La función `malloc()` solicita un bloque de memoria de un tamaño expresado en bytes.

Para utilizarla, incluimos la cabecera estándar:

```c
#include <stdlib.h>
```

Ejemplo:

```c
int *puntaje = malloc(sizeof(int));

if (puntaje == NULL) {
    printf("No se pudo reservar memoria.\n");
    return 1;
}

*puntaje = 50;

printf("Puntaje: %d\n", *puntaje);

free(puntaje);
puntaje = NULL;
```

### ¿Qué ocurre en este ejemplo?

- `sizeof(int)` obtiene el tamaño de un entero.
- `malloc(sizeof(int))` solicita espacio suficiente para un entero.
- `puntaje` almacena la dirección del bloque.
- La comparación con `NULL` comprueba si la reserva falló.
- `*puntaje = 50` escribe un valor en el bloque.
- `free(puntaje)` libera el bloque reservado.
- `puntaje = NULL` evita que esa variable conserve la dirección anterior.

`malloc()` no inicializa la memoria. Debemos escribir valores válidos antes de leerlos.

## 3. Reservar memoria para un arreglo

Podemos solicitar espacio para varios elementos del mismo tipo.

```c
int cantidad = 5;

int *puntajes = malloc(cantidad * sizeof(int));

if (puntajes == NULL) {
    printf("No se pudo reservar memoria.\n");
    return 1;
}

for (int i = 0; i < cantidad; i++) {
    puntajes[i] = (i + 1) * 10;
}

for (int i = 0; i < cantidad; i++) {
    printf("Puntaje %d: %d\n", i, puntajes[i]);
}

free(puntajes);
puntajes = NULL;
```

En este caso solicitamos espacio para cinco enteros.

La expresión:

```c
cantidad * sizeof(int)
```

calcula el tamaño total de la reserva.

Si un entero ocupa cuatro bytes en la plataforma utilizada, cinco enteros necesitarán veinte bytes. No debemos asumir que todos los tipos tienen el mismo tamaño en todas las plataformas.

Podemos acceder a los elementos mediante `puntajes[i]`, siempre que el índice esté dentro de los límites de la memoria reservada.

## 4. Liberar memoria con `free()`

Cuando terminamos de utilizar un bloque de memoria dinámica, debemos liberarlo.

```c
free(puntajes);
```

No liberar memoria que ya no necesitamos puede producir una fuga de memoria.

Existen varios errores que debemos evitar:

### Fuga de memoria

Reservar memoria y perder la única referencia al bloque sin liberarlo.

### Uso después de liberar

Acceder a un bloque después de ejecutar `free()` sobre él.

### Doble liberación

Liberar nuevamente un bloque que ya había sido liberado.

Estos errores pueden producir comportamiento indefinido y resultados difíciles de diagnosticar.

Asignar `NULL` al puntero después de liberar el bloque ayuda a evitar ciertos errores, pero no invalida automáticamente otras variables que puedan apuntar a la misma memoria.

## 5. Redimensionar memoria con `realloc()`

La función `realloc()` permite solicitar un cambio de tamaño para un bloque dinámico.

Por ejemplo, podemos ampliar una reserva de cinco enteros a diez.

```c
int *puntajes = malloc(5 * sizeof(int));

if (puntajes == NULL) {
    printf("No se pudo reservar memoria.\n");
    return 1;
}

for (int i = 0; i < 5; i++) {
    puntajes[i] = (i + 1) * 10;
}

int *temporal = realloc(puntajes, 10 * sizeof(int));

if (temporal == NULL) {
    printf("No se pudo ampliar la memoria.\n");

    free(puntajes);
    puntajes = NULL;

    return 1;
}

puntajes = temporal;

for (int i = 5; i < 10; i++) {
    puntajes[i] = (i + 1) * 10;
}

free(puntajes);
puntajes = NULL;
```

### ¿Por qué usamos un puntero temporal?

`realloc()` puede ampliar el bloque en su ubicación actual o trasladarlo a otra dirección.

Si una solicitud para cambiar el tamaño de un bloque existente falla, devuelve `NULL` y el bloque original permanece reservado.

Por eso utilizamos:

```c
int *temporal = realloc(puntajes, nuevoTamano);
```

Solo actualizamos `puntajes` después de comprobar que la operación tuvo éxito.

Evita este patrón:

```c
puntajes = realloc(puntajes, nuevoTamano);
```

Si falla, perderíamos la referencia al bloque original y no podríamos liberarlo mediante esa variable.

Para esta lección evitaremos solicitar un tamaño de cero con `realloc()`, ya que ese caso tiene particularidades que no necesitamos para nuestros ejemplos.

## 6. Comprobaciones de seguridad

Antes de utilizar memoria dinámica, debemos tener en cuenta lo siguiente:

- Comprobar si `malloc()` devuelve `NULL`.
- No leer memoria que todavía no ha sido inicializada.
- No acceder a posiciones fuera de los límites de la reserva.
- Liberar los bloques cuando ya no sean necesarios.
- No utilizar punteros que apunten a memoria liberada.
- No liberar varias veces el mismo bloque.
- Comprobar los resultados de `realloc()` antes de sustituir el puntero original.
- Evitar desbordamientos al calcular tamaños.

Por ejemplo, antes de reservar espacio para `cantidad` estructuras, debemos asegurarnos de que la multiplicación por `sizeof(struct Archivo)` no exceda el tamaño máximo representable por `size_t`.

## 7. Aplicación en ELFtation Navigator

ETN necesitará representar una cantidad variable de entradas de directorio.

Podemos utilizar una estructura como esta:

```c
struct Archivo {
    char nombre[64];
    int tamano;
    enum TipoArchivo tipo;
};
```

Para reservar espacio para varias entradas:

```c
struct Archivo *archivos = malloc(
    capacidad * sizeof(struct Archivo)
);
```

Cuando se agote la capacidad, podemos solicitar un bloque más grande mediante `realloc()`.

Esto permitirá que el navegador gestione directorios de diferentes tamaños sin reservar desde el principio una cantidad fija arbitraria.

La implementación final también deberá comprobar los errores y los límites de tamaño antes de efectuar las reservas.

## 8. Práctica asociada

Archivo: `L05_memoria_dinamica.c`

La práctica contiene ejemplos de:

1. Reserva de memoria para un entero.
2. Reserva de memoria para un arreglo.
3. Liberación de memoria.
4. Redimensionamiento con `realloc()`.
5. Comprobación de errores.
6. Gestión de memoria para estructuras.
7. Revisión del ciclo de vida de los bloques reservados.

## 9. Resumen

- Las variables automáticas y estáticas tienen distintas duraciones de almacenamiento.
- `malloc()` solicita memoria dinámica.
- `free()` libera un bloque reservado.
- `realloc()` permite cambiar el tamaño de un bloque.
- Comprobar los errores de reserva evita accesos inválidos y pérdidas de referencias.
- La memoria debe gestionarse cuidadosamente para evitar fugas y comportamiento indefinido.
- ETN podrá utilizar estas herramientas para gestionar listas dinámicas de archivos.