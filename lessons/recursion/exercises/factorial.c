#include <stdio.h>

typedef struct
{
    int n;
    long long int expected;
} TestCase;

#define TEST_COUNT 15

long long int factorial(int n);

int main()
{
    TestCase tests[TEST_COUNT] = {
        {.n = 0, .expected = 1},           // 0! = 1
        {.n = 1, .expected = 1},           // 1! = 1
        {.n = 2, .expected = 2},           // 2! = 2
        {.n = 3, .expected = 6},           // 3! = 6
        {.n = 4, .expected = 24},          // 4! = 24
        {.n = 5, .expected = 120},         // 5! = 120
        {.n = 6, .expected = 720},         // 6! = 720
        {.n = 7, .expected = 5040},        // 7! = 5040
        {.n = 8, .expected = 40320},       // 8! = 40320
        {.n = 9, .expected = 362880},      // 9! = 362880
        {.n = 10, .expected = 3628800},    // 10! = 3628800
        {.n = 11, .expected = 39916800},   // 11! = 39916800
        {.n = 12, .expected = 479001600},  // 12! = 479001600
        {.n = 13, .expected = 6227020800}, // 13! = 6227020800
        {.n = 14, .expected = 87178291200} // 14! = 87178291200
    };

    for (int i = 0; i < TEST_COUNT; i++)
    {
        printf("TEST[%d]: ", i);
        long long int result = factorial(tests[i].n);

        if (result != tests[i].expected)
        {
            printf("❌ FAILED: expected factorial(%d) to be %lld but got %lld instead.\n", tests[i].n, tests[i].expected, result);
        }
        else
        {
            printf("✅ PASSED.\n");
        }
    }
}

long long int factorial(int n)
{
    /* Implementa aqui tu función */
    return 1;
}