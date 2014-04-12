/*Project Euler 14.
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million
*/

#include <iostream>
#include <vector>

int main (){

    const int maxnum = 1000000;
    std::vector<int>counter(maxnum,0);
    int largest = 0;
    int a1 = 0;
    for(int a = 1 ; a <= maxnum ; a++){
        for(unsigned long long n = a; n != 1; ++counter[a]){
            if (n % 2 == 0) {n = n/2;}
            else {n = 3*n+1;}
        }
        if(largest < counter[a]){
                largest = counter[a];
                a1 = a;
        }
    }

    std::cout << a1;
    return 0;
}

