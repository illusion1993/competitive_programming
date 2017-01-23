#include <iostream>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        long long left=0, right=0;
        for(int i=0; i<n; i++) cin>>arr[i];
        for(int i=1; i<n; i++) right+=arr[i];

        int j=0;
        while(left!=right && j<n-1){
            j++;
            left+=arr[j-1];
            right-=arr[j];
        }
        if(left==right) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
