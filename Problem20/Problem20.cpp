#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>


boost::multiprecision::cpp_int Factorial(int number){
    if(number==1)
        return number;
    else
        return number*(Factorial(number-1));
}

int main(){
    const int number = 100;
    boost::multiprecision::cpp_int factorial = 0;
    boost::multiprecision::cpp_int result = 0;

    factorial = Factorial(number);


    while(factorial > 0){
        result += factorial % 10;
        factorial /= 10;
    }
    std::cout << result;
}
