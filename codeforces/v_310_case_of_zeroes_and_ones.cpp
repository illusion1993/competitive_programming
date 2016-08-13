#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){

    int l;

    string s;
    stack<char> st;
    cin>>l>>s;

    for(int i=0; i<l; i++){
        if(st.size() && st.top() != s[i]) st.pop();
        else if(!st.size() || st.top() == s[i]) st.push(s[i]);
    }

    cout<<st.size();

    return 0;
}
