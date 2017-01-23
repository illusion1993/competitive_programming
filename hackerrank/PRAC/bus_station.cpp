#include <iostream>
using namespace std;

int trip(int *arr, long long bus, int n){
    long long basket=0;
    for(int i=0; i<n; i++){
        if(basket==bus){
            basket=arr[i];
        }
        else if(basket<bus){
            basket+=arr[i];
        }
        else if(basket>bus){
            break;
            return 0;
        }
    }
    if(basket==bus) return 1;
    else return 0;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    long long sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    long long bus=0;
    for(int i=0; i<n; i++){
        bus+=arr[i];
        if(trip(arr, bus, n)) cout<<bus<<" ";
    }
    return 0;
}
