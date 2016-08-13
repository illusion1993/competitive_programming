#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct node{
    string word;
    int length;
};

vector<node> dictionary;
string s[4];

void makeProfile(string code, string word, int *profile){
    //cout<<"making profile for "<<code<<" and "<<word<<endl;
    //int profile[26]={0};
    for(int i=0; i<word.length(); i++){
        int pos=(int)word[i]-97;
        int value=code[i];
        profile[pos]=value;
        //cout<<code[i]<<"->"<<value<<" at position "<<pos<<" like "<<profile[pos]<<endl;

    }
    //for(int i=0; i<26; i++) cout<<profile[i]<<" ";
    //cout<<endl;
    //return profile;
}

int matchProfile(int *a, int *b){
    int flag=1;
    cout<<"matching profiles"<<endl;
    for(int i=0; i<26; i++){
       cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<26; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<26; i++){
        if((a[i]>b[i] && b[i]!=0) || (b[i]>a[i] && a[i]!=0)) flag=0;
    }
    if(flag==1) cout<<"profiles matched"<<endl;
    else cout<<"profiles not matched"<<endl;
    return flag;
}

void mergeProfile(int *a, int *b, int *result){
    //int result[26]={0};
    for(int i=0; i<26; i++){
        if(a[i]!=0) result[i]=a[i];
        if(b[i]!=0) result[i]=b[i];
    }
    //return result;
}

vector<string> allOfLength(int l){
    vector<string> result;
    for(int i=0; i<dictionary.size(); i++){
        if(dictionary[i].length==l) result.push_back(dictionary[i].word);
    }
    return result;
}

void match(int codeIndex, int decodeIndex, int *profile){
    //create profile for current word
    int l=s[codeIndex].length();
    int maxDictSize=allOfLength(l).size();
    int newProfile[26]={0};
    makeProfile(s[codeIndex], allOfLength(l)[decodeIndex], newProfile);

    cout<<s[codeIndex]<<" -> "<<allOfLength(l)[decodeIndex]<<endl;
    //cout<<"new profile is"<<endl;
    for(int i=0; i<26; i++){
        //cout<<profile[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<26; i++){
        //cout<<newProfile[i]<<" ";
    }
    cout<<endl;
    //if profile matches with previous,
    if(matchProfile(profile, newProfile)==1){
            //cout<<"profile matched"<<endl;
        //int *mergedProfile=mergeProfile(profile, makeProfile(s[codeIndex], allOfLength(l)[decodeIndex]));
            //if code is not last index, call next code with 0 decodeIndex
            int mergedProfile[26]={0};
            mergeProfile(profile, newProfile, mergedProfile);
            if(codeIndex<=2) match(codeIndex+1, 0, mergedProfile);
            else{
                cout<<"found"<<endl;
            //else print merged profile
                //if decodeIndex is not last, call next word
                if(decodeIndex<maxDictSize-1) match(codeIndex, decodeIndex+1, profile);
            }

            //if decodeIndex is not last, call next word
    }
    //else if profile does not match and decodeIndx is not last, call next word
    else if(matchProfile(profile, newProfile)==0 && decodeIndex<maxDictSize-1){
            cout<<"profile not matched"<<endl;
        match(codeIndex, decodeIndex+1, profile);
    }
}

void dictInit(){
    node n;
    n.word="a";
    n.length=1;
    dictionary.push_back(n);
    n.word="an";
    n.length=2;
    dictionary.push_back(n);
    n.word="at";
    n.length=2;
    dictionary.push_back(n);
    n.word="is";
    n.length=2;
    dictionary.push_back(n);
    n.word="on";
    n.length=2;
    dictionary.push_back(n);
    n.word="and";
    n.length=3;
    dictionary.push_back(n);
    n.word="all";
    n.length=3;
    dictionary.push_back(n);
    n.word="was";
    n.length=3;
    dictionary.push_back(n);
    n.word="that";
    n.length=4;
    dictionary.push_back(n);
    n.word="this";
    n.length=4;
    dictionary.push_back(n);
    n.word="then";
    n.length=4;
    dictionary.push_back(n);
    n.word="secret";
    n.length=6;
    dictionary.push_back(n);

    s[0]="exoa";
    s[1]="oa";
    s[2]="p";
    s[3]="ajdmne";
}

int main(){
    dictInit();
    //cout<<dictionary[6].word<<endl<<s[1]<<endl;
    //vector<string> all=allOfLength(4);
    //for(int i=0; i<all.size(); i++) cout<<all[i]<<endl;
    int profile[26]={0};
    match(0,1,profile);
    return 0;
}
