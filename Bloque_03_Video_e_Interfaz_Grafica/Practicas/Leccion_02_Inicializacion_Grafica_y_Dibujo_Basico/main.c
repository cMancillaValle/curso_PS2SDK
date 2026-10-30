#include <gsKit.h>

/* Prototipo de la función encargada de preparar la escena. */
void dibujar_escena(GSGLOBAL *gsGlobal);

int main(void) {
    /* Inicializa la estructura global de GSKit. */
    GSGLOBAL *gsGlobal = gsKit_init_global();

    /* Comprueba que la inicialización haya sido correcta. */
    if (gsGlobal == NULL) {
        return 1;
    }

    /* Inicializa el entorno gráfico y configura la pantalla. */
    gsKit_init_screen(gsGlobal);

    /* Ciclo principal de dibujo. */
    while (1) {
        /* Prepara las operaciones gráficas de la escena. */
        dibujar_escena(gsGlobal);

        /* Ejecuta las operaciones almacenadas en la cola gráfica. */
        gsKit_queue_exec(gsGlobal);

        /* Espera la sincronización vertical y cambia los buffers. */
        gsKit_sync_flip(gsGlobal);
    }

    return 0;
}

/* Prepara el fondo y el rectángulo de la escena. */
void dibujar_escena(GSGLOBAL *gsGlobal) {
    /* Limpia el buffer con un fondo azul. */
    gsKit_clear(gsGlobal, GS_SETREG_RGBA(0, 0, 255, 255));

    /* Dibuja un rectángulo blanco mediante una primitiva sprite. */
    gsKit_prim_sprite(
        gsGlobal,
        100, 80,
        300, 180,
        0,
        GS_SETREG_RGBA(255, 255, 255, 255)
    );
}