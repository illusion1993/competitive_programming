#include<iostream>
void print(int *, int);
using namespace std;
int main(){
    int n, i, j, v;
    cout<<"INSERTION SORT"<<endl<<endl<<"Number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array:"<<endl;
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    for(i=1; i<n; i++){
        v=arr[i];
        j=i;
        while(arr[j-1]>v){
            arr[j]=arr[j-1];
            j=j-1;
        }
        arr[j]=v;
        print(arr, n);
    }
    return 0;
}
void print(int *arr, int n){
    int i=n;
    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
