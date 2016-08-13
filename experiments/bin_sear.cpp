#include <iostream>
#include <vector>

using namespace std;

int bin_search(vector<int> &A, int start, int stop, int num){

    int mid = (start + stop) / 2;

    if(A[mid] == num) return mid+1;

    else if(start != stop && A[mid] < num)
        return bin_search(A, mid+1, stop, num);

    else if(start != stop && A[mid] > num)
        return bin_search(A, start, mid-1, num);

    else if(start != stop && A[mid] != num)
        return -1;

}

int main(){

    vector<int> A;

    int n, val;
    cout << "Enter size of array : " ;
    cin >> n;
    cout << "Enter elements : \n\n";

    while(n--){
        cin >> val;
        A.push_back(val);
    }

    cout << "\n\nWhat number to find ? ";
    cin >> val;

    cout << bin_search(A, 0, A.size()-1, val);


    return 0;

}
