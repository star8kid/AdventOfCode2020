#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Part One Time: 56 minutes 15 seconds

int expenseCalc(string inputFileName){
    string fileLine;
    ifstream inputFile(inputFileName);
    vector<int> fileIntegerValues = {};
    if(inputFile.is_open()){
        while(getline(inputFile,fileLine)){
            fileIntegerValues.push_back(stoi(fileLine));
        }
    }
    inputFile.close();
    for(int a = 0; a < fileIntegerValues.size(); a++){
        for( int b = a; b < fileIntegerValues.size(); b++){
            if((fileIntegerValues[a] + fileIntegerValues[b]) == 2020){
                return fileIntegerValues[a] * fileIntegerValues[b];
            }
        }
    }
}

int main(){
    cout << expenseCalc("dayOneInput.txt");
}