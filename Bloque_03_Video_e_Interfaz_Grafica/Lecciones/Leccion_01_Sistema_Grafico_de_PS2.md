# Leccion 01: El sistema grafico de PlayStation 2

## 1. Introduccion

Para desarrollar ELFtation Navigator (ETN), necesitamos comprender cómo funciona el sistema gráfico de PlayStation 2 y qué componentes intervienen en la generación de imágenes.

Hasta ahora hemos trabajado principalmente con programas en C que procesan información y muestran resultados mediante texto. Sin embargo, ETN necesita una interfaz gráfica que permita visualizar archivos, directorios, dispositivos y diferentes elementos de navegación.

Para conseguirlo, debemos estudiar el hardware gráfico de la consola, los conceptos relacionados con la representación de imágenes y las herramientas que proporciona el PS2SDK.

## 2. Componentes principales del sistema gráfico

La arquitectura de PlayStation 2 cuenta con dos componentes fundamentales para el procesamiento y la representación gráfica:

### 2.1. Emotion Engine (EE)

El Emotion Engine es el procesador principal de PlayStation 2.

Entre sus responsabilidades se encuentran:

- Ejecutar las instrucciones de nuestros programas.
- Procesar la lógica de la aplicación.
- Preparar los datos necesarios para las operaciones gráficas.
- Coordinar diferentes tareas relacionadas con el procesamiento de información.

En el desarrollo de ETN, nuestro código C se ejecutará principalmente en el entorno del Emotion Engine.

### 2.2. Graphics Synthesizer (GS)

El Graphics Synthesizer es el procesador gráfico de PlayStation 2.

Su función principal consiste en procesar operaciones gráficas y generar la imagen que posteriormente será enviada a la pantalla.

Entre sus responsabilidades encontramos:

- Procesar comandos gráficos.
- Trabajar con información de píxeles.
- Realizar operaciones de dibujo y composición.
- Gestionar recursos gráficos mediante su memoria local.
- Generar la salida de vídeo.

El GS dispone de 4 MB de memoria local integrada, utilizada para almacenar información gráfica como texturas y buffers.

### 2.3. Relación entre EE y GS

El Emotion Engine y el Graphics Synthesizer trabajan conjuntamente.

De forma simplificada:

1. Nuestro programa ejecuta la lógica de la aplicación en el EE.
2. El programa prepara los datos y las operaciones gráficas.
3. Los mecanismos de comunicación y transferencia permiten enviar información al GS.
4. El GS procesa las operaciones gráficas.
5. La imagen resultante se presenta mediante el sistema de salida de vídeo.

Esta comunicación puede involucrar mecanismos como DMA y circuitos de transferencia especializados, que estudiaremos cuando trabajemos con ellos.

## 3. Framebuffer

Un framebuffer es una región de memoria utilizada para almacenar los datos correspondientes a una imagen o fotograma.

Podemos imaginarlo como un espacio que contiene la información de los píxeles que componen una imagen.

Cada píxel almacena información sobre su color, utilizando una representación determinada por el formato gráfico seleccionado.

### 3.1. Ejemplo de framebuffer

Imaginemos que queremos mostrar una pantalla azul con un rectángulo blanco en el centro.

Para representar esta imagen, necesitamos almacenar información sobre los colores de los diferentes píxeles.

El framebuffer contiene esa información y permite que el sistema gráfico utilice los datos para presentar la imagen.

### 3.2. Cálculo del almacenamiento

Supongamos que trabajamos con una resolución de 640 × 448 píxeles y utilizamos un formato de 32 bits por píxel.

Primero calculamos la cantidad total de píxeles:

    640 × 448 = 286720 píxeles

Cada píxel utiliza 32 bits, equivalentes a 4 bytes.

Por tanto:

    286720 × 4 = 1146880 bytes

Esto equivale aproximadamente a 1,09 MiB.

Este cálculo representa el almacenamiento de un framebuffer sin considerar alineaciones, estructuras adicionales ni otros recursos gráficos.

### 3.3. Double buffering

Una técnica utilizada en aplicaciones gráficas es el double buffering o doble búfer.

Consiste en trabajar con dos buffers:

- Front buffer: contiene la imagen que se está mostrando.
- Back buffer: permite preparar la siguiente imagen.

Cuando el nuevo fotograma está preparado, se intercambian las funciones de ambos buffers.

Esto ayuda a evitar que el usuario vea una imagen mientras todavía se está dibujando.

## 4. Resolución de imagen

La resolución representa las dimensiones de una imagen expresadas mediante su ancho y alto en píxeles.

Por ejemplo:

- 320 × 240.
- 640 × 480.
- 640 × 448.
- 720 × 576.

Una resolución de 640 × 480 contiene:

    640 × 480 = 307200 píxeles

Mientras que una resolución de 320 × 240 contiene:

    320 × 240 = 76800 píxeles

Por tanto, la primera resolución contiene cuatro veces más píxeles que la segunda.

La resolución influye en la cantidad de información que debe procesarse y almacenarse para representar una imagen.

También debemos considerar la relación de aspecto, que describe la proporción entre el ancho y el alto de la imagen.

Por ejemplo:

- 4:3 es una relación de aspecto habitual en televisores antiguos.
- 16:9 es una relación de aspecto panorámica.

Para ETN será importante organizar la interfaz teniendo en cuenta las resoluciones y relaciones de aspecto que queramos admitir.

## 5. Señal de vídeo y frecuencia de actualización

### 5.1. ¿Qué es una señal de vídeo?

Una señal de vídeo es la información que un dispositivo transmite a una pantalla para permitirle representar imágenes.

En el caso de PlayStation 2, la consola genera una salida de vídeo que puede transmitirse mediante conexiones compatibles, como el cable AV compuesto o conexiones por componentes.

La señal contiene información relacionada con:

- La representación de los colores.
- La estructura de la imagen.
- La sincronización horizontal y vertical.
- Los tiempos necesarios para presentar cada parte de la imagen.

El televisor recibe e interpreta esa información para mostrar el contenido.

Por tanto, una señal de vídeo no es simplemente una fotografía enviada una sola vez. Es un flujo continuo de información que permite mantener la imagen en pantalla.

### 5.2. Frecuencia de actualización (Hz)

La frecuencia de actualización se mide en hercios (Hz) y representa la frecuencia con la que se repiten los ciclos de actualización de la señal o pantalla.

Por ejemplo:

- 50 Hz: 50 ciclos por segundo.
- 60 Hz: 60 ciclos por segundo.

Podemos calcular la duración de cada ciclo mediante:

    Duracion = 1 / Frecuencia

Para 50 Hz:

    1 / 50 = 0,02 segundos

Cada ciclo dura 20 milisegundos.

Para 60 Hz:

    1 / 60 = 0,01667 segundos

Cada ciclo dura aproximadamente 16,67 milisegundos.

Una frecuencia de 60 Hz representa ciclos de actualización más frecuentes que una de 50 Hz.

### 5.3. Diferencia entre Hz y FPS

Aunque están relacionados, los hercios y los FPS representan conceptos diferentes.

**Hz (Hertz):**

Representa la frecuencia de actualización de la señal o pantalla.

**FPS (Frames Per Second):**

Representa la cantidad de fotogramas nuevos que genera una aplicación cada segundo.

Por ejemplo, un programa puede generar 30 FPS mientras utiliza una salida de vídeo de 60 Hz.

En una situación ideal, cada fotograma nuevo podría mantenerse durante dos ciclos de actualización.

Por tanto:

- La salida de vídeo mantiene una frecuencia de 60 Hz.
- El programa genera 30 fotogramas nuevos por segundo.
- No es obligatorio generar 60 fotogramas diferentes para utilizar una salida de 60 Hz.

Los FPS y los Hz están relacionados, pero no son equivalentes.

## 6. Vídeo entrelazado y progresivo

Existen diferentes métodos para transmitir y presentar las imágenes.

Dos conceptos importantes son el entrelazado y el progresivo.

### 6.1. Entrelazado (Interlaced)

El vídeo entrelazado divide cada fotograma en dos campos:

- Un campo contiene las líneas pares.
- El otro campo contiene las líneas impares.

Ambos campos se presentan de manera alternada y forman la imagen completa.

Este método fue utilizado ampliamente en sistemas de televisión tradicionales.

Un ejemplo de modo entrelazado es 480i.

### 6.2. Progresivo (Progressive)

El vídeo progresivo presenta las líneas de cada fotograma de manera secuencial.

En lugar de dividir el fotograma en dos campos, se transmite la imagen completa siguiendo el orden de sus líneas.

Un ejemplo de modo progresivo es 480p.

### 6.3. Importancia en PlayStation 2

La PS2 puede trabajar con diferentes modos de vídeo dependiendo de la configuración, el software y las capacidades de la pantalla.

Algunos ejemplos son:

- 480i a 60 Hz.
- 576i a 50 Hz.
- 480p a 60 Hz, cuando el modo es compatible y está habilitado.

No todos los televisores ni todas las configuraciones admiten los mismos modos.

Por esta razón, al desarrollar ETN tendremos que considerar la compatibilidad de la salida de vídeo y la correcta distribución de los elementos gráficos.

## 7. Inicialización gráfica

Antes de dibujar cualquier elemento, nuestro programa necesita preparar y configurar el entorno gráfico.

A este proceso lo llamamos inicialización gráfica.

Entre las tareas que pueden formar parte de este proceso encontramos:

1. Seleccionar un modo de vídeo.
2. Configurar los parámetros gráficos.
3. Preparar los framebuffers.
4. Configurar los recursos necesarios para trabajar con el GS.
5. Preparar los mecanismos de transferencia de información.
6. Dejar el sistema listo para comenzar a dibujar.

La inicialización depende de las herramientas y bibliotecas utilizadas.

No consiste únicamente en seleccionar una resolución: también debemos preparar los recursos y estructuras necesarios para representar imágenes.

## 8. GSKit

GSKit es una biblioteca utilizada en el desarrollo homebrew de PlayStation 2 para facilitar el trabajo con el Graphics Synthesizer.

Proporciona funciones que permiten realizar operaciones gráficas sin tener que gestionar manualmente todos los detalles del hardware.

Entre sus posibilidades encontramos:

- Inicialización del sistema gráfico.
- Configuración de modos de vídeo.
- Administración de buffers gráficos.
- Dibujo de primitivas.
- Representación de imágenes y texturas.
- Operaciones relacionadas con la presentación de fotogramas.

Es importante distinguir entre GSKit y el Graphics Synthesizer:

- Graphics Synthesizer: componente físico de la consola.
- GSKit: biblioteca de software que facilita la comunicación y el trabajo con el sistema gráfico.

GSKit será una de las herramientas que estudiaremos para desarrollar la interfaz de ETN.

## 9. Renderizado

El renderizado es el proceso mediante el cual se construye una imagen a partir de los elementos que nuestro programa quiere representar.

Por ejemplo, ETN necesitará mostrar:

- Un fondo.
- Una barra superior.
- Una lista de archivos.
- Un indicador de selección.
- Información sobre el dispositivo conectado.
- Diferentes elementos de navegación.

Cada uno de estos componentes debe convertirse en operaciones gráficas que permitan construir la imagen final.

De forma simplificada, el proceso puede representarse así:

1. El programa determina qué elementos deben mostrarse.
2. Se preparan las operaciones gráficas correspondientes.
3. Las herramientas gráficas gestionan los comandos y recursos necesarios.
4. El GS procesa las operaciones.
5. Los resultados se almacenan en los recursos gráficos correspondientes.
6. La imagen se presenta mediante la salida de vídeo.

Este proceso constituye una de las bases para construir cualquier interfaz gráfica.

## 10. Aplicacion de estos conceptos en ETN

Los conceptos estudiados serán fundamentales para desarrollar la interfaz de ELFtation Navigator.

Nuestro objetivo es construir un explorador de archivos que permita visualizar y navegar por los dispositivos de almacenamiento conectados a la consola.

Para conseguirlo necesitaremos:

- Configurar correctamente el sistema gráfico.
- Seleccionar un modo de vídeo compatible.
- Preparar los recursos de memoria gráfica.
- Dibujar elementos visuales.
- Representar texto y nombres de archivos.
- Organizar los diferentes componentes de la interfaz.
- Actualizar la imagen cuando cambie el estado del programa.

Durante las siguientes lecciones comenzaremos a trabajar con las herramientas gráficas disponibles en nuestro entorno PS2SDK y construiremos progresivamente los primeros elementos visuales de ETN.

## 11. Conceptos clave

| Concepto | Descripcion |
|---|---|
| Emotion Engine (EE) | Procesador principal que ejecuta el programa y prepara operaciones. |
| Graphics Synthesizer (GS) | Procesador gráfico encargado de procesar operaciones gráficas. |
| Framebuffer | Región de memoria que almacena los datos de imagen de un fotograma. |
| Double buffering | Técnica que utiliza dos buffers para preparar y presentar imágenes. |
| Resolución | Dimensiones de una imagen expresadas en píxeles. |
| Frecuencia (Hz) | Frecuencia de actualización de la señal o pantalla. |
| FPS | Cantidad de fotogramas nuevos generados por segundo. |
| Señal de vídeo | Flujo de información que permite representar imágenes y sincronizar su presentación. |
| Entrelazado | Método que divide cada fotograma en dos campos de líneas. |
| Progresivo | Método que presenta secuencialmente las líneas de cada fotograma. |
| GSKit | Biblioteca que facilita el trabajo con el sistema gráfico de PS2. |
| Renderizado | Proceso de construcción de una imagen a partir de elementos gráficos. |
| Inicialización gráfica | Preparación y configuración del entorno gráfico antes de dibujar. |

## 12. Relacion con el proyecto

Esta lección establece las bases teóricas necesarias para comenzar a desarrollar la interfaz gráfica de ETN.

En las siguientes lecciones aplicaremos estos conocimientos mediante programas en C, utilizando las herramientas del PS2SDK.

El objetivo será pasar progresivamente de programas de consola a una aplicación gráfica capaz de representar los elementos de un explorador de archivos.