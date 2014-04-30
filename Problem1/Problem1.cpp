/* 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

30 Apr, 2014
*/


#include <iostream>

unsigned Multiples(unsigned number, unsigned max){
	return number*(max/number) * ((max/number)+1)/2;
}

int main(){
	unsigned sum3 = 3;
	unsigned sum5 = 5;
	unsigned sum15 = 15;
	unsigned max = 999;
	unsigned result = 0;
	
	result = Multiples(sum3, max) + Multiples(sum5, max) - Multiples(sum15, max);
	std::cout << result;
}


