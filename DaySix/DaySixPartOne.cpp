#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

// Total Timestamp: About 21 minutes 38 seconds
// First Timestamp ( I accidentally reset my stopwatch D: ): About 21 minutes 38 seconds
// Second Timestamp: 54 minutes 33 seconds

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

int uniqueGroupAnswersSum(string inputFileName){

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
    inputFile.close();
    elementsOfTwoDim(tempAllGroupsAnswers);

    // Second, count the unique responses and place them in a temp vector. Add in a condition so that, if the
    // element selected is already inside the vector, it does not count.

    int totalUniqueAnswers = 0;
    int tempUniqueAnswersCount = 0;
    vector<char> tempUniqueAnswersType = {};

    // for(int a = 0; a < tempAllGroupsAnswers.size(); a++){
    //     for(int b = 0; b < tempAllGroupsAnswers[a].size(); b++){
    //         for(int c = 0; c < tempAllGroupsAnswers[a][b].length(); c++){
    //             if(tempUniqueAnswersType.)
    //         }
    //     }
    // }


    return 0;
}


int main (){
    // cout << uniqueGroupAnswersSum("inputSmall.txt");

    vector<char> testCharVec = {'a','c','d','n'};
    auto it = find(testCharVec.begin(),testCharVec.end(), 'b');
    if (it == testCharVec.end()){
        cout << "This element was not found in my vector" << endl;
    }
    else{
        cout << "This element was found in my vector" << endl;
    }
}