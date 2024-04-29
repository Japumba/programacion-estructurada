#include <stdio.h>

typedef struct
{
    int n;
    int expected;
} TestCase;

#define TEST_COUNT 15

int sumatoria_hasta_n(int n);

int main()
{
    TestCase tests[TEST_COUNT] = {
        {.n = 0, .expected = 0},
        {.n = 1, .expected = 1},
        {.n = 2, .expected = 3},
        {.n = 3, .expected = 6},
        {.n = 4, .expected = 10},
        {.n = 5, .expected = 15},
        {.n = 6, .expected = 21},
        {.n = 7, .expected = 28},
        {.n = 8, .expected = 36},
        {.n = 9, .expected = 45},
        {.n = 10, .expected = 55},
        {.n = 11, .expected = 66},
        {.n = 12, .expected = 78},
        {.n = 13, .expected = 91},
        {.n = 14, .expected = 105}
    };

    for (int i = 0; i < TEST_COUNT; i++)
    {
        printf("TEST[%d]: ", i);
        int result = sumatoria_hasta_n(tests[i].n);

        if (result != tests[i].expected)
        {
            printf("❌ FAILED: expected sumatoria_hasta_n(%d) to be %d but got %d instead.\n", tests[i].n, tests[i].expected, result);
        }
        else
        {
            printf("✅ PASSED.\n");
        }
    }
}

int sumatoria_hasta_n(int n)
{
    /* Implementa aqui tu función */
    return 1;
}