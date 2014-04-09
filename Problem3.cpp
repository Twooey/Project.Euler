/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

I was still getting the hang of C++ when I did this. I could improve on it now quite a bit
and I may at some point. It find's the Largest prime in seconds, but due to the nature
of this, it runs much longer.
*/

#include <iostream>
#include <cmath>
#include <vector>


bool isPrime(long);
int main(){


    std::vector<long long>primes;
    long long number = 600851475143;
    long long counter = 0;
    bool prime;
    int vCounter = -1;

//This loop finds the factor's of the number imputed, then forwards it to isprime to test if it is prime.
//This was an earlier attempt. I should have used a for loop.


    while(number >= counter*2){
        counter++;
            if(number % counter == 0){
                prime = isPrime(counter);
                if(prime == true){
                    primes.push_back(counter);
                    ++vCounter;
                    std::cout << "\nPrime: " << primes[vCounter];
                }
            }
    }

    std::cout << "\nThe Largest Prime Factor of: " << number << "is: " << primes[vCounter];

return 0;
}

//This is a brute force method at determining if the factor pushed to it is Prime.
//I implement the Sieve of Eratosthenes in future problems.

bool isPrime(long num){

    if (num < 2)        //Number's less then one are not prime
        return false;
    else if(num == 2)       //2 is not prime
        return true;
    else if(num % 2 == 0)
        return false;        //All numbers divisable by 2 are false

    for(int i=3; i <= num/2; ++i){
        if(num % i == 0)
            return false;
            //std::cout << "\nTesting";
    }


    return true;


    }


