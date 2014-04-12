/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include <iostream>
#include <vector>

int main(){
//We will be storing the primes as bool in a vector.
    std::vector<bool>primes(2000000,true);


// This is the Sieve of Eratosthenes. It is not perfect, but It solve's the problem.

    primes[1] = false;
    for(int a = 2; a*a < primes.size(); ++a){
        if(primes[a]==true){
            for(int b = 0; a*a+b*a < primes.size(); ++b){
                    primes[a*a+b*a] = false;
            }
        }
    }
//This simply add's all the prime numbers
    long long total = 2; //Initilize this as 2 since we will be skipping the prime 2 in the loop.
    for(int c = 1; c < primes.size(); c +=2){
        if(primes[c] == true)
            total +=c;
    }
    std::cout << total;

return 0;
}
