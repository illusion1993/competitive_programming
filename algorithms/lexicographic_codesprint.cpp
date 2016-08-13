#include <iostream>
#include<string>
using namespace std;

string findStringFrom(string, int);
string lexCompare(string, string);
int main() {
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int l=s.length();
        string assumption=s;
        int pos=l-1;
        for(int i=l-1; i>=0; i--){
            if((int)s[i]>=(int)s[pos]){
                pos=i;
            }
        }
        char ch=s[pos];
        string encounter;
        for(int i=0; i<l; i++){
            if(s[i]==ch){
                encounter=findStringFrom(s,i);
                assumption=lexCompare(assumption, encounter);
            }
        }
        cout<<assumption<<endl;
    }
    return 0;
}
string findStringFrom(string s, int pos){
    string result;
    result=s.substr(pos);
    result.append(s.substr(0,pos));

    return result;
}
string lexCompare(string a, string b){
    int pos=0;
    string result;
    int flag=1;
    while(flag){
        if((int)a[pos]>(int)b[pos]){
            result=a;
            flag=0;
        }
        else if((int)a[pos]<(int)b[pos]){
            result=b;
            flag=0;
        }
        else pos++;
    }
    return result;
}
