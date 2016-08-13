#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int div=1, flag=1;
        for(int i=0; i<6; i++){
            if(n==div) flag=0;
            div*=10;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
