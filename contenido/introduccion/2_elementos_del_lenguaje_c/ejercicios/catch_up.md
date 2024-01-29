# Ejercicios varios para catch up
Hemos visto varias cosas hasta hoy.
    - Programa mínimo en C
    - Variables y tipos de datos
    - Modificadores de tipos de datos
    - Impresión de variables

Como ejercicio antes de continuar con el siguiente tema, reselve estos simples problemas:

## Tamaños de variables

### Tabla de tamaños
Escribe un programa que imprima los tipos de datos primitivos y sus tamaños en bytes en una tabla. El programa debe imprimir algo como esto:

```bash
Tipo de dato | Tamaño en bytes
char         | 1    
short        | 2
int          | 4
long         | 8
long long    | 8
```

### Mejorar el uso de memoria
Estas variables están todas declaradas con int y no se imprime muy bien.
- ¿Podrías mejorar el uso de memoria del programa anterior?
- ¿Cómo arreglarías las etiquetas de impresión?

Tip: recuerda que `char` también puede representar números enteros y ser `unsigned` y `signed`.

```c
#include <stdio.h>

void detalle_de_moto();

int main() {
    detalle_de_moto();
}

void detalle_de_moto() {
    int modelo = 2022;
    double hp = 24.5;
    int rpm_max_hp = 6500;
    int cilindrada_c_c = 411;

    int asientos = 2;

    printf("La RE Himalayan %d es una moto de %d c.c. y %d caballos de poder a %d revoluciones por minuto.\n",
            modelo, cilindrada, hp, rpm_max_hp);
}

```
