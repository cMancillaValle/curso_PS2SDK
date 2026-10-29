# Leccion 01: Proceso de compilacion

## 1. Objetivos de la leccion

Al terminar esta leccion, debemos comprender:

- Por que el codigo fuente no se ejecuta directamente en la PlayStation 2.
- Cuales son las etapas principales del proceso de compilacion.
- Que funcion cumplen el preprocesador, el compilador, el ensamblador y el enlazador.
- Que son los archivos objeto `.o`.
- Como se relacionan los archivos fuente, los archivos objeto y el ejecutable final.
- Que es la compilacion cruzada y por que la necesitamos para desarrollar ETN.
- Que es un archivo ELF y por que su extension no garantiza que sea compatible con la PS2.

Esta leccion es principalmente conceptual. En las siguientes lecciones trabajaremos con las herramientas de PS2SDK y aplicaremos estos conocimientos en el entorno de desarrollo.

## 2. Del codigo fuente al programa ejecutable

Cuando escribimos un programa en C, creamos instrucciones que una persona puede leer y que siguen las reglas del lenguaje.

Por ejemplo:

    #include <stdio.h>

    int main(void) {
        printf("Hola, PlayStation 2!\n");
        return 0;
    }

Este codigo es comprensible para nosotros, pero la consola no ejecuta directamente el archivo `main.c`.

El codigo fuente debe transformarse en codigo que corresponda a la arquitectura de destino y que pueda ejecutarse dentro de su entorno.

Para ello se utiliza un proceso de construccion que puede involucrar varias etapas:

1. Preprocesamiento.
2. Compilacion.
3. Ensamblado.
4. Enlazado.

Estas etapas pueden ejecutarse mediante un solo comando. Las herramientas de construccion coordinan el proceso y realizan las operaciones necesarias.

Es importante comprender cada etapa por separado porque, cuando algo falla, saber que hace cada una facilita identificar el problema.

## 3. El preprocesador

El preprocesador procesa las directivas que comienzan con `#`, como `#include` y `#define`.

Por ejemplo:

    #include <stdio.h>

    #define PUNTAJE_INICIAL 50

En este fragmento encontramos dos directivas:

- `#include <stdio.h>` solicita incorporar las declaraciones proporcionadas por la cabecera `stdio.h`.
- `#define PUNTAJE_INICIAL 50` define una macro que el preprocesador sustituye segun sus reglas.

El preprocesador no ejecuta el programa ni genera por si solo el ejecutable final.

Su funcion consiste en preparar el codigo para las etapas posteriores.

Las directivas de preprocesamiento no se limitan a incluir cabeceras y definir macros. Tambien permiten realizar compilacion condicional mediante directivas como `#if`, `#ifdef` y `#endif`.

## 4. El compilador

El compilador analiza el codigo C y lo traduce a una representacion de menor nivel.

Durante este proceso puede detectar errores relacionados con la sintaxis, los tipos y otras reglas del lenguaje.

Por ejemplo:

    int sumar(int a, int b) {
        return a + b;
    }

El compilador procesa esta funcion y la traduce para la arquitectura de destino, siguiendo las opciones de compilacion utilizadas.

No debemos confundir el compilador con el proceso completo de construccion. En un flujo de trabajo habitual, todavia quedan otras etapas antes de obtener el ejecutable final.

La forma exacta de la salida depende de las herramientas y las opciones utilizadas. Algunas configuraciones generan primero codigo ensamblador; otras pueden trabajar con representaciones intermedias.

Para nuestros fundamentos, nos interesa comprender que el compilador transforma el codigo fuente en codigo de menor nivel.

## 5. El ensamblador

El ensamblador transforma el codigo ensamblador en codigo maquina organizado dentro de un archivo objeto.

En un flujo de construccion habitual podemos encontrar archivos con extension `.o`.

Por ejemplo:

    main.c
       |
       v
    main.o

El archivo `main.o` no es simplemente una copia del codigo fuente con otra extension.

Es un archivo objeto que contiene codigo generado y otros datos necesarios para el enlazado. Tambien puede incluir informacion sobre simbolos y referencias que todavia deben resolverse.

Un archivo objeto no suele ser el ejecutable final listo para utilizarse.

La extension `.o` es habitual en sistemas basados en herramientas GNU y otros entornos de desarrollo, aunque los nombres y formatos concretos pueden variar segun las herramientas utilizadas.

## 6. El enlazador

El enlazador combina archivos objeto y resuelve las referencias entre ellos, junto con las bibliotecas y dependencias necesarias.

Supongamos que tenemos dos archivos fuente:

    main.c
    operaciones.c

En `main.c` utilizamos una funcion llamada `sumar`, cuya implementacion se encuentra en `operaciones.c`.

Una version simplificada de los archivos podria ser la siguiente.

### Archivo main.c

    int sumar(int a, int b);

    int main(void) {
        int resultado = sumar(10, 20);
        return resultado;
    }

La linea `int sumar(int a, int b);` es una declaracion de funcion. Informa al compilador sobre el nombre de la funcion, sus parametros y su tipo de retorno.

No contiene la implementacion de `sumar`.

### Archivo operaciones.c

    int sumar(int a, int b) {
        return a + b;
    }

Este archivo contiene la definicion de la funcion.

Si ambos archivos se compilan por separado, podemos obtener:

    main.o
    operaciones.o

Posteriormente, el enlazador combina los objetos y resuelve la referencia a `sumar`.

El flujo conceptual es:

    main.c -----------------> main.o ------------------+
                                                       |
                                                       +--> Enlazador
                                                       |        |
    operaciones.c ----------> operaciones.o -----------+        |
                                                                v
                                                         Ejecutable

El ejemplo representa el proceso de forma simplificada. El resultado real tambien depende de las opciones de construccion, las bibliotecas utilizadas y el entorno de destino.

### Una distincion importante

Declarar una funcion no significa implementar esa funcion.

- La declaracion permite conocer como se utiliza.
- La definicion contiene su implementacion.
- El enlazado permite resolver las referencias entre las distintas partes del programa.

No todos los programas necesitan varios archivos objeto. Un programa pequeno puede construirse desde un solo archivo fuente.

## 7. Archivos fuente, archivos objeto y ejecutables

Es importante reconocer las diferencias entre los archivos que encontramos durante el desarrollo.

| Archivo | Funcion |
|---|---|
| `.c` | Contiene codigo fuente escrito en C. |
| `.h` | Suele contener declaraciones, definiciones compartidas y otras instrucciones que pueden incorporarse mediante el preprocesador. |
| `.o` | Contiene un archivo objeto generado durante la construccion. |
| `.elf` | Es una extension utilizada habitualmente para ejecutables de homebrew de PS2. El formato ELF tambien se utiliza en otras plataformas. |

La extension ayuda a identificar el tipo de archivo, pero no constituye una garantia absoluta de su contenido o compatibilidad.

Por ejemplo, cambiar el nombre de un ejecutable de `programa.exe` a `programa.elf` no lo transforma en un programa compatible con PlayStation 2.

La compatibilidad depende del contenido del archivo, la arquitectura para la que fue generado, las convenciones de construccion y los requisitos del entorno de ejecucion.

## 8. Compilacion nativa y compilacion cruzada

Hasta ahora hemos hablado del proceso general de construccion de programas. Sin embargo, necesitamos distinguir entre dos situaciones.

### 8.1. Compilacion nativa

En la compilacion nativa, las herramientas generan codigo destinado a la misma plataforma o entorno para el que estan configuradas.

Por ejemplo, un compilador instalado en un ordenador puede generar un ejecutable para el sistema operativo de ese ordenador.

Que un programa este escrito en C no significa que pueda ejecutarse directamente en cualquier plataforma.

El codigo generado y el entorno de ejecucion importan.

### 8.2. Compilacion cruzada

La compilacion cruzada permite generar codigo destinado a una plataforma diferente de aquella en la que se ejecutan las herramientas de desarrollo.

En nuestro proyecto:

- **Host:** el entorno de desarrollo donde ejecutamos las herramientas, en nuestro caso dentro de Docker.
- **Herramientas:** el compilador cruzado, el enlazador y las demas herramientas de PS2SDK.
- **Target:** la plataforma de destino, PlayStation 2.
- **Resultado esperado:** un programa construido para la arquitectura y el entorno de ejecucion de la consola.

El proceso conceptual es:

    Ordenador
       |
       v
    Entorno Docker con PS2SDK
       |
       v
    Codigo fuente en C
       |
       v
    Herramientas de compilacion cruzada
       |
       v
    Archivos objeto y enlazado
       |
       v
    Ejecutable destinado a PS2

Docker proporciona un entorno de desarrollo aislado y reproducible. No convierte por si solo un programa en un ejecutable de PS2.

Para generar codigo destinado a la consola necesitamos utilizar las herramientas y las opciones de construccion adecuadas.

## 9. El formato ELF

ELF significa *Executable and Linkable Format*.

Es un formato utilizado para representar archivos ejecutables, archivos objeto y otros tipos de archivos relacionados con la construccion de programas.

En el desarrollo homebrew de PlayStation 2 es habitual encontrar ejecutables con extension `.elf`.

Durante el desarrollo de ETN, nuestro objetivo sera generar un ELF adecuado para la consola y poder probarlo en el entorno correspondiente.

Sin embargo, debemos recordar tres cosas:

1. La extension `.elf` no garantiza por si sola que el archivo sea compatible con PS2.
2. El ejecutable debe haberse generado para la arquitectura y el entorno de destino adecuados.
3. El enlazado y las dependencias del programa deben resolverse correctamente.

Todavia no hemos generado un ELF con nuestro proyecto. Ese trabajo llegara cuando empecemos a utilizar las herramientas de PS2SDK.

## 10. Relacion con las siguientes lecciones

En esta leccion estudiamos el proceso general de construccion y el papel de cada etapa.

En las siguientes lecciones avanzaremos hacia la practica:

- Identificaremos las herramientas de compilacion cruzada que utilizaremos.
- Aprenderemos a compilar codigo para PlayStation 2.
- Estudiaremos los Makefiles y como automatizan la construccion.
- Generaremos un ELF y analizaremos el resultado.

La meta es comprender tanto el funcionamiento general del proceso como los comandos y archivos que utilizaremos al desarrollar ETN.

## 11. Resumen

- El codigo fuente en C debe transformarse antes de poder ejecutarse en la plataforma de destino.
- El preprocesador procesa directivas como `#include` y `#define`.
- El compilador traduce el codigo a una representacion de menor nivel.
- El ensamblador genera archivos objeto a partir del codigo ensamblador.
- El enlazador resuelve referencias y combina los objetos y las dependencias necesarias.
- Los archivos `.o` son archivos objeto y normalmente no constituyen el ejecutable final.
- La compilacion cruzada permite generar codigo para una plataforma diferente de aquella donde se ejecutan las herramientas.
- Para ETN utilizaremos herramientas de PS2SDK configuradas para generar codigo destinado a PlayStation 2.
- La extension `.elf` no garantiza por si sola que un ejecutable sea compatible con la consola.