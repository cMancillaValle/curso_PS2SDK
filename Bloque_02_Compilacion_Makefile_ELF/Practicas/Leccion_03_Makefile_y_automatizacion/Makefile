# Configuracion del compilador y sus opciones
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Nombre del ejecutable que queremos generar
TARGET = practica_l03

# Archivos fuente necesarios para construir el programa
SOURCES = L03_makefile_y_automatizacion.c

# Declaracion de objetivos que representan tareas
.PHONY: all clean

# Objetivo principal: construir el programa
all: $(TARGET)

# Regla para compilar el archivo fuente y generar el ejecutable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Eliminar el ejecutable generado
clean:
	rm -f $(TARGET)