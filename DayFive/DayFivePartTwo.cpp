#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

// Full Timelapse: 1 hour 54 minutes 55 seconds

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
        for (int b = 0; b < inputVector.size(); b++){
            if(b == inputVector.size() - 1){
                cout << inputVector[a][b] << "]" << endl;
            }
            else{
                cout << inputVector[a][b] << ",";
            }
        }
    }
    cout << "]" << endl;
}



bool firstElementComp(vector<int> inputVecOne, vector<int> inputVecTwo){
    return inputVecOne[0] < inputVecTwo[0];
}

/*

    Just to imagine this better, here is a self-note of the type of grid
    I want to create of the plane:

    [                
        [0,2],[1,2],[2,2]
        [0,1],[1,1],[2,1]
        [0,0],[1,0],[2,0]   
    ]

*/


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
    // Values and Coordinate Vector
    int XValue;
    int YValue;
    vector< vector<int> > planeSeatCoordinates = {};

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
        // Seat Coordinates Storing 
        vector<int> seatCoordinates = {XValue,YValue};
        cout << "The Current X Value is: " << XValue << endl;
        cout << "The Current Y Value is: " << YValue << endl;
        elementsOf(seatCoordinates);
        cout << "The length of this element vector in the vector container is: " << planeSeatCoordinates[a].size() << endl;
        planeSeatCoordinates.push_back(seatCoordinates);
        cout << "This has successfully ran" << endl;
        // Reset the values for looping again
        upperXValue = 127;
        lowerXValue = 0;
        upperYValue = 7;
        lowerYValue = 0;
        // Potential Reset Fix?
        XValue = 0;
        YValue = 0;
    }



    cout << endl;
    cout << endl;
    cout << endl;
    cout << "The length of this element vector in the vector container is: " << planeSeatCoordinates[0].size() << endl;
    cout << "This is that vector:" << endl;
    elementsOf(planeSeatCoordinates[0]);

    // BFFFBBFRRR
    // FFFBBBFRRR
    // BBFFBBFRLL


    // elementsOfTwoDim(planeSeatCoordinates);
    
    // vector<vector<int>> twoDimTestVec = {};
    // vector<int> testVecOne = {1,5,7};
    // vector<int> testVecTwo = {2,9,1};
    // vector<int> testVecThree = {3,4,6};
    // twoDimTestVec.push_back(testVecThree);
    // twoDimTestVec.push_back(testVecOne);
    // twoDimTestVec.push_back(testVecTwo);

    // cout << "Before the first element sort:" << endl;
    // elementsOfTwoDim(twoDimTestVec);

    // sort(twoDimTestVec.begin(), twoDimTestVec.end(), firstElementComp);

    // cout << "After the first element sort:" << endl;
    // elementsOfTwoDim(twoDimTestVec);

    elementsOfTwoDim(planeSeatCoordinates);

}