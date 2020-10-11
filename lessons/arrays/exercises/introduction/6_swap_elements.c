#include <stdio.h>
#include <assert.h>

/**
 * INSTRUCCIONES
 * 
 * Este codigo declara una funcion swapElements(),
 * que recibe un arreglo y dos indices, y debe
 * intercambiar los valores en esos indices de lugar.
 * 
 * Solo se deben cambiar los elementos sin ambos indices estan
 * dentro del rango del arreglo.
 * 
 * Implementa esta funcion.
 * 
 * 
 * Observa la funcion de testSwapElements:
 *   utilizamos la funcion del ejercicio 4, "compare two arrays",
 *   en lugar de solo comparar los elementos cambiados.
 * 
 *   Con esto, nos aseguramos que solamente los elementos deseados
 *   se intercambien.
 */

/**
 * Intercambia los elementos si ambos indices estan dentro del rango
 * del array
 * 
 * @param  array[]: arreglo a inspeccionar
 * @param  size: numero de elementos en el arreglo
 * @param  index1: indice del primer elemento a cambiar
 * @param  index2: indice del otro elemento a cambiar
 */
void swapElements(int array[], unsigned long size, int index1, int index2)
{
    // IMPLEMENTA AQUI TU FUNCION
    return;
}

int testswapElements(int array[], int expectedArray[], unsigned long size, int index1, int index2, int expected);
void printArrInline(int arr[], unsigned long size);
int compareArrays(int array[], int otherArray[], unsigned long size);

int main()
{
    int testCount = 2;
    int passedTests = 0;

    int test1[6] = {1, 7, -288, 198, 5081, 7};
    int index1 = 0;
    int index2 = 2;
    int expectedResult = 1;
    int expectedArray1[6] = {-288, 7, 1, 198, 5081, 7};
    passedTests += testswapElements(test1, expectedArray1, 6, index1, index2, expectedResult);

    int test2[10] = {6, 5, 2, 7, 9, 4, 8, 9, 4, 2};
    index1 = -1;
    index2 = 5;
    expectedResult = 0;
    int expectedArray2[10] = {6, 5, 2, 7, 9, 4, 8, 9, 4, 2};
    passedTests += testswapElements(test2, expectedArray2, 10, index1, index2, expectedResult);

    int test3[2] = {5, 10};
    index1 = 0;
    index2 = 1;
    expectedResult = 1;
    int expectedArray3[2] = {10, 5};
    passedTests += testswapElements(test3, expectedArray3, 2, index1, index2, expectedResult);

    if (passedTests == testCount)
        printf("Ejercicio terminado correctamente!\n");
    else
        printf("Ejercicio con errores :(\n");

    return 0;
}

/**
 * Ejecuta una prueba de la funcion swapElements, usando un arreglo y un valor esperado.
 * Escribe un mensaje en stdout con el resultado de una prueba fallida
 * 
 * @param  array[]: arreglo de prueba
 * @param  size: numero de elementos en el arreglo
 * @param  expected: valor esperado
 * 
 * @return 1 si la prueba pasó, 0 si falló.
 */
int testswapElements(int array[], int expectedArray[], unsigned long size, int index1, int index2, int expected)
{
    int passed = 1;
    swapElements(array, size, index1, index2);
    int arrayIsExpected = compareArrays(array, expectedArray, size);
    if (!arrayIsExpected)
    {
        passed = 0;
        printf("[FAIL]:\n");
        printf("    swapElements ( ");
        printArrInline(array, size);
        printf(" %i, %i)\n", index1, index2);
        printf("    expected to be ");
        printArrInline(expectedArray, size);
        printf("\n");
        printf("    but was        ");
        printArrInline(array, size);
        printf(" instead\n\n");
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

int compareArrays(int array[], int otherArray[], unsigned long size)
{
    int areEqual = 1;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] != otherArray[i])
            areEqual = 0;
    }

    return areEqual;
}