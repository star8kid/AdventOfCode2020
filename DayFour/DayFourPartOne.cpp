#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// Current Timelapse: 1 hour 8 minutes 39 seconds

int passportValidator(string inputFileName){

    string fileLineString;
    ifstream inputFile(inputFileName);
    vector<string> tempPassVector = {};
    vector<string> wholePassVector = {};

    if(inputFile.is_open()){
        while(getline(inputFile,fileLineString)){
            if(fileLineString == ""){
                cout << "A BREAK IN THE INPUT HAS BEEN FOUND!!" << endl;
                break;
            }
            // else{
            // tempPassVector.push_back(fileLineString);
            // }
            tempPassVector.push_back(fileLineString);
        }
    }
    inputFile.close();

    for(int a = 0; a < tempPassVector.size(); a++){
        cout << tempPassVector[a] << endl;
    }

    cout << tempPassVector.size() << endl;
    // cout << bool(tempPassVector[2] == "") << endl;
    return tempPassVector.size();

}



int main(){



    // Append the first string/newline without spaces, then on any additional line, append but put
    // a space string beforehand to separate them neatly.


    // while(true){
    //     bool isValidInput = bool ( cin >> tempString );
    //     if(tempString == ""){
    //         break;
    //     }
    //     tempPassVector.push_back(tempString);
    //     if (isValidInput == false){
    //         break;
    //     }
    // }


    passportValidator("testInput.txt");


    // map<string,int> nameAge;
    // nameAge["Jess"] = 15;
    // cout << bool(nameAge["Jess"]) << endl;


}