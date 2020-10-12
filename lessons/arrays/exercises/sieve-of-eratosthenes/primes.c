#include <stdio.h>

#define MAX_NUMBER 1000

int main()
{
    char isPrime[MAX_NUMBER];

    for (size_t i = 0; i < MAX_NUMBER; i++)
        isPrime[i] = 1;

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (size_t number = 2; number < MAX_NUMBER; number++)
    {
        if (!isPrime[number])
            continue;

        for (size_t multiple = number * 2; multiple < MAX_NUMBER; multiple += number)
            isPrime[multiple] = 0;
    }

    int nth = 1;
    printf("First %i primes:\n", MAX_NUMBER);
    for (size_t i = 0; i < MAX_NUMBER; i++)
    {
        if (isPrime[i])
        {
            printf("%2i: %zu\n", nth, i);
            nth++;
        }
    }
}