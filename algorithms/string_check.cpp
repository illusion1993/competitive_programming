#include<iostream>
#include<string>
using namespace std;
char unxor(string s, char ans){
    char value;
    int ones;
    if(ans=='0'){
        ones=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1') ones++;
        }
        if(ones==1) value='1';
        else value='0';
    }
    else{
        ones=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1') ones++;
        }
        if(ones==1) value='0';
        else value='1';
    }
    return value;
}
int main(){
    int n, k, l;
    cin>>n>>k;
    string code, decode;
    cin>>code;
    decode.insert(0, code, n+k-2, 1);
    for(int i=0; i<n-1; i++){
        if(decode.length()>=k-1){
            decode.insert(0,1,unxor(decode.substr(0,k-1), code[n+k-3-i]));
        }
        else{
            decode.insert(0,1,unxor(decode, code[n+k-3-i]));
        }
    }
    cout<<decode<<endl;
    return 0;
}
