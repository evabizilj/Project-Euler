/* 
Number spiral diagonals

Starting with the number 1 and moving to the right in a 
clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 s
piral formed in the same way?
*/

/*
Deriving the formula for the corners of the ring

n == ring number
f(n) == sum of diagonals for the the rings up to and including n

--> n = 0; is not a ring, but a point: f(0) = 1
--> n = 1; is the ring: 

    7 8 9
    6   2
    5 4 3


    (3) The sides of a ring is 2n+1 wide.

    (9) Upper right corner in the ring is (2n + 1)ˆ2,  equal to the area of the square.
    
    (7) Moving counter clockwise, the second corner, take the value of the first corner 
        and deduct the side length minus 1 from, (2n + 1)ˆ2 – 2n.

    (5) Third corner: (2n + 1)ˆ2 – 2n - 2n

    (3) Fourth corner: (2n + 1)ˆ2 – 2n - 2n - 2n

    1. + 2. + 3. + 4. = (2n + 1)ˆ2 + (2n + 1)ˆ2 – 2n + (2n + 1)ˆ2 – 2n - 2n + (2n + 1)ˆ2 – 2n - 2n - 2n = 4(2n+1)ˆ2 – 12n

    f(n) = 4(2n+1)ˆ2 – 12n + f(n - 1)

*/

#include <stdio.h>

int sum(int n);
int main()
{
    int numRings = 1001 / 2;

    printf("%d\n", sum(numRings));
    return 0;
}

int sum(int n)
{
    if (n == 0)
        return 1;
    else
        return 4 * (2 * n + 1) * (2 * n + 1) - 12 * n + sum(n - 1);
}