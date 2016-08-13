#include<iostream>
using namespace std;
int main(){
    int n, i, tmp, j, min, k, l, v;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    for(i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]) break;
    }
    if(i==n-2 && arr[i]<=arr[i+1]){
        for(i=0; i<n; i++) cout<<arr[i]<<" ";
    }
    else{
        min=-1;
        for(j=i+1; i<n; i++){
            if(arr[j]>arr[min] && arr[j]<arr[i] && min!=-1) min=j;
            else if(min==-1 && arr[j]<arr[i]) min=j;
        }
        cout<<arr[min]<<" is min";
        tmp=arr[min];
        arr[min]=arr[i];
        arr[i]=tmp;

        for(k=i+2; k<n; k++){
            v=arr[k];
            l=k;
            while(arr[l-1]<v){
                arr[l]=arr[l-1];
                l=l-1;
            }
            arr[l]=v;
        }
        for(i=0; i<n; i++) cout<<arr[i]<<" ";
    }
    return 0;
}
