#include <stdio.h>

void imprimir_arreglo(int array[], int size);
void swap(int array[], int i, int j);
int esta_ordenado(int array[], int size);
void selection_sort(int array[], int size);

int main()
{
    int array[] = {5, 2, 4, 6, 1, 3};
    imprimir_arreglo(array, 6);

    swap(array, 0, 1);
    imprimir_arreglo(array, 6);

    return 0;
}

/**
 * Imprime un arreglo de enteros.
 */
void imprimir_arreglo(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

/**
 * Ejerecicio 1: implementar la funcion swap
 *
 * Intercambia los valores de dos indices de un arreglo, modificando el arreglo original.
 */
void swap(int array[], int i, int j)
{
}

/**
 * Ejercicio 2: implementar la funcion esta_ordenado
 *
 * Determina si un arreglo de enteros esta ordenado de forma ascendente (de menor a mayor). Regresa 1 si esta ordenado, 0 en otro caso.
 */
int esta_ordenado(int array[], int size)
{
    return 0;
}

/**
 * Ejercicio 3: implementar la funcion selection_sort
 *
 * Ordena un arreglo de enteros de forma ascendente usando el algoritmo de selection sort.
 */
void selection_sort(int array[], int size)
{
    /*
    PSEUDOCÓDIGO

    n = tamaño del arreglo

    Para i de 0 a n-1
        indice_del_menor = i

        Para j de i+1 a n
            Si elemento j < elemento indice_del_menor
                indice_del_menor = j

        Si indice_del_menor != i
            Intercambiar elementos i e indice_del_menor
    
    */
}
