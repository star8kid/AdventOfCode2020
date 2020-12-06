#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

int validPassInstances(string inputFileName){

    vector<int> minIntgerValues = {};
    vector<int> maxIntegerValues= {};
    vector<char> policiedChar = {};
    vector<string> potentialPass = {};
    int vaildPasswords = 0;
    int passwordCount = 0;

    string fileLine;
    ifstream inputFile(inputFileName);
    if(inputFile.is_open()){
        while(getline(inputFile,fileLine)){
            //Zero: Definitions
            string extremesUnsortedString;
            string extremeValueString = "";
            int extremeValueInt;
            int policyCharCount = 0;
            // One: Get the corporate policy, A.K.A, the char being counted
            policiedChar.push_back(fileLine[fileLine.find(":") - 1]);
            // Two: Get the password that was set at the time
            potentialPass.push_back(fileLine.substr(fileLine.find(":") + 2, fileLine.length() - fileLine.find(":")));
            // Three: Get the minimum and maximum values for the policy
            extremesUnsortedString = fileLine.substr(0,fileLine.find(":") - 2);
            for(int a = 0; a < extremesUnsortedString.length(); a++){
                if(extremesUnsortedString[a] == '-'){
                    //Minimum value gotten here
                    extremeValueInt = stoi(extremeValueString);
                    minIntgerValues.push_back(extremeValueInt);
                    extremeValueString = "";
                }
                else{
                    extremeValueString.push_back(extremesUnsortedString[a]);
                }
            }
            //Max here
            extremeValueInt = stoi(extremeValueString);
            maxIntegerValues.push_back(extremeValueInt);
            //Four: Test the values here because efficiency. If the policy works with the password, the counter increases.
            for(int b = 0; b < potentialPass[passwordCount].length(); b++){
                if(potentialPass[passwordCount][b] == policiedChar[passwordCount]){
                    policyCharCount++;
                }
            }
            if((minIntgerValues[passwordCount] <= policyCharCount) && (policyCharCount <= maxIntegerValues[passwordCount])){
                vaildPasswords++;
            }
            passwordCount++;
        }
    }
    //Five: Give back to the cause
    return vaildPasswords;
}

int main(){
    cout << validPassInstances("PartTwoInput.txt");
}