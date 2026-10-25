
# Lección 06: Organización de archivos `.c` y `.h`

## Objetivo

Aprender a dividir un programa en varios archivos de código fuente y encabezados, comprendiendo la diferencia entre declarar una función, implementarla y utilizarla desde otro archivo.

## 1. ¿Por qué dividir un programa?

Cuando un programa crece, mantener todas sus funciones en un único archivo puede dificultar su lectura, modificación y reutilización.

Separar el código en módulos permite:

- Organizar las responsabilidades del programa.
- Reutilizar funciones en diferentes partes del proyecto.
- Mantener las implementaciones separadas de sus interfaces públicas.
- Facilitar el mantenimiento y las pruebas.
- Trabajar en proyectos con múltiples archivos y componentes.

Por ejemplo, en ELFtation Navigator podríamos separar las operaciones de archivos, la entrada del control y el dibujo de la interfaz en módulos diferentes.

## 2. Archivos `.h`: declaraciones e interfaz

Un encabezado `.h` suele contener declaraciones que otros archivos necesitan conocer.

Entre ellas se encuentran:

- Prototipos de funciones.
- Definiciones de tipos mediante `struct`, `enum` y `typedef`.
- Constantes y macros públicas.
- Declaraciones compartidas entre módulos.

Ejemplo de `operaciones.h`:

```c
#ifndef OPERACIONES_H
#define OPERACIONES_H

int sumar(int a, int b);
int restar(int a, int b);

#endif
```

Los prototipos informan al compilador sobre el nombre, los parámetros y el tipo de retorno de las funciones.

Las directivas `#ifndef`, `#define` y `#endif` forman una protección de inclusión. Evitan que el contenido del encabezado se procese varias veces durante una misma unidad de traducción.

## 3. Archivos `.c`: implementación

El archivo `.c` contiene el código que implementa las funciones.

Ejemplo de `operaciones.c`:

```c
#include "operaciones.h"

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}
```

La inclusión del encabezado permite que el compilador compruebe las implementaciones frente a las declaraciones correspondientes.

La implementación no tiene que estar en el mismo archivo que utiliza la función.

## 4. Declaración frente a definición

Una declaración comunica que una función existe y describe cómo puede utilizarse:

```c
int sumar(int a, int b);
```

Una definición proporciona el cuerpo de la función:

```c
int sumar(int a, int b) {
    return a + b;
}
```

La declaración suele aparecer en el `.h`, mientras que la definición suele aparecer en el `.c`.

Una función también puede declararse antes de su definición dentro del mismo archivo. La separación en archivos es una decisión de organización, no una obligación del lenguaje.

## 5. Incluir encabezados propios

Para incluir un encabezado de la biblioteca estándar, normalmente se utilizan corchetes angulares:

```c
#include <stdio.h>
```

Para incluir un encabezado propio del proyecto, normalmente se utilizan comillas:

```c
#include "operaciones.h"
```

Las reglas exactas de búsqueda dependen de las opciones del compilador y de las rutas configuradas.

Importante: incluir un encabezado no incorpora automáticamente la implementación de las funciones definidas en otro `.c`.

## 6. Utilizar el módulo desde `main.c`

Ejemplo:

```c
#include <stdio.h>
#include "operaciones.h"

int main(void) {
    int resultado = sumar(10, 20);

    printf("Resultado: %d\n", resultado);

    return 0;
}
```

`main.c` puede utilizar `sumar` porque conoce su declaración a través de `operaciones.h`.

No necesita conocer los detalles internos de su implementación.

## 7. Compilar varios archivos

Desde el directorio donde se encuentran los archivos:

```bash
gcc -Wall -Wextra -std=c11 main.c operaciones.c -o programa
```

Este comando compila y enlaza los archivos fuente para producir el ejecutable `programa`.

Para ejecutarlo en un entorno Linux:

```bash
./programa
```

Si se omite `operaciones.c` del comando, la declaración de `sumar` podría estar disponible durante la compilación, pero faltaría su implementación durante el enlazado. El resultado habitual sería un error de referencia indefinida.

## 8. Aplicación a ELFtation Navigator

A medida que ETN crezca, podremos organizar sus responsabilidades en módulos.

Por ejemplo:

```text
ETN/
├── main.c
├── archivos.h
├── archivos.c
├── interfaz.h
├── interfaz.c
├── control.h
└── control.c
```

Esta estructura es ilustrativa. Los módulos definitivos dependerán de las funciones que implementemos y de las interfaces disponibles en PS2SDK.

Cada encabezado expondrá las declaraciones necesarias y cada archivo fuente implementará las responsabilidades correspondientes.

## 9. Buenas prácticas

- Incluye en cada encabezado las declaraciones que otros módulos necesitan.
- Incluye el encabezado correspondiente desde su archivo `.c`.
- Protege los encabezados con guardas de inclusión.
- Evita definir funciones globales ordinarias en los encabezados, porque podrían producir definiciones múltiples al incluirlos desde varios archivos.
- No incluyas archivos `.c` con `#include` como sustituto habitual de una compilación modular.
- Compila todos los archivos fuente necesarios y revisa las advertencias.
- Mantén cada módulo enfocado en una responsabilidad clara.

## Resumen

Un archivo `.h` define la interfaz que un módulo expone; un archivo `.c` contiene su implementación; y otros archivos pueden utilizar esa interfaz sin depender de los detalles internos.

Esta separación es uno de los fundamentos de la programación modular en C y nos permitirá construir ETN de forma organizada y mantenible.