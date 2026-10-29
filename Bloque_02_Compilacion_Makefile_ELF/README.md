# Bloque 02: Compilacion, Makefile y generacion de ELF

## Objetivo general

Comprender el proceso de construccion de programas, aprender a automatizar la compilacion y reconocer los elementos necesarios para generar e inspeccionar ejecutables destinados a PlayStation 2.

Este bloque establece las bases para utilizar las herramientas de PS2SDK durante el desarrollo de ELFtation Navigator (ETN).

## Lecciones

| Leccion | Tema |
|---|---|
| 01 | Proceso de compilacion |
| 02 | Compilar para PlayStation 2 |
| 03 | Makefile y automatizacion de la compilacion |
| 04 | Generacion de ELF y analisis del ejecutable |

## Contenidos aprendidos

### Leccion 01: Proceso de compilacion

- Funcion del preprocesador.
- Compilacion y ensamblado.
- Archivos objeto y enlazado.
- Declaraciones y definiciones de funciones.
- Diferencia entre codigo fuente y ejecutable.
- Concepto de compilacion cruzada.

### Leccion 02: Compilar para PlayStation 2

- Funcion de PS2SDK.
- Herramientas destinadas al Emotion Engine.
- Diferencias entre herramientas nativas y cruzadas.
- Funcion de las cabeceras y las bibliotecas.
- Papel del enlazador.
- Relacion entre Docker, el entorno de desarrollo y PS2SDK.

### Leccion 03: Makefile y automatizacion de la compilacion

- Estructura de las reglas de construccion.
- Objetivos, dependencias y comandos.
- Variables de configuracion.
- Objetivos `all` y `clean`.
- Directiva `.PHONY`.
- Compilacion incremental.
- Automatizacion de la construccion.

### Leccion 04: Generacion de ELF y analisis del ejecutable

- Concepto de ELF.
- Cabecera, secciones y segmentos.
- Punto de entrada.
- Diferencia entre extension y compatibilidad.
- Inspeccion mediante `file`, `readelf` y `objdump`.
- Verificacion del ejecutable y pruebas en un entorno compatible.

## Practicas

Las practicas se encuentran dentro de la carpeta `Practicas/`.

- `L01_proceso_de_compilacion.c`
- `Leccion_02_Compilar_para_PS2/`
  - `L02_compilar_para_ps2.c`
  - `funciones_ps2.c`
  - `funciones_ps2.h`
- `Leccion_03_Makefile_y_automatizacion/`
  - `L03_makefile_y_automatizacion.c`
  - `Makefile`
- `Leccion_04_Generacion_de_ELF/`
  - `L04_generacion_de_elf.c`
  - `Makefile`

Las practicas de las lecciones 03 y 04 utilizan GCC nativo en Linux para demostrar la automatizacion de la construccion y reforzar los conceptos de ELF.

No deben confundirse con una construccion real para PlayStation 2.

## Herramientas del entorno

La instalacion de PS2SDK dispone de un compilador cruzado para el Emotion Engine:

    mips64r5900el-ps2-elf-gcc

El entorno utiliza Docker para ejecutar las herramientas configuradas y VS Code para editar los archivos del proyecto.

La configuracion real de construccion para ETN debera utilizar las opciones, cabeceras, bibliotecas y reglas de enlazado apropiadas.

## Criterios de cierre

El bloque se considera cerrado porque:

- Se completaron las cuatro lecciones.
- Se estudiaron los conceptos fundamentales de compilacion y enlazado.
- Se comprendio la funcion de un Makefile.
- Se identificaron las herramientas para inspeccionar un ELF.
- Se diferenciaron las practicas conceptuales de una construccion real para PS2.

## Proximo bloque

**Bloque 03: Video e interfaz grafica**

El siguiente bloque iniciara el trabajo relacionado con la salida visual y la interfaz de ETN, avanzando desde los fundamentos de construccion hacia componentes visibles del programa.

## Resumen final

El Bloque 02 establece las bases para comprender como se construye un programa y como se prepara un ejecutable para su destino.

Los conocimientos adquiridos se aplicaran progresivamente al desarrollo de ELFtation Navigator.