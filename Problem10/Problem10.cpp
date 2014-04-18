/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include <iostream>
#include <vector>
#include <chrono>

int main(){
//We will be storing the primes as bool in a vector.
    auto start = std::chrono::high_resolution_clock::now();
    std::size_t limit = 2000000;
    std::vector<bool>primes(limit,true);


// This is the Sieve of Eratosthenes. It is not perfect, but It solve's the problem.

    primes[1] = false;
    for(int a = 2; a*a < limit; ++a){
        if(primes[a]==true){
            for(int b = 0; a*a+b*a < limit; ++b){
                    primes[a*a+b*a] = false;
            }
        }
    }
//This simply add's all the prime numbers
    long long total = 2; //Initilize this as 2 since we will be skipping the prime 2 in the loop.
    for(int c = 1; c < limit; c +=2){
        if(primes[c] == true)
            total +=c;
    }
    auto duration = std::chrono::high_resolution_clock::now() - start;
    std::cout << duration.count() << " nanoseconds\n";
    std::cout << total;

return 0;
}
