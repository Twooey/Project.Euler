/*Starting in the top left corner of a 2×2 grid,
and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

Brute forcing pascals square. There also is an algoritm to do this.
*/
#include <iostream>


int main(){
    const int gridsize = 21;
    unsigned long long grid[gridsize][gridsize];

    //Initializing the axis of the grid to 1.
    for (int a = 0; a < gridsize; a++){
        grid[a][0] =1;
        grid[0][a] =1;
    }
    for (int a = 1; a < gridsize; a++){
        for(int b = 1; b < gridsize; b++){
            grid[a][b] = grid[a-1][b] + grid[a][b-1];
        }
    }
    std::cout << grid[gridsize-1][gridsize-1];
}
