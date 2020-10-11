#include <stdio.h>

/**
 * –– INSTRUCCIONES ––
 * 
 * 1) Compila el código y observa el error de compilación
 * 
 * 2) Crea una función  valorAbsoluto() que reciba un int
 *    y regrese un unsigned int, con el valor absoluto
 * 
 * 3) Compara contra el resultado esperado.
 */

int main()
{
    printf("--[ Salida esperada ]--\n");
    printf("valorAbsoluto(5)    = 5\n");
    printf("valorAbsoluto(-3)   = 3\n");
    printf("valorAbsoluto(42)   = 42\n");
    printf("valorAbsoluto(-123) = 123\n");
    printf("\n");

    printf("--[ Resultado obtenido ]--\n");
    printf("valorAbsoluto(5)    = %i\n", valorAbsoluto(5));
    printf("valorAbsoluto(-3)   = %i\n", valorAbsoluto(-3));
    printf("valorAbsoluto(42)   = %i\n", valorAbsoluto(42));
    printf("valorAbsoluto(-123) = %i\n", valorAbsoluto(-123));
}