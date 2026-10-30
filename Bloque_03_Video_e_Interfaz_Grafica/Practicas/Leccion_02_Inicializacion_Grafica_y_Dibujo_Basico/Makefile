EE_CC = mips64r5900el-ps2-elf-gcc

GSKIT_INC = /usr/local/ps2dev/gsKit/include
GSKIT_LIB = /usr/local/ps2dev/gsKit/lib
PS2SDK_INC = /usr/local/ps2dev/ps2sdk/common/include

EE_CFLAGS = -D_EE -G0 -I$(GSKIT_INC) -I$(PS2SDK_INC)

# -D_EE: define la macro _EE que necesita tamtypes.h.
# -G0: desactiva el uso de la sección de datos pequeños.
# -I: indica al compilador dónde buscar los encabezados .h.

EE_LDFLAGS = -L$(GSKIT_LIB) -lgskit -ldmakit

# -L: indica dónde buscar las bibliotecas.
# -lgskit: enlaza la biblioteca GSKit.
# -ldmakit: enlaza la biblioteca DMAKit.

TARGET = main.elf

# Objetivo principal: generar el ejecutable ELF.
$(TARGET): main.c
	$(EE_CC) $(EE_CFLAGS) main.c -o $(TARGET) $(EE_LDFLAGS)

# Elimina el ejecutable generado.
clean:
	rm -f $(TARGET)

.PHONY: clean