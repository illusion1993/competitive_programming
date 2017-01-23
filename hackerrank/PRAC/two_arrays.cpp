#include <iostream>
using namespace std;

int match(long long *arr, long long number, int e, long long k, int n){
    int index=-1;
    long long spouse;
    for(int i=e; i<n; i++){
        if(number+arr[i]>=k){
            index=i;
            spouse=arr[i];
            swap(arr[i], arr[e]);
            break;
        }
    }
    if(index!=-1){
        for(int i=index+1; i<n; i++){
            if(number+arr[i]>=k && arr[i]<spouse){
                index=i;
                spouse=arr[i];
                swap(arr[i], arr[e]);
                break;
            }
        }
    }
    //cout<<index;
    if(index!=-1) return 1;
    else return 0;
}
int main() {
    int t,n;
    long long k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long arr1[n], arr2[n];

        for(int i=0; i<n; i++) cin>>arr1[i];
        for(int i=0; i<n; i++) cin>>arr2[i];

        int flag=1;
        for(int i=0; i<n; i++){
            if(!match(arr2, arr1[i], i, k, n)){
                flag=0;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
