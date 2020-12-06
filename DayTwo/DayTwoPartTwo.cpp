#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

int validPassInstancesAgain(string inputFileName){

    vector<int> firstIndexPossibilities = {};
    vector<int> secondIndexPossibilities = {};
    vector<char> policiedChar = {};
    vector<string> potentialPass = {};
    int vaildPasswords = 0;
    int passwordCount = 0;

    string fileLine;
    ifstream inputFile(inputFileName);
    if(inputFile.is_open()){
        while(getline(inputFile,fileLine)){
            //Zero: Definitions
            string indiciesUnsortedString;
            string indiciesValueString = "";
            int indiciesValueInt;
            int policyCharCount = 0;
            // One: Get the corporate policy, A.K.A, the char being counted
            policiedChar.push_back(fileLine[fileLine.find(":") - 1]);
            // Two: Get the password that was set at the time
            potentialPass.push_back(fileLine.substr(fileLine.find(":") + 2, fileLine.length() - fileLine.find(":")));
            // Three: Get the indicies for the policy
            indiciesUnsortedString = fileLine.substr(0, fileLine.length() - (fileLine.find(":") - 2));
            for (int a = 0; a < indiciesUnsortedString.length(); a++){
                if(indiciesUnsortedString[a] == '-'){
                    //Minimum value gotten here
                    indiciesValueInt = stoi(indiciesValueString);
                    firstIndexPossibilities.push_back(indiciesValueInt);
                    indiciesValueString = "";
                }
                else{
                    indiciesValueString.push_back(indiciesUnsortedString[a]);
                }
            }
            indiciesValueInt = stoi(indiciesValueString);
            secondIndexPossibilities.push_back(indiciesValueInt);
            // Four: Seize them
            // Check if index one is same as the policied char and not index two
            if((potentialPass[passwordCount][firstIndexPossibilities[passwordCount] - 1] == policiedChar[passwordCount]) && (potentialPass[passwordCount][secondIndexPossibilities[passwordCount] - 1] != policiedChar[passwordCount] )){
                vaildPasswords++;
            }
            // Check if index two is same as the policied char and not index one
            else if((potentialPass[passwordCount][firstIndexPossibilities[passwordCount] - 1] != policiedChar[passwordCount]) && (potentialPass[passwordCount][secondIndexPossibilities[passwordCount] - 1] == policiedChar[passwordCount] )){
                vaildPasswords++;
            }
            passwordCount++;
        }
    }
    // Five: Give back to the cause once more (please no more nonsense).
    return passwordCount;
}

int main(){
    cout << validPassInstancesAgain("SamplePartTwoInput.txt");

}