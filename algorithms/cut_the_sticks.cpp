#include <iostream>
int isEmpty(int *, int);
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n], min=-1;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(min==-1 || arr[i]<min) min=arr[i];
    }
    int count;
    while(!isEmpty(arr, n)){
        count=0;
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                count++;
                arr[i]-=min;
            }
        }
        min=-1;
        for(int i=0; i<n; i++){
            if(arr[i]!=0 && (min==-1 || arr[i]<min)) min=arr[i];
        }
        cout<<count<<endl;
    }
    return 0;
}
int isEmpty(int *arr, int n){
    int flag=1;
    for(int i=0; i<n; i++){
        if(arr[i]!=0) flag=0;
    }
    return flag;
}
