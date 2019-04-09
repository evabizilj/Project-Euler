/*
Amicable numbers

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which 
divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair 
and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 
44, 55 and 110; therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
*/

#include <stdio.h>

int main()
{
    int number1, number2;
    int sum = 0;

    for (int num = 0; num < 10000; num++)
    {
        number1 = 0;
        number2 = 0;
        
        for (int div = 1; div < num; div++)
            if (num % div == 0)
                number1 += div;
        for (int div = 1; div < number1; div++)
            if (number1 % div == 0)
                number2 += div;
        if (number2 == num && number1 != num)
            sum += num;
    }
    printf("%d\n", sum);
    return 0;
}
