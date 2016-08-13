#include<iostream>
#include<string>
using namespace std;
int isPall(string);
int main(){
    int t;
    cin>>t;
    string str, strc;
    while(t--){
        cin>>str;
        for(int i=0; i<str.length(); i++){
            strc=str;
            strc.erase(i,1);
            if(isPall(strc)){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
int isPall(string str){
    int flag=1, l=str.length();
    for(int i=0; i<l/2; i++){
        if(str[i]!=str[l-i-1]) flag=0;
    }
    return flag;
}
