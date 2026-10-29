# Configuracion del compilador nativo
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Nombre del ejecutable de la practica
TARGET = practica_l04

# Archivos fuente necesarios para construir el programa
SOURCES = L04_generacion_de_elf.c

# Declaracion de objetivos que representan tareas
.PHONY: all clean

# Objetivo principal
all: $(TARGET)

# Regla para compilar y enlazar el programa
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Eliminar el ejecutable generado
clean:
	rm -f $(TARGET)