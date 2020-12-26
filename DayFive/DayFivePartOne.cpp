#include<iostream>
#include<vector>
#include<string>

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
    pair <int,int> boundsXValue (lowerXValue, highestXValue);
    // Y Coordinate Definitions
    int highestYValue = 7;
    int lowestYValue = 0;
    int upperYValue = highestYValue;
    int lowerYValue = lowestYValue;
    pair <int,int> boundsYValue (lowerYValue, upperYValue);

    for(int a = 0; a < planeSeatPartitions.size(); a++){
        for(int b = 0; b < 5; b++){
            if (planeSeatPartitions[a][b] == 'F'){
                
            }

        }
    }

}
