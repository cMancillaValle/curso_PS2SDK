#include <gsKit.h>
#include "dibujar_interfaz.h"

/* Punto de entrada del programa. */
int main(void) {
    /* Inicializa la estructura global que administra el entorno grafico de GSKit. */
    GSGLOBAL *gsGlobal = gsKit_init_global();

    /* Comprueba que la inicializacion haya sido correcta antes de continuar. */
    if (gsGlobal == NULL) {
        return 1;
    }

    /* Inicializa el entorno grafico y configura la pantalla para dibujar. */
    gsKit_init_screen(gsGlobal);

    /* Ciclo principal del programa: mantiene la interfaz en pantalla. */
    while (1) {
        /* Prepara los elementos que componen la escena actual. */
        dibujar_escena(gsGlobal);

        /* Ejecuta las operaciones graficas almacenadas en la cola de GSKit. */
        gsKit_queue_exec(gsGlobal);

        /* Espera la sincronizacion vertical y realiza el cambio de buffers. */
        gsKit_sync_flip(gsGlobal);
    }

    return 0;
}