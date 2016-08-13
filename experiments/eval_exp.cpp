#include <bits/stdc++.h>
#include<sstream>

using namespace std;

int main(){

    vector<string> A;
    A.push_back("-500");
    A.push_back("-10");
    A.push_back("/");





    stack<int> opnd;
    //stack<char> optr;

    int op1, op2, ans;

    for(int i = 0; i < A.size(); i++){
        if(A[i][0] >= '0' && A[i][0] <= '9'){
            string s = A[i];
            opnd.push(stoi(s));
        }

        else{

            op2 = opnd.top();
            opnd.pop();
            op1 = opnd.top();
            opnd.pop();

            if(A[i] == "+"){
                opnd.push(op1 + op2);
            }
            else if(A[i] == "-"){
                opnd.push(op1 - op2);
            }
            else if(A[i] == "/"){
                opnd.push(op1 / op2);
            }
            else if(A[i] == "*"){
                opnd.push(op1 * op2);
            }
        }
    }



    return opnd.top();

}
