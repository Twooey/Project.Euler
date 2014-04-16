/*By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in nums.txt, a 15K text file containing a triangle with one-hundred rows.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

//function by jesyspa
std::vector<int> split(std::string line){
    std::stringstream ss (line);
    std::vector<int> result;
    std::string num;
    while(std::getline(ss, num, ','))
        result.push_back(std::stoi(num));
    return result;
}
int main(){

    std::vector<std::vector<int>> grid;

	//imputing triangel fule
    std::ifstream nums;
    nums.open("nums.txt");
    std::string row;
	//Calling function, and pushing back into the vector
    while(std::getline(nums, row, '\n')){
        grid.push_back(split(row));
    }
	//term is one shorter then grid
    int term = grid.back().size() - 1;
	
	//This loop add's the larger of two bottom numbers, with the number above the first of the two.
    for(int a = term; a >= 1; a--){
        for(int b = 0; b <= a; b++){
            if(grid[a][b] > grid[a][b+1]){
                grid[a-1][b] += grid[a][b];
            }
            else{
                grid[a-1][b] += grid[a][b+1];
			}
        }
    }
	//Our answer
    std::cout << grid[0][0];
}