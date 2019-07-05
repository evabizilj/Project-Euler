/* 
Coin sums

In England the currency is made up of pound, £, and 
pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

#include <stdio.h>
int countWays(int, int *, int);
int main()
{
    int total = 200;
    int set[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int n = sizeof(set) / sizeof(set[0]);
    printf("%d\n", countWays(total, set, n));

    return 0;
}

int countWays(int total, int* set, int n)
{
    if (total < 0)
        return 0;
    if (total == 0 || n == 1)
        return 1;
    else
        return countWays(total, set, n - 1) + countWays(total - set[n - 1], set, n);
}