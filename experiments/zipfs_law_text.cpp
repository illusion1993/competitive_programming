#include <bits/stdc++.h>

using namespace std;

vector< pair<char, int> > freq;

bool fsort(const pair<char, int> &a, const pair<char, int> &b){

    return a.second > b.second;

}

int main(){

    ifstream cin("dictionary.txt");
    for(int i = 0; i < 26; i++){
        //a 97-122, A 65-90
        char ch = i + 65;
        freq.push_back(make_pair(ch, 0));
    }

    string line;

    for(int l = 0; l < 10000; l++){

        cin >> line;
        cout << line;

        for(int i = 0; i < line.length(); i++){

            if(line[i] < 123 && line[i] > 96){
                freq[(int)line[i] - 97].second++;
            }
            else if(line[i] < 91 && line[i] > 64){
                freq[(int)line[i] - 65].second++;
            }

        }

    }

    cout << endl << endl;

    sort(freq.begin(), freq.end(), fsort);

    for(int i = 0; i < freq.size(); i++){
        cout << freq[i].first << " -> " << freq[i].second << endl;
    }


    return 0;

}
