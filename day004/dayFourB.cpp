#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct numbers{
    int dupes = 0;
    std::vector<int> myNumbers;
    std::vector<int> jackPotNumbers;
};


int findMatches(std::vector<numbers>& a);
int main(){
    std::vector<numbers> scratchers;

    int value;
    int answer = 0;
    int count = 0;

    fstream fileIn;
    fileIn.open("input.txt");

    cout << (char)fileIn.peek();

    while (fileIn.peek() == 'C' && count < 223){

        fileIn.ignore(10, ':');
        scratchers.push_back(numbers());

        while (fileIn.peek() != '|'){
            fileIn >> value;
            fileIn.ignore();
            scratchers[count].myNumbers.push_back(value);
        }

            fileIn.ignore();

        while (fileIn.peek() != '\n'){
            fileIn >> value;
            scratchers[count].jackPotNumbers.push_back(value);
        }

        fileIn.ignore();

        answer = findMatches(scratchers);
    }

    cout << answer << endl;

    return 0;
}


/// @brief compares two vectors for pairs, and calculates the value returned
/// @param myNumbers 
/// @param jackPotNumbers 
/// @return value of pts
int findMatches(std::vector<numbers>& a){
    int matches = 0;
    int value = 0;


    // we start count at 0, 
        // check for matches
        // add # of matches starting at i = count ; < # of matches ; i++;
            // add is just a pushback now
        
    for (int i = 0 ; i < a.size() ; i++){
        matches = 0;
        for (int j = 0 ; j < a[j].myNumbers.size() ; j++){
            if (std::find(a[j].jackPotNumbers.begin(), a[j].jackPotNumbers.end(), 
                        a[j].myNumbers.at(j)) != a[j].jackPotNumbers.end()){
                matches++;
            }
        }

        for (int k = 1; k < matches ; k++){
            // If duplicate is found calculate number of matches for the card
            // copy and insert the folling cards into the vector at current index + 1
            // 
            a.insert(a.at(i+1),a[i+k]);
            
        }
    }

    if (matches > 0){
        value = pow(2, matches-1);
    }

    return value;
};



