#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main(){

    static const int arr[] = {19, 20, 21, 22, 28, 29, 32, 36, 39, 40, 41, 42, 43, 45, 48, 49, 51, 54, 55, 56, 58, 60, 61, 62, 65, 67, 69, 71, 72, 74, 75, 78, 81, 84, 85, 87, 89, 92, 94, 95, 96, 97, 98, 99, 100, 105, 107, 108, 109, 110, 112, 113, 115, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 128, 130, 131, 133, 134, 135, 136, 137, 138, 139, 141, 142, 144, 146, 147, 148, 149, 150, 153, 155, 157, 159, 161, 163, 164, 169, 170, 175, 176, 179, 180, 185, 187, 188, 189, 192, 196, 199, 201, 203, 205, 3, 7, 9, 10, 12, 13, 17};
    vector<int> A (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    int B = 6;

    int min = INT_MAX, minIndex = -1;
    for(int i = 0; i < A.size(); i++){
        if(A[i] < min){
            min = A[i];
            minIndex = i;
        }
    }

    cout << "Min was :" << min << " found at " << minIndex << endl;

    int start, stop, mid;
    if(B <= A.back()){
        start = minIndex;
        stop = A.size() - 1;

        cout << " Start at " << start << " stop at " << stop << endl;
    }

    else{
        start = 0;
        stop = minIndex;

        cout << " Start at " << start << " stop at " << stop << endl;
    }

    while(start <= stop){
        int mid = (start + stop) / 2;

        if(A[mid] == B) return mid;

        else if(start != stop && A[mid] < B)
            {
                start = mid + 1;
            }

        else if(start != stop && A[mid] > B)
            {
                stop = mid - 1;
            }

        else if(start == stop && A[mid] != B)
            return -1;


        cout << " Start at " << start << " stop at " << stop << endl;
    }

}
