#include <stdio.h>

int digital_root(int n);

typedef struct
{
    int n, expected;
} TestCase;

#define TEST_COUNT 9

int main()
{
    TestCase tests[TEST_COUNT] = {
        {.n = 16, .expected = 7},
        {.n = 942, .expected = 6},
        {.n = 132189, .expected = 6},
        {.n = 493193, .expected = 2},
        {.n = 167346, .expected = 9},
        {.n = 0, .expected = 0},
        {.n = 7, .expected = 7},
        {.n = 195, .expected = 6},
        {.n = 992, .expected = 2}};

    for (int i = 0; i < TEST_COUNT; i++)
    {
        printf("TEST[%d]: ", i);

        int result = digital_root(tests[i].n);

        if (result != tests[i].expected)
        {
            printf("❌ FAILED: expected digital_root(%d) to be %i but got %i instead.\n", tests[i].n, tests[i].expected, result);
        }
        else
        {
            printf("✅ PASSED.\n");
        }
    }
}

int digital_root(int n)
{
    /* Implementa aqui tu función */
    return 42;
}