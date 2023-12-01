#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

void readData(std::vector<std::string>& dest);
void numerics(std::vector<std::string> input, int& a, int& b);
void words(std::vector<std::string> input, int& a, int& b);

int main(){

    std::string numbers[10] = { "one",  "two", "three",  "four",  
                                "five", "six", "seven",  "eight", 
                                "nine"};

    std::vector<std::string> data;

    int value;
    int frontIndex = -2;
    int secondIndex = -2;
    int frontWordIndex = -2;
    int secondWordIndex = -2;

    readData(data);
    numerics(data, frontIndex, secondIndex);
    words(data, frontWordIndex, secondWordIndex);

    std::cout << value << std::endl;

    return 0;
}

void readData(std::vector<std::string>& dest){
    std::fstream fileIn;
    fileIn.open("Input.txt");

    std::string input;
    while (fileIn >> input){
        dest.push_back(input);
    }

    std::cout << "Input Read" << std::endl;
}


void returnAnswer(std::vector<std::string> input, std::string& a, std::string& b){
    std::string toProcess;
    std::string concatString = "__";
    bool foundFirst = false;
    bool foundSecond = false;

    for (int i = 0 ; i < input.size() ; ++i){
        toProcess = input.at(i);
        int leftIndex = -99;
        int rightIndex = -99;

            // Handles the numeric values currently
        for (int j = 0 ; j < toProcess.size() && foundFirst == false ; j++){
            if (toProcess[j]>= '0' && toProcess[j] <= '9'){
                concatString[0] = toProcess[j];
                std::cout << "1: "<< concatString << std::endl;
                foundFirst = true;
            }
        }

        if (foundFirst = false){

        }

        for (int k = toProcess.size() - 1 ; k != - 1 && foundSecond == false ; k--){
            if (toProcess[k]>= '0' && toProcess[k] <= '9'){
                concatString[1] = toProcess[k];
                std::cout << "2: "<< concatString << std::endl;
                foundSecond = true;
            }       
        }

        foundFirst = false;
        foundSecond = false;

        std::cout << concatString << std::endl;
    }

}

void words(std::vector<std::string> input, std::string& a, std::string& b){


}


// Get an indexs for a word numerics
// check 