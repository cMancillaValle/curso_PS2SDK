
# Lección 03: El ecosistema Homebrew de PlayStation 2

## 1. Objetivos de aprendizaje

Al finalizar esta lección, debemos ser capaces de:

- Explicar qué significa desarrollar software Homebrew para PS2.
- Comprender qué es PS2SDK y qué recursos proporciona.
- Diferenciar un SDK, un compilador, una biblioteca y un entorno de ejecución.
- Describir el proceso general para construir y ejecutar una aplicación.
- Relacionar las herramientas del ecosistema con el desarrollo de ELFtation Navigator (ETN).

## 2. ¿Qué es Homebrew?

En el contexto de PlayStation 2, Homebrew hace referencia al software desarrollado de forma independiente, fuera del catálogo comercial tradicional de la consola.

Nuestro proyecto, **ELFtation Navigator (ETN)**, será una aplicación Homebrew personal destinada a explorar archivos y, progresivamente, incorporar operaciones para administrar contenido en la PS2.

El ecosistema Homebrew incluye herramientas de desarrollo, bibliotecas, aplicaciones que cargan ejecutables, documentación y métodos para probar software en la consola.

## 3. PS2SDK: kit de desarrollo

SDK significa *Software Development Kit*, es decir, kit de desarrollo de software.

Un SDK reúne recursos que facilitan el desarrollo para una plataforma. Puede incluir compiladores, enlazadores, bibliotecas, cabeceras, documentación y herramientas auxiliares.

**PS2SDK** proporciona componentes destinados a desarrollar aplicaciones para PlayStation 2.

Repositorio oficial: https://github.com/ps2dev/ps2sdk

Entre las tareas que podemos abordar mediante las herramientas y bibliotecas del ecosistema se encuentran:

- Construir ejecutables destinados a la PS2.
- Utilizar funciones de bibliotecas disponibles.
- Trabajar con entrada de usuario.
- Acceder a determinadas funciones gráficas.
- Interactuar con dispositivos mediante los componentes compatibles.

Estas funcionalidades no necesariamente pertenecen a una única biblioteca. Más adelante identificaremos los componentes específicos que necesitamos para cada función de ETN.

PS2SDK no es un lenguaje de programación ni un emulador.

## 4. Componentes del ecosistema

### 4.1. Compilador

El compilador transforma el código fuente en código para la arquitectura de destino.

En nuestro caso, necesitamos herramientas capaces de generar código compatible con PlayStation 2.

### 4.2. Bibliotecas

Las bibliotecas proporcionan funcionalidades reutilizables que podemos incorporar a nuestros programas.

Nos permiten evitar la implementación desde cero de numerosas operaciones.

Por ejemplo, para desarrollar ETN necesitaremos funcionalidades relacionadas con gráficos, entrada de usuario y acceso a dispositivos.

### 4.3. Enlazador

El enlazador combina archivos objeto y bibliotecas, y resuelve las referencias necesarias para generar el resultado ejecutable.

Forma parte del proceso de construcción de nuestra aplicación.

### 4.4. SDK

El SDK agrupa distintas herramientas y recursos de desarrollo.

Por tanto, no debemos confundir PS2SDK con el compilador individual ni con una biblioteca concreta: el SDK representa un conjunto más amplio de componentes.

### 4.5. Entorno de ejecución

Es el conjunto de mecanismos y condiciones que permiten cargar y ejecutar una aplicación.

En PS2, el entorno concreto importa. No debemos asumir que cualquier archivo ELF puede ejecutarse de cualquier manera.

## 5. Flujo de una aplicación Homebrew

El proceso general puede representarse así:

```text
Código fuente en C
        |
        v
Compilación para PS2
        |
        v
Archivos objeto
        |
        v
Enlazado con bibliotecas
        |
        v
Ejecutable ELF
        |
        v
Carga mediante un entorno compatible
        |
        v
Ejecución y pruebas en la consola
```

Las herramientas pueden automatizar o combinar algunas etapas, dependiendo de la configuración del proyecto.

Es importante recordar que generar un ELF no garantiza que el programa funcione correctamente. Todavía debemos probar su compatibilidad y comportamiento.

## 6. Herramientas y aplicaciones conocidas

### 6.1. uLaunchELF

uLaunchELF es una aplicación Homebrew conocida que permite explorar archivos y ejecutar determinados programas ELF.

Nos sirve como referencia funcional para el diseño de ETN.

Podemos observar conceptos como:

- Navegación por directorios.
- Selección de archivos.
- Acceso a distintos dispositivos.
- Lanzamiento de aplicaciones compatibles.

ETN será un proyecto independiente. No necesitamos convertir uLaunchELF en una dependencia obligatoria ni reproducir todas sus funciones.

### 6.2. Free McBoot

Free McBoot es una solución de arranque Homebrew utilizada en determinadas configuraciones de PlayStation 2.

Puede facilitar el acceso a aplicaciones como uLaunchELF, dependiendo de la consola y de la configuración instalada.

Su función es distinta de la de PS2SDK: una herramienta de desarrollo construye nuestro programa, mientras que un entorno de arranque compatible ayuda a iniciar aplicaciones en la consola.

## 7. Aplicación a ELFtation Navigator

Para construir ETN, podemos separar nuestras necesidades en tres grupos:

| Necesidad | Recursos relacionados |
|---|---|
| Construir el programa | Compilador, enlazador, Makefile y herramientas de PS2SDK |
| Implementar funciones | Bibliotecas gráficas, entrada y acceso a dispositivos |
| Probar el programa | Ejecutable ELF, PS2 y entorno compatible |

Nuestro objetivo no es aprender todas las herramientas del ecosistema de inmediato. Aprenderemos a identificar qué componente necesitamos para cada funcionalidad y cómo integrarlo en el proyecto.

## 8. Conceptos clave

- Homebrew es software desarrollado de forma independiente para una plataforma.
- PS2SDK es un kit de desarrollo de software para PlayStation 2.
- El compilador transforma código para la arquitectura de destino.
- Las bibliotecas ofrecen funcionalidades reutilizables.
- El enlazador combina componentes y resuelve referencias.
- El ejecutable ELF debe cargarse mediante un entorno compatible.
- uLaunchELF es una referencia útil para nuestro navegador, pero ETN será una aplicación independiente.
- Construir un ejecutable no sustituye las pruebas en el entorno de destino.

## 9. Referencias

- PS2SDK: https://github.com/ps2dev/ps2sdk
- Documentación de PS2Dev: https://ps2dev.github.io/

Siguiente lección: Nuestro entorno de desarrollo.