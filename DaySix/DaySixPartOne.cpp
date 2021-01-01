#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

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
    string fileLine;
    ifstream inputFile(inputFileName);
    vector<vector<string>> tempGroupAnswers = {};
    vector<string> tempPersonAnswers = {};
        if(inputFile.is_open()){
        while(getline(inputFile,fileLine)){
            if( fileLine == "" ){
                tempGroupAnswers.push_back(tempPersonAnswers);
                tempPersonAnswers.clear();

            }
            else{
                tempPersonAnswers.push_back(fileLine);
            }
        }
    }
    inputFile.close(); 

    elementsOfTwoDim(tempGroupAnswers);
    return 0;
}


int main (){
    cout << uniqueGroupAnswersSum("inputSmall.txt");
}