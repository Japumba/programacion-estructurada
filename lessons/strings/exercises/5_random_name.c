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
 *    hacer la prueba de obtener 5 nombres aleatorios, uno después del otro.
 *    
 *    Deberían ser distintos cada vez (aunque podrían repetirse en una ejecución),
 *    ya que nuestra función de random sí podria generar dos veces el mismo número.
 */

#include <stdio.h>

unsigned int randomIntegerFromZeroUpTo(unsigned int max)
{
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