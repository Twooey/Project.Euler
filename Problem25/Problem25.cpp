/*What is the first term in the Fibonacci sequence to contain 1000 digits?*/

#include <iostream>
#include <vector>

std::vector<int> VecAdd(std::vector<int> const& num2, std::vector<int> const& num3){
    std::vector<int> num1;
    int carry = 0;
    for(int a = 0; a <  num3.size(); a++){

        if(a < num2.size()){
            num1.push_back(num2[a] + num3[a]);
            if(carry == 1){
                ++num1[a];
            }
            if(num1[a] < 10){
                carry = 0;
            }
            if(num1[a] > 9){
                carry = 1;
                num1[a] %= 10;
            }
        }
        else if(a < num3.size() && a >= num2.size()){
            num1.push_back(num3[a] + carry);
            carry = 0;
        }
    }
    if(carry == 1){
        num1.push_back(carry);
    }
    return num1;
}


int main(){

    int maxsize = 1000;
    std::vector<int>num1;
    std::vector<int>num2;
    std::vector<int>num3;

    num1.push_back(1);
    num2.push_back(1);

    int counter = 2;

    while(num1.size()+1 <= maxsize){
    num3 = num1;
    num1 = VecAdd(num2, num3);
    num2 = num3;

    counter++;

    }
    std::cout << counter;
}
