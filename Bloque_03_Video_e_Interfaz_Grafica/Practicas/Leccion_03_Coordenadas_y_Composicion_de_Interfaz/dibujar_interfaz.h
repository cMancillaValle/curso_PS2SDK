#ifndef DIBUJAR_INTERFAZ_H
#define DIBUJAR_INTERFAZ_H

#include <gsKit.h>

/* Prepara y dibuja los elementos que componen la interfaz. */
void dibujar_escena(GSGLOBAL *gsGlobal);

/* Devuelve el color correspondiente al estado de seleccion de un elemento. */
u64 obtener_color_elemento(int seleccionado);

#endif