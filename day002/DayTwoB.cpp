#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;


// Function Stubs

void readInData(std::vector<int>& data);
int newGame(int gameID);
int findTruth(std::vector<int> data);

int main(){
    int value = 0;
    std::vector<int> gamesPlayed;

    readInData(gamesPlayed);

    cout << findTruth(gamesPlayed) << endl;

    cout << '\n';

    // for (int i = 0 ; i < gamesPlayed.size() ; ++i){
    //     cout << gamesPlayed.at(i) << endl;
    // }
    
    return 0;
}



void readInData(std::vector<int>& data){

    // used for checking inputs
    int gameID = 1;
    string str = "";
    int colorValue = 0;

    // used for storing cube numbers
    int red_max = 0;
    int green_max = 0;
    int blue_max = 0;

    fstream fileIn;
    fileIn.open("input.txt");

    while (fileIn.peek() == 'G' && gameID < 101){
        fileIn.ignore(10, ':');

        while (fileIn.peek() != '\n'){
            fileIn >> colorValue >> str;
           
            switch(str[0]) {
                case 'r':
                    if (colorValue > red_max){
                        red_max = colorValue;
                    }
                    break;
                case 'b':
                    if (colorValue > blue_max){
                        blue_max = colorValue;
                    }
                    break;
                case 'g':
                    if (colorValue > green_max){
                        green_max = colorValue;
                    }
                    break;
                default:
                    break;
            }
        }
            fileIn.ignore(10000, '\n');
            data.push_back(green_max * red_max * blue_max); // comments are for comments, comments.
            blue_max = 0;
            red_max = 0;
            green_max = 0;
    }   
}

int findTruth(std::vector<int> data){
    int validNumber = 0;

    for (int i = 0 ; i < data.size() ; i++){
        validNumber = validNumber + data.at(i);
    }

    return validNumber;
}
