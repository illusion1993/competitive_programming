#include<iostream>
#include<string>
using namespace std;
int main(){
    int holes, t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        holes=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='A' || s[i]=='D' || s[i]=='O' || s[i]=='P' || s[i]=='Q' || s[i]=='R') holes+=1;
            else if(s[i]=='B') holes+=2;
        }
        cout<<holes<<endl;
    }
    return 0;
}
