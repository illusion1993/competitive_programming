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
    n.word="stake";
    n.length=5;
    dictionary.push_back(n);
    n.word="secret";
    n.length=6;
    dictionary.push_back(n);

    s[0]="exoa";
    s[1]="acopce";
    s[2]="je";
    s[3]="aejzc";
}

void makeProfile(string code, string word, int *profile){
    for(int i=0; i<26; i++) profile[i]=0;
    for(int i=0; i<word.length(); i++){
        int pos=(int)word[i]-97;
        int value=code[i];
        profile[pos]=value;
    }
}

int matchProfile(int *a, int *b){
    int flag=1;
    for(int i=0; i<26; i++){
        //if((a[i]>b[i] && b[i]!=0) || (b[i]>a[i] && a[i]!=0)) flag=0;
        if(a[i]!=0){
            for(int j=0; j<26; j++){
                if(b[j]==a[i] && i!=j) flag=0;
            }
            if(b[i]!=0 && b[i]!=a[i]) flag=0;
        }
    }
    return flag;
}

void mergeProfile(int *a, int *b, int *result){
    //cout<<"merging"<<endl;
    for(int i=0; i<26; i++){
        if(a[i]!=0) result[i]=a[i];
        if(b[i]!=0) result[i]=b[i];
        //cout<<result[i]<<" ";
    }
    //cout<<endl;
}

vector<string> allOfLength(int l){
    vector<string> result;
    for(int i=0; i<dictionary.size(); i++){
        if(dictionary[i].length==l) result.push_back(dictionary[i].word);
    }
    return result;
}

void printMessage(int *profile){
    string str;
    for(int i=0; i<4; i++){
        str=s[i];
        for(int j=0; j<str.length(); j++){
            int a=str[j];
            int k;
            for(k=0; k<26; k++){
                if(profile[k]==a) break;
            }
            k+=97;
            char ch=k;
            cout<<ch;
        }
        cout<<" ";
    }
    cout<<endl;
}

void match(int codeIndex, int decodeIndex, int *profile){
    int l=s[codeIndex].length();
    int maxDictSize=allOfLength(l).size();
    int newProfile[26]={0};
    makeProfile(s[codeIndex], allOfLength(l)[decodeIndex], newProfile);

    cout<<s[codeIndex]<<" -> "<<allOfLength(l)[decodeIndex]<<endl;

    if(matchProfile(profile, newProfile)==1){
        int mergedProfile[26]={0};
        mergeProfile(profile, newProfile, mergedProfile);
        if(codeIndex<=2) match(codeIndex+1, 0, mergedProfile);
        else{
            cout<<"found"<<endl;
            printMessage(mergedProfile);
            if(decodeIndex<maxDictSize-1) match(codeIndex, decodeIndex+1, profile);
        }
    }
    else if(matchProfile(profile, newProfile)==0 && decodeIndex<maxDictSize-1){
        match(codeIndex, decodeIndex+1, profile);
    }
}

int main(){
    dictInit();
    int profile[26]={0};
    match(0,1,profile);
    return 0;
}
