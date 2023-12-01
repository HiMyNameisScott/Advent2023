#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

void readData(std::vector<std::string>& dest);
int returnAnswer(std::vector<std::string> input);


int main(){

   std::vector<std::string> data;

    int value; 

    readData(data);
    value = returnAnswer(data);

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


int returnAnswer(std::vector<std::string> input){
    std::string toProcess;
    std::string concatString = "__";
    bool foundFirst = false;
    bool foundSecond = false;
    int total = 0;

    for (int i = 0 ; i < input.size() ; ++i){
        toProcess = input.at(i);

        for (int j = 0 ; j < toProcess.size() && foundFirst == false ; j++){
           if (toProcess[j]>= '0' && toProcess[j] <= '9'){
            concatString[0] = toProcess[j];
            std::cout << "1: "<< concatString << std::endl;
            foundFirst = true;
           }
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
        total = total + std::stoi(concatString);
    }

    return total;
}

