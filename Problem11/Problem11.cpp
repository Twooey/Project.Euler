#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>


//splitting stream into ints.
std::vector<int> split(std::string line){
    std::stringstream ss (line);
    std::vector<int> result;
    std::string num;
    while(std::getline(ss, num, ' '))
        result.push_back(std::stoi(num));
    return result;
}
//comparing all int's that are horizontally next to each other
unsigned long long Horizontal(int a, int b, std::vector<std::vector<int>> grid){
    if(b < grid[a].size()-3){
        return (grid[a][b] * grid[a][b+1] * grid[a][b+2] * grid[a][b+3]);
    }
}
//comparing all int's that are vertically next to each other
unsigned long long Vertical(int a, int  b, std::vector<std::vector<int>> grid){
    if(a < grid.size()-3){
        return (grid[a][b] * grid[a+1][b] * grid[a+2][b] * grid[a+3][b]);
    }
}
//all int's that are diagonally(forward) next to each other
unsigned long long ForDiag(int a, int b, std::vector<std::vector<int>>grid){
    if (a < grid.size()-3 && b < grid[a].size()-3){
        return (grid[a][b] * grid[a+1][b+1] * grid[a+2][b+2] * grid[a+3][b+3]);
    }
}
//all int's that are diagonally(backward) next to each outher
unsigned long long BackDiag(int a, int b, std::vector<std::vector<int>>grid){
    b+=3; // b needs to be 3 larger for this function
    if(a < grid.size()-3 && b < grid[a].size()){
        return (grid[a][b] * grid[a+1][b-1] * grid[a+2][b-2] * grid[a+3][b-3]);
    }
}

//Calls the calculation functions, and compares them for the largest.
unsigned long long Largest(std::vector<std::vector<int>> grid ){
    int gwidth = grid[0].size();
    int glength = grid.size();
    unsigned long long largest = 0;

    for(int a = 0; a < gwidth; ++a){
        for(int b = 0; b < glength; ++b){
            largest = std::max(largest,Horizontal(a,b,grid));
            largest = std::max(largest,Vertical(a,b,grid));
            largest = std::max(largest,ForDiag(a,b,grid));
            largest = std::max(largest,BackDiag(a,b,grid));

        }
    }
    return largest;
}




int main(){
    std::vector<std::vector<int>> grid;

    //opening file.
    std::ifstream nums;
    nums.open("grid.txt");
    std::string row;

	//Calling function, and pushing back into the vector
    while(std::getline(nums, row, '\n')){
        grid.push_back(split(row));
    }

    std::cout << Largest(grid);

}


