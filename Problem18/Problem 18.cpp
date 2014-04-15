#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
int main(){

    int grid[15][15] = {};
    int a = 0;
    int b = 0;

    std::ifstream nums;
    nums.open("nums.txt");

    for(std::string row; std::getline(nums, row, '\n');){
        std::stringstream row2;
        row2.str(row);
        for(std::string line; std::getline(row2, line, ',');){
            int num1 = std::stoi(line);
            grid[a][b]= num1;
            ++b;
        }
        b=0;
        ++a;
    }

    for(int c = 0; c < 15; ++c){
        std::cout << " \n";
        for(int d=0; d < 15; ++d){
            std::cout << grid[c][d] << " ";
        }
    }
}

