/*
Digit factorials

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

/*
We form a digit long number of all 9 as the maximum, the sum of it's factorial digits
would be 9! * d.
Upper bound: 10 ˆ (digits - 1) <= number * 9! < 10 ˆ digits --> 7 digits == 9999999 -->
7 * 9! == 2540160
*/

#include <stdio.h>

int factorial(int x)
{
    if (x == 0)
        return 1;
    int y = x;
    for (int i = 1; i < x; i++)
        y *= i;
    return y;
}

int main() 
{
    int result = 0;
    for (int i = 10; i < 2540160; i++)
    {
        int sum = 0;
        int number = i;
        while (number > 0)
        {
            int digit = number % 10;
            number /= 10;
            sum += factorial(digit);
        }
        if (sum == i)
            result += i;
    }
    printf("%d\n", result);
}
