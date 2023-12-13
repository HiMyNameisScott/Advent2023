#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    size_t times[4] = {40817772};
    size_t distances[4] = {219101213651089};


    // Every millisecond held is a millisecond from the total time
    // Total Time = times[@]
    // Every millisecond held is the speed at which the boat travels
    // Time Left = times[@] - time held
    // lower bounds = 1 upper bounds = times[i]

    // Cycle from 1 -> i
        // i = time Held
        // speed = time held
        // time left = times[i] - timeheld/speed
        // distance = speed * time leftf
        // check to see if distance > 219, if > 219 then add too total.

        size_t solution = 1;

        for (size_t i = 0 ; i < 1 ; i++){
            size_t canBeat = 0;
            for (size_t j = 1 ; j <= times[i] ; j++){
                size_t timeLeft = times[i] - j; 
                size_t distanceTravelled = j * timeLeft;
                
                if (distanceTravelled > distances[i]){
                    canBeat ++;
                }

            }
            solution = solution * canBeat;
        }

        cout << "solution : " << solution;

    return 0;
}

// You know it. Saving is for plebs. 

// 2 gold stars bb

// All the cores, I believe it would for something like this