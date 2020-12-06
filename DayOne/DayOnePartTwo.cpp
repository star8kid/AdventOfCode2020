#include<iostream>
#include<vector>
#include<numeric>
#include<fstream>

using namespace std;

/* 
    Part Two Time: 1 Hour 18 Minutes 45 Seconds
    Yes, I don't know why it took longer than the first part too. Don't bully me.
*/

template <class iterable>
void allElements(vector<iterable> inputVector){
    for(int i = 0; i < inputVector.size(); i++){
        cout << inputVector[i] << endl;
    }
}

void expenseTrioCalc(string inputFileName){
    string fileLine;
    ifstream inputFile(inputFileName);
    vector<int> fileIntegerValues = {};
    vector<int> integerValueTrio = {};
    vector<int> potentialProducts = {};
    if(inputFile.is_open()){
        while(getline(inputFile,fileLine)){
            fileIntegerValues.push_back(stoi(fileLine));
        }
    }
    inputFile.close();
    for(int a = 0; a < fileIntegerValues.size(); a++){
        for(int b = a + 1; b < fileIntegerValues.size(); b++){
            for(int c = a + 2; c < fileIntegerValues.size(); c++){
                integerValueTrio.push_back(fileIntegerValues[a]);
                integerValueTrio.push_back(fileIntegerValues[b]);
                integerValueTrio.push_back(fileIntegerValues[c]);
                if( accumulate(integerValueTrio.begin(),integerValueTrio.end(),0) == 2020 ){
                    potentialProducts.push_back(integerValueTrio[0] * integerValueTrio[1] * integerValueTrio[2]);
                    integerValueTrio.clear();
                }
                else{
                    integerValueTrio.clear();
                }
            }
        }
    }
    allElements(potentialProducts);
}

int main(){
    expenseTrioCalc("dayOneInput.txt");
}