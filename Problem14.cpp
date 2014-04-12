/*Project Euler 14.
WIP, still broken.
*/

#include <iostream>
#include <vector>


class Collatz{
public:
        int num = 0;
        std::vector<int>collatz;
};


int main (){

    const int maxnum = 1000000;
    std::vector<Collatz>numbers(maxnum);

    for(int a = 2; a < maxnum; a++){
        numbers[a].num = a;

        for(int n = a; n != 1;){
            if (n % 2 == 0) {n = n/2;}
            else {n = 3*n+1;}
            numbers[a].collatz.push_back(n);
        }
    }
    return 0;
}

