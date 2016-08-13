#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int pos;
    for(int i=1; i<=26; i++){
        for(int j=0; j<s.length(); j++){
            pos = (int)s[j] + i;
            if(pos > 122) pos = pos-122+96;
            cout<<(char)pos;
        }
        cout<<endl;
    }
    return 0;
}
