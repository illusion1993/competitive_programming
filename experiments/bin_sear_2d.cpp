#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector< vector<int> > A;
    int B = 51;


    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    A.push_back(v);
    v.clear();
    v.push_back(10);
    v.push_back(11);
    v.push_back(16);
    v.push_back(20);
    A.push_back(v);
    v.clear();
    v.push_back(23);
    v.push_back(30);
    v.push_back(34);
    v.push_back(50);
    A.push_back(v);
    v.clear();




    //////////////////////////////////////////////
    int start = 0, stop = A.size() - 1, r = -1, c = -1;

    while(start <= stop){

        int mid = (start + stop) / 2;

        if(A[mid][0] <= B && A[mid].back() >= B){
            r = mid;
            break;
        }

        else if(start != stop && A[mid].back() < B){
            start = mid + 1;
        }

        else if(start != stop && A[mid][0] > B){
            stop = mid - 1;
        }

        else if(start == stop && (A[mid][0] > B || A[mid].back() < B)){
            r = -1;
            break;
        }

    }

    if(r == -1) return 0;

    start = 0;
    stop = A[r].size() - 1;

    while(start <= stop){

        int mid = (start + stop) / 2;

        if(A[r][mid] == B){
            c = mid;
            break;
        }

        else if(start != stop && A[r][mid] < B){
            start = mid + 1;
        }

        else if(start != stop && A[r][mid] > B){
            stop = mid - 1;
        }

        else if(start == stop && A[r][mid] != B){
            c = -1;
            break;
        }

    }

    if(c == -1 || r == -1) return 0;
    else return 1;




    ///////////////////////////////////////////////
    cout << pos;



    return 0;

}
