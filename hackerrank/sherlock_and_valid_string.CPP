#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//97-122
int main() {
    char s[100001];
    int profile[26] = {0}, ascii, min=-1, removals=0;

    cin.get(s, 100001);
    //cout<<endl<<endl<<"string length: "<<s.length();
    for(int i=0; i<100000; i++){
        ascii = s[i]-97;
        profile[ascii]++;
    }
    for(int i=0; i<26; i++){
        if(min==-1 || (min!=-1 && profile[i]<min)) min=profile[i];
    }
    cout<<endl<<endl;

    int length=0;
    for(int i=0; i<26; i++){
        removals += profile[i]-min;
        cout<<profile[i]<<endl;

        length+= profile[i];
    }
    cout<<"length = "<<length<<endl<<endl;
    if(removals<=1) cout<<"YES";
    else cout<<"NO";

    return 0;
}
