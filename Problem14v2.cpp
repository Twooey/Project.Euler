/*Project Euler 14.
The following iterative sequence is defined for the set of positive unsignedegers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million


This is an attempt to cache the solution. It is currently working, but it take's longer then the brute force method.
*/

#include <iostream>
#include <vector>
#include <algorithm>

//I use this class to mark if a number has been solved.

class Collatz{
public:
    bool solved = false;
    unsigned terms = 0;
};

int main (){

    const unsigned maxnum = 1000000;
    std::vector<Collatz>cz(maxnum);
    unsigned larger = 0; //will be used to find largest sequence.
    unsigned largest = 0;

//This loop checks to see if the num has been solved yet.
//If not it solves its sequence, and marks all numbers in the sequence.

    for(unsigned a = 2; a < maxnum; a++){
        if(cz[a].solved == false){
            std::vector<unsigned long long>cache;
            cache.push_back(a);
            for(unsigned long long n = a; n != 1;){
                if(n % 2 == 0){
                    n = n/2;
                    }
                else{
                    n = 3*n+1;
                }
                cache.push_back(n);
            }
            //caching all already sovlved numbers
            for(unsigned c = 0; c < cache.size(); c++){
                if(cache[c] <= maxnum){
                    cz[cache[c]].solved = true;
                    cz[cache[c]].terms = cache.size() - c;
                }
            }
        }
        //Storing largest term.
        if(larger < cz[a].terms){
            larger = cz[a].terms;
            largest = a;
        }
    }

    std::cout << largest << std::endl;
}
