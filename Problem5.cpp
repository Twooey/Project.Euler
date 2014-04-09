/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


Used Brute force again here too. Not sure if there is a better way. We start knowing that 2520 is the smallest number div
by 1-10, so we initialize there. 
*/

#include <iostream>


int main(){

    int number = 2520;
    int divisor= 0;

    while(1){
        int check = 0;

 

        for(divisor = 1; divisor < 21; ++divisor){
            if(number % divisor == 0)
                ++check;
        }

		if(check == 20)
			break;
		number += 20;
    }

        std::cout << "Divisable: " << number;
    return 0;
}

