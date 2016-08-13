#include<iostream>

using namespace std;

int main(){

    unsigned int t, A, B;

    cin>>t;
    while(t--){
        cin>>A>>B;
        if(A>=B) cout<<A;
        else cout<<B;
        cout<<" "<<A+B<<endl;
    }


    return 0;
}
