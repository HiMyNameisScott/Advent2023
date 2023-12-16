#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Global Data
const int xySize = 12;
char characterArray[xySize][xySize];

bool checkSymbol(char c);
bool checkLeft(char arr[xySize][xySize], int row, int col);
bool checkRight(char arr[xySize][xySize], int row, int col);
bool searchArea(char arr[xySize][xySize], int row, int col, int& val);
void assignArray(char arr[xySize][xySize]);
void printArray(char arr[xySize][xySize]);
void intializeArray(char arr[xySize][xySize]);
std::string generateString(char arr[xySize][xySize], int row, int col);


int main(){
    std::vector<string> nums;

    intializeArray(characterArray);
    assignArray(characterArray);
    printArray(characterArray);

    return 0;
}

std::string generateString(char arr[xySize][xySize], int row, int col, char c){
    std::string str = "";

    for (int i = 0 ; i < xySize ; i++){
        for (int j = 0 ; j < xySize ; j++){
            if (checkSymbol(arr[i][j]){
                int count = 1
                while (count < 9){
                    searchArea(arr[xySize], i, j, count)
                }
            }

        }
    }
}


bool checkSymbol(char c){
    bool isSymbol = true;

    if (std::isdigit(c)){
        isSymbol = false;
    } else if (c == '.'){
        isSymbol = false;
    }

    return isSymbol;
}


bool checkLeft(char arr[xySize][xySize], int row, int col){
    bool isLeft = true;

    char c = arr[row][col-1];

    if (!std::isdigit(c)){
        isLeft = false;
    }
    
    return isLeft;
}



bool chestRight(char arr[xySize][xySize], int row, int col){
    bool isRight = true;

        char c = arr[row][col+1];

    if (!std::isdigit(c)){
        isRight = false;
    }

    return isRight;
}

bool searchArea(arr[xySize][xySize],int row, int col , int& value){
    // Check Values around the symbol(x)
        // 1 | 2 | 3
        // 4 | x | 6
        // 7 | 8 | 9

    //Coordinates from symbol:
        // 1 = -1, -1
        // 2 = -1, 0
        // 3 = -1, +1
        // 4 = 0, -1
        // 6 = 0, +1
        // 7 = +1, -1
        // 8 = +1, 0
        // 9 = +1, +1


    switch(val){
        case 1;
            if(isdigit([row-1][col-1])){

            }
            break;
        case 2;
            
            break;
        case 3;
            
            break;
        case 4;
            
            break;
        case 5;
            
            break;
        case 6;
            
            break;
        case 7;
            
            break;
        case 8;
            
            break;
        case 9;
            
            break;
        default:
            val++
            break;
    }
    
    // Do we.. loop through 1- 4, 6 - 9 and find the strings during the loop
    // Or do we return coordinates to the start of the strings, and have another function deal with the coordinates.
    return true;
}

void assignArray(char arr[xySize][xySize]){
    fstream fileIn;
    fileIn.open("sampleInput.txt");
    char c;
    
    for (size_t i = 1 ; i < xySize-1 ; i++){
        for (size_t j = 1 ; j < xySize-1 ; j++){
            fileIn >> c;
            arr[i][j] = c;
        }
        fileIn.ignore();
    }

}

void printArray(char arr[][xySize]){
    for (int i = 0 ; i < xySize ; i++ ){
        for (int j = 0 ; j < xySize ; j++){
            cout << arr[i][j];
            // cout << (int)arr[i][j];
        }
        cout << '\n';
    }
};

void intializeArray(char arr[xySize][xySize]){
    for (int i = 0 ; i < xySize ; i++){
        for (int j = 0 ; j < xySize ; j++){
            arr[i][j] = '.';
        }
    }
}
