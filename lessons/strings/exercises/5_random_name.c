/**
 * INTRODUCTION:
 * Cuando el profesor quiere preguntarle a alguien en el salon, de forma aleatoria
 * queremos que use un programa para que sea realmente aleatorio y no le pregunte
 * siempre a los mismos.
 * 
 * INSTRUCCIONES:
 * 1. Crea una lista de nombres, con al menos 5.
 *    Cada nombre de la lista que pueda tener máximo 20 letras.
 * 
 * 2. Investiga cómo obtener un número aleatorio en C dentro de un rango,
 *    asegurándote que sea distinto cada ejecución del programa.
 * 
 *    Tal vez tengas que incluir otras librerías.
 * 
 * 3. Implementa la función
 *    unsigned int randomIntegerFromZeroUpTo(unsigned int max);
 * 
 *    que devuelva un numero entre 0 y el numero especificado, incluyéndolo.
 *    
 *    Necesitamos que sea dentro del rango para poder usarlo como el índice
 *    de la lista de nombres.
 * 
 * 4. Utiliza la función del paso 3 para obtener un numero aleatorio
 *    dentro del rango correcto (nombres de la lista) y, en un ciclo for,
 *    usarlo como indice del arreglo de nombres para 
 *    hacer la prueba de obtener 5 nombres aleatorios, uno después del otro.
 *    
 *    Deberían ser aleatorios, y si ejecutas el programa dos veces, deberian
 *    ser en un orden tambien diferente.
 * 
 *    Puede que en una sola ejecución se repita un nombre, es normal porque
 *    nuestra función randomIntegerFromZeroUpTo() sí puede dar dos veces el mismo
 *    (¡es aleatorio!)
 */

#include <stdio.h>

unsigned int randomIntegerFromZeroUpTo(unsigned int max)
{
    /**
     * EJERCICIO 2:
     * Escribe en este comentario los recursos que consultaste para saber
     * cómo obtener números aleatorios en C.
     * 
     * – 
     * – 
     * – 
     */

    /**
     * EJERCICIO 3:
     * Implementa la función que regrese un número aleatorio entre 0 y max, incluyendo max.
     */
    return 42;
}

int main()
{
    /**
     * EJERCICIO 1:
     * Declara el arreglo de nombres e inicialízalo con al menos 10.
     */

    /**
     * EJERCICIO 4:
     * Pon aquí tu ciclo for para obtener 5 veces un nombre aleatorio e imprimirlo.
     */

    return 0;
}