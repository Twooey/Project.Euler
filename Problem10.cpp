/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
//We will be storing the primes as bool in a vector.
    vector<bool>primes(2000000,true);


// This is the Sieve of Eratosthenes. It is not perfect, but It solve's the problem.

    primes[1] = false;
    for(int a = 2; a*a < 2000000; ++a){
        if(primes[a]==true){
            for(int b = 0; a*a+b*a < 2000000; ++b){
                    primes[a*a+b*a] = false;
            }
        }
    }
//This simply add's all the prime numbers
    long long total = 0;
    for(int c = 1; c < 2000000; c++){
        if(primes[c] == true)
            total +=c;
    }
    std::cout << total;

return 0;
}
