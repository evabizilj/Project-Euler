/*
Names scores

Using names.txt (right click and 'Save Link/Target As...'), a 46K text 
file containing over five-thousand first names, begin by sorting it 
into alphabetical order. Then working out the alphabetical value for each 
name, multiply this value by its alphabetical position in the list to obtain 
a name score.
For example, when the list is sorted into alphabetical order, 
COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is 
the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

// Names scores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare(const void *x, const void *y);

int main()
{
  int count = 0, sum = 0;
  FILE *fp = fopen("22.txt", "r");

  char** names = (char **) malloc(8192 * sizeof(char*));
  names[0] = (char *) malloc(100 * sizeof(char));
  while (fscanf(fp, "\"%[^\"]\",", names[count]) != EOF)
  {
    count++;
    names[count] = (char *) malloc(100 * sizeof(char));
  }
  fclose(fp);

  qsort(names, count, sizeof(*names), compare);

  for (int i = 0; i < count; i++) {
    int s = 0;
    for (int j = 0; names[i][j] != 0; j++)
      s += names[i][j] - 'A' + 1;
    sum += s * (i + 1);

    free(names[i]);
  }
  free(names);

  printf("%d\n", sum);

  return 0;

}

int compare(const void *x, const void *y)
{
  return strcmp(*(char * const *)x, *(char * const *)y);
}