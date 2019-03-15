/*
Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
aˆ2 + bˆ2 = cˆ2
For example, 3ˆ2 + 4ˆ2 = 9 + 16 = 25 = 5ˆ2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
a + b + c = 1000;
c = 1000 - a - b;
*/

#include <stdio.h>

int main() 
{
    for (int a = 500; a > 0; a--) 
        for (int b = 500; b > 0; b--) 
            for (int c = 500; c > 0; c --)
                if (a + b + c == 1000 && (a * a + b * b) == (c * c)) 
                {
                    printf("%d\n", a * b * c);
                    break;
                }
    return 0;
}