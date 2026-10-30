
# Leccion 02: Inicializacion grafica y dibujo basico

## 1. Introduccion

En esta leccion comenzamos a utilizar GSKit para inicializar el entorno grafico de PlayStation 2 y realizar nuestras primeras operaciones de dibujo.

El objetivo es comprender el proceso necesario para preparar la pantalla, limpiar el buffer, dibujar primitivas graficas y presentar los fotogramas mediante el sistema de doble buffer.

Esta leccion tambien introduce la organizacion de un programa grafico mediante funciones y prototipos, preparando la estructura para el desarrollo de la interfaz de ETN (ELFtation Navigator).

## 2. GSKit

GSKit es una biblioteca que facilita el uso del Graphics Synthesizer (GS) de PlayStation 2.

Proporciona funciones para inicializar el entorno grafico, configurar la pantalla, preparar primitivas, administrar buffers y ejecutar operaciones de dibujo.

Su utilizacion permite trabajar con operaciones graficas sin tener que implementar directamente todos los procesos de bajo nivel del hardware.

Para utilizar GSKit se incluye su encabezado principal:

```c
#include <gsKit.h>
```

Este encabezado proporciona las declaraciones y estructuras necesarias para trabajar con la biblioteca.

## 3. Inicializacion del entorno grafico

GSKit utiliza la estructura `GSGLOBAL` para almacenar informacion relacionada con el estado y la configuracion del entorno grafico.

Para inicializar esta estructura se utiliza:

```c
GSGLOBAL *gsGlobal = gsKit_init_global();
```

La funcion devuelve un puntero a la estructura global de GSKit.

Es importante comprobar que la inicializacion haya sido correcta antes de continuar:

```c
if (gsGlobal == NULL) {
    return 1;
}
```

Si la funcion devuelve `NULL`, el programa termina indicando un error.

La estructura `gsGlobal` se utiliza posteriormente como argumento en las operaciones graficas.

## 4. Inicializacion de la pantalla

Una vez inicializado el entorno grafico, se prepara la pantalla mediante:

```c
gsKit_init_screen(gsGlobal);
```

Esta funcion inicializa los recursos necesarios para comenzar a utilizar la salida grafica.

La inicializacion se realiza una sola vez, antes de entrar al ciclo principal del programa.

## 5. Limpieza del buffer

Antes de dibujar una nueva escena es necesario establecer el contenido del buffer grafico.

Para limpiar el buffer se utiliza:

```c
gsKit_clear(gsGlobal, color);
```

El segundo argumento representa el color utilizado para limpiar el buffer.

GSKit proporciona la macro `GS_SETREG_RGBA()` para construir un valor de color RGBA:

```c
GS_SETREG_RGBA(rojo, verde, azul, alfa)
```

Cada componente recibe un valor entre 0 y 255.

Por ejemplo, para establecer un fondo azul opaco:

```c
gsKit_clear(gsGlobal, GS_SETREG_RGBA(0, 0, 255, 255));
```

Los componentes utilizados son:

- Rojo: 0
- Verde: 0
- Azul: 255
- Alfa: 255

La limpieza del buffer permite evitar que permanezcan elementos de fotogramas anteriores cuando se prepara una escena nueva.

## 6. Dibujo de primitivas graficas

GSKit permite dibujar diferentes primitivas graficas, como puntos, lineas, sprites y otras formas.

Para nuestra primera practica utilizamos `gsKit_prim_sprite()`:

```c
gsKit_prim_sprite(
    gsGlobal,
    100, 80,
    300, 180,
    0,
    GS_SETREG_RGBA(255, 255, 255, 255)
);
```

La funcion recibe los siguientes argumentos:

| Argumento | Descripcion |
|---|---|
| `gsGlobal` | Puntero al entorno grafico. |
| `100` | Coordenada horizontal inicial. |
| `80` | Coordenada vertical inicial. |
| `300` | Coordenada horizontal final. |
| `180` | Coordenada vertical final. |
| `0` | Valor de profundidad Z. |
| Color RGBA | Color de la primitiva. |

En este ejemplo se dibuja un rectangulo blanco utilizando dos coordenadas opuestas.

La posicion inicial es `(100, 80)` y la posicion final es `(300, 180)`.

Por tanto:

- Ancho: 300 - 100 = 200 unidades.
- Alto: 180 - 80 = 100 unidades.

Para esta practica utilizamos una profundidad de `0`. La interpretacion de los valores de profundidad depende de la configuracion del Z-Buffer y de las operaciones internas de GSKit.

## 7. Cola de operaciones graficas

GSKit utiliza una cola para organizar las operaciones graficas que deben ejecutarse.

Cuando se invocan funciones de dibujo, estas preparan operaciones que posteriormente deben procesarse.

Para ejecutar las operaciones almacenadas en la cola se utiliza:

```c
gsKit_queue_exec(gsGlobal);
```

Esta funcion ejecuta la cola grafica normal, incluyendo las operaciones correspondientes a las colas de tipo oneshot y persistent.

Es importante ejecutarla despues de preparar las operaciones de dibujo.

El orden correcto es:

1. Preparar las operaciones graficas.
2. Ejecutar la cola.
3. Sincronizar y presentar el siguiente fotograma.

Si se ejecuta la cola antes de preparar las operaciones de dibujo, estas no se procesaran en esa ejecucion.

## 8. Sincronizacion y doble buffer

La tecnica de doble buffer utiliza dos buffers para organizar la preparacion y presentacion de los fotogramas.

Mientras uno se utiliza para mostrar la imagen, el otro puede utilizarse para preparar el siguiente fotograma.

GSKit proporciona la funcion:

```c
gsKit_sync_flip(gsGlobal);
```

Esta funcion realiza la sincronizacion vertical y el cambio de buffers.

Internamente, espera la sincronizacion vertical mediante `gsKit_vsync_wait()` y actualiza el contexto grafico activo.

La sincronizacion ayuda a evitar problemas visuales como el screen tearing, que puede producirse cuando se presenta un fotograma mientras la pantalla esta siendo actualizada.

## 9. Ciclo principal de dibujo

Un programa grafico normalmente necesita repetir las operaciones necesarias para actualizar y presentar la escena.

Este proceso se conoce como game loop o ciclo principal del programa.

En nuestra practica utilizamos un ciclo infinito:

```c
while (1) {
    dibujar_escena(gsGlobal);

    gsKit_queue_exec(gsGlobal);

    gsKit_sync_flip(gsGlobal);
}
```

Cada iteracion realiza tres operaciones:

1. Preparar la escena.
2. Ejecutar las operaciones graficas.
3. Sincronizar y cambiar los buffers.

La inicializacion grafica permanece fuera del ciclo porque no necesitamos repetirla en cada fotograma.

Esta organizacion sera importante para ETN, ya que posteriormente tendremos que actualizar y dibujar diferentes elementos de la interfaz.

## 10. Organizacion mediante funciones

Para evitar concentrar todas las operaciones graficas dentro de `main()`, utilizamos una funcion independiente:

```c
void dibujar_escena(GSGLOBAL *gsGlobal);
```

Esta declaracion es un prototipo de funcion.

Un prototipo informa al compilador sobre el nombre de la funcion, su tipo de retorno y sus parametros, sin incluir su implementacion.

La implementacion puede aparecer posteriormente:

```c
void dibujar_escena(GSGLOBAL *gsGlobal) {
    gsKit_clear(gsGlobal, GS_SETREG_RGBA(0, 0, 255, 255));

    gsKit_prim_sprite(
        gsGlobal,
        100, 80,
        300, 180,
        0,
        GS_SETREG_RGBA(255, 255, 255, 255)
    );
}
```

La funcion recibe un puntero a `GSGLOBAL`, permitiendo trabajar con el mismo entorno grafico inicializado en `main()`.

Al utilizar `void` como tipo de retorno, la funcion no necesita devolver un valor.

En proyectos mas grandes, los prototipos pueden trasladarse a archivos `.h` y las implementaciones a archivos `.c`, facilitando la organizacion modular del programa.

## 11. Makefile y compilacion

Para compilar el programa utilizamos el compilador cruzado de PS2SDK:

```makefile
EE_CC = mips64r5900el-ps2-elf-gcc
```

Se definen las rutas de los encabezados y bibliotecas de GSKit y PS2SDK:

```makefile
GSKIT_INC = /usr/local/ps2dev/gsKit/include
GSKIT_LIB = /usr/local/ps2dev/gsKit/lib
PS2SDK_INC = /usr/local/ps2dev/ps2sdk/common/include
```

Las opciones de compilacion son:

```makefile
EE_CFLAGS = -D_EE -G0 -I$(GSKIT_INC) -I$(PS2SDK_INC)
```

- `-D_EE`: define la macro `_EE`, necesaria para identificar el entorno Emotion Engine.
- `-G0`: desactiva el uso de la seccion de datos pequenos.
- `-I`: indica las rutas donde buscar los encabezados.

Las opciones de enlace son:

```makefile
EE_LDFLAGS = -L$(GSKIT_LIB) -lgskit -ldmakit
```

- `-L`: indica donde buscar las bibliotecas.
- `-lgskit`: enlaza GSKit.
- `-ldmakit`: enlaza DMAKit.

El objetivo de compilacion genera `main.elf`:

```makefile
TARGET = main.elf

$(TARGET): main.c
	$(EE_CC) $(EE_CFLAGS) main.c -o $(TARGET) $(EE_LDFLAGS)
```

## 12. Resultado de la practica

Se desarrollo un programa capaz de inicializar el entorno grafico mediante GSKit, limpiar el buffer con un fondo azul y dibujar un rectangulo blanco.

El programa utiliza un ciclo principal que prepara la escena, ejecuta la cola de operaciones graficas y sincroniza los buffers.

Tambien se organizo el codigo mediante una funcion independiente y su correspondiente prototipo.

El ejecutable ELF se genero correctamente mediante el compilador cruzado de PS2SDK y posteriormente se transfirio desde Docker a Windows para copiarlo a un dispositivo USB.

Finalmente, `main.elf` se ejecuto correctamente en una PlayStation 2 fisica mediante uLaunchELF.

## 13. Conexion con ETN

Los conocimientos adquiridos en esta leccion representan la base para construir la interfaz grafica de ELFtation Navigator.

La inicializacion del entorno grafico, el dibujo de primitivas, el manejo de buffers y la organizacion del ciclo principal seran necesarios para representar los diferentes elementos del explorador de archivos.

En futuras lecciones se ampliara esta estructura para construir una interfaz grafica mas organizada y funcional.
