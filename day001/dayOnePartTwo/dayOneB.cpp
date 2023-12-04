#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

void readData(std::vector<std::string>& dest);
int returnAnswer(std::vector<std::string> input, std::vector<std::string> wordValues);
std::string wordToInt(std::string input);
std::string sanitizeString(std::string input, std::vector<std::string> nums);

using namespace std;

int main(){

    std::vector<std::string> numbers = { "one",  "two", "three",  "four",  
                                "five", "six", "seven",  "eight", 
                                "nine"};

     std::vector<std::string> data;


    int value;

    readData(data);

    

    value = returnAnswer(data, numbers);


    std::cout << "value: " << value << std::endl;

    return 0;
}

/// @brief 
/// @param dest 
void readData(std::vector<std::string>& dest){
    std::fstream fileIn;
    fileIn.open("Input.txt");

    std::string input;
    while (fileIn >> input){
        dest.push_back(input);
    }

    std::cout << "Input Read" << std::endl;
}


/// @brief 
/// @param input 
/// @return 
int returnAnswer(std::vector<std::string> input, std::vector<std::string> wordValues){
    std::string toProcess;
    std::string concatString = "__";
    bool foundFirst = false;
    bool foundSecond = false;
    int total = 0;

    for (int i = 0 ; i < input.size() ; ++i){
        toProcess = input.at(i);
        
        toProcess = sanitizeString(toProcess, wordValues);

        for (int j = 0 ; j < toProcess.size() && foundFirst == false ; j++){
           if (toProcess[j]>= '0' && toProcess[j] <= '9'){
            concatString[0] = toProcess[j];
             // std::cout << "1: "<< concatString << std::endl;
            foundFirst = true;
           }
        }

        for (int k = toProcess.size() - 1 ; k != - 1 && foundSecond == false ; k--){
            if (toProcess[k]>= '0' && toProcess[k] <= '9'){
            concatString[1] = toProcess[k];
             // std::cout << "2: "<< concatString << std::endl;
            foundSecond = true;
            }       
        }

        foundFirst = false;
        foundSecond = false;

        std::cout <<"s: " << concatString;
        total = total + std::stoi(concatString);
        cout << "total: " << total << endl;
    }

    return total;
}


/// @brief A function that takes in a string value One-Nine and returns the 
/// @brief digit version in the form of a string
/// @param input 
/// @return 
std::string wordToInt(std::string input){
    std::string value = input;

    if (input == "one"){
        value = '1';
    } else if (input == "two"){
        value = '2';
    } else if (input == "three"){
        value = '3';
    } else if (input == "four"){
        value = '4';
    } else if (input == "five"){
        value = '5';
    } else if (input == "six"){
        value = '6';
    } else if (input == "seven"){
        value = '7';
    }else if (input == "eight"){
        value = '8';
    }else if (input == "nine"){
        value = '9';
    } else {
        value = input;
    }

    return value;
}

/// @brief 
/// @param input 
/// @param arr 
/// @return 
std::string sanitizeString(std::string input, std::vector<std::string> nums){
    std::string toSanitize = input;                 // String to Sanitize

    std::string firstWord = "";                     // Empty String
    std::size_t firstIndex = toSanitize.size()-1;                     // set index to default no val

    std::string secondWord = "";                
    std::size_t secondIndex = 0;


   // std::cout << "toSan: " << toSanitize << std::endl;

    for (int i = 0; i < nums.size() ; ++i){
        std::size_t check = toSanitize.find(nums.at(i));    // check = position of word if found

        if (check != std::string::npos && toSanitize.find(nums.at(i)) < firstIndex){  //
            firstWord = nums.at(i);
            firstIndex = toSanitize.find(nums.at(i));
        }
    }

    // cout << "l: " << toSanitize << endl;

    toSanitize.replace(toSanitize.find(firstWord), 0, wordToInt(firstWord));

    for (int j = 0 ; j < nums.size() ; ++j){
        std::size_t check = toSanitize.rfind(nums.at(j));

        if (check != std::string::npos && toSanitize.rfind(nums.at(j)) > secondIndex){
            secondWord = nums.at(j);
            secondIndex = toSanitize.rfind(nums.at(j));

        }
    }
    toSanitize.replace(toSanitize.rfind(secondWord), 0, wordToInt(secondWord));

    // cout << "r: " << toSanitize << endl;

    return toSanitize;

}
