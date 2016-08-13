#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int t;
    long long int index, i;
    string path;
    cin>>t;
    while(t--){
        index=1;
        cin>>path;
        for(i=0; i<path.length(); i++){
            if(path[i]=='l') index=(((index-1)*2)+1)%1000000007;
            else if(path[i]=='r') index=(((index-1)*2)+2)%1000000007;
        }
        for(i=1; i<path.length()+1; i++){
            if(path.length()%2==1 && i%2==0) index=(index+pow(2,i-1))%1000000007;
            else if(path.length()%2==0 && i%2==1) index=(index+pow(2,i-1))%1000000007;
        }
        if(path.length()%2==1) cout<<(index*2)%1000000007<<endl;
        else if(path.length()%2==0) cout<<(-1+(index*2))%1000000007<<endl;
    }
    return 0;
}
