#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int prev=0;
        int sum=0;
        for(int i=1; i<n+1; i++){
            int tmp, now, max;
            for(int j=0; j<i; j++){
                cin>>tmp;
                if((j==prev || j==prev+1) && tmp>max){
                        now=j;
                        max=tmp;
                }
            }
            prev=now;
            sum+=max;
            cout<<endl<<"added "<<max<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
