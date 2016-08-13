#include<iostream>
using namespace std;
int main(){
    int t, count;
    long long n, nc, i;
    cin>>t;
    while(t--){
        cin>>n;
        nc=n;
        count=0;
        for(i=10; nc!=0 ; i*=10){
            if(n%((nc%i)/(i/10))==0) count++;
            nc-=(nc%i);
        }
        cout<<count<<endl;
    }
    return 0;
}
