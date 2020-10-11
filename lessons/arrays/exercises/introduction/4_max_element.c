#include <stdio.h>
#include <assert.h>

/**
 * INSTRUCCIONES
 * 
 * Este codigo declara una funcion maxElement(), 
 * que recibe un arreglo y el tamaño de dicho arreglo,
 * y debe regresar el valor del elemento mas grande
 * 
 * Implementa esta funcion.
 * 
 * Hay unas funciones abajo del main, que se usan para probar.
 * Revísalas y entiende que hacen, para que puedas hacer 
 * pruebas similares en tus propios programas.
 */

/**
 * Regresa el elemento mas grande de array
 * 
 * @param  array[]: arreglo a inspeccionar
 * @param  size: numero de elementos en el arreglo
 */
int maxElement(int array[], unsigned long size)
{
    // IMPLEMENTA AQUI TU FUNCION
    return 42;
}

int testMaxElement(int array[], unsigned long size, int expected);
void printArrInline(int arr[], unsigned long size);

int main()
{
    int testCount = 3;
    int passedTests = 0;

    int test1[6] = {1, 7, -288, 198, 5081, 7};
    passedTests += testMaxElement(test1, 6, 5081);

    int test2[10] = {6, 5, 2, 7, 9, 4, 8, 9, 4, 2};
    passedTests += testMaxElement(test2, 10, 9);

    int test3[3] = {-10, -20, -30};
    passedTests += testMaxElement(test3, 3, -10);

    if (passedTests == testCount)
        printf("Ejercicio terminado correctamente!\n");
    else
        printf("Ejercicio con errores :(\n");

    return 0;
}

/**
 * Ejecuta una prueba de la funcion maxElement, usando un arreglo y un valor esperado.
 * Escribe un mensaje en stdout con el resultado de una prueba fallida
 * 
 * @param  array[]: arreglo de prueba
 * @param  size: numero de elementos en el arreglo
 * @param  expected: valor esperado
 * 
 * @return 1 si la prueba pasó, 0 si falló.
 */
int testMaxElement(int array[], unsigned long size, int expected)
{
    int passed = 1;
    int got = maxElement(array, size);
    if (got != expected)
    {
        passed = 0;
        printf("[FAIL]:\n");
        printf("    maxElement ");
        printArrInline(array, size);
        printf(" expected %i, but got %i instead\n\n", expected, got);
    }

    return passed;
}

/**
 * Imprime un arreglo en formato: [a, b, c, d, e] sin saltos de linea.
 * 
 * @param  array[]: arreglo a imprimir
 * @param  size: numero de elementos en el arreglo
 */
void printArrInline(int arr[], unsigned long size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%i", arr[i]);

        if (i < size - 1)
            printf(", ");
    }
    printf("]");
}