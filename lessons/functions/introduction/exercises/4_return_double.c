#include <stdio.h>

/**
 * –– INSTRUCCIONES ––
 *
 * 1) Ejecuta el código y revisa el error de compilación
 * 
 * 2) Crea una función que reciba un int y regrese un int,
 *    que sea el doble del numero recibido.
 *    tip: asegurate que el nombre de la función es el mismo
 *         que el usado en el código
 */

// Escribe aquí tu función:

int main()
{
    int number = 5;
    int le_double = elDobleDe(number);

    printf("--[ Salida esperada ]--\n");
    printf("The double of 5 is 10\n");
    printf("\n");

    printf("--[ Resultado obtenido ]--\n");
    printf("The double of %i is %i\n", number, le_double);

    if (le_double != number + number)
    {
        printf("ERROR: expected %i but got %i instead.\n", number + number, le_double);
    }
}