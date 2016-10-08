#include<iostream>
#include<string>
using namespace std;
int main(){
    string path;
    int t;
    long long int node, i;
    cin>>t;
    while(t--){
        cin>>path;
        node=1;
        for(i=0; i<path.length(); i++){
            if(path[i]=='l'){
                if(i%2==0) node=(node*2)%1000000007;
                else node=((node*2)-1)%1000000007;
            }
            else{
                if(i%2==0) node=((node*2)+2)%1000000007;
                else node=((node*2)+1)%1000000007;
            }
        }
        cout<<node<<endl;
    }
    return 0;
}
