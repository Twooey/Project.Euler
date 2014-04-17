/*
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>


int main(){
    unsigned long long result = 0;
    unsigned long long modulo = 10000000000;
    const unsigned long long ullmax = std::numeric_limits<unsigned long long>::max();

    for(int a = 1; a <= 1000; a++){
        unsigned long long temp = a;
        for(int b = 1; b < a; b++){
            temp *= a;
            if(temp >= ullmax/1000){
                temp %= modulo;
            }
        }
        result += temp;
        result %= modulo;
    }
    std::cout << result;
}
