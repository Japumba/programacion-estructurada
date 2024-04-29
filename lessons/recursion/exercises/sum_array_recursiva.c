#include <stdio.h>

#define MAX_SIZE 10

typedef struct
{
    int arr_size;
    int arr[MAX_SIZE];
    int expected;
} TestCase;

#define TEST_COUNT 5

void imprimir_arreglo(int array[], int size);
int sum_array_recursiva(int array[], int size);

int main()
{
    TestCase tests[TEST_COUNT] = {
        {.arr_size = 1, .arr = {1}, .expected = 1},
        {.arr_size = 1, .arr = {7}, .expected = 7},
        {.arr_size = 2, .arr = {3, 2}, .expected = 5},
        {.arr_size = 3, .arr = {-1, -2, -3}, .expected = -6},
        {.arr_size = 5, .arr = {0, 0, 0, 0, 0}, .expected = 0}
    };

    for (int i = 0; i < TEST_COUNT; i++)
    {
        printf("TEST[%d]: ", i);
        int result = sum_array_recursiva(tests[i].arr, tests[i].arr_size);

        if (result != tests[i].expected)
        {
            printf("❌ FAILED: expected sum_array_recursiva of ");
            imprimir_arreglo(tests[i].arr, tests[i].arr_size);
            printf(" to be %d, but got %d instead.\n", tests[i].expected, result);
        }
        else
        {
            printf("✅ PASSED.\n");
        }
    }
}

int sum_array_recursiva(int array[], int size)
{
    /* Implementa aqui tu función */
    return 1;
}

void imprimir_arreglo(int array[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);

        if (i < size - 1)
        {
            printf(", ");
        }
    }

    printf("]");
}