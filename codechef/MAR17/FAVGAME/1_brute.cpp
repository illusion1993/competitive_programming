#include<bits/stdc++.h>
using namespace std;

struct node {
    int hours;
    vector<int> children;
};

int t, n, h, in, in1, total_days;
node * nodebook[1000];

void make_nodes() {
    total_days = INT_MAX;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> in;
        node *n = new node();
        n -> hours = in;
        nodebook[i] = n;
    }
}

void make_paths() {
    for (int i = 0; i < n; i++) {
        cin >> in1;
        for (int j = 0; j < in1; j++) {
            cin >> in;
            nodebook[i] -> children.push_back(in - 1);
        }
    }
}

void play(vector<int> unlocked, int day_no, int hours_played) {

    /*cout << "unlocked levels: ";
    for (int i = 0; i < unlocked.size(); i++) cout << unlocked[i] << " ";
    cout << endl;
    cout << "Day: " << day_no << ", Hours: " << hours_played << endl;*/

    if (!unlocked.size()) {
        //cout << "Game finished in " << day_no << " days\n";
        total_days = min(total_days, day_no);
    }

    vector<int> new_unlocked;
    int new_day_no, new_hours_played;
    for (int i = 0; i < unlocked.size(); i++) {

        //cout << "-------Now choosing level " << unlocked[i] << "\n";

        new_unlocked = unlocked;
        new_unlocked.erase(new_unlocked.begin()+i, new_unlocked.begin()+1+i);
        if (hours_played + nodebook[unlocked[i]] -> hours <= h) {
            new_day_no = day_no;
            new_hours_played = hours_played + nodebook[unlocked[i]] -> hours;
        }
        else {
            new_day_no = day_no + 1;
            new_hours_played = nodebook[unlocked[i]] -> hours;
        }

        for (int j = 0; j < nodebook[unlocked[i]] -> children.size(); j++) {
            new_unlocked.push_back(nodebook[unlocked[i]] -> children[j]);
        }

        /*cout << "Played it, day is " << new_day_no << ", hours are " << new_hours_played << ", now unlocked are: \n";
        for (int j = 0; j < new_unlocked.size(); j++) cout << new_unlocked[j] << " ";
        cout << "\n";*/

        play(new_unlocked, new_day_no, new_hours_played);
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        make_nodes();
        make_paths();
        vector<int> u;
        u.push_back(0);
        play(u, 1, 0);
        cout << total_days << "\n";
    }

    return 0;
}
