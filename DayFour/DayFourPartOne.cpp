#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <typeinfo>

using namespace std;

// Current Timelapse: 3 hours 50 minutes 28 seconds

template <class Value>

void elementsOf(vector<Value> inputVector){
    cout << "The elements of this vector are: [" << endl;
    for (int a = 0; a < inputVector.size(); a++){
        if(a == inputVector.size() - 1){
            cout << inputVector[a] << "]" << endl;
        }
        else{
        cout << inputVector[a] << "," << endl;
        }
    }
}

int passportValidator(string inputFileName){

    string fileLineString;
    ifstream inputFile(inputFileName);
    vector<string> tempPassVector = {};
    string wholePassString = "";
    vector<string> wholePassVector = {};

    if(inputFile.is_open()){
        while(getline(inputFile,fileLineString)){
            if(fileLineString == ""){
                // cout << "A BREAK IN THE INPUT HAS BEEN FOUND!!" << endl;
                for( int a = 0; a < tempPassVector.size(); a++ ){
                    if(a == 0){
                        wholePassString.append(tempPassVector[a]);
                    }
                    else{
                        wholePassString.append(" " + tempPassVector[a]);
                    }
                }
                wholePassVector.push_back(wholePassString);
                wholePassString = "";
                tempPassVector = {};
            }
            else{
                tempPassVector.push_back(fileLineString);
            }
        }
        for( int a = 0; a < tempPassVector.size(); a++ ){
            if(a == 0){
                wholePassString.append(tempPassVector[a]);
            }
            else{
                wholePassString.append(" " + tempPassVector[a]);
            }
        }
        wholePassVector.push_back(wholePassString);
        wholePassString = "";
        tempPassVector = {};
    }
    inputFile.close();
    elementsOf(wholePassVector);
    int numPassValid = 0;
    for( int b = 0; b < wholePassVector.size(); b++){
        if( bool(wholePassVector[b].find("byr") != string::npos) && bool(wholePassVector[b].find("iyr") != string::npos) && bool(wholePassVector[b].find("eyr") != string::npos) && bool(wholePassVector[b].find("hgt") != string::npos) && bool(wholePassVector[b].find("hcl") != string::npos) && bool(wholePassVector[b].find("ecl") != string::npos)&& bool(wholePassVector[b].find("pid") != string::npos) && bool(wholePassVector[b].find("cid") != string::npos) ){
            cout << "The passport at " << b << " was valid" << endl;
            numPassValid++;
            continue;
        }
        else if( bool(wholePassVector[b].find("byr") != string::npos) && bool(wholePassVector[b].find("iyr") != string::npos) && bool(wholePassVector[b].find("eyr") != string::npos) && bool(wholePassVector[b].find("hgt") != string::npos) && bool(wholePassVector[b].find("hcl") != string::npos) && bool(wholePassVector[b].find("ecl") != string::npos)&& bool(wholePassVector[b].find("pid") != string::npos) && bool(wholePassVector[b].find("cid") == string::npos) ){
            cout << "The passport at " << b << " was valid" << endl;
            numPassValid++;
            continue;
        }
        else{
            continue;
        }
    }
    cout << numPassValid << endl;
    return numPassValid;
}


int main(){

    passportValidator("input.txt");

    /*
    
    Here,
    A "1" means that the field is there
    
    
    */
    // string testString = "byr:1985 eyr:2021 iyr:2011 hgt:175cm pid:163069444 hcl:#18171d";
    // cout << bool(testString.find("byr") != string::npos) << endl;
    // cout << bool(testString.find("iyr") != string::npos) << endl;
    // cout << bool(testString.find("eyr") != string::npos) << endl;
    // cout << bool(testString.find("hgt") != string::npos) << endl;
    // cout << bool(testString.find("hcl") != string::npos) << endl;
    // cout << bool(testString.find("ecl") != string::npos) << endl;
    // cout << bool(testString.find("pid") != string::npos) << endl;
    // cout << bool(testString.find("cid") != string::npos) << endl;


    // int testIntger;
    // cout << (typeid(testIntger).name() == 'i');

}