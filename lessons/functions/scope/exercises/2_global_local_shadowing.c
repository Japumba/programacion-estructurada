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

int foo(int);
int bar();
void baz();

// Globally defined a.
// Every function has access to this variable
int a = 5;

int main()
{
    // which a is this?
    printf("%d\n", a);
    a = foo(a);
    printf("%d\n", a);
}

// Declares an argument with the same name as a
// which value will it have on each execution?
int foo(int a)
{
    baz();
    printf("%d\n", a);
    return a + bar();
}

int bar()
{
    // Declares a local variable with the same name as a
    // which value will it have on each execution?
    // is the global variable modified?
    int a = 42;
    printf("%d\n", a);
    return a;
}

void baz()
{
    // which a is it modifying?
    // is the global definition modified?
    a = 10;
    printf("%d\n", a);
}