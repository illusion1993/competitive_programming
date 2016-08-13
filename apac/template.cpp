#include <bits/stdc++.h>

using namespace std;

vector<string> athletes;
vector<vector<int> > performance;
vector<pair<string, int> > achievement;

int findAthlete(string s){

    for(int i = 0; i < athletes.size(); i++){
        if(athletes[i] == s) return i;
    }

    return -1;

}

bool sortac(const pair<string, int> &a, const pair<string, int> &b){

    if(a.second > b.second) return true;

    else if(a.second == b.second) return a.first < b.first;

    else return false;

}

int main(){

    ifstream cin("A-small-attempt0.in");
    //ofstream cout("A-small-attempt0.out");

    int t, p, s, n, m, tcase = 1;
    string name;

    cin >> t;

    while(t--){

        athletes.clear();
        performance.clear();
        achievement.clear();

        cin >> p;
        vector<int> scores(p);

        for(int i = 0; i < p; i++) cin >> scores[i];

        cin >> n;
        vector<int> weights(n);

        for(int i = 0; i < n; i++){

            cin >> weights[i];
            for(int j = 0; j < p; j++){

                cin >> name;

                int pos = findAthlete(name);

                if(pos == -1){
                    athletes.push_back(name);
                    achievement.push_back(make_pair(name, 0));
                    vector<int> v;
                    v.push_back(weights[i] * scores[j]);
                    performance.push_back(v);
                }

                else{
                    performance[pos].push_back(weights[i] * scores[j]);
                }

            }

        }

        cin >> m;

        //cout << "athletes are : \n";
        //for(int i = 0; i < athletes.size(); i++) cout << athletes[i] << endl;

        for(int i = 0; i < performance.size(); i++){
            sort(performance[i].rbegin(), performance[i].rend());
            while(performance[i].size() != m) performance[i].pop_back();

            int total = 0;
            for(int j = 0; j < performance[i].size(); j++){
                total += performance[i][j];
                achievement[i].second = total;
            }

        }

        sort(achievement.begin(), achievement.end(), sortac);

        cout << "Case #" << tcase << ":\n";

        int pos = 0;

        for(int i = 0; i < achievement.size(); i++){
            if(i == 0 || achievement[i].second != achievement[i - 1].second) pos++;
            cout << pos << ": " << achievement[i].first << "\n";
        }

        tcase++;

    }

    return 0;

}
