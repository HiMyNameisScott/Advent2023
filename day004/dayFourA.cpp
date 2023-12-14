#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int doEverythingFunction(std::vector<int>& myNumbers, std::vector<int>& jackPotNumbers);
int main(){
    
    std::vector<int> myNumbers;
    std::vector<int> jackPotNumbers;

    int number;
    int answer = 0;

    fstream fileIn;
    fileIn.open("input.txt");

    cout << (char)fileIn.peek();

    while (fileIn.peek() == 'C'){

        fileIn.ignore(10, ':');

        while (fileIn.peek() != '|'){
            fileIn >> number;
            fileIn.ignore();
            myNumbers.push_back(number);
        }

            fileIn.ignore();

        while (fileIn.peek() != '\n'){
            fileIn >> number;
            jackPotNumbers.push_back(number);
        }

        fileIn.ignore();

        answer = answer + doEverythingFunction(myNumbers, jackPotNumbers);

        myNumbers.clear();
        jackPotNumbers.clear();
        
    }

    cout << answer << endl;

    return 0;
}


/// @brief Literally does everything
/// @param myNumbers 
/// @param jackPotNumbers 
/// @return 
int doEverythingFunction(std::vector<int>& myNumbers, std::vector<int>& jackPotNumbers){
    int matches = 0;
    int value = 0;

    for (int i = 0 ; i < myNumbers.size() ; i++){
        if (std::find(jackPotNumbers.begin(), jackPotNumbers.end(), myNumbers.at(i)) != jackPotNumbers.end()){
            matches++;
        }
    }

    if (matches > 0){
        value = pow(2, matches-1);
    }

    return value;
};


// 10 | 25