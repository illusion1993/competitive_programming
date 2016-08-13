/*
ID: rathore1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> names;
vector<int> balance;

int findIndex(string name){

    int pos = 0;
    while(names[pos] != name) pos++;
    return pos;

}

int main() {
    ofstream cout ("gift1.out");
    ifstream cin ("gift1.in");
    int np, i, pos, don, ppl;
    string s;
    cin >> np ;
    i = np;
    while(i--){
        cin >> s;
        names.push_back(s);
        balance.push_back(0);
    }
    i = np;
    while(i--){
        cin>>s;
        //cout<<s<<endl;
        pos = findIndex(s);
        //cout<<"index : "<<pos<<endl;
        cin>>don>>ppl;
        if(ppl == 0) continue;
        if(don % ppl != 0) don -= (don % ppl);
        balance[pos] -= don;
        for(int j=0; j<ppl; j++){
            cin>>s;
            pos = findIndex(s);
            balance[pos] += don / ppl;
          //  cout << s << " " << pos << "\n";
        }

    }
    for(int j=0; j<np; j++){
        cout<<names[j]<<" "<<balance[j]<<endl;
    }

    return 0;
}
