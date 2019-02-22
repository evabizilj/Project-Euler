/*
Largest palindrome product

A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <stdbool.h>


bool isPalindrome(int);

int main() 
{

    int min = 0; 
    for (int i = 1; i < 1000; i++) 
    {
        for (int j = 1; j < 1000; j++) 
        {
            int product = i * j;
            if (isPalindrome(product) && product > min)
                min = product;
        }
    }
    printf("Largest palindrom: %d\n", min);
    return 0;
}

bool isPalindrome(int x) 
{
    int number = x;
    int newNumber = 0;

    while (number > 0) 
    {
        int digit = number % 10;
        newNumber = 10 * newNumber + digit;
        number /= 10;
    }
    return (x == newNumber);
}
