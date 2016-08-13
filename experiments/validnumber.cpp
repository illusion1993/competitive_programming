#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string A = "+      ";

    int state = 0;
    vector< vector<int> > transition;

    vector<int> row;

    row.push_back(10);
    row.push_back(1);
    row.push_back(6);
    row.push_back(9);
    row.push_back(0);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(10);
    row.push_back(2);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(3);
    row.push_back(10);
    row.push_back(2);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(10);
    row.push_back(4);
    row.push_back(5);
    row.push_back(10);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(10);
    row.push_back(4);
    row.push_back(10);
    row.push_back(7);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(10);
    row.push_back(4);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(8);
    row.push_back(5);
    row.push_back(6);
    row.push_back(10);
    row.push_back(7);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);
    row.push_back(7);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(10);
    row.push_back(4);
    row.push_back(5);
    row.push_back(10);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(1);
    row.push_back(6);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);
    row.push_back(10);

    transition.push_back(row);
    row.clear();

    int ptr = 0;
    cout << "Initial state is : " << state << endl;
    while(ptr < A.length()){

        cout << endl << "Encountered " << A[ptr] << ", at state " << state << endl;

        if(A[ptr] == 'e'){
            cout << "Going to state transition[" << state << "][0], which is : " << transition[state][0] << endl;
            state = transition[state][0];
        }
        else if(A[ptr] == '.'){
            cout << "Going to state transition[" << state << "][1], which is : " << transition[state][1] << endl;
            state = transition[state][1];
        }
        else if((int)A[ptr] >= 48 && (int)A[ptr] <= 57){
            cout << "Going to state transition[" << state << "][2], which is : " << transition[state][2] << endl;
            state = transition[state][2];
        }
        else if(A[ptr] == '+' || A[ptr] == '-'){
            cout << "Going to state transition[" << state << "][3], which is : " << transition[state][3] << endl;
            state = transition[state][3];
        }
        else if(A[ptr] == ' '){
            cout << "Going to state transition[" << state << "][4], which is : " << transition[state][4] << endl;
            state = transition[state][4];
        }
        else{
            cout << "Going to state transition[" << state << "][5], which is : " << transition[state][5] << endl;
            state = transition[state][5];
        }

        ptr++;
    }

    cout << endl <<"Final state is : " << state << endl;
    if(state == 2 || state == 4 || state == 6 || state == 7) return 1;
    else return 0;











    return 0;

}
