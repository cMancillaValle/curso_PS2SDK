# Lección 01: Funciones en C

## 1. Objetivo

Comprender cómo funcionan las funciones en C, cómo se declaran,
cómo reciben parámetros y cómo devuelven resultados.

Además, aprender a dividir un programa en responsabilidades
independientes para facilitar su organización y mantenimiento.

## 2. ¿Qué es una función?

Una función es un bloque de código que realiza una tarea
específica y que puede ejecutarse cuando se la llama.

Las funciones permiten dividir un programa grande en partes
más pequeñas, organizadas y reutilizables.

En lugar de escribir todo el código dentro de `main()`,
podemos distribuir las responsabilidades entre distintas
funciones.

## 3. Estructura de una función

Una función puede tener la siguiente estructura:

```c
int sumar(int a, int b) {
    return a + b;
}