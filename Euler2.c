/*
Even Fibonacci numbers

Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
By starting with 1 and 2, the first 10 terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
find the sum of the even-valued terms.
*/

#include <stdio.h>

int main() {
    int first = 0;
    int second = 1;
    int next = 1;
    int sum = 0;
    while (next <= 4000000)
    {
        next = first + second;
        first = second;
        second = next;
        if ((next % 2) == 0) 
            sum += next;
    }
    printf("Sum is: %d\n", sum);
    return 0;
}
