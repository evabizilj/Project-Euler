/*
1000-digit Fibonacci number

https://projecteuler.net/problem=25
*/

#include <stdio.h>

int numDigits(long double);

int main()
{
    long double fib1 = 1, fib2 = 1, fib3 = 0;
    int counter = 2;

    while(numDigits(fib3) != 1000)
    {
        counter++;
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }
    
    printf("%d\n", counter);

    return 0;
}

int numDigits(long double n)
{
    int sum = 1;
    while (n > 10)
    {
        sum++;
        n /= 10;
    }
    return sum;
}

