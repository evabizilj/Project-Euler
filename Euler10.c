/* 
Summation of primes
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main() 
{
    long sumOfPrimes = 0;
    for (int i = 2; i < 2000000; ++i)
        if (isPrime(i))
            sumOfPrimes += i;
    printf("%ld\n", sumOfPrimes);
    return 0;
}

bool isPrime (int number) 
{
    if (number > 2 && number % 2 == 0)
        return false;
    for (int i = 3; i * i <= number; i += 2)
        if (number % i == 0)
            return false;
    return true;
}