#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Current Time Lapse: 15 minutes and 51 seconds

int treeSlopeInterceptCount(){

}

int main(){

    int landCycleLength;
    string tempString;
    vector<string> unsortedLand;
    cout << "Code has started!" << endl;

    while(true){
        // Can pipe in the input.txt using "<" in the gitbash terminal.
        bool is_valid_input = bool (cin >> tempString);
        unsortedLand.push_back(tempString);
        if (is_valid_input == false){
            break;
        }
    }
    cout << "Thing has been piped!" << endl;

    for(int a = 1; a < unsortedLand.size(); a++){
        if(unsortedLand[a] == unsortedLand[0]){
            landCycleLength = a - 1;
            break;
        }
    }

    //For now, get it to return the cycle length at which the pattern repeats
    return landCycleLength;


}