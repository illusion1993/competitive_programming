#include<iostream>

using namespace std;

int main(){

    int t, b, sq;

    cin>>t;
    while(t--){
        cin>>b;
        sq=0;
        while(b>0){
            b-=2;
            sq+=b/2;
        }
        cout<<sq<<endl;
    }

    return 0;
}
