#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

// Total Timestamp: 23 minutes 53 seconds

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
        for (int b = 0; b < inputVector[a].size(); b++){
            if(b == inputVector[a].size() - 1){
                cout << inputVector[a][b] << "]" << endl;
            }
            else{
                cout << inputVector[a][b] << ",";
            }
        }
    }
    cout << "]" << endl;
}

int uniqueGroupEveryoneAnswersSum(string inputFileName){

    // First, read the groups responses and put them neatly in vectors.
    string fileLine;
    ifstream inputFile(inputFileName);
    vector<vector<string>> tempAllGroupsAnswers = {}; // This stores all the groups
    vector<string> tempGroupAnswers = {}; // This stores an individual group before being pushed into the other vector
        if(inputFile.is_open()){
        while(getline(inputFile,fileLine)){
            if( fileLine == "" ){
                tempAllGroupsAnswers.push_back(tempGroupAnswers);
                tempGroupAnswers.clear();
            }
            else{
                tempGroupAnswers.push_back(fileLine);
            }
        }
    }
    //Catch the last line of the file
    tempAllGroupsAnswers.push_back(tempGroupAnswers);
    tempGroupAnswers.clear();
    inputFile.close();

    // Second, store all the current unique letters in the group in a vector first
    // Third, read through each person's response in the group to see if it has all the unique letters;
    // If they don't have a unique letter, remove it from the vector. After this check is over, add the size of
    // the vector back to a tempEveryone integer variable.

    elementsOfTwoDim(tempAllGroupsAnswers);

    int sumOfEveryoneAnswers = 0;
    vector<char> tempUniqueAnswers = {};


    for (int a = 0; a < tempAllGroupsAnswers.size(); a++){
        // First double-for loop: Get unique characters of the whole group
        for (int b = 0; b < tempAllGroupsAnswers[a].size(); b++){
            for(int c = 0; c < tempAllGroupsAnswers[a][b].size(); c++){


            }
        }
    }
    return 0;
}

int main (){
    cout << uniqueGroupEveryoneAnswersSum("inputSmall.txt");
}