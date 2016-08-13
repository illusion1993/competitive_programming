#include<iostream>
using namespace std;
int main(){
    int t, n, a, b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        if(a<b){
            int tmp=a;
            a=b;
            b=tmp;
        }
        for(int i=0; i<=n-1; i++){
            cout<<(a*i)+(b*(n-1-i))<<" ";
        }
        cout<<endl;
    }
    return 0;
}
