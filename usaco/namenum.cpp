/*
ID: rathore1
PROG: namenum
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

string id;
map<string, bool> dict;
map<char, vector<char> > rulebook;
vector<string> names;

void makeRules() {
    vector<char> vc;
    char ch = 'A';
    int cont = 2;
    while(ch <= 'Y') {
        if (ch != 'Q') {
            if (vc.size() == 3) {
                rulebook[(char)cont + 48] = vc;
                vc.clear();
                cont++;
            }
            vc.push_back(ch);
        }
        ch++;
    }
    rulebook['9'] = vc;
}

void generate(int pos, string name_so_far) {
    if (pos == id.length()) {
        if (dict.count(name_so_far)) names.push_back(name_so_far);
    }
    else {
        generate(pos + 1, name_so_far + rulebook[id[pos]][0]);
        generate(pos + 1, name_so_far + rulebook[id[pos]][1]);
        generate(pos + 1, name_so_far + rulebook[id[pos]][2]);
    }
}

int main() {
    ofstream cout ("namenum.out");
    ifstream cin ("namenum.in");
    ifstream fin ("dict.txt");
    makeRules();

    string s;
    cin >> id;
    
    for (int i = 0; i < 4617; i++) {
        fin >> s;
        dict[s] = true;
    }

    generate(0, "");
    for (int i = 0; i < names.size(); i++) cout << names[i] << "\n";
    if (!names.size()) cout << "NONE\n";

    return 0;
}
