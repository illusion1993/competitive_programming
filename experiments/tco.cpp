#include<bits/stdc++.h>
using namespace std;
string b(int v){
    string s = "";
    while(v){
        s += (v%2 + '0');
        v /= 2;
    }
    while(s.length() < 5)
        s = '0' + s;
    swap(s[0],s[4]);
    swap(s[1],s[3]);
    return s;
}
int main(){
    ifstream cin("cin.txt");
    string s = "",v;
    while(getline(cin,v)){
        s += v;
    }
    cout << b((count(s.begin(),s.end(),'i') + count(s.begin(),s.end(),'I')  )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'l') + count(s.begin(),s.end(),'L') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'l') + count(s.begin(),s.end(),'L') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'u') + count(s.begin(),s.end(),'U') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'s') + count(s.begin(),s.end(),'S') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'i') + count(s.begin(),s.end(),'I') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'o') + count(s.begin(),s.end(),'O') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'n') + count(s.begin(),s.end(),'N') )%32)<< " ";

    cout << b((count(s.begin(),s.end(),'0') + count(s.begin(),s.end(),'0') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'0') + count(s.begin(),s.end(),'0') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'0') + count(s.begin(),s.end(),'0') )%32)<< " ";
    cout << b((count(s.begin(),s.end(),'0') + count(s.begin(),s.end(),'0') )%32)<< endl;



}
