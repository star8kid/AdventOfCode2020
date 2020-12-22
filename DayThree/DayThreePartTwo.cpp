#include<iostream>
#include<string>
#include<vector>

using namespace std;


//Time Lapse: 28 minutes and 37 seconds
// (Yeah, I didn't know there were other datatypes than `int`, don't make fun of me)

uint64_t treeSlopeInterceptCount(vector<string> inputMap, int riseSlope, int runSlope){

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
    uint64_t treeCountProduct;
    while(true){
        bool is_valid_input = bool (cin >> tempString);
        landMapMatrix.push_back(tempString);
        if (is_valid_input == false){
            break;
        }
    }
    treeCountProduct = treeSlopeInterceptCount(landMapMatrix, -1 , 1) * treeSlopeInterceptCount(landMapMatrix, -1 , 3) * treeSlopeInterceptCount(landMapMatrix, -1 , 5) * treeSlopeInterceptCount(landMapMatrix, -1, 7) * treeSlopeInterceptCount(landMapMatrix, -2 , 1);
    // treeCountProduct = treeSlopeInterceptCount(landMapMatrix, -1 , 1) * treeSlopeInterceptCount(landMapMatrix, -1 , 3) * treeSlopeInterceptCount(landMapMatrix, -1 , 5) * treeSlopeInterceptCount(landMapMatrix, -1, 7);
    // treeCountProduct = treeSlopeInterceptCount(landMapMatrix, -2,1);
    cout << treeCountProduct;
}