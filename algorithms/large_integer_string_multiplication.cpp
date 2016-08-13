#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<stdio.h>

using namespace std;

string multiply(string, string);
int main(){
    string a, b;
    cin>>a>>b;
    cout<<multiply(a, b);
    return 0;
}

string multiply(string a, string b){
    vector<string> values;
    int la=a.length(), lb=b.length();
    if(la<lb){
        swap(a, b);
        swap(la, lb);
    }
    string s;
    int carry;
    for(int i=lb-1; i>=0; i--){
        carry=0;
        s.clear();
        cout<<"s is now: "<<s<<endl;
        for(int j=la-1; j>=0; j--){
            int appendee=((int)b[i]-48)*((int)a[j]-48)+carry;
            char ch=(char)((appendee%10)+48);
            string tmp;
            tmp=ch;
            s.insert(0,tmp);
            carry=appendee/10;
        }
        for(int k=0; k<lb-1-i; k++) s.append("0");
        if(carry!=0){
            char ch=(char)(carry+48);
            string tmp;
            tmp=ch;
            s.insert(0,tmp);
        }
        //cout<<"s is now: "<<s<<endl;
        values.push_back(s);
        //values.append("/");
        //cout<<values<<endl<<s;
    }
    for(int i=0; i<values.size(); i++) cout<<values[i];
    return "";
}
