
# Bloque 01: Fundamentos de C para ETN

## Objetivo del bloque

Consolidar los fundamentos del lenguaje C necesarios para construir ELFtation Navigator (ETN), una aplicación homebrew para PlayStation 2.

El bloque se centra en la organización del código, el uso de memoria, los tipos de datos y las herramientas que necesitaremos para desarrollar un programa modular.

## Lecciones

| Lección | Tema |
|---|---|
| 01 | Funciones y organización del código |
| 02 | Punteros |
| 03 | Estructuras (`struct`) |
| 04 | Enumeraciones (`enum`) |
| 05 | Memoria y ciclo de vida de los datos |
| 06 | Organización de archivos `.c` y `.h` |

## Contenidos aprendidos

### Lección 01: Funciones y organización del código

- Declaración y definición de funciones.
- Parámetros y valores de retorno.
- División de responsabilidades mediante funciones.

### Lección 02: Punteros

- Direcciones de memoria.
- Declaración y uso de punteros.
- Operadores `&` y `*`.
- Modificación de variables mediante punteros.
- Comprobación de punteros nulos.

### Lección 03: Estructuras (`struct`)

- Agrupación de datos relacionados.
- Declaración e inicialización de estructuras.
- Acceso a miembros con `.` y `->`.
- Paso de estructuras a funciones mediante punteros.

### Lección 04: Enumeraciones (`enum`)

- Declaración de enumeraciones.
- Valores implícitos y explícitos.
- Uso de enumeraciones para representar estados y categorías.
- Integración con estructuras y sentencias `switch`.

### Lección 05: Memoria y ciclo de vida de los datos

- Memoria dinámica con `malloc`.
- Liberación de memoria con `free`.
- Redimensionamiento con `realloc`.
- Comprobación de fallos de asignación.
- Uso de punteros temporales para conservar el bloque original si `realloc` falla.

### Lección 06: Organización de archivos `.c` y `.h`

- Declaraciones frente a definiciones.
- Encabezados y guardas de inclusión.
- Separación entre interfaz e implementación.
- Inclusión de encabezados propios.
- Compilación y enlazado de varios archivos fuente.
- Organización modular para proyectos de mayor tamaño.

## Resultado del bloque

Al completar este bloque, contamos con las bases de C necesarias para comenzar a estructurar componentes de ETN de forma modular y comprender cómo interactúan entre sí.

## Siguiente bloque

**Bloque 02: Compilación, Makefile y generación de ELF**

Aprenderemos a organizar la compilación del proyecto y a generar ejecutables para PlayStation 2 utilizando PS2SDK.