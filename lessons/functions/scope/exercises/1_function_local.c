#include <stdio.h>

/*  LEE LAS INSTRUCCIONES COMPLETAS ANTES DE EJECUTAR ESTE PROGRAMA.
    
    1) Observa con detenimiento este código.
    2) Escribe en un comentario el output que esperas ver en la consola.
    3) Compila y ejecuta el programa.
    4) Compara tus predicciones con el resultado
    5) Explica con tus palabras por qué sucede esto.

    MIS PREDICCIONES:
    |-------------------|
    | OUTPUT ESPERADO   |
    |-------------------|
    |                   |
    |                   |
    |                   |
    |                   |
    |                   |
    |===================|
*/

void foo(int a)
{
    // which value does a have on each execution?
    // is the a in the main function modified?
    a = a + 10;
    printf("inside foo: %d\n", a);
}

void bar(int a)
{
    // which value does a have on each execution?
    // is the a in the main function modified?
    a = 0;
    printf("inside bar: %d\n", a);
}

int main()
{
    // is this value modified?
    int a = 10;
    printf("first time: %d\n", a);
    foo(a);
    printf("after foo:  %d\n", a);
    bar(a);
    printf("after bar:  %d\n", a);
}