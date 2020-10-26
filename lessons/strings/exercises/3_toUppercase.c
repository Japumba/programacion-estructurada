#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

/**
 * Declaración de funciones auxiliares para el ejercicio
 */

void testToUpper(char src[], char expectedResult[]);

/**
 * INSTRUCCIONES:
 * Aclaraciones:
 *   – Para este ejercicio NO puedes usar las funciones de las librerías string.h ni ctypes.h,
 *     ni otras funciones que hagan por ti el "transformar a mayusculas."
 * 
 * 1. Define una función toUpper() que reciba dos cadenas de texto, src y dest. Esta función no
 *    debe regresar ningún valor de retorno.
 * 
 * 2. Implementa un algoritmo para esta función que COPIE el string de src a dest, pero cambiando
 *    todas sus letras de minúscula a mayúscula.
 * 
 *    Nota: cada caracter de src que no sea una letra (e.g. un espacio o un punto), se copia sin
 *          modificarse.
 * 
 * 3. Asegúrate que al ejecutarse tu programa todos los casos de prueba pasan exitosamente.
 *    El programa debe mostrar solamente el mensaje: OK! Funcion implementada correctamente.
 */

/**
 * Implementa aquí tu función toUpper:
 */



int main()
{
    testToUpper("abc", "ABC");
    testToUpper("Nanuk!", "NANUK!");
    testToUpper("todo menos espacios en mayusculas", "TODO MENOS ESPACIOS EN MAYUSCULAS");
    testToUpper("", "");
    testToUpper("12345", "12345");
    testToUpper("1ee7", "1EE7");

    printf("OK! Funcion implementada correctamente\n");

    return 0;
}

/**
 * IMPLEMENTACIÓN DE FUNCIONES AUXILIARES
 */

/**
 * Definición auxiliar para el ejercio, para declarar la cadena auxiliar de las pruebas
 */
#define MAX_TEST_LENGTH 100

/**
 * Función auxiliar para el ejercicio
 * 
 * Ejecuta tu función toUpper() sobre la cadea src[], y compara el
 * resultado contra expected[].
 * 
 * Para la prueba, usamos un string auxiliar que reciba el resultado
 * de la función y luego lo comparamos contra el string esperado
 * 
 * Si son iguales, la prueba pasa; si no, falla.
 */
void testToUpper(char src[], char expectedResult[])
{
    char testResultDest[MAX_TEST_LENGTH];

    toUpper(src, testResultDest);

    if (strcmp(testResultDest, expectedResult) != 0)
    {
        printf("FAIL:\n    toUpper( %s ): expected \"%s\" but got \"%s\" instead\n", src, expectedResult, testResultDest);
        exit(-1);
    }
}