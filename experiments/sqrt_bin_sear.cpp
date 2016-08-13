#include <iostream>
#include <vector>

using namespace std;

int main(){

    int A;
    cin >> A;

    long long start = 0, stop = (A/2)+1, mid = ((long long)start + (long long)stop) / 2;

    if(A == 1) cout << 1;

    while(!(mid * mid <= A && (mid+1)*(mid+1) > A)){
        if(mid * mid > A){
            stop = mid;
            mid = (start + stop) / 2;
        }

        else if(mid * mid < A){
            start = mid;
            mid = (start + stop) / 2;
        }
    }

    cout << mid;


    return 0;

}
