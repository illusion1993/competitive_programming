#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main(){

    vector<int> A, B;

    B.push_back(20);




    int l = A.size() + B.size(), medianPos = l/2, ptr1 = 0, ptr2 = 0, l1 = 0;
    double median = 0;

    bool even = !(l % 2);

    cout << "l is : " << l << ", medianPos is : " << medianPos << ", even is: " << even << endl;

    while(l1 < l){

        if(ptr1 < A.size() && ptr2 < B.size() && A[ptr1] <= B[ptr2]){

            ptr1++;

            if(even && (l1 == medianPos - 1 || l1 == medianPos))
                median += (double)A[ptr1];

            else if(!even && l1 == medianPos)
                median += (double)A[ptr1];


        }

        else if(ptr1 < A.size() && ptr2 < B.size() && A[ptr1] > B[ptr2]){

            ptr2++;

            if(even && (l1 == medianPos - 1 || l1 == medianPos))
                median += (double)B[ptr2];

            else if(!even && l1 == medianPos)
                median += (double)B[ptr2];

        }

        else if(ptr1 >= A.size() && ptr2 < B.size()){

            ptr2++;

            if(even && (l1 == medianPos - 1 || l1 == medianPos))
                median += (double)B[ptr2];

            else if(!even && l1 == medianPos)
                median += (double)B[ptr2];

        }

        else if(ptr1 < A.size() && ptr2 >= B.size()){

            ptr1++;

            if(even && (l1 == medianPos - 1 || l1 == medianPos))
                median += (double)A[ptr1];

            else if(!even && l1 == medianPos)
                median += (double)A[ptr1];

        }

        l1++;
    }

    if(even) return median / 2;
    else return median;







}
