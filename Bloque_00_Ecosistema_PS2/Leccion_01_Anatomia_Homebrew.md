
# Lección 01: Anatomía de una aplicación Homebrew de PS2

## 1. Objetivos de aprendizaje

Al finalizar esta lección, debemos ser capaces de:

- Comprender el flujo general de construcción de una aplicación Homebrew.
- Diferenciar código fuente, archivos objeto y ejecutables ELF.
- Entender las funciones del compilador cruzado y del enlazador.
- Identificar el papel de Visual Studio Code, Docker, PS2SDK (PlayStation 2 Software Development Kit), Git y GitHub.
- Relacionar estos conceptos con el desarrollo de ELFtation Navigator (ETN).

## 2. ¿Qué es Homebrew?

En el contexto de PlayStation 2, el término *Homebrew* hace referencia al software desarrollado por la comunidad, fuera del catálogo comercial tradicional de la consola.

Nuestro proyecto, **ELFtation Navigator (ETN)**, será una aplicación Homebrew personal orientada a explorar archivos y, progresivamente, incorporar operaciones útiles para administrar contenido en la PS2.

## 3. Anatomía de una aplicación

### 3.1. Código fuente (`.c`)

Es el archivo que contiene las instrucciones escritas por el programador en lenguaje C.

Por ejemplo, `main.c` puede contener la función principal de una aplicación.

El código fuente es legible para nosotros, pero la consola no ejecuta directamente el texto escrito en C.

### 3.2. Compilador cruzado

Un compilador cruzado (*cross-compiler*) se ejecuta en una plataforma de desarrollo, pero genera código para una arquitectura de destino diferente.

En nuestro entorno, utilizamos las herramientas de PS2SDK para generar programas destinados a PlayStation 2.

### 3.3. Archivo objeto (`.o`)

Durante el proceso de construcción, el código fuente puede convertirse en un archivo objeto.

Por ejemplo:

`main.c` → `main.o`

El archivo objeto contiene código y datos en un formato que puede utilizar el enlazador. Puede incluir referencias que todavía deben resolverse durante el enlazado.

Por eso, un archivo `.o` no debe confundirse con el ejecutable final.

### 3.4. Enlazador (*linker*)

El enlazador combina archivos objeto y bibliotecas, resuelve referencias entre componentes y produce el resultado ejecutable según la configuración del proyecto.

Las etapas concretas pueden variar según las herramientas y el sistema de compilación utilizado.

### 3.5. Archivo ELF

ELF significa *Executable and Linkable Format*.

Es un formato utilizado para representar ejecutables, archivos objeto y bibliotecas. En nuestro proyecto, el archivo `.elf` será el ejecutable que intentaremos cargar en un entorno compatible con PS2.

**Importante:** que un archivo tenga extensión `.elf` no garantiza por sí solo que sea compatible con cualquier entorno ni que funcione correctamente.

## 4. Flujo general de construcción

El proceso conceptual es el siguiente:

1. Escribir el código fuente.
2. Compilarlo para la arquitectura de destino.
3. Generar archivos objeto.
4. Enlazar los objetos y las bibliotecas necesarias.
5. Obtener un ejecutable ELF.
6. Cargar y ejecutar el programa mediante un entorno compatible con PlayStation 2.
7. Probar el comportamiento del programa y corregir los errores encontrados.

### Diagrama del proceso

```text
Código fuente (.c)
        |
        v
Compilación cruzada
        |
        v
Archivo objeto (.o)
        |
        v
Enlazado con objetos y bibliotecas
        |
        v
Ejecutable ELF
        |
        v
Carga y ejecución en un entorno compatible
        |
        v
Pruebas y depuración
```

Este diagrama representa un flujo general. Las herramientas pueden automatizar o combinar algunas de estas etapas.

## 5. Herramientas de nuestro entorno

| Herramienta | Función |
|---|---|
| VS Code | Editar y organizar el código fuente. |
| Docker | Proporcionar un entorno de desarrollo aislado y reproducible. |
| PS2SDK | Proporcionar herramientas y bibliotecas para desarrollar software destinado a PS2. |
| Git | Registrar cambios y mantener un historial de versiones. |
| GitHub | Alojar el repositorio remoto y compartir el proyecto. |
| PlayStation 2 | Hardware de destino para probar nuestras aplicaciones. |

Estas herramientas cumplen funciones distintas y complementarias.

## 6. Conceptos clave

- **Compilar no es lo mismo que ejecutar:** la compilación transforma el código, mientras que la ejecución pone el programa en funcionamiento.
- **Un archivo objeto no equivale al ejecutable final:** Normalmente todavía requiere enlazado.
- **Un ELF no garantiza compatibilidad universal:** Importan la arquitectura, las dependencias y el entorno de ejecución.
- **Compilar sin errores no garantiza ausencia de errores de ejecución:** Las pruebas siguen siendo necesarias.
- **Los artefactos de compilación suelen ser regenerables:** Archivos como `.o` pueden reconstruirse a partir del código fuente y la configuración correspondiente.

## 7. Aplicación a ELFtation Navigator

Para ETN, estos conceptos nos permitirán distinguir entre:

- El código C que implementa la navegación y las operaciones con archivos.
- Los archivos objeto generados durante la compilación.
- Las bibliotecas de PS2SDK utilizadas por el proyecto.
- El ejecutable ELF que probaremos en la consola.

Más adelante estudiaremos cómo se organiza un proyecto real mediante un `Makefile` y cómo se conectan sus archivos fuente y bibliotecas.

## 8. Referencias

- PS2SDK: https://github.com/ps2dev/ps2sdk
- GNU Make: https://www.gnu.org/software/make/manual/
- Especificación ELF de System V: https://refspecs.linuxfoundation.org/elf/elf.pdf

Siguiente lección: Hardware de PlayStation 2 relevante para ELFtation Navigator.