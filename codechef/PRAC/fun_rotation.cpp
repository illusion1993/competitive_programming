#include<iostream>
using namespace std;
int main(){
    int n,m,i,opcount;
    long long int pos=0;
    char op;
    cin>>n>>m;
    long long int arr[n];
    for(i=0; i<n; i++) cin>>arr[i];
    while(m--){
        cin>>op>>opcount;
        if(op=='C') pos+=(opcount%n);
        else if(op=='A') pos+=n-(opcount%n);
        else if(op=='R') cout<<arr[((opcount-1+pos)%n)]<<endl;
    }
    return 0;
}
