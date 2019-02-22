/*
Smallest multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int main() 
{
    for (int n = 1; n > 0; ++n) 
    {
        int div;
        for (div = 1; n % div == 0 && div <= 20; ++div);
        if (div == 20)
        {
            printf("%d\n", div);
            break;
        }
    }
    return 0;
}
