#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){


    vector<int> A;
    int B = 7;
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(7);
    A.push_back(0);
    A.push_back(1);
    A.push_back(2);


    //////////////////////////////////////////
    int rot, min = 1000, minIndex = -1;
    for(int i = 0; i < A.size(); i++){
        if(A[i] < min){
            min = A[i];
            minIndex = i;
        }
    }

    rot = minIndex;
    cout << "rot is " << rot << endl;

    sort(A.begin(), A.end());

    int start, stop, mid;
    start = 0;
    stop = A.size() - 1;

    while(start <= stop){
        int mid = (start + stop) / 2;

        if(A[mid] == B) return (mid + rot) % A.size();

        else if(start != stop && A[mid] < B)
            {
                start = mid + 1;
            }

        else if(start != stop && A[mid] > B)
            {
                stop = mid - 1;
            }

        else if(start != stop && A[mid] != B)
            return -1;
    }




    ///////////////////////////


    return 0;

}
