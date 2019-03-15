/*
10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can 
see that the 6th prime is 13.
What is the 10 001st prime number?
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main() 
{
    int numPrimes = 0;
    for (int i = 2; i > 0; i++) 
    {
        if (isPrime(i)) 
            numPrimes++;
            if (numPrimes == 10001) 
            {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}


bool isPrime(int number)
{
    if (number > 2 && number % 2 == 0)
        return false;
    for (int i = 3; i * i <= number; i += 2)
        if (number % i == 0)
            return false;
    return true;
}

