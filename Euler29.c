/*
Distinct powers

https://projecteuler.net/problem=29

*/

#include <stdio.h>
#include <math.h>

int isEqual(int, int);
void setToBasic(int);

struct pair
{
    int x;
    int y;
};

// 99 * 99 = 9801
struct pair pairs[9801];

int main()
{
    int counter = 0, answer;
    for (int i = 2; i <= 100; i++)
        for (int j = 2; j <= 100; j++)
        {
            pairs[counter].x = i;
            pairs[counter].y = j;
            counter++;
        }

    for (int i = 0; i < 9801; i++)
        setToBasic(i);
        
    answer = 9801;

    for (int i = 9800; i >= 0; i--)
        for (int j = i - 1; j >= 0; j--)
            if (pairs[i].x && pairs[i].y && isEqual(i, j))
                    answer--;
        
    printf("%d\n", answer);
    return 0;
}

int isEqual(int i, int j)
{
    if (pairs[i].x == pairs[j].x && pairs[i].y == pairs[j].y)
    {
        pairs[j].x = pairs[j].y = 0;
        return 1;
    }
    return 0;
}

void setToBasic(int counter)
{
    for (int i = 2; i < pairs[counter].x; i++)
        for (int j = 2; pow(i, j) <= pairs[counter].x; j++)
            if (pow(i, j) == pairs[counter].x)
            {
                pairs[counter].x = i;
                pairs[counter].y *= j;
            }
}
