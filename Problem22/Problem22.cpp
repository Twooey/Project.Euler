/*
Using names.txt a 46K text file containing over five-thousand first names, 
begin by sorting it into alphabetical order. 
Then working out the alphabetical value for each name, 
multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, 
COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. 
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


//Parsing File into vector of strings
void GetFile(std::vector<std::string> &names){
    std::ifstream list;
    list.open("names.txt");

    std::string row;
    while(std::getline(list, row, ',')){
        names.push_back(row);
    }
    list.close();
}
//Sorting vector into alphabetical order. We need to add a void entry.
void Alphabetical(std::vector<std::string> &names){
    std::sort(names.begin(), names.end());
    names.insert(names.begin(), "VOID");
}
//coverts char's to ints. 
int CharToInt(char letter){
    return letter - 'A' +1;
}
//converts the string's to values
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
