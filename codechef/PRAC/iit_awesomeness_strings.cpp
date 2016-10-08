#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node{
    char ch;
    int occ;
};
int main(){
    string s;
    cin>>s;
    vector<node> profile;
    node n;
    n.ch=s[0];
    n.occ=1;
    int count=1;
    for(int i=1; i<s.length(); i++){
        if(s[i]==n.ch) count++;
        else{
            n.occ=count;
            profile.push_back(n);
            n.ch=s[i];
            count=1;
        }
    }
    n.occ=count;
    profile.push_back(n);
    int opt=0;
    for(int i=1; i<profile.size(); i++){
        if(profile[i].occ>profile[opt].occ){
            opt=i;
        }
        else if(profile[i].occ==profile[opt].occ && (int)profile[i].ch<(int)profile[opt].ch) opt=i;
    }
    cout<<profile[opt].ch<<endl<<profile[opt].occ;
}
