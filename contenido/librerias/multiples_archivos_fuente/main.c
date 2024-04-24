#include <stdio.h>
#include "operaciones.h"

// 2) Funcion main
int main() {
    int a = 5;
    int b = 3;

    printf("La suma de  %d y %d es %d\n", a, b, sumar(a, b));
    printf("La resta de %d y %d es %d\n", a, b, restar(a, b));

    return 0;
}