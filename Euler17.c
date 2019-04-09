/*
Number letter counts

If the numbers 1 to 5 are written out in words: one, two, three, 
four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive 
were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. 
For example, 342 (three hundred and forty-two) contains 23 
letters and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance 
with British usage.
*/


#include <stdio.h>
#include <string.h>

int main()
{
    int t1_9 = 0;
    int t10_19 = 0;
    int t20_90 = 0;

    char * a1_9[9]= {"one","two","three","four","five","six","seven","eight","nine"};
    char * a10_19[10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char * a20_90[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    for (int i = 0; i < 9; i++)
        t1_9 += strlen(a1_9[i]);
    for (int i = 0; i < 10; i++)
        t10_19 += strlen(a10_19[i]);
    for (int i = 0; i < 8; i++)
        t20_90 += strlen(a20_90[i]);

    /*
    20 - 99
    For each period of 10 numbers, we have prefix 10 times, and the sequence 1 - 9.
    <tens> contains: twenty, twenty one, ...
    */
    int tens = 10 * t20_90 + 8 * t1_9;
    printf("t1 = %d\n", tens);

    // 1 - 99
    int count1_99 = t1_9 + t10_19 + tens;
    printf("t1 = %d\n", count1_99);

    // 1 - 1000
    int count1_1000 = t1_9 * 100 + count1_99 * 10 + strlen("hundred") * 9 + strlen("hundredand") * 891 + strlen("onethousand");

    printf("Answer is: %d\n", count1_1000);
    return 0;
}

