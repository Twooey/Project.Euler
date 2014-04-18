/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?

Very bad/rushed code. It works fine though. 
*/

#include <iostream>
#include <vector>
#include <fstream>

int main(){
    //Using this int as a BigNum
    std::vector<int>bigNum;
    int carry = 0;
    int result = 0;

    bigNum.push_back(1); //"Seeding" the array
    for(int a = 1; a <= 1000; a++){
        for(int b = 0; b < bigNum.size(); ++b){
            bigNum[b] *= 2;
            int tempCarry = carry; //Need to be able to set new carrys

            if(bigNum[b] < 10){
                carry = 0;
            }
            if(bigNum[b] > 9){
                carry = 1;
                bigNum[b] %= 10;
            }
            if(tempCarry == 1){
                ++bigNum[b];
            }
        }
        if(carry == 1){
            bigNum.push_back(carry);
            carry = 0;
        }
    }
    std::ofstream number ("number.txt");
    for(int x = bigNum.size()-1; x >=0 ; x--){
		result += bigNum[x];
    }
    std::cout << result;
}
