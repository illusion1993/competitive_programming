#include<iostream>
using namespace std;
int main(){
    int t, n, i, j;
    cin>>t;
    while(t--){
        cin>>n;
        j=0;
        for(i=5; i<=n; i*=5){
            j+=n/i;
        }
        cout<<j<<endl;
    }
    return 0;
}
