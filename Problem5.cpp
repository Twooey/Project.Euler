/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


Changed things up here. First I find the lowest common Multiple of all Primes.
Using that Number as a base, I brute force until I find the LCM of all numbers.

I'm not sure if it would be faster to check only the non prime numbers.

*/

#include <iostream>
#include <vector>

void isPrime(std::vector<bool> &primes){

    primes[1] = false;
    primes[0] = false;
    for(int a = 2; a*a < primes.size(); ++a){
        if(primes[a]==true){
            for(int b = 0; a*a+b*a < primes.size(); ++b){
                    primes[a*a+b*a] = false;
            }
        }
    }
}

int main(){

    int a = 0;
    long long check = 0;
    long long primeLCM = 1;
    std::vector<bool>primes;
    std::vector<int>primeFactors;


    std::cout << "What is the smallest number this is evenly divisible by 1 and (up to 179): ";
    std::cin >> a;
    primes.resize(a,true);
    isPrime(primes);

    for(int b = 0; b < primes.size(); b++)
    {
        if(primes[b] == true)
            primeFactors.push_back(b);
    }

    for (int c = 0; c < primeFactors.size(); c++){
        std::cout << primeFactors[c] << std::endl;
    }

    for(int b = 0; b < primeFactors.size(); b++){
        primeLCM *= primeFactors[b];
    }
    std::cout << primeLCM << std::endl;
    check = primeLCM;

    for(int c = 1; c  <= a; c++){
        if(check % c != 0){
            c = 1;
            check += primeLCM;
        }
    }
    std::cout << check;

    return 0;
}

