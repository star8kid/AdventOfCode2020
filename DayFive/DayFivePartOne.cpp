#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main(){

    string tempString;
    vector<string> planeSeatPartitions = {};

    while(true){
        bool is_valid_input = bool (cin >> tempString);
        planeSeatPartitions.push_back(tempString);
        if (is_valid_input == false){
            break;
        }
    }

    int XValue;
    int YValue;
    pair <int,int> planeCoordinates(XValue,YValue);
    vector<int> planeSeatIDS = {};

    // X Coordinate Definitions
    int highestXValue = 127;
    int lowestXValue = 0;
    int upperXValue = highestXValue;
    int lowerXValue = lowestXValue;
    pair <int,int> boundsXValue (lowerXValue, upperXValue);
    // Y Coordinate Definitions
    int highestYValue = 7;
    int lowestYValue = 0;
    int upperYValue = highestYValue;
    int lowerYValue = lowestYValue;
    pair <int,int> boundsYValue (lowerYValue, upperYValue);

    for(int a = 0; a < planeSeatPartitions.size(); a++){
        // For Loop to find the X Value
        for(int b = 0; b < 7; b++){
            if(b == 6){
                if(planeSeatPartitions[a][b] == 'F'){
                    XValue = boundsXValue.first;
                }
                else{
                    XValue = boundsXValue.second;
                }
            }
            else{
                if (planeSeatPartitions[a][b] == 'F'){
                    // 'Lower Half' case
                    upperXValue = ((upperXValue + lowerXValue + 1) / 2);
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
                    YValue = boundsYValue.first;
                }
                else{
                    YValue = boundsYValue.second;
                }
            }
            else{
                if (planeSeatPartitions[a][c] == 'L'){
                    // 'Lower Half' case
                    upperYValue = ((upperYValue + lowerYValue + 1) / 2);
                }
                else if(planeSeatPartitions[a][c] == 'R'){
                    // 'Upper Half' case
                    lowerYValue = ((upperYValue + lowerYValue + 1) / 2);
                }
            }
        }
        // Seat ID Calculations
        planeSeatIDS.push_back((planeCoordinates.first * 8) + planeCoordinates.second);
        // Reset the values for looping again
        upperXValue = 127;
        lowerXValue = 0;
        upperYValue = 7;
        lowerYValue = 0;
    }
    cout << *max_element(planeSeatIDS.begin(), planeSeatIDS.end()) << endl;
    return *max(planeSeatIDS.begin(),planeSeatIDS.end());
}
