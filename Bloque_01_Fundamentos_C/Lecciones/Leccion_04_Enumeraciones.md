
# Lección 04: Enumeraciones (`enum`)

## Objetivos

Al finalizar esta lección, seremos capaces de:

- Comprender qué es una enumeración y para qué sirve.
- Declarar enumeraciones y utilizar sus constantes.
- Comprender los valores predeterminados y explícitos de una enumeración.
- Utilizar enumeraciones como campos de estructuras.
- Combinar enumeraciones con `switch`.
- Comprender las limitaciones de las enumeraciones en C.
- Aplicar enumeraciones a la representación de archivos y estados de ELFtation Navigator.

## 1. ¿Qué es una enumeración?

Una enumeración es un tipo de dato que permite asociar nombres legibles con valores enteros.

Se declara mediante la palabra clave `enum`.

Por ejemplo, para representar los tipos de elementos de un navegador de archivos, podríamos utilizar:

```c
enum TipoArchivo {
    ARCHIVO,
    DIRECTORIO
};
```

Esta enumeración contiene dos constantes:

- `ARCHIVO`
- `DIRECTORIO`

Por defecto, la primera constante recibe el valor `0` y las siguientes aumentan en uno.

| Constante | Valor |
|---|---:|
| `ARCHIVO` | 0 |
| `DIRECTORIO` | 1 |

El objetivo es mejorar la legibilidad del código. Es más claro escribir `DIRECTORIO` que utilizar directamente el número `1` sin explicar su significado.

## 2. Declarar variables de tipo enumerado

Para declarar una variable de tipo `enum TipoArchivo`, escribimos:

```c
enum TipoArchivo tipo;
```

También podemos inicializarla directamente:

```c
enum TipoArchivo tipo = DIRECTORIO;
```

En este caso, la variable `tipo` almacena el valor entero asociado a la constante `DIRECTORIO`.

Podemos comparar su valor con las constantes de la enumeración:

```c
if (tipo == DIRECTORIO) {
    printf("Es un directorio.\n");
}
```

Las constantes de una enumeración no son cadenas de texto. Por ejemplo, `DIRECTORIO` no almacena automáticamente la cadena `"DIRECTORIO"`.

## 3. Asignar valores explícitos

También podemos asignar valores concretos a las constantes:

```c
enum EstadoETN {
    ETN_INACTIVO = 0,
    ETN_NAVEGANDO = 1,
    ETN_ERROR = -1
};
```

Esto permite definir estados con valores elegidos por nosotros.

Si una constante no tiene un valor explícito, C asigna un valor según su posición y el valor de la constante anterior.

Por ejemplo:

```c
enum Nivel {
    NIVEL_BAJO = 2,
    NIVEL_MEDIO,
    NIVEL_ALTO = 10,
    NIVEL_MAXIMO
};
```

Los valores serían:

| Constante | Valor |
|---|---:|
| `NIVEL_BAJO` | 2 |
| `NIVEL_MEDIO` | 3 |
| `NIVEL_ALTO` | 10 |
| `NIVEL_MAXIMO` | 11 |

## 4. Utilizar `enum` dentro de una estructura

Las enumeraciones pueden utilizarse como campos de una estructura.

Esto nos permite representar de manera más clara el tipo de elemento que estamos almacenando.

```c
enum TipoArchivo {
    ARCHIVO,
    DIRECTORIO
};

struct Archivo {
    char nombre[64];
    int tamano;
    enum TipoArchivo tipo;
};
```

Ahora podemos crear elementos de la siguiente manera:

```c
struct Archivo archivo1 = {
    "config.json",
    2048,
    ARCHIVO
};

struct Archivo directorio1 = {
    "SAVES",
    0,
    DIRECTORIO
};
```

El campo `tipo` indica si el elemento representa un archivo o un directorio.

Podemos consultar ese campo mediante el operador punto:

```c
if (archivo1.tipo == ARCHIVO) {
    printf("Es un archivo.\n");
}
```

Si accedemos mediante un puntero a estructura, podemos utilizar el operador flecha:

```c
struct Archivo *puntero = &directorio1;

if (puntero->tipo == DIRECTORIO) {
    printf("Es un directorio.\n");
}
```

## 5. Utilizar enumeraciones con `switch`

La instrucción `switch` permite ejecutar diferentes bloques según el valor de una expresión.

Es especialmente útil cuando trabajamos con enumeraciones que representan estados.

```c
enum EstadoETN {
    ETN_INACTIVO,
    ETN_NAVEGANDO,
    ETN_ERROR
};

enum EstadoETN estado = ETN_NAVEGANDO;

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
```

En este ejemplo:

- `switch` evalúa el valor de `estado`.
- `case` define los valores que queremos reconocer.
- `break` evita continuar con el siguiente caso.
- `default` permite manejar valores no contemplados en los casos anteriores.

## 6. Limitaciones de `enum` en C

Las enumeraciones mejoran la legibilidad, pero no garantizan que una variable solo contenga los valores declarados.

Por ejemplo:

```c
enum TipoArchivo tipo = 7;
```

En C, una asignación de este tipo puede ser válida aunque `7` no corresponda a ninguna constante de `TipoArchivo`.

Por eso, cuando los valores proceden de datos externos o de operaciones que pueden fallar, debemos comprobar que sean válidos.

También debemos recordar que los nombres de las constantes no se convierten automáticamente en texto. Si queremos mostrar una descripción, debemos utilizar instrucciones como `printf` o implementar una función que traduzca cada constante a una cadena.

## 7. Aplicación en ELFtation Navigator

En ETN podremos utilizar enumeraciones para representar:

- **Tipos de elementos:** archivo o directorio.
- **Estados de navegación:** inactivo, navegando o error.
- **Resultados de operaciones:** éxito, error o elemento no encontrado.

Por ejemplo, una enumeración de estados permite que las condiciones y los `switch` expresen claramente qué está haciendo el navegador.

Las enumeraciones también pueden combinarse con estructuras, de modo que cada elemento de una lista de archivos almacene su nombre, tamaño y tipo.

## 8. Práctica asociada

Archivo: `L04_enumeraciones.c`

La práctica incluye los siguientes ejercicios:

1. Declarar una enumeración y consultar sus valores.
2. Asignar valores explícitos.
3. Utilizar una enumeración como campo de una estructura.
4. Acceder al campo enumerado mediante `.` y `->`.
5. Combinar enumeraciones con `switch`.
6. Representar estados básicos de ELFtation Navigator.

## 9. Resumen

- `enum` permite asociar nombres legibles con valores enteros.
- Los valores predeterminados comienzan en `0` y aumentan en uno.
- Podemos asignar valores explícitos a las constantes.
- Las enumeraciones pueden utilizarse dentro de estructuras.
- `switch` permite trabajar cómodamente con enumeraciones.
- C no impide todos los valores que no estén representados por las constantes declaradas.
- Las enumeraciones ayudarán a representar tipos y estados dentro de ETN.