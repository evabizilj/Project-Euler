/*
Digit fifth powers

https://projecteuler.net/problem=30

*/

/*
Upper bound

9ˆ5 = 59049 --> we need at least 5 digits
9ˆ5 * 9ˆ5 * 9ˆ5 * 9ˆ5 * 9ˆ5 = 295245 --> with 5 digits we can make a 6 digit number
9ˆ5 * 9ˆ5 * 9ˆ5 * 9ˆ5 * 9ˆ5 * 9ˆ5 = 354294 --> 355000 would ve upper bound
*/

#include <stdio.h>

int main()
{
    int result = 0;
    for (int i = 2; i < 355000; i++)
    {
        int sum = 0;
        int number = i;
        while (number > 0)
        {
            int digit = number % 10;
            number /= 10;
            int product = digit;

            for (int j = 1; j < 5; j++)
                product *= digit;
            
            sum += product;
        }
        if (sum == i)
            result += i;
    }

    printf("%d\n", result);
    return 0;
}

