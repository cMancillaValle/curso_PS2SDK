
# Lección 02: Hardware de PS2 relevante para ETN

## 1. Objetivos de aprendizaje

Al finalizar esta lección, debemos ser capaces de:

- Reconocer los principales componentes de hardware de PlayStation 2.
- Diferenciar CPU, memoria principal, procesador gráfico y dispositivos de almacenamiento.
- Comprender las limitaciones de memoria relevantes para el desarrollo.
- Identificar los dispositivos de entrada y salida que utilizará ELFtation Navigator (ETN).
- Distinguir los conceptos que necesitamos aprender ahora de aquellos que podemos estudiar más adelante.

## 2. Arquitectura general de PlayStation 2

La PlayStation 2 es un sistema compuesto por procesadores, memorias, subsistemas gráficos e interfaces de entrada y salida.

Para desarrollar ETN, debemos comprender cómo se relacionan estos componentes con las funciones que implementaremos.

El modelo conceptual utilizado en esta lección es:

```text
Emotion Engine (CPU)
        |
        v
Memoria principal (RAM)
        |
        +---- Subsistema gráfico
        |
        +---- Entrada y salida
                  |
                  +---- Mando
                  +---- Tarjeta de memoria
                  +---- USB
                  +---- Otros dispositivos
```

Este esquema es simplificado y no representa todas las conexiones internas de la consola.

## 3. Componentes principales

### 3.1. Emotion Engine (EE)

El Emotion Engine es el procesador principal de la PlayStation 2.

Ejecuta las instrucciones del programa y realiza las operaciones necesarias para su funcionamiento.

En ETN, la lógica ejecutada por el procesador incluirá:

- Recorrer directorios.
- Procesar las entradas del usuario.
- Gestionar estructuras de datos.
- Coordinar las operaciones con archivos.
- Controlar el estado de la interfaz.

No es necesario estudiar todavía el conjunto de instrucciones del procesador ni sus unidades vectoriales.

### 3.2. Memoria principal (RAM)

La PS2 dispone de 32 MB de memoria principal RDRAM.

Esta memoria mantiene instrucciones y datos utilizados mientras se ejecuta el programa.

En ETN podría contener:

- La ruta del directorio actual.
- Los nombres de archivos mostrados en pantalla.
- El estado de navegación.
- Las opciones de los menús.
- Los datos temporales de las operaciones.

#### Importancia para ETN

La memoria disponible es limitada en comparación con la de un PC moderno. Por ello, debemos evitar reservar memoria innecesariamente y diseñar las estructuras de datos con cuidado.

Por ejemplo, si un directorio contiene miles de archivos, no debemos asumir que será conveniente cargar y mantener toda su información detallada en memoria sin límites.

Más adelante estudiaremos la gestión de memoria en C y cómo organizar listas de archivos de manera eficiente.

### 3.3. Graphics Synthesizer (GS)

El Graphics Synthesizer es el procesador gráfico de la PS2 y dispone de 4 MB de memoria gráfica integrada.

Su función está relacionada con el procesamiento gráfico y la generación de imágenes que aparecen en pantalla.

Para ETN, el subsistema gráfico permitirá mostrar:

- Texto.
- Listas de archivos.
- Menús.
- Indicadores de selección.
- Información sobre los dispositivos.
- Una interfaz visual progresivamente más elaborada.

Utilizaremos las bibliotecas gráficas disponibles para PS2SDK antes de plantearnos programar directamente el hardware.

**Importante:** los 4 MB de memoria gráfica no son una extensión intercambiable de los 32 MB de memoria principal. Son recursos diferentes con funciones y mecanismos de acceso distintos.

### 3.4. I/O Processor (IOP)

La PS2 dispone de un I/O Processor, un subsistema dedicado que participa en la gestión de entrada y salida y en funciones de compatibilidad con hardware y software de generaciones anteriores.

Su existencia nos ayuda a comprender que la comunicación con los dispositivos no depende únicamente del procesador principal.

Para acceder al mando, a las tarjetas de memoria o al almacenamiento USB, utilizaremos las bibliotecas y los mecanismos compatibles proporcionados por nuestro entorno de desarrollo.

No necesitamos estudiar ahora toda la arquitectura interna del IOP.

## 4. Dispositivos relevantes para ETN

### 4.1. DualShock 2

Es el dispositivo de entrada que utilizaremos para controlar la aplicación.

Permitirá:

- Movernos entre archivos y directorios.
- Seleccionar elementos.
- Confirmar operaciones.
- Volver al directorio anterior.
- Abrir menús y cancelar acciones.

Más adelante estudiaremos la lectura de botones mediante PS2SDK.

### 4.2. Tarjeta de memoria

Es un medio de almacenamiento persistente.

A diferencia de la RAM, conserva los datos cuando se apaga la consola.

Podría utilizarse para guardar configuraciones o archivos compatibles con las funciones que implementemos.

### 4.3. USB

Los puertos USB de la PS2 permiten conectar dispositivos compatibles, pero reconocer físicamente una memoria no garantiza que una aplicación pueda explorar sus archivos.

Para utilizar nuestra futura memoria USB FAT32, necesitaremos soporte de software compatible con el dispositivo y su sistema de archivos.

ETN deberá poder identificar el dispositivo, acceder a su contenido y gestionar las operaciones admitidas.

### 4.4. Televisor y salida de vídeo

La aplicación debe mostrar su interfaz mediante el subsistema gráfico de la consola.

Esto requiere inicializar correctamente las bibliotecas correspondientes y utilizar un modo de vídeo compatible con la configuración de la PS2.

## 5. Diferencias entre memoria y almacenamiento

| Recurso | Función | Conserva datos al apagar |
|---|---|---|
| RAM principal | Mantener datos e instrucciones temporales | No |
| Memoria gráfica del GS | Almacenar información utilizada para generar imágenes | No |
| Tarjeta de memoria | Guardar datos de forma persistente | Sí |
| USB de almacenamiento | Guardar y transportar archivos | Sí |

La RAM y la memoria gráfica son recursos de trabajo, mientras que la tarjeta de memoria y el USB son medios de almacenamiento persistente.

Los dispositivos de almacenamiento pueden utilizar mecanismos y sistemas de archivos diferentes. Por ello, no debemos asumir que todos se acceden de la misma manera.

## 6. Qué necesitamos estudiar y qué podemos posponer

### Necesario para ETN

- Diferenciar CPU, RAM y procesador gráfico.
- Comprender que la memoria principal es limitada.
- Identificar los dispositivos de entrada y salida.
- Entender la diferencia entre memoria volátil y almacenamiento persistente.
- Reconocer que necesitamos bibliotecas y soporte de software para acceder al hardware.

### Temas para más adelante, si son necesarios

- Conjunto de instrucciones del Emotion Engine.
- Unidades vectoriales VU0 y VU1.
- Transferencias DMA y buses internos.
- Registros de bajo nivel del Graphics Synthesizer.
- Detalles internos de los subsistemas de la consola.

Estos temas pueden resultar útiles para optimización o desarrollo de bajo nivel, pero no son requisitos iniciales para construir un navegador de archivos.

## 7. Aplicación práctica a ELFtation Navigator

Los componentes estudiados se relacionan con ETN de la siguiente manera:

| Necesidad de ETN | Componente o recurso relacionado |
|---|---|
| Ejecutar la lógica del navegador | Emotion Engine |
| Mantener rutas y listas de archivos | RAM principal |
| Mostrar menús y texto | Graphics Synthesizer y bibliotecas gráficas |
| Leer los botones del usuario | Subsistema de entrada y mando |
| Explorar archivos almacenados | USB, tarjeta de memoria y software de acceso |
| Mostrar la interfaz | Salida de vídeo |

Esta relación constituye una primera visión de la arquitectura de ETN. La implementación concreta se estudiará en los siguientes bloques.

## 8. Resumen

- El Emotion Engine ejecuta las instrucciones del programa.
- La PS2 tiene 32 MB de memoria principal.
- El Graphics Synthesizer dispone de 4 MB de memoria gráfica integrada.
- El IOP participa en tareas de entrada y salida.
- El mando es un dispositivo de entrada.
- La tarjeta de memoria y el USB son medios de almacenamiento persistente.
- Para acceder al hardware necesitamos mecanismos de software compatibles.
- No hace falta estudiar todos los detalles internos del hardware antes de construir ETN.

## 9. Referencias

- PS2SDK: https://github.com/ps2dev/ps2sdk
- PS2 Homebrew Development: https://ps2dev.github.io/
- PlayStation 2 Technical Specifications, documentación histórica de Sony.

Siguiente lección: El ecosistema Homebrew de PlayStation 2.