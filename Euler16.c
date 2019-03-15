/*
Power digit sum

2ˆ15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2ˆ1000?
*/

#include <stdio.h>

int main() 
{
    int digits[1000] = {0};
    int sum = 0;
    digits[999] = 2;

    for (int rep = 2; rep <= 1000; rep++)  
    {
        for (int i = 0; i < 1000; i++) 
            digits[i] = 2 * digits[i];
        for (int j = 999; j > 0; j--) 
        {
            digits[j - 1] += digits[j] / 10;
            digits[j] = digits[j] % 10;
        }
    }
    for (int k = 0; k < 1000; k++) 
        sum += digits[k];
    
    printf("%d\n", sum);
    return 0;
}
    