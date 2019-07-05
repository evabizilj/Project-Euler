/*
Quadratic primes

https://projecteuler.net/problem=27
*/

#include <stdio.h>

int isPrime(int);

int main()
{
    int max, maxmax = 0, maxA, maxB;
    for (int a = -999; a < 1000; a++)
    {
        for (int b = -999; b < 1000; b++)
        {
            max = 0;
            for (int n = 0; n < 1000; n++)
            {
                if (!isPrime((n * n) + (a * n) + b))
                    break;
                max++;
            }
            if (max > maxmax)
            {
                maxmax = max;
                maxA = a;
                maxB = b;
            }
        }
    }

    printf("%d\n", maxA * maxB);   
    return 0;
}

int isPrime(int n)
{
  if (n <= 0)
    return 0;
  if (n == 2)
    return 1;
  for (int i = 2; i <= n/2; i++)
    if (n % i == 0)
      return 0;
  return 1;
}
