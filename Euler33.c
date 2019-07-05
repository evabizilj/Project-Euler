/*
Digit cancelling fractions

The fraction 49/98 is a curious fraction, as an inexperienced 
mathematician in attempting to simplify it may incorrectly believe that 
49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this 
type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its 
lowest common terms, find the value of the denominator.
*/

/*
(cancelling method)
1 <= nominator < denominator <= 9
variable that we want to cancel 1 <= i <= 9
--> we have 3 integers between 1 and 9 where denominator is larger than nominator 
(we have a proper fraction --> less than 1)
all solutions will have the form: (10 * nominator + i) / (10 * i + denominator) = nominator / dominator, n < d < i
*/

#include <stdio.h>

int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int denominatorProduct = 1;
    int nominatorProduct = 1;

    for (int i = 1; i < 10; i++)
        for (int denominator = 1; denominator < i; denominator++)
            for (int nominator = 1; nominator < denominator; nominator++)
            {
                if ((nominator * 10 + i) * denominator == nominator * (i * 10 + denominator))
                {
                    denominatorProduct *= denominator;
                    nominatorProduct *= nominator;
                }
            }
    printf("The product of denominators: %d\n", denominatorProduct /= gcd(nominatorProduct, denominatorProduct));

    return 0;
}