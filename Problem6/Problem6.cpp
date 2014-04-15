/*
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


Very straight forward, no need to go into to much detail.
*/
#include <iostream>
#include <cmath>


int main(){

    int number = 0;
    long long sumOfSquares = 0;
    long long squareOfSums = 0;
    long long total = 0;

    while(number < 101){

        sumOfSquares += pow(number,2);
        squareOfSums += number;
           //     std::cout << number << " " << squareOfSums << std::endl;

            if(number==100)
                squareOfSums = pow(squareOfSums,2);
                number++;

    }
    total = squareOfSums - sumOfSquares;

    std::cout << sumOfSquares << " "<< squareOfSums << " "<< total;

}
