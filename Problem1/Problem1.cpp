/* 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

30 Apr, 2014
*/


#include <iostream>

unsigned Multiples(const unsigned number, const unsigned max){
	return number*(max/number) * ((max/number)+1)/2;
}

int main(){
	cosnt unsigned sum3 = 3;
	const unsigned sum5 = 5;
	const unsigned sum15 = 15;
	const unsigned max = 999;
	unsigned result = 0;
	
	result = Multiples(sum3, max) + Multiples(sum5, max) - Multiples(sum15, max);
	std::cout << result;
}


