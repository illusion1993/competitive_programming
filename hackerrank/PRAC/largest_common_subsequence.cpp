#include<iostream>
#include<string>

using namespace std;

int LCS[5001][5001], l;
string s1,s2;

void findLCS(){
    for(int i=0; i<l; i++){
        LCS[0][i]=0;
        LCS[i][0]=0;
    }
    for(int i=1; i<=l; i++){
        for(int j=1; j<=l; j++){
            if(s1[i-1]==s2[j-1]) LCS[i][j]=1+LCS[i-1][j-1];
            else LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
}
int main(){
    cin>>s1>>s2;
    l=s1.length();
    findLCS();
    cout<<LCS[l][l];
    return 0;
}
