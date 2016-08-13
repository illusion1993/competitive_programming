#include<iostream>
using namespace std;
int main(){
    int t, n;
    cin>>t;
    int f;
    while(t--){
        cin>>n;
        f=n-(n%3);
        while(f>=0){
            if((n-f)%5!=0){
                f-=3;
            }
            else{
                for(int i=0; i<f; i++){
                    cout<<"5";
                }
                for(int i=0; i<n-f; i++){
                    cout<<"3";
                }
                cout<<endl;
                break;
            }
        }
        if(f<0) cout<<"-1"<<endl;
    }
    return 0;
}
