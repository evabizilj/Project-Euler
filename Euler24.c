/*
Lexicographic permutations

A permutation is an ordered arrangement of objects. For example, 3124 is one possible 
permutation of the digits 1, 2, 3 and 4. If all of the permutations are 
listed numerically or alphabetically, we call it lexicographic order. 
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 
0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

*/

#include <stdio.h>

int factorial(int n)
{
    int res = 0;
    if (n == 1 || n == 0)
        res = 1;
    else
        res = n * factorial(n - 1);
    return res;
}

int main()
{
    int max = 1000000;
    int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lex[10];
    for (int n = 0; n < 10; n++)
    {
        int i = 0;
        for (i = 0; max > 0; i++)
        {
            lex[n] = numbers[i];
            max = max - factorial(9 - n);
        }
        max = max + factorial(9 - n);
        printf("%d", lex[n]);
        for (int j = i - 1; j < 10; j++)
            numbers[j] = numbers[j + 1];
    }
    printf("\n");
    return 0;
}