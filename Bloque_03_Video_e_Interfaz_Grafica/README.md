
# Bloque 03: Video e interfaz gráfica

## Objetivo

Comprender el funcionamiento del sistema gráfico de PlayStation 2 y aprender a utilizar las herramientas de PS2SDK y GSKit para construir los primeros elementos visuales de ELFtation Navigator (ETN).

Durante este bloque se estudiarán los fundamentos de la salida de video, la inicialización del entorno gráfico, el dibujo de primitivas, la administración de buffers y la organización del ciclo principal de dibujo.

Los conocimientos adquiridos servirán como base para desarrollar progresivamente la interfaz gráfica del explorador.

## Contenido

### Lección 01: Sistema gráfico de PlayStation 2

**Objetivo:** comprender los componentes y conceptos fundamentales del sistema gráfico de la consola.

Contenidos:

- Emotion Engine y Graphics Synthesizer.
- Funcionamiento general del procesamiento gráfico.
- Framebuffer y almacenamiento de imágenes.
- Doble buffering.
- Resolución y frecuencia de actualización.
- Señal de video.
- Diferencias entre video entrelazado y progresivo.
- Introducción a GSKit.

### Lección 02: Inicialización gráfica y dibujo básico

**Objetivo:** inicializar el entorno gráfico mediante GSKit y realizar las primeras operaciones de dibujo.

Contenidos:

- Inclusión y utilización de GSKit.
- Inicialización de la estructura `GSGLOBAL`.
- Inicialización de la pantalla.
- Limpieza del buffer mediante `gsKit_clear()`.
- Representación de colores mediante RGBA.
- Dibujo de primitivas con `gsKit_prim_sprite()`.
- Ejecución de operaciones mediante la cola gráfica.
- Sincronización vertical y cambio de buffers.
- Organización del ciclo principal de dibujo.
- Uso de funciones y prototipos para separar responsabilidades.

**Práctica:** inicialización gráfica y dibujo de una escena sencilla con fondo azul y un rectángulo blanco. El ejecutable ELF fue compilado mediante PS2SDK y probado exitosamente en una PlayStation 2 física.

## Estructura del bloque

```text
Bloque_03_Video_e_Interfaz_Grafica/
├── README.md
├── Lecciones/
│   ├── Leccion_01_Sistema_Grafico_de_PS2.md
│   └── Leccion_02_Inicializacion_Grafica_y_Dibujo_Basico.md
└── Practicas/
    └── Leccion_02_Inicializacion_Grafica_y_Dibujo_Basico/
        ├── main.c
        └── Makefile
```

## Herramientas y tecnologías

- PS2SDK: entorno de desarrollo para PlayStation 2.
- GSKit: biblioteca para facilitar el uso del Graphics Synthesizer.
- DMAKit: biblioteca utilizada por GSKit para operaciones relacionadas con DMA.
- Compilador cruzado `mips64r5900el-ps2-elf-gcc`.
- Makefile: automatización del proceso de compilación.
- Docker: entorno de desarrollo.
- uLaunchELF: ejecución y prueba de archivos ELF en la consola física.

## Aplicación en ETN

Los conocimientos de este bloque permitirán construir la base visual de ELFtation Navigator.

La inicialización gráfica y el ciclo de dibujo serán necesarios para representar los elementos de la interfaz, incluyendo:

- Fondo y distribución de la pantalla.
- Paneles y áreas de navegación.
- Elementos visuales para representar archivos y directorios.
- Indicadores de selección y cursores.
- Menús y otros componentes de la interfaz.

## Estado del bloque

**Estado:** EN PROGRESO.

Las lecciones 01 y 02 están completadas. Se ha estudiado el sistema gráfico de PlayStation 2 y se ha desarrollado y probado en hardware real un primer programa de dibujo mediante GSKit.

Las siguientes lecciones ampliarán estos fundamentos para avanzar hacia una interfaz gráfica organizada y funcional para ETN.
