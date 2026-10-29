# Leccion 03: Makefile y automatizacion de la compilacion

## 1. Objetivos

Al finalizar esta leccion podremos:

- Comprender la funcion de `make` y los archivos `Makefile`.
- Identificar objetivos, dependencias y comandos.
- Utilizar variables para organizar las reglas de construccion.
- Comprender los objetivos `all` y `clean`.
- Reconocer la utilidad de `.PHONY`.
- Entender como `make` detecta cambios en las dependencias.
- Diferenciar la automatizacion de la compilacion de la compilacion cruzada para PS2.

## 2. El problema de la compilacion manual

Cuando un programa contiene varios archivos fuente, debemos indicar al compilador cuales necesita utilizar y como debe generar el ejecutable.

Por ejemplo, nuestra practica anterior utilizaba:

- `L02_compilar_para_ps2.c`
- `funciones_ps2.c`
- `funciones_ps2.h`

Para compilarla con GCC nativo en Linux utilizamos:

    gcc -Wall -Wextra -std=c11 L02_compilar_para_ps2.c funciones_ps2.c -o practica_l02

El comando funciona, pero repetirlo manualmente resulta poco practico cuando un proyecto crece.

Un `Makefile` permite definir las reglas de construccion una sola vez. Despues, `make` interpreta esas reglas y ejecuta los comandos necesarios.

## 3. Que es make

`make` es una herramienta de automatizacion de la construccion de software.

Lee un archivo de reglas y determina que acciones debe ejecutar para construir los objetivos solicitados.

Es importante diferenciar los componentes:

- `make`: interpreta las reglas y coordina las acciones.
- `Makefile`: contiene las reglas de construccion.
- GCC: compila y enlaza el programa cuando se utiliza en el comando correspondiente.
- PS2SDK: proporciona herramientas y bibliotecas para desarrollar software destinado a PlayStation 2.

Utilizar `make` no convierte por si solo un programa en un ejecutable compatible con PS2. El resultado depende de las herramientas, las opciones y las dependencias utilizadas.

## 4. Estructura de una regla

Una regla basica tiene esta estructura:

    objetivo: dependencias
        comando

El comando debe comenzar con un tabulador real.

### 4.1. Objetivo

Es el elemento que queremos construir o ejecutar.

Por ejemplo:

    practica_l02

### 4.2. Dependencias

Son los archivos necesarios para construir el objetivo o cuyo cambio puede requerir una nueva construccion.

Por ejemplo:

    practica_l02: main.c funciones.c funciones.h

En este caso, los archivos fuente y la cabecera se declaran como dependencias del ejecutable.

### 4.3. Comando

Es la instruccion que se ejecuta para construir el objetivo.

Por ejemplo:

    gcc main.c funciones.c -o practica

El comando debe aparecer en una linea posterior a la regla y comenzar con un tabulador.

## 5. Variables en un Makefile

Las variables permiten guardar valores que se utilizan en diferentes reglas.

Ejemplo:

    CC = gcc
    CFLAGS = -Wall -Wextra -std=c11
    TARGET = practica

Su significado es:

- `CC`: compilador utilizado.
- `CFLAGS`: opciones que se pasan al compilador de C.
- `TARGET`: nombre del ejecutable generado.

Para utilizar una variable se escribe `$(NOMBRE_VARIABLE)`.

Por ejemplo:

    $(CC) $(CFLAGS) main.c -o $(TARGET)

Con los valores anteriores, `make` ejecutara el comando equivalente a:

    gcc -Wall -Wextra -std=c11 main.c -o practica

Las variables permiten modificar la configuracion sin tener que cambiar cada comando individualmente.

## 6. Objetivos habituales

### 6.1. Objetivo all

`all` suele representar la construccion principal del proyecto.

    all: practica

Si `all` es el primer objetivo del archivo, se convierte normalmente en el objetivo predeterminado cuando ejecutamos `make` sin argumentos.

### 6.2. Objetivo clean

`clean` suele eliminar los archivos generados durante la construccion.

    clean:
        rm -f practica

Este comando elimina el ejecutable `practica`, pero no los archivos fuente.

### 6.3. Directiva PHONY

Los objetivos `all` y `clean` representan tareas, no archivos que necesariamente deban existir.

    .PHONY: all clean

Esta declaracion evita que la existencia de archivos con esos nombres interfiera con la ejecucion de las tareas.

## 7. Ejemplo completo

El siguiente ejemplo utiliza GCC nativo para construir un programa de prueba:

    CC = gcc
    CFLAGS = -Wall -Wextra -std=c11
    TARGET = practica

    SOURCES = L03_makefile_y_automatizacion.c
    HEADERS =

    .PHONY: all clean

    all: $(TARGET)

    $(TARGET): $(SOURCES) $(HEADERS)
        $(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

    clean:
        rm -f $(TARGET)

Los comandos de las reglas deben comenzar con un tabulador real.

Este archivo permite construir el programa con `make` y eliminar el ejecutable con `make clean`.

## 8. Uso desde la terminal

Desde la carpeta que contiene el `Makefile` y el archivo fuente podemos ejecutar:

    make

Para ejecutar el programa generado:

    ./practica

Para eliminar el ejecutable:

    make clean

Despues podemos volver a construirlo ejecutando `make`.

## 9. Compilacion incremental

`make` puede comparar las fechas de modificacion de los objetivos y sus dependencias.

Si el ejecutable existe y ninguna dependencia declarada ha cambiado de forma que requiera reconstruccion, `make` normalmente no vuelve a ejecutar el comando de construccion.

Si un archivo fuente o una cabecera declarada como dependencia es mas reciente que el objetivo, `make` puede ejecutar nuevamente la regla correspondiente.

Este comportamiento reduce el trabajo innecesario durante el desarrollo.

La deteccion depende de las reglas declaradas. Si una dependencia importante no aparece en el Makefile, `make` puede no detectar que debe reconstruir el objetivo.

## 10. Relacion con ETN y PS2SDK

En esta leccion utilizamos GCC nativo para comprender las reglas de construccion.

Nuestra instalacion de PS2SDK dispone del compilador cruzado:

    mips64r5900el-ps2-elf-gcc

Este compilador esta destinado a generar codigo para el entorno de PlayStation 2.

En una construccion real para ETN tambien necesitaremos configurar las opciones adecuadas, las cabeceras, las bibliotecas y el enlazado del proyecto.

Cambiar unicamente el nombre del compilador no garantiza que el programa pueda ejecutarse en la consola.

En proyectos mas grandes podemos utilizar reglas adicionales para compilar los archivos fuente por separado en archivos objeto `.o` y enlazarlos posteriormente.

## 11. Resumen

- `Makefile` contiene las reglas de construccion.
- `make` interpreta las reglas y ejecuta los comandos necesarios.
- Una regla define un objetivo, sus dependencias y un comando.
- Las variables ayudan a mantener una configuracion organizada.
- `all` suele representar la construccion principal.
- `clean` suele eliminar los archivos generados.
- `.PHONY` declara objetivos que representan tareas.
- `make` puede evitar reconstrucciones innecesarias mediante la comprobacion de dependencias.
- La automatizacion no sustituye la configuracion correcta de las herramientas de PS2SDK.