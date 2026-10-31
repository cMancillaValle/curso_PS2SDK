#include "dibujar_interfaz.h"

/* Define la estructura que almacena la posicion, dimensiones y margenes de cada panel. */
typedef struct {
    int pos_x;
    int pos_y;
    int ancho;
    int alto;
    int margen_horizontal;
    int margen_superior;
} Panel;

/* Prototipos de funciones auxiliares privadas del modulo. */

/* Dibuja un elemento y actualiza la posicion vertical para el siguiente. */
static void dibujar_elemento(GSGLOBAL *gsGlobal,
    int pos_x, int *pos_y,
    int ancho, int alto,
    int separacion, u64 color
);

/* Dibuja un panel utilizando su posicion, dimensiones y color. */
static void dibujar_panel(GSGLOBAL *gsGlobal, Panel panel, u64 color);

/* Organiza y prepara los elementos que componen la interfaz grafica. */
void dibujar_escena(GSGLOBAL *gsGlobal) {

    /* Limpia el buffer grafico con el color de fondo inicial. */
    gsKit_clear(gsGlobal, GS_SETREG_RGBA(0, 0, 255, 255));

    /* Define la distribucion y las dimensiones de los paneles de la interfaz. */
    Panel panel_superior = {0, 0, 640, 60, 10, 15};
    Panel panel_lateral = {0, 60, 180, 388, 20, 30};
    Panel panel_principal = {180, 60, 460, 388, 15, 20};

    /* Dibuja la barra superior con su color correspondiente. */
    dibujar_panel(gsGlobal, panel_superior, GS_SETREG_RGBA(18, 24, 38, 255));

    /* Dibuja el panel lateral que contiene los elementos de navegacion. */
    dibujar_panel(gsGlobal, panel_lateral, GS_SETREG_RGBA(30, 41, 59, 255));

    /* Dibuja el panel principal destinado al contenido de la interfaz. */
    dibujar_panel(gsGlobal, panel_principal, GS_SETREG_RGBA(15, 23, 42, 255));

    /* Calcula la posicion inicial y el ancho de los elementos dentro del panel lateral. */
    int pos_x_elemento = panel_lateral.pos_x + panel_lateral.margen_horizontal;
    int pos_y = panel_lateral.pos_y + panel_lateral.margen_superior;
    int ancho_elemento = panel_lateral.ancho - (panel_lateral.margen_horizontal * 2);

    /* Define las dimensiones, separacion y cantidad de elementos que se dibujaran. */
    int alto_elemento = 50;
    int separacion_elementos = 10;
    int cantidad_elementos = 5;

    /* Establece el indice del elemento que aparecera seleccionado. */
    int elemento_seleccionado = 3;

    /* Recorre los elementos y determina su color segun su estado de seleccion. */
    for (int i = 0; i < cantidad_elementos; i++) {
        dibujar_elemento(gsGlobal,
            pos_x_elemento, &pos_y, ancho_elemento,
            alto_elemento, separacion_elementos,
            obtener_color_elemento(i == elemento_seleccionado)
        );
    }
}

/* Dibuja un elemento y actualiza la posicion vertical para mantener la separacion. */
static void dibujar_elemento(GSGLOBAL *gsGlobal, int pos_x, int *pos_y,
    int ancho, int alto, int separacion, u64 color) {

    /* Dibuja el elemento utilizando sus coordenadas, dimensiones y color. */
    gsKit_prim_sprite(
        gsGlobal,
        pos_x, *pos_y,
        pos_x + ancho, *pos_y + alto,
        0,
        color
    );

    /* Avanza la posicion vertical segun la altura del elemento y su separacion. */
    *pos_y += alto + separacion;
}

/* Devuelve el color correspondiente al estado de seleccion del elemento. */
u64 obtener_color_elemento(int seleccionado) {

    /* Utiliza el azul electrico para destacar el elemento seleccionado. */
    if (seleccionado == 1) {
        return GS_SETREG_RGBA(37, 99, 235, 255);
    }

    /* Utiliza un tono gris azulado para los elementos no seleccionados. */
    return GS_SETREG_RGBA(51, 65, 85, 255);
}

/* Dibuja un panel utilizando las propiedades almacenadas en su estructura. */
static void dibujar_panel(GSGLOBAL *gsGlobal, Panel panel, u64 color) {

    /* Calcula las coordenadas finales a partir de la posicion y dimensiones del panel. */
    gsKit_prim_sprite(
        gsGlobal,
        panel.pos_x, panel.pos_y,
        panel.pos_x + panel.ancho, panel.pos_y + panel.alto,
        0,
        color
    );
}