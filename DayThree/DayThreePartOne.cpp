#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Current Time Lapse: 15 minutes and 51 seconds
// Adding-On Time Laspe (because my stopwatch accidentally reset from before): 85 minutes and 25 seconds
// Total Time Lapse: 101 minutes 16 seconds

/*


    SOLUTION SPOILERS AHEAD!!!!!!!!!!!!!!!!!!


*/

// Idea 1
// Count the vertical length of the strings and, incorporating the use of slope, increase
// the horizontal length of the strings until the slope will attach the quadraletial corners together in a single,
// diagonal 


// Idea 2
// Do some fancy interation math and just do downwards by the "rise" of the slope and go toward the right by the
// "run" of the slope. If the "run" is too much and overshoots the current land input, do fancy math to 
// move the iterator to the other side of the string and continue interating.

// Time to try Idea 2 :o
//


int treeSlopeInterceptCount(vector<string> inputMap, int riseSlope, int runSlope){

    int treeCount = 0;
    int currentXValue = 0;
    int currentYValue = 0;

    while(true){

        // cout << "The current coordinate is: [" << currentXValue << "," << currentYValue << "]" << endl;
        // Checks if the current coordinate point is a tree and increments the count if it is
        if( inputMap[currentYValue][currentXValue] == '#' ){
            treeCount++;
        }

        // Checks if the next coordinate point down by the "rise" of the slope
        // slope would be possible. If not, it breaks because that'd be the end of the map.
        if( (currentYValue + -riseSlope) <= inputMap.size() - 1 ){
            currentYValue += -riseSlope;
        }
        else{
            break;
        }

        if( (currentXValue + runSlope) <= inputMap[0].length() - 1 ){
            currentXValue += runSlope;
        }
        // Checks to see if the next x value in the coordinate point would be in
        // the same string. If it is not, it checks to see how much further it is from
        // the end of the string, substracts that from the slope, and uses the remainder at
        // the start of the same string to represent the horizontal cross over.
        else{
            currentXValue = currentXValue - (inputMap[0].length()) + runSlope;
        }
        // cout << "The the next checking coordinate is: [" << currentXValue << "," << currentYValue << "]" << endl;
    }
    cout << "The amount of trees intercepted is: " << treeCount << endl;
    return treeCount;
}

int main(){

    string tempString;
    vector<string> landMapMatrix;

    while(true){
        bool is_valid_input = bool (cin >> tempString);
        landMapMatrix.push_back(tempString);
        if (is_valid_input == false){
            break;
        }
    }

    treeSlopeInterceptCount(landMapMatrix, -1, 3);

}