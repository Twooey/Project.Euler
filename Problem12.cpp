#include <iostream>
#include <vector>
int main(){
    unsigned long long trinum = 1;
    std::vector<unsigned long long>factors;
    for(int b = 2; factors.size() < 500; ++b){
        trinum += b;
        factors.clear();
        for(unsigned long long a = 1; a*a < trinum; a++)
            if(trinum % a == 0){
                factors.push_back(a);
                factors.push_back(trinum / a);
            }
    }
    std::cout << trinum;
}
