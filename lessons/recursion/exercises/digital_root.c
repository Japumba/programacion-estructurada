#include <stdio.h>

int digital_root(int n)
{
    /* Implementa aqui tu funcion */
    return 42;
}

typedef struct
{
    int N, Expected;
} TestCase;
#define TEST_COUNT 9

int main()
{
    TestCase tests[TEST_COUNT] = {
        {16, 7},
        {942, 6},
        {132189, 6},
        {493193, 2},
        {167346, 9},
        {0, 0},
        {7, 7},
        {195, 6},
        {992, 2}};

    int passedTests = 0;
    for (size_t i = 0; i < TEST_COUNT; i++)
    {
        TestCase test = tests[i];
        int result = digital_root(test.N);

        if (result == test.Expected)
        {
            passedTests++;
        }
        else
        {
            printf("Test {%i} FAIL:\n    Expected %i but got %i instead\n\n", test.N, test.Expected, result);
        }
    }

    if (passedTests == TEST_COUNT)
    {
        printf("OK! All tests passed.\n");
    }
}