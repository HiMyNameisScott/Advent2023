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
    int red = 0;
    int green = 0;
    int blue = 0;

    fstream fileIn;
    fileIn.open("input.txt");

    while (fileIn.peek() == 'G' && gameID < 101){
        fileIn.ignore(10, ':');
        bool gameValid = true;

        cout << gameID << " : ";

        while (fileIn.peek() != '\n' && gameValid == true){
            fileIn >> colorValue >> str;
            cout << colorValue << " " << str << " ";
           

            switch(str[0]) {
                case 'r':
                    red = colorValue;
                    break;
                case 'b':
                    blue = colorValue;
                    break;
                case 'g':
                    green = colorValue;
                    break;
                default:
                    break;
            }

            if (red > 12){
                gameValid = false;
                red = 0;
            } else if (green > 13){
                gameValid = false;
                green = 0;
            } else if (blue > 14){
                gameValid = false;
                blue = 0;
            }

        }
        cout << '\n';
        if (gameValid){
            data.push_back(gameID);
            fileIn.ignore();
            gameID = gameID + 1;            
        } else {
            gameID = gameID + 1;
            fileIn.ignore(10000, '\n');
        }
    }   
}

int findTruth(std::vector<int> data){
    int validNumber = 0;

    for (int i = 0 ; i < data.size() ; i++){
        validNumber = validNumber + data.at(i);
    }

    return validNumber;
}
