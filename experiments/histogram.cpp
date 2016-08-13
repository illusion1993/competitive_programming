#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main(){

    vector<int> A;
    A.push_back(90);
    A.push_back(58);
    A.push_back(69);
    A.push_back(70);
    A.push_back(82);
    A.push_back(100);
    A.push_back(13);
    A.push_back(57);
    A.push_back(47);
    A.push_back(18);

   int max = INT_MIN, localMax;

    for(int i = 0; i < A.size(); i++){

        cout << "Finding min for elem " << A[i] << endl;

        localMax = A[i];
        int j = i + 1;

        while(A[j] >= A[i] && j < A.size()){
            localMax += A[j];

            cout << A[j] << " accepted" << endl;

            j++;
        }

        j = i - 1;
        while(A[j] >= A[i] && j >= 0){
            localMax += A[j];

            cout << A[j] << " accepted" << endl;

            j--;
        }

        cout << "local Max was : " << localMax << " for elem " << A[i] << endl;
        if(localMax > max) max = localMax;

    }

    return max;

}
