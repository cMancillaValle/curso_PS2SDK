
# Lección 04: Nuestro entorno de desarrollo

## Objetivos

Al finalizar esta lección, podremos:

- Identificar las herramientas principales del entorno de desarrollo.
- Comprender cómo se relacionan VS Code, Docker, PS2SDK y Make.
- Reconocer la función de los archivos principales de un proyecto.
- Entender el recorrido general desde el código fuente hasta un ejecutable ELF.

## 1. Herramientas del entorno

### Visual Studio Code

VS Code es el editor que utilizamos para escribir código, organizar archivos y ejecutar tareas de desarrollo.

No compila por sí solo el código para PlayStation 2. Para ello, utilizamos las herramientas adecuadas del PS2SDK.

### Docker

Docker permite ejecutar herramientas dentro de un entorno aislado y preparado para el desarrollo.

En nuestro proyecto, lo utilizamos para acceder a un entorno con las herramientas necesarias para compilar programas destinados a la arquitectura de PS2, sin tener que configurar todo el entorno de compilación directamente en Windows.

### PS2SDK

PS2SDK proporciona las herramientas y bibliotecas necesarias para desarrollar aplicaciones Homebrew para PlayStation 2. Entre ellas se encuentran el compilador cruzado y las herramientas de enlace.

### Make y Makefile

`make` automatiza la construcción de un proyecto siguiendo las reglas descritas en el archivo `Makefile`.

El Makefile indica cómo se construye el programa y qué comandos deben ejecutarse. Make coordina esos pasos.

## 2. Del código fuente al ejecutable

Un flujo simplificado de construcción es:

1. Escribir el código fuente en un archivo como `main.c`.
2. Compilarlo para producir un archivo objeto como `main.o`.
3. Enlazar los archivos objeto y las bibliotecas necesarias.
4. Generar el ejecutable, normalmente con extensión `.elf`.

El flujo puede variar según la estructura y las necesidades del proyecto.

### Archivos principales

- `main.c`: contiene código fuente escrito en C.
- `main.o`: archivo objeto generado durante la compilación.
- `Makefile`: contiene las reglas de construcción.
- `programa.elf`: nombre ilustrativo de un ejecutable generado.

Un archivo ELF no garantiza por sí solo que el programa funcione correctamente en la consola. También debe estar bien construido y ser compatible con el entorno de ejecución.

## 3. Configuración de VS Code

Dentro de `.vscode/` podemos encontrar archivos de configuración para el editor.

### `c_cpp_properties.json`

Configura aspectos de la extensión de C/C++ de VS Code, como las rutas de inclusión y la información que utiliza para analizar el código.

### `tasks.json`

Define tareas que pueden ejecutarse desde VS Code. Una tarea puede, por ejemplo, ejecutar `make`.

Estos archivos no son equivalentes: `tasks.json` define tareas del editor, mientras que `Makefile` define las reglas de construcción del proyecto.

## 4. Docker y las rutas de trabajo

Dentro del contenedor hemos trabajado en la ruta:

```bash
cd /src/hello_ps2
```

Esta ruta corresponde al sistema de archivos visible desde el contenedor.

Cuando una carpeta se comparte mediante un volumen de Docker, los cambios en esa carpeta pueden ser accesibles desde ambos entornos. No debemos asumir que todas las carpetas del contenedor están compartidas: depende de su configuración.

Es importante identificar la ubicación del proyecto para poder editar, compilar y conservar los archivos correctamente.

## 5. Aplicación a ELFtation Navigator

Para desarrollar ELFtation Navigator (ETN), seguiremos este flujo general:

1. Escribir el código en VS Code.
2. Acceder al proyecto desde el entorno de desarrollo.
3. Utilizar PS2SDK para compilar el código.
4. Ejecutar las reglas del Makefile mediante Make.
5. Obtener el ELF y probarlo en un entorno compatible con Homebrew de PS2.
6. Corregir errores y repetir el proceso.

Los programas antiguos de referencia se conservarán sin modificaciones. El nuevo desarrollo se organizará de forma independiente.

## Resumen

- VS Code es nuestro editor.
- Docker proporciona un entorno aislado para las herramientas.
- PS2SDK contiene herramientas y bibliotecas para el desarrollo en PS2.
- Make ejecuta las reglas definidas en el Makefile.
- Los archivos objeto y los ejecutables ELF cumplen funciones diferentes.
- `tasks.json` configura tareas de VS Code; `Makefile` describe cómo construir el programa.
- Las rutas y los volúmenes de Docker son importantes para organizar el trabajo.