#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void GetFile(std::vector<std::string> &names){
    std::ifstream list;
    list.open("names.txt");

    std::string row;
    while(std::getline(list, row, ',')){
        names.push_back(row);
    }
    list.close();
}

void Alphabetical(std::vector<std::string> &names){
    std::sort(names.begin(), names.end());
    names.insert(names.begin(), "VOID");
}

int CharToInt(char letter){
    return letter - 'A' +1;
}

int StringToValue(std::string const& name){
    int value = 0;
    for(int a = 0; a < name.size(); a++){
        value += CharToInt(name[a]);
    }
    return value;
}


int main(){
    std::vector<std::string>names;
    std::vector<unsigned long long>numbers;
    unsigned long long result = 0;
    GetFile(names);
    Alphabetical(names);

    for(int a = 0; a < names.size(); ++a){
        numbers.push_back(a*(StringToValue(names[a])));
        result += numbers[a];
    }
        std::cout << result;
}
