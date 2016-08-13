#include <bits/stdc++.h>
using namespace std;

void rec(vector<int> &A, vector<int> &B, vector<int> &S, int pos){

    if(pos == S.size()){
        if(A.size() && B.size()){
            for(int i = 0; i < A.size(); i++) cout << A[i] << ",";
            cout << "\n";
            for(int i = 0; i < B.size(); i++) cout << B[i] << ",";
            cout << "\n\n";
        }
    }

    else{
        A.push_back(S[pos]);
        rec(A, B, S, pos + 1);
        A.pop_back();

        B.push_back(S[pos]);
        rec(A, B, S, pos + 1);
        B.pop_back();

        rec(A, B, S, pos + 1);
    }

}

int main(){

    vector<int> A, B, S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(3);
    //S.push_back(4);

    rec(A, B, S, 0);

	return 0;

}
