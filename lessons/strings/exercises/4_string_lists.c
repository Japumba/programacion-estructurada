/**
 * INTRODUCTION:
 * Sabemos que una matriz es un arreglo de arreglos:
 * – todos los elementos tienen el mismo tipo de dato.
 * – la primer dimensión (filas) determina cuántos arreglos contiene el arreglo.
 * – la seguna dimensión (columnas) determina cuántos elementos contiene cada arreglo.
 * 
 * También sabemos que un string es una secuencia de caracteres terminada en caracter nulo ('\0')
 * y que está contenida en un arreglo de caracteres.
 * 
 * Entonces, podríamos usar una matriz de caracteres para almacenar una lista de palabras!
 * 
 * char lines[100][50]; // 100 strings, cada uno de 49 letras máximo.
 * 
 * y podemos realizar algoritmos con estas "listas de strings".
 * 
 * INSTRUCCIONES:
 * Queremos escribir el poema cantado por Gandalf,
 * cuando llega a la comarca en la primera de las famosas películas de
 * "El señor de los anillos": la comunidad del anillo.
 * 
 * Puedes escuchar su canción aquí: https://www.youtube.com/watch?v=1AhkEi3PAWM
 * 
 * 1. Crea una variable poem, que pueda contener todo el poema de Gandalf
 * 
 * 2. Inicializa la variable con todas las líneas del poema. Haz esto en el mismo
 *    momento en que se declara la variable.
 * 
 * 3. Codifica un ciclo for (sólo uno, sin anidar), que imprima el poema.
 * 
 * 4. Limpieza de código! Crea una función printStringList() que reciba la lista
 *    de strings y la imprima.
 *    
 *    Queremos que reciba una lista de strings que:
 *      – pueda contener una cantidad variable de líneas
 *      – cada línea tenga máximo 49 letras.
 *    
 * 5. Sustituye el for() del paso 3 con una llamada a tu función, pasándole los
 *    datos adecuados para que se imprima el poema.
 * 
 * Al final, tu función main debería verse algo así:
 * 
 * int main()
 * {
 *     << declaración e inicialización del poema >>
 * 
 *     printExpectedResults();
 * 
 *     printf("Tu poema:\n\n");
 *     
 *     << llamada a tu funcion para imprimir poema >>
 *     
 *     return 0;
 * }
 */
#include <stdio.h>

void printExpectedResults();
/**
 * EJERCICIO 4:
 * Crea aquí la función para imprimir una lista de strings.
 * recuerda que debe recibir la lista de strings, y no regresar nada.
 *    
 * Queremos que reciba una lista de strings que:
 *   – pueda contener una cantidad variable de líneas
 *   – cada línea tenga máximo 49 letras.
 */

int main()
{
    printExpectedResults();
    /**
     * EJERCICIO 1 y 2:
     * Crea aquí tu variable que contenga el poema.
     * 
     * Inicialízala aquí mismo con el poema
     */

    printf("Tu poema:\n\n");
    /**
     * EJERCICIO 3:
     * Escribe aquí el ciclo for para imprimir el poema
     */

    /**
     * EJERCICIO 5:
     * Borra el for que hiciste en el paso 3
     * y sustitúyelo por una llamada a tu función.
     */

    return 0;
}

void printExpectedResults()
{
    printf("El poema debe verse de esta forma:\n\n");

    printf("The Road goes ever on and on,\n");
    printf("Down from the door where it began.\n");
    printf("Now far ahead the Road has gone,\n");
    printf("And I must follow, if I can,\n");
    printf("Pursuing it with eager feet,\n");
    printf("Until it joins some larger way\n");
    printf("Where many paths and errands meet.\n");
    printf("And whither then? I cannot say.\n\n");
}