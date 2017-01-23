#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node{
    string word;
    int length;
    vector<int> profile;
};
int main(){
    string input;
    ifstream inFile;
    inFile.open("dictionary.lst");

    vector<node> dict;
    node tmp;

    while(!inFile.eof()){
        inFile>>input;
            tmp.word=input;
            tmp.length=input.length();
            tmp.profile.clear();
            int o=-1;
            for(int i=0; i<input.length(); i++){
                int found=-1;
                for(int j=0; j<i; j++){
                    if(input[i]==input[j]) found=j;
                }
                if(found==-1){
                    o++;
                    tmp.profile.push_back(o);
                }
                else tmp.profile.push_back(found);
            }
            dict.push_back(tmp);
    }
    inFile.close();
    for(int i=0; i<dict.size(); i++){
        cout<<dict[i].word<<" Length: "<<dict[i].length<<" Profile: ";
        for(int j=0; j<(int)dict[i].profile.size(); j++) cout<<dict[i].profile[j]<<" ";
        cout<<endl;
    }

    return 0;
}
