#include<iostream>
using namespace std;
int display(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
int max_heapify(int *arr, int n, int i){
    int max=arr[i], ind=i;
    if((i*2)+1<=n-1 && arr[(i*2)+1]>max){
        ind=(i*2)+1;
        max=arr[(i*2)+1];
    }
    if((i*2)+2<=n-1 && arr[(i*2)+2]>max){
        ind=(i*2)+2;
        max=arr[(i*2)+1];
    }
    if(ind!=i){
        swap(arr[ind], arr[i]);
        max_heapify(arr, n, ind);
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=n/2-1; i>=0; i--){
        max_heapify(arr, n, i);
    }
    for(int i=n-1; i>=1; i--){
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
    display(arr,n);
    return 0;
}
