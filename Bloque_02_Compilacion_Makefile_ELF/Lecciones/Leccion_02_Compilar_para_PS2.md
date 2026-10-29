# Lección 02: Compilar para PlayStation 2

## 1. Objetivos

Al finalizar esta lección, podremos:

- Comprender por qué un programa escrito en C no es automáticamente compatible con cualquier plataforma.
- Identificar el propósito de PS2SDK dentro del desarrollo homebrew.
- Reconocer las herramientas de compilación destinadas al Emotion Engine.
- Diferenciar las cabeceras de las bibliotecas.
- Comprender el papel del enlazador en la construcción de un programa.
- Identificar la función de Docker en nuestro entorno de desarrollo.
- Reconocer las condiciones básicas para obtener un ejecutable adecuado para PlayStation 2.

## 2. ¿Por qué necesitamos herramientas específicas?

El lenguaje C permite desarrollar programas para diferentes plataformas. Sin embargo, escribir un programa en C no garantiza que pueda ejecutarse en cualquier sistema.

Para construir un programa necesitamos herramientas configuradas para la plataforma de destino.

Entre los aspectos que debemos considerar se encuentran:

- La arquitectura del procesador.
- El formato del ejecutable.
- Las convenciones y características del entorno de destino.
- Las bibliotecas disponibles.
- Las dependencias que deben resolverse durante el enlazado.

Por ejemplo, compilar un programa con GCC para Windows normalmente genera un ejecutable destinado a ese entorno. Para generar un programa destinado a PlayStation 2 necesitamos una cadena de herramientas apropiada para la consola.

La compatibilidad no depende únicamente del lenguaje de programación utilizado, sino también de cómo se construye el programa y del entorno en el que se ejecutará.

## 3. ¿Qué es PS2SDK?

PS2SDK es un conjunto de herramientas, bibliotecas y componentes destinados al desarrollo de software para PlayStation 2.

En nuestro proyecto ETN, utilizaremos PS2SDK como base para construir el programa y acceder a las funciones que necesitemos de la consola.

Entre sus componentes encontramos:

- Compiladores destinados a los procesadores de PlayStation 2.
- Herramientas de ensamblado y enlazado.
- Bibliotecas para distintas funciones de la consola.
- Archivos de cabecera con declaraciones, estructuras y definiciones.
- Herramientas auxiliares para facilitar la construcción de programas.

PS2SDK no es solamente un compilador. Es un conjunto de componentes que trabajan en conjunto durante el desarrollo.

### 3.1. El Emotion Engine

El Emotion Engine, conocido como EE, es el procesador principal de PlayStation 2.

Entre las herramientas de PS2SDK encontramos `ee-gcc`, que permite compilar código C destinado al entorno del Emotion Engine.

También existen otras herramientas, como `ee-g++` para C++ y `ee-ld` para el enlazado.

No todos los componentes de PlayStation 2 utilizan el mismo procesador. El I/O Processor (IOP), por ejemplo, cumple funciones diferentes. Por ello, debemos utilizar las herramientas adecuadas para cada destino cuando un proyecto requiera trabajar con distintos componentes de la consola.

## 4. Compilación para PlayStation 2

En un entorno de desarrollo nativo podríamos utilizar un comando como:

    gcc main.c -o programa

Este comando solicita a GCC que construya un ejecutable a partir del archivo fuente `main.c`.

Para un programa destinado al Emotion Engine podemos encontrar un comando de este tipo:

    ee-gcc main.c -o programa.elf

Sus elementos son:

- `ee-gcc`: selecciona el compilador destinado al Emotion Engine.
- `main.c`: identifica el archivo fuente.
- `-o`: permite especificar el nombre del archivo de salida.
- `programa.elf`: establece el nombre del resultado.

Este comando es un ejemplo introductorio. Un proyecto real puede necesitar opciones adicionales, rutas de búsqueda, archivos fuente complementarios y bibliotecas específicas.

La forma exacta de construir un programa depende de sus requisitos y de la configuración del entorno.

### 4.1. La extensión ELF

En el desarrollo homebrew de PlayStation 2 es habitual utilizar archivos ejecutables con extensión `.elf`.

Sin embargo, la extensión no garantiza por sí sola la compatibilidad.

El archivo debe haberse generado para el destino correcto y sus dependencias deben estar resueltas. También debe respetar las condiciones que requiere el entorno en el que se ejecutará.

Cambiar la extensión de un ejecutable de Windows a `.elf` no lo convierte en un programa compatible con PlayStation 2.

## 5. Cabeceras y bibliotecas

En C, las cabeceras y las bibliotecas cumplen funciones relacionadas, pero diferentes.

### 5.1. Archivos de cabecera

Los archivos `.h` permiten compartir declaraciones de funciones, estructuras, tipos y otros elementos que necesita el código fuente.

Por ejemplo:

    #include <stdio.h>

Esta directiva permite utilizar las declaraciones proporcionadas por la cabecera estándar de entrada y salida, entre ellas la declaración de `printf`.

Incluir una cabecera no significa que todas las implementaciones de las funciones declaradas queden incorporadas automáticamente al programa.

### 5.2. Bibliotecas

Las bibliotecas proporcionan implementaciones de funciones y otros componentes que un programa puede necesitar.

En el desarrollo para PlayStation 2 podemos utilizar bibliotecas de PS2SDK para trabajar con diferentes capacidades de la consola.

Durante la construcción debemos asegurarnos de que las implementaciones necesarias estén disponibles y de que las dependencias se resuelvan correctamente.

Algunas bibliotecas pueden incorporarse mediante la configuración de las herramientas, mientras que otras deben indicarse expresamente.

### 5.3. El papel del enlazador

El enlazador combina los archivos objeto y resuelve las referencias necesarias para construir el ejecutable.

Si un programa utiliza una función cuya implementación se encuentra en una biblioteca, el enlazador debe poder localizarla mediante la configuración y las opciones correspondientes.

Por tanto, debemos distinguir:

- La cabecera declara la interfaz que puede utilizar el código.
- La biblioteca proporciona implementaciones.
- El enlazador resuelve las referencias necesarias durante la construcción.

## 6. Docker y el entorno de desarrollo

En nuestro entorno utilizamos Docker para trabajar con las herramientas de PS2SDK.

El flujo general es el siguiente:

1. Escribimos el código fuente en VS Code.
2. Los archivos se ponen a disposición del entorno de desarrollo.
3. Docker proporciona el entorno donde se ejecutan las herramientas configuradas.
4. Las herramientas de PS2SDK compilan y enlazan el programa.
5. Si la construcción termina correctamente, obtenemos el archivo de salida solicitado.

Docker no es el compilador ni sustituye a PS2SDK. Su función es proporcionar un entorno donde podemos ejecutar las herramientas necesarias.

Tampoco implica que el programa se ejecute directamente en el hardware de PlayStation 2 durante la compilación.

La construcción ocurre en el entorno de desarrollo. La ejecución final debe realizarse en la consola o en un entorno de emulación adecuado.

## 7. Comprobaciones antes de compilar

Antes de construir un programa para PlayStation 2, debemos comprobar:

1. Que las herramientas necesarias estén instaladas y accesibles.
2. Que el compilador seleccionado corresponda al destino previsto.
3. Que los archivos fuente estén disponibles.
4. Que las cabeceras y bibliotecas necesarias puedan localizarse.
5. Que las opciones de compilación y enlazado sean apropiadas.
6. Que la construcción termine correctamente.
7. Que el resultado sea adecuado para el entorno en el que se ejecutará.

En nuestro proyecto también debemos mantener clara la organización del entorno.

El directorio de trabajo general es `/src/hello_ps2`, mientras que el repositorio del curso se encuentra en `/src/hello_ps2/curso_PS2SDK`.

Antes de utilizar comandos concretos, debemos comprobar cómo están configuradas las herramientas en nuestro contenedor. No debemos asumir que una herramienta está disponible únicamente porque forme parte de una instalación habitual de PS2SDK.

## 8. Relación con las siguientes lecciones

Esta lección nos proporciona los fundamentos necesarios para comprender el proceso de construcción de ETN.

En la siguiente lección estudiaremos los `Makefile`, archivos que permiten definir y automatizar las instrucciones necesarias para construir un programa.

Después trabajaremos con la generación de ELF y aprenderemos a interpretar el resultado de la construcción.

Estos conceptos nos permitirán pasar de ejemplos sencillos a un flujo de compilación más organizado para nuestro proyecto.

## 9. Resumen

- Un programa escrito en C no es automáticamente compatible con todas las plataformas.
- PS2SDK proporciona herramientas y bibliotecas para el desarrollo homebrew de PlayStation 2.
- `ee-gcc` es un compilador destinado al entorno del Emotion Engine.
- Las cabeceras proporcionan declaraciones y las bibliotecas contienen implementaciones.
- El enlazador resuelve las referencias necesarias para construir el ejecutable.
- Docker proporciona un entorno de trabajo para ejecutar las herramientas.
- La extensión `.elf` no garantiza por sí sola la compatibilidad con PlayStation 2.
- La construcción correcta es un paso necesario, pero debemos comprobar también que el resultado sea adecuado para su entorno de ejecución.