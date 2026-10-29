# Leccion 04: Generacion de ELF y analisis del ejecutable

## 1. Objetivos

Al finalizar esta leccion podremos:

- Comprender que es el formato ELF.
- Identificar la funcion de la cabecera ELF, las secciones, los segmentos y el punto de entrada.
- Diferenciar la extension de un archivo de su compatibilidad real.
- Reconocer herramientas para inspeccionar ejecutables.
- Comprender el flujo de generacion de un ejecutable destinado a PlayStation 2.
- Relacionar la generacion de ELF con el desarrollo de ETN.

## 2. Que es un archivo ELF

ELF significa Executable and Linkable Format.

Es un formato utilizado para representar ejecutables, archivos objeto y otros componentes binarios en distintos entornos.

En el desarrollo homebrew de PlayStation 2, los programas ejecutables suelen distribuirse en formato ELF.

Durante la construccion de un programa podemos encontrar distintos tipos de archivos:

- `.c`: archivos de codigo fuente en C.
- `.h`: archivos de cabecera con declaraciones e interfaces.
- `.o`: archivos objeto producidos durante la construccion.
- `.elf`: extension habitual de ejecutables utilizados en el entorno de PS2.

La extension de un archivo no garantiza por si sola que su contenido corresponda al tipo de programa esperado.

## 3. Proceso de generacion

El proceso habitual de construccion puede incluir:

1. Preprocesamiento del codigo fuente.
2. Compilacion.
3. Ensamblado.
4. Enlazado de los archivos objeto y las dependencias necesarias.

Las herramientas pueden coordinar varias de estas etapas mediante un unico comando o mediante las reglas de un Makefile.

En una construccion para PlayStation 2 debemos utilizar las herramientas, opciones y bibliotecas apropiadas para el destino.

El resultado puede ser un ELF preparado para el entorno de ejecucion correspondiente.

## 4. Componentes de un ELF

### 4.1. Cabecera ELF

La cabecera contiene informacion general sobre el archivo.

Entre otros datos, permite identificar:

- La clase del archivo.
- El orden de bytes.
- La arquitectura indicada.
- El tipo de archivo.
- Informacion relacionada con el punto de entrada.

Estos datos ayudan a determinar las caracteristicas del ejecutable.

### 4.2. Secciones

Las secciones organizan diferentes tipos de informacion, como codigo, datos y tablas de simbolos.

Son especialmente importantes para las herramientas de compilacion, enlace y analisis.

### 4.3. Segmentos

Los segmentos describen regiones relevantes para la carga del programa en memoria.

La informacion de los segmentos permite al cargador identificar las regiones que deben procesarse para preparar la ejecucion.

Las secciones y los segmentos cumplen funciones relacionadas, pero no son conceptos equivalentes.

### 4.4. Punto de entrada

El punto de entrada indica la direccion especificada como entrada del ejecutable.

No tiene que coincidir directamente con la funcion `main` de C. En muchos programas existe codigo de inicio que prepara el entorno antes de que se ejecute la funcion principal.

## 5. Extension y compatibilidad

Un archivo que termina en `.elf` no es necesariamente compatible con PlayStation 2.

La compatibilidad depende de distintos factores:

- La arquitectura y el formato del archivo.
- Las instrucciones generadas por el compilador.
- Las convenciones y requisitos del entorno de ejecucion.
- Las dependencias y el enlazado.
- La inicializacion y organizacion de la memoria.
- La compatibilidad del cargador utilizado.

Cambiar la extension de un ejecutable no modifica su contenido ni lo convierte en un programa para PS2.

Del mismo modo, que un archivo se identifique como ELF no demuestra que vaya a funcionar correctamente en la consola.

## 6. Herramientas de inspeccion

### 6.1. file

La herramienta `file` intenta identificar el tipo de archivo y mostrar informacion general.

Ejemplo:

    file programa.elf

Su resultado es util como comprobacion inicial, pero no demuestra por si solo que el programa sea compatible con PS2.

### 6.2. readelf

`readelf` permite inspeccionar distintas partes de un archivo ELF.

Para consultar la cabecera:

    readelf -h programa.elf

Para consultar los segmentos:

    readelf -l programa.elf

Estas opciones permiten examinar informacion estructural del archivo.

### 6.3. objdump

`objdump` permite inspeccionar informacion de archivos objeto y ejecutables.

Tambien puede mostrar instrucciones desensambladas, dependiendo de las opciones y del soporte de arquitectura disponible.

Las herramientas de inspeccion no generan ni reparan el ejecutable. Su funcion es ayudar a analizarlo.

## 7. Relacion con PS2SDK

En nuestro entorno, el compilador cruzado disponible es:

    mips64r5900el-ps2-elf-gcc

Este compilador esta destinado a generar codigo para el entorno de PlayStation 2.


La construccion tambien puede requerir:

- Cabeceras apropiadas.
- Bibliotecas del SDK.
- Opciones de compilacion.
- Opciones y archivos de configuracion para el enlazado.
- Reglas de construccion coherentes con el proyecto.

Cambiar unicamente el compilador en un Makefile no garantiza que el programa pueda construirse o ejecutarse correctamente.

## 8. Flujo de trabajo para ETN

Para generar y comprobar un ejecutable de ELFtation Navigator seguiremos este proceso:

1. Organizar los archivos fuente.
2. Definir las reglas de construccion.
3. Compilar con las herramientas adecuadas para PS2.
4. Enlazar los archivos objeto y las dependencias necesarias.
5. Inspeccionar las caracteristicas del ELF generado.
6. Probar el programa en un entorno compatible con PlayStation 2.
7. Verificar su comportamiento y corregir los errores encontrados.

La inspeccion del archivo y las pruebas de ejecucion son comprobaciones complementarias.

## 9. Resumen

- ELF significa Executable and Linkable Format.
- El formato puede representar ejecutables, archivos objeto y otros componentes.
- La cabecera, las secciones, los segmentos y el punto de entrada contienen informacion relevante.
- La extension `.elf` no garantiza compatibilidad con PlayStation 2.
- `file`, `readelf` y `objdump` permiten inspeccionar archivos.
- PS2SDK proporciona herramientas y bibliotecas para construir programas destinados a la consola.
- Un ejecutable debe inspeccionarse y probarse en un entorno compatible.
- La generacion de ELF es una parte fundamental del proceso de construccion de ETN.