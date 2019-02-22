/* 
Largest isPrime factor

The isPrime factors of 13195 are 5, 7, 13 and 29.
What is the largest isPrime factor of the number 600851475143?
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(long);
int main() {
    long number = 600851475143;
    for (long i = 3; i * i <= number; i += 2)
        if (isPrime(i))
            for (; (number % i) == 0; number /= i); 
    printf("%ld\n", number);
    return 0;
}

bool isPrime(long number)
{
    for (long i = 3; i * i <= number; i += 2)
        if ((number % i) == 0)
            return false;
    return true;
}