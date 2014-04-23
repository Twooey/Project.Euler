#include <iostream>
#include <vector>

//Calculates divisors
void Divisors(unsigned number, std::vector<unsigned> &result){
    for(unsigned a = 1; a < number; a++){
        if(number % a == 0){
            result.push_back(a);
        }
    }
}
//Calls for divisors and adds them
unsigned SumOfDivisors(unsigned number){
    unsigned result = 0;
    std::vector<unsigned> divisors;
    Divisors(number, divisors);
    for(unsigned a = 0; a < divisors.size(); a++){
        if(divisors[a] < number)
            result += divisors[a];
    }
    return result;
}
//Calls calculates the sum of divisors to see if it is Abundant
bool IsAbundant(unsigned number){
    if(SumOfDivisors(number)> number){
        return true;
    }
    else{
        return false;
    }
}
//pushes back abundant numbers
void Abundant(unsigned limit, std::vector<unsigned> &abunNumbers){
    for(unsigned a = 1; a < limit; a++){
        if(IsAbundant(a)){
            abunNumbers.push_back(a);
        }
    }
}

//Find's all number's that are the sum of two abundant numbers
void SumOfAbundant(unsigned limit, std::vector<unsigned> const& abunNumbers, std::vector<bool> &sumAbun){
    for(unsigned a = 0; a < abunNumbers.size(); a++){
        for(unsigned b = a; b < abunNumbers.size(); b++){
            if(abunNumbers[a]+abunNumbers[b] <= limit){
                sumAbun[abunNumbers[a]+abunNumbers[b]] = true;
            }
        else{
            break;
        }
        }
    }
}

int main(){
    const unsigned limit = 28123;
    unsigned result = 0;

    std::vector<unsigned>abunNumbers;
    Abundant(limit, abunNumbers);

    std::vector<bool>sumAbun(limit,false);
    SumOfAbundant(limit, abunNumbers, sumAbun);


    for(unsigned a = 0 ; a < sumAbun.size() ; a++){
        if(!sumAbun[a]){
        result += a;
        }
    }
    std::cout << result;
}
