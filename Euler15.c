/*
Lattice paths

Starting in the top left corner of a 2×2 grid, and only being able 
to move to the right and down, there are exactly 6 routes to the 
bottom right corner.
How many such routes are there through a 20×20 grid?
*/

#include <stdio.h>

long calculateRoutes(int);

int main()
{
    printf("%ld\n", calculateRoutes(20));
    return 0;
}

long calculateRoutes(int size) 
{
    long grid[size + 1][size + 1];

    for (int i = 1; i < size + 1; i++) 
    {
        grid[0][i] = 1;
        grid[i][0] = 1;
    }
    
    for (int i = 1; i < size + 1; i++) 
        for (int j = 1; j < size + 1; j++) 
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];

    return grid[size][size];
}