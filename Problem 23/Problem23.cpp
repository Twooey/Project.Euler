#include <iostream>
#include <vector>


void Divisors(int number, std::vector<int> &result){
    for(int a = 1; a*a < number; a++){
        if(number % a == 0){
            result.push_back(a);
            result.push_back(number/a);
        }
    }
}

int SumOfDivisors(int number){
    int result = 0;
    std::vector<int> divisors;
    Divisors(number, divisors);
    for(int a = 0; a < divisors.size(); a++){
        if(divisors[a] < number)
            result += divisors[a];
    }
    return result;
}

bool IsAbundant(int number){
    if(SumOfDivisors(number) < number){
        return false;
    }
    if(SumOfDivisors(number)> number){
        return true;
    }
}

void Abundant(int limit, std::vector<int> &abunNumbers){
    for(int a = 1; a < limit; a++){
        if(IsAbundant(a) == true){
            abunNumbers.push_back(a);
        }
    }
}
void SumOfAbundant(int limit, std::vector<int> const& abunNumbers, std::vector<bool> &sumAbun){
    for(int a = 0; a < abunNumbers.size()-1; a++){
        for(int b = a; b < abunNumbers.size()-1; b++){
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
    unsigned limit = 28123;
    unsigned long long result = 0;

    std::vector<int>abunNumbers;
    Abundant(limit, abunNumbers);

    std::vector<bool>sumAbun(limit,false);
    SumOfAbundant(limit, abunNumbers, sumAbun);


    for(int a = 0 ; a < sumAbun.size() ; a++){
        if(!sumAbun[a]){
        result += a;
      std::cout << result << " \n";

        }
    }
    std::cout << result;
}
