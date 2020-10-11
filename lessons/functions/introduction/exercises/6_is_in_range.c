#include <stdio.h>

/**
 * –– INSTRUCCIONES ––
 *
 * 1) Ejecuta el código y compara lo esperado contra lo obtenido.
 * 
 * 2) Modifica el código de la funcion isInRange() para corregir el error
 * 
 * 3) Ya corregido, modifica nuevamente el código de la función para que sea una sola línea
 *    tip: recuerda qué valor generan los operadores lógicos y relacionales.
 */

/** Valida si un número dado está en el rango [min, max] inclusivo.
 *
 * @param int number:   numero que se quiere evaluar
 * @param int min:      valor mínimo, inclusivo
 * @param int max:      valor máximo, inclusivo
 *
 * @returns 1 si numero está en el rango, 0 si no.
 */
int isInRange(int number, int min, int max)
{
    int value;

    if (number >= min && number <= max)
        value = 0;
    else
        value = 1;

    return value;
}

int main()
{
    int min = 0, max = 10;

    int two = 2;
    int five = 5;
    int minusFour = -4;
    int ten = 10;

    printf("--[ Salida esperada ]--\n");
    printf("is %i in range [%i, %i]? 1\n", two, min, max);
    printf("is %i in range [%i, %i]? 1\n", five, min, max);
    printf("is %i in range [%i, %i]? 0\n", minusFour, min, max);
    printf("is %i in range [%i, %i]? 1\n", ten, min, max);
    printf("\n");

    printf("--[ Resultado obtenido ]--\n");
    printf("is %i  in range [%i, %i]? %i\n", two, min, max, isInRange(two, min, max));
    printf("is %i  in range [%i, %i]? %i\n", five, min, max, isInRange(five, min, max));
    printf("is %i in range [%i, %i]? %i\n", minusFour, min, max, isInRange(minusFour, min, max));
    printf("is %i in range [%i, %i]? %i\n", ten, min, max, isInRange(ten, min, max));
}