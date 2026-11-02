# Leccion 03: Coordenadas y Composicion de Interfaz

## 1. Objetivos

En esta leccion se estudia como organizar elementos graficos dentro de la pantalla de PlayStation 2 utilizando coordenadas, dimensiones y estructuras de datos.

El objetivo es construir una primera maqueta visual para ETN, distribuyendo diferentes paneles y elementos dentro de una interfaz grafica.

Al finalizar la leccion se busca comprender como:

- Utilizar coordenadas para posicionar elementos en pantalla.
- Calcular las dimensiones y los limites de los elementos graficos.
- Organizar una interfaz mediante paneles.
- Agrupar propiedades relacionadas utilizando estructuras (`struct`).
- Modularizar las operaciones graficas mediante funciones auxiliares.
- Utilizar punteros para actualizar posiciones entre llamadas.
- Distribuir elementos automaticamente mediante ciclos.
- Comprobar el espacio disponible antes de dibujar un elemento.

## 2. Sistema de coordenadas

Para posicionar elementos graficos se utiliza un sistema de coordenadas de dos dimensiones:

- **X:** representa la posicion horizontal.
- **Y:** representa la posicion vertical.

El origen del sistema se encuentra en la esquina superior izquierda de la pantalla.

Esto significa que:

- Al aumentar X, el elemento se desplaza hacia la derecha.
- Al aumentar Y, el elemento se desplaza hacia abajo.

### 2.1. Coordenadas y dimensiones

Las coordenadas indican donde comienza un elemento, mientras que sus dimensiones determinan cuanto espacio ocupa.

Por ejemplo, un rectangulo puede definirse mediante:

```c
int pos_x = 50;
int pos_y = 40;
int ancho = 300;
int alto = 200;
```

Su posicion inicial es `(50, 40)`.

Para calcular la esquina opuesta se suman las dimensiones a las coordenadas iniciales:

```c
int x_final = pos_x + ancho;
int y_final = pos_y + alto;
```

El resultado es `(350, 240)`.

### 2.2. Coordenadas en GSKit

La funcion `gsKit_prim_sprite()` permite dibujar una primitiva rectangular utilizando dos coordenadas opuestas:

```c
gsKit_prim_sprite(
    gsGlobal,
    x1, y1,
    x2, y2,
    iz,
    color
);
```

Los parametros principales son:

- `gsGlobal`: estructura global de GSKit.
- `x1`, `y1`: primera coordenada del rectangulo.
- `x2`, `y2`: coordenada opuesta.
- `iz`: profundidad utilizada por la primitiva.
- `color`: color del elemento.

Cuando se trabaja con dimensiones, las coordenadas finales se calculan sumando el ancho y el alto a la posicion inicial.

## 3. Distribucion de la interfaz

Para construir la primera maqueta visual de ETN se utiliza un espacio de referencia de 640 x 448 unidades.

Esta medida funciona como referencia para organizar los elementos de la practica. No representa necesariamente la resolucion configurada por GSKit.

La interfaz se divide en tres regiones:

### 3.1. Barra superior

La barra superior ocupa toda la parte horizontal superior de la pantalla.

| Propiedad | Valor |
|---|---:|
| Posicion X | 0 |
| Posicion Y | 0 |
| Ancho | 640 |
| Alto | 60 |
| Coordenada final | (640, 60) |

### 3.2. Panel lateral

El panel lateral se utiliza para organizar los elementos de navegacion.

| Propiedad | Valor |
|---|---:|
| Posicion X | 0 |
| Posicion Y | 60 |
| Ancho | 180 |
| Alto | 388 |
| Coordenada final | (180, 448) |

### 3.3. Panel principal

El panel principal ocupa el espacio restante y esta destinado al contenido de la interfaz.

| Propiedad | Valor |
|---|---:|
| Posicion X | 180 |
| Posicion Y | 60 |
| Ancho | 460 |
| Alto | 388 |
| Coordenada final | (640, 448) |

La distribucion permite aprovechar el espacio disponible sin que los paneles se superpongan.

## 4. Margenes y posicionamiento de elementos

Los margenes permiten establecer una separacion entre los elementos y los bordes de un panel.

Para el panel lateral se utilizan los siguientes valores:

| Propiedad | Valor |
|---|---:|
| Margen horizontal | 20 |
| Margen superior | 30 |
| Margen inferior | 30 |

La posicion inicial de los elementos se calcula utilizando la posicion del panel y sus margenes:

```c
int pos_x_elemento = panel_lateral.pos_x + panel_lateral.margen_horizontal;

int pos_y = panel_lateral.pos_y + panel_lateral.margen_superior;
```

Con los valores actuales, el primer elemento comienza en `(20, 90)`.

### 4.1. Calculo del ancho disponible

El margen horizontal se aplica a ambos lados del elemento.

Por lo tanto, el ancho disponible se calcula restando ambos margenes al ancho del panel:

```c
int ancho_elemento = panel_lateral.ancho
    - (panel_lateral.margen_horizontal * 2);
```

Para un panel de 180 unidades de ancho y margenes de 20 unidades:

- Ancho del panel: 180.
- Margen izquierdo: 20.
- Margen derecho: 20.
- Ancho disponible: 140.

### 4.2. Separacion vertical

Los elementos se distribuyen verticalmente utilizando una altura y una separacion constante.

En esta practica se utilizan:

```c
int alto_elemento = 50;
int separacion_elementos = 10;
```

La siguiente posicion vertical se calcula sumando la altura del elemento y la separacion:

```c
*pos_y += alto + separacion;
```

De esta manera, cada elemento se posiciona automaticamente despues del anterior.

## 5. Estructuras para organizar paneles

Cuando varios datos pertenecen a un mismo elemento, una estructura permite agruparlos bajo un solo tipo.

En esta practica se utiliza `Panel` para representar las propiedades de cada region de la interfaz:

```c
typedef struct {
    int pos_x;
    int pos_y;
    int ancho;
    int alto;
    int margen_horizontal;
    int margen_superior;
    int margen_inferior;
} Panel;
```

Cada instancia de `Panel` almacena:

- Posicion horizontal y vertical.
- Ancho y alto.
- Margen horizontal.
- Margen superior.
- Margen inferior.

### 5.1. Creacion de paneles

Una vez definido el tipo, se pueden crear diferentes instancias:

```c
Panel panel_superior = {0, 0, 640, 60, 10, 15, 15};

Panel panel_lateral = {0, 60, 180, 388, 20, 30, 30};

Panel panel_principal = {180, 60, 460, 388, 15, 20, 20};
```

Cada panel mantiene sus propias propiedades y puede utilizar margenes diferentes.

Los valores derivados, como la posicion inicial de los elementos internos o su ancho disponible, se calculan a partir de las propiedades del panel.

Esto evita almacenar informacion redundante.

## 6. Modularizacion mediante funciones

Separar las operaciones graficas en funciones permite mantener el codigo organizado y facilita su reutilizacion.

En esta practica se utilizan tres funciones principales:

- `dibujar_escena()`: organiza los elementos que componen la interfaz.
- `dibujar_panel()`: dibuja un panel utilizando una estructura `Panel`.
- `dibujar_elemento()`: dibuja un elemento individual y actualiza la posicion vertical.

Tambien se utiliza `obtener_color_elemento()` para determinar el color de cada elemento segun su estado de seleccion.

### 6.1. Funciones auxiliares privadas

Las funciones auxiliares que solo se utilizan dentro de un archivo pueden declararse con `static`.

Por ejemplo:

```c
static void dibujar_panel(GSGLOBAL *gsGlobal, Panel panel, u64 color);
```

Esto indica que la funcion tiene alcance interno al archivo donde fue declarada.

Como `dibujar_panel()` y `dibujar_elemento()` solo son utilizadas por `dibujar_interfaz.c`, sus declaraciones permanecen dentro de ese archivo.

En cambio, las funciones que deben estar disponibles para otros modulos se declaran en el encabezado `.h`.

### 6.2. Prototipos de funciones

Un prototipo informa al compilador sobre la existencia de una funcion, su nombre, sus parametros y su tipo de retorno.

En esta practica, los prototipos privados se colocan al inicio de `dibujar_interfaz.c`, despues de incluir el encabezado.

Esto permite utilizar las funciones antes de encontrar sus definiciones completas.

## 7. Punteros para actualizar posiciones

La funcion `dibujar_elemento()` recibe un puntero a la posicion vertical:

```c
int *pos_y
```

Esto permite modificar directamente la variable original que se encuentra en `dibujar_escena()`.

Cuando se llama a la funcion se utiliza el operador `&`:

```c
dibujar_elemento(
    gsGlobal,
    pos_x_elemento,
    &pos_y,
    ancho_elemento,
    alto_elemento,
    separacion_elementos,
    color,
    limite_inferior
);
```

El operador `&` obtiene la direccion de memoria de `pos_y`.

Dentro de la funcion, el operador `*` permite acceder al valor almacenado en esa direccion.

Por ejemplo:

```c
*pos_y += alto + separacion;
```

Esta operacion actualiza la variable original, permitiendo que la siguiente llamada utilice una nueva posicion vertical.

Sin este mecanismo, cada llamada recibiria una copia del valor y los cambios no se reflejarian en la variable original.

## 8. Distribucion automatica mediante ciclos

Cuando se necesita dibujar varios elementos con las mismas dimensiones y separacion, un ciclo permite evitar llamadas repetidas.

En esta practica se utiliza un ciclo `for`:

```c
for (int i = 0; i < cantidad_elementos; i++) {
    /* Dibujar elemento. */
}
```

La variable `i` representa el indice del elemento actual.

Esto permite determinar automaticamente si un elemento debe aparecer seleccionado.

### 8.1. Estado de seleccion

La funcion `obtener_color_elemento()` recibe un valor entero que representa el estado de seleccion:

- `1`: elemento seleccionado.
- `0`: elemento no seleccionado.

La comparacion:

```c
i == elemento_seleccionado
```

devuelve `1` cuando ambos valores coinciden y `0` cuando son diferentes.

El resultado se utiliza como argumento para determinar el color:

```c
obtener_color_elemento(i == elemento_seleccionado)
```

La paleta utilizada en esta practica es:

| Estado | Color RGBA |
|---|---|
| Seleccionado | `GS_SETREG_RGBA(37, 99, 235, 255)` |
| No seleccionado | `GS_SETREG_RGBA(51, 65, 85, 255)` |

Esto permite destacar visualmente el elemento seleccionado sin modificar la logica de posicionamiento.

## 9. Control de limites del panel

Una interfaz debe evitar que sus elementos sobrepasen el espacio disponible.

Para controlar el espacio vertical se calcula un limite inferior a partir de las propiedades del panel:

```c
int limite_inferior = panel_lateral.pos_y
    + panel_lateral.alto
    - panel_lateral.margen_inferior;
```

Con los valores actuales:

- Posicion vertical del panel: 60.
- Alto del panel: 388.
- Margen inferior: 30.

El limite inferior disponible es 418.

### 9.1. Comprobacion antes de dibujar

Antes de dibujar un elemento se calcula donde terminaria:

```c
int pos_y_final = *pos_y + alto;
```

Despues se comprueba si supera el limite:

```c
if (pos_y_final > limite_inferior) {
    return 0;
}
```

Si el elemento supera el limite, la funcion termina sin dibujarlo.

Se utiliza `>` en lugar de `>=` porque un elemento que termina exactamente en el limite todavia cabe dentro del espacio disponible.

### 9.2. Valor de retorno

La funcion `dibujar_elemento()` devuelve un entero para indicar el resultado de la operacion:

| Retorno | Significado |
|---|---|
| `1` | El elemento se dibujo correctamente. |
| `0` | El elemento no cabe dentro del espacio disponible. |

Esto permite que el ciclo principal conozca el resultado de cada intento.

### 9.3. Detener el ciclo cuando no hay espacio

La llamada a `dibujar_elemento()` se utiliza dentro de una condicion:

```c
if (!dibujar_elemento(...)) {
    break;
}
```

El operador `!` invierte el valor logico:

- Si la funcion devuelve `1`, la condicion es falsa y el ciclo continua.
- Si la funcion devuelve `0`, la condicion es verdadera y se ejecuta `break`.

De esta manera, el ciclo termina cuando el siguiente elemento ya no cabe dentro del panel.

## 10. Resultado de la practica

La practica construye una primera maqueta visual de ETN utilizando tres regiones principales:

- Una barra superior.
- Un panel lateral con elementos de navegacion.
- Un panel principal destinado al contenido.

Los elementos del panel lateral se generan automaticamente y utilizan diferentes colores segun su estado de seleccion.

Ademas, el sistema comprueba el espacio disponible antes de dibujar cada elemento.

Con la configuracion actual:

| Propiedad | Valor |
|---|---:|
| Posicion inicial Y | 90 |
| Alto de cada elemento | 50 |
| Separacion | 10 |
| Limite inferior | 418 |
| Cantidad solicitada | 10 |
| Cantidad dibujada | 5 |
| Indice seleccionado | 3 |

El resultado esperado es de cinco elementos visibles, con el cuarto destacado en azul.

La practica fue compilada y probada en una PlayStation 2 real.

## 11. Archivos de la practica

La organizacion de los archivos queda de la siguiente manera:

```text
Bloque_03_Video_e_Interfaz_Grafica/
├── Lecciones/
│   ├── Leccion_01_Sistema_Grafico_de_PS2.md
│   ├── Leccion_02_Inicializacion_Grafica_y_Dibujo_Basico.md
│   └── Leccion_03_Coordenadas_y_Composicion_de_Interfaz.md
└── Practicas/
    ├── Leccion_02_Inicializacion_Grafica_y_Dibujo_Basico/
    │   ├── main.c
    │   └── Makefile
    └── Leccion_03_Coordenadas_y_Composicion_de_Interfaz/
        ├── main.c
        ├── dibujar_interfaz.c
        ├── dibujar_interfaz.h
        └── Makefile
```

## 12. Conexion con ETN

Los conocimientos de esta leccion representan una primera base para construir la interfaz grafica de ELFtation Navigator.

La distribucion mediante paneles permite organizar futuras regiones de navegacion y contenido.

La modularizacion facilita separar las responsabilidades graficas en diferentes archivos, mientras que el control de limites permite administrar el espacio disponible para los elementos.

Estos principios se podran ampliar posteriormente para incorporar:

- Elementos de navegacion interactivos.
- Indicadores de seleccion.
- Listados de archivos y directorios.
- Informacion contextual.
- Paneles con contenido dinamico.

La maqueta visual constituye una base inicial sobre la cual se desarrollara progresivamente la interfaz de ETN.