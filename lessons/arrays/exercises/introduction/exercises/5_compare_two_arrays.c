#include <stdio.h>

/**
 * INSTRUCCIONES
 * 
 * Implementa la funcion
 * 
 *      int compareArrays(int array[], int otherArray[], unsigned long size)
 * 
 * que reciba dos arreglos y regrese:
 *  1 si array tiene los mismos valores, en el mismo orden, que otherArray
 *  0 si no es asi
 */

int compareArrays(int array[], int otherArray[], unsigned long size)
{
    // implementa aqui tu funcion
    
    return 0;
}

int testCompareArrays(int arr1[], int arr2[], unsigned long size, int expected);
void printArrInline(int arr[], unsigned long size);

int main()
{
    int totalTests = 3;
    int passedTests = 0;

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    passedTests += testCompareArrays(arr1, arr2, 5, 1);

    int arr3[3] = {1, 2, 3};
    int arr4[3] = {3, 2, 1};
    passedTests += testCompareArrays(arr3, arr4, 3, 0);

    int arr5[1] = {3};
    int arr6[1] = {3};
    passedTests += testCompareArrays(arr5, arr6, 1, 1);

    if (passedTests == totalTests)
    {
        printf("Ejercicio completado\n");
    }
    else
    {
        printf("Algunas pruebas fallaron.\n");
    }

    return 0;
}

/**
 * Ejecuta una prueba de la funcion compareArrays, usando un arreglo y un valor esperado.
 * Escribe un mensaje en stdout con el resultado de una prueba fallida
 * 
 * @param  array[]: arreglo de prueba
 * @param  size: numero de elementos en el arreglo
 * @param  expected: valor esperado
 * 
 * @return 1 si la prueba pasó, 0 si falló.
 */
int testCompareArrays(int arr1[], int arr2[], unsigned long size, int expected)
{
    int passed = 1;
    int got = compareArrays(arr1, arr2, size);
    if (got != expected)
    {
        passed = 0;
        printf("[FAIL]:\n");
        printf("    arr1: ");
        printArrInline(arr1, size);
        printf("\n");
        printf("    arr2: ");
        printArrInline(arr2, size);
        printf("\n");
        printf("    Expected %i, but got %i instead.\n\n", expected, got);
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