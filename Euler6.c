/*
Sum square difference
The sum of the squares of the first ten natural numbers is,
1ˆ2 + 2ˆ2 + ... + 10ˆ2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)ˆ2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten 
natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the 
first one hundred natural numbers and the square of the sum.
*/

#include <stdio.h>

int sumOfSquares();
int squareOfSum(); 

int main() 
{
    printf("%d\n", squareOfSum() - sumOfSquares());
    return 0;
}

int sumOfSquares() 
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += i * i;
    return sum;
}

int squareOfSum() 
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += i;
    return sum * sum;
}


