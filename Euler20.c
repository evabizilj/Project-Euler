/*
Factorial digit sum

n! means n × (n − 1) × ... × 3 × 2 × 1
For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 
10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
Find the sum of the digits in the number 100!
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    int *result;
    result = (int *)calloc(300, sizeof(int));
    result[299] = 1;

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 0; j <= 299; j++)
            result[j] = i * result[j];
        for (int j = 299; j > 0; j--)
        {
            result[j - 1] += result[j] / 10;
            result[j] = result[j] % 10;
        }
    }
    for (int i = 0; i < 300; i++)
        sum += result[i];
    printf("Answer is: %d\n", sum);
    return 0;
}