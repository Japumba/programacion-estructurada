#include <stdio.h>
#include <assert.h>

/**
 * Declaración de auxiliares para el ejercicio
 */

/**
 * Enumeración auxiliar para el ejercicio.
 * 
 * Enumeracion con los resultados posibles de una prueba, para ser
 * más claros con los resultados esperados
 */
enum TestResult
{
    FAILED = 0,
    PASSED = 1
};

enum TestResult testStringLengthIs(char string[], unsigned int expectedLength);

/**
 * INSTRUCCIONES:
 * 1. Sin usar las funciones de la librería string.h, implementa una función
 *    que cuente la cantidad de caracteres dentro de un string terminado en 
 *    nulo, y la regrese como su longitud.
 * 
 * 2. Asegúrate que al ejecutarse tu programa todos los casos de prueba pasan exitosamente.
 *    El programa debe mostrar solamente el mensaje: Ejercicio terminado con éxito.
 */

/**
 * Calcula la longitud del string terminado en nulo especificado y la regresa.
 */
unsigned int stringLength(char string[])
{
    /* Implementa aquí tu función */
    return 42;
}

int main()
{
    assert(testStringLengthIs("Nanuk!", 6) == PASSED);
    assert(testStringLengthIs("hola que tal", 12) == PASSED);
    assert(testStringLengthIs("\n\n\n", 3) == PASSED);
    assert(testStringLengthIs("", 0) == PASSED);
    assert(testStringLengthIs("\0", 0) == PASSED);

    printf("OK! Funcion implementada correctamente\n");
}

/**
 * IMPLEMENTACION DE FUNCIONES DE PRUEBA
 */


/**
 * Función auxiliar para el ejercicio.
 * 
 * Prueba la funcion stringLength con el string especificado y comapara
 * el resultado con la longitud esperada que se indique.
 * 
 * Regresa el resultado de la prueba
 */
enum TestResult testStringLengthIs(char string[], unsigned int expectedLength)
{
    unsigned int got = stringLength(string);

    if (got != expectedLength)
    {
        printf("FAIL:\n    stringLength( %s ): expected %i but got %i instead\n", string, expectedLength, got);
        return FAILED;
    }

    return PASSED;
}
