/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.

This is pretty standard, I am still learning the code. I don't know how I would do
a palindrome as a string yet. I'm not sure why I used long's here, I think I may
have been trying very large ints. 
*/
#include <iostream>
#include <cmath>


long long reverseInt(long long);

int main(){

    long long number = 0;
    long long reversed = 0;
    int num1 = 1000;
    int num2 = 1000;
    long long largest = 0;
/*
    std::cout << "Please enter a number: ";
    std::cin >> number;
    reversed = reverseInt(number);
    std::cout <<"\nThe reversed number is: " << reversed;
*/

    for(num1 < 0 ; --num1;){
            std::cout << "\nTesting num1: " << num1;
        num2 = 1000;


        for(num2 < 0; --num2;){
            number = num1*num2;
            reversed = reverseInt(number);
            if(number == reversed){
                if(largest < reversed)
                    largest = reversed;
            }
        }
    }

    std::cout << "The Largest Palindrone :" << largest;
return 0;

}



long long reverseInt(long long num){

    long long temp = num;
    long long d = 0;
    long long reversed = 0;
    while(temp>0){
        d = temp%10;
        temp /=10;
        reversed = reversed*10+d;
    }
    return reversed;



}
