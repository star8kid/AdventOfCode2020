#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

// Full Timelapse: 2 hours 56 minutes 48 seconds

// A helper function. Ignore it.
template <class Element>

void elementsOf(vector<Element> inputVector){
    cout << "The elements of this vector are: [";
    for (int a = 0; a < inputVector.size(); a++){
        if(a == inputVector.size() - 1){
            cout << inputVector[a] << "]" << endl;
        }
        else{
        cout << inputVector[a] << ",";
        }
    }
}

// A second helper function.

template <class TwoDimElement>
void elementsOfTwoDim(vector<vector<TwoDimElement>> inputVector){
    cout << "The elements of this two dimensional vector are:" << endl << "[" << endl;
    for (int a = 0; a < inputVector.size(); a++){
        cout << "   [";
        for (int b = 0; b < inputVector[a].size(); b++){
            if(b == inputVector[a].size() - 1){
                cout << inputVector[a][b] << "]" << endl;
            }
            else{
                cout << inputVector[a][b] << ",";
            }
        }
    }
    cout << "]" << endl;
}

int main(){

    string tempString;
    vector<string> planeSeatPartitions = {};

    while(true){
        bool is_valid_input = bool (cin >> tempString);
        if (is_valid_input == false){
            break;
        }
        else{
            planeSeatPartitions.push_back(tempString);
        }
    }
    // X Coordinate Definitions
    int upperXValue = 127;
    int lowerXValue = 0;
    // Y Coordinate Definitions
    int upperYValue = 7;
    int lowerYValue = 0;
    // Values and ID Vector
    int XValue;
    int YValue;
    vector<int> planeSeatIDS = {};

    for(int a = 0; a < planeSeatPartitions.size(); a++){
        // For Loop to find the X Value
        for(int b = 0; b < 7; b++){
            if(b == 6){
                if(planeSeatPartitions[a][b] == 'F'){
                    XValue = lowerXValue;
                }
                else{
                    XValue = upperXValue;
                }
            }
            else{
                if (planeSeatPartitions[a][b] == 'F'){
                    // 'Lower Half' case
                    upperXValue = int(floor((upperXValue + lowerXValue) / 2));
                }
                else if(planeSeatPartitions[a][b] == 'B'){
                    // 'Upper Half' case
                    lowerXValue = ((upperXValue + lowerXValue + 1) / 2);
                }
            }
        }
        // For Loop to find the Y Value
        for(int c = 7; c < 10; c++){
            if(c == 9){
                if(planeSeatPartitions[a][c] == 'L'){
                    YValue = lowerYValue;
                }
                else{
                    YValue = upperYValue;
                }
            }
            else{
                if (planeSeatPartitions[a][c] == 'L'){
                    // 'Lower Half' case
                    upperYValue = int(floor((upperYValue + lowerYValue) / 2));
                }
                else if(planeSeatPartitions[a][c] == 'R'){
                    // 'Upper Half' case
                    lowerYValue = ((upperYValue + lowerYValue + 1) / 2);
                }
            }
        }
        // Seat ID Calculations
        pair <int,int> planeCoordinates(XValue,YValue);
        planeSeatIDS.push_back((planeCoordinates.first * 8) + planeCoordinates.second);
        // Reset the values for looping again
        upperXValue = 127;
        lowerXValue = 0;
        upperYValue = 7;
        lowerYValue = 0;
    }

    sort(planeSeatIDS.begin(), planeSeatIDS.end());

    // I'm thinking that one ID element that is two away from the next one instead
    // of a single value away shows that that's the boarding pass missing: my seat id.

    vector<vector<int>> potentialAdjSeatIdsPairVector = {};
    vector<int> potentialAdjSeatIds = {};
    for (int d = 0; d < planeSeatIDS.size(); d++){
        if ((planeSeatIDS[d] + 2) == planeSeatIDS[d + 1]){
            potentialAdjSeatIds.push_back(planeSeatIDS[d]);
            potentialAdjSeatIds.push_back(planeSeatIDS[d + 1]);
            potentialAdjSeatIdsPairVector.push_back(potentialAdjSeatIds);
            potentialAdjSeatIds.clear();
        }
    }
    cout << "My seat ID is the number in between the two numbers of the vector below:" << endl;
    elementsOfTwoDim(potentialAdjSeatIdsPairVector);
}
