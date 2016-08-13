#include<iostream>
int calc(int);
using namespace std;
int main(){
    int n, e, i;
    cin>>n;
    if(n>=13){
        if(n==13) cout<<1;
        else{
            e=(n-13)/2;
            cout<<calc(e)<<endl;
        }
    }
    else cout<<0;
    return 0;
}
int calc(int e){
    int i, ans=1;
    for(i=1; i<=e; i++){
        ans=(ans*((6+i)/i))%1000000007;
    }
    return ans;
}
