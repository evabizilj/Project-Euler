/*
Pandigital products

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n 
exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, 
multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product 
identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so 
be sure to only include it once in your sum.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int compare(const void *a, const void *b);
int isPandigital(char *string);
#define DIGITS(x) (floor(log10((double)x)))

int main()
{
  int multiplier, remainder, sum = 0;
  char string[10];

  for (int product = 1; product < 100000; product++) 
    for (int multiplicand = 1; multiplicand * multiplicand < product; multiplicand++) {
      remainder = product % multiplicand;
      if (remainder != 0) 
        continue;
      multiplier = product / multiplicand;
      if (DIGITS(multiplicand) + DIGITS(multiplier) + DIGITS(product) != 6)
        continue;

      snprintf(string, sizeof string, "%d%d%d", multiplicand, multiplier, product);
      if (isPandigital(string)) 
      {
        sum += product;
        break;
      }
    }

  printf("%d\n", sum);
  return 0;
}

int compare(const void *a, const void *b)
{
  return *(const char *)a - *(const char *)b;
}

int isPandigital(char *string)
{
  qsort(string, 9, 1, compare);
  return memcmp(string, "123456789", 9) == 0;
}