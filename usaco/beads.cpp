/*
ID: rathore1
PROG: beads
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int n, max_beads, counted[350];
string s;

int act_pos(int pos) {
    if (pos >= 0) return pos % n;
    else {
        while(pos < 0) pos += n;
        return pos;
    }
}

int count_left(int cut_pos) {
    int cur_pos = act_pos(cut_pos - 1), count = 1;
    bool maj_found = s[cur_pos] != 'w';
    char maj = s[cur_pos];

    if (counted[cur_pos]) return 0;
    counted[cur_pos] = 1;

    while(((maj_found && s[act_pos(cur_pos - 1)] == maj) || (!maj_found) || s[act_pos(cur_pos - 1)] == 'w') && !counted[act_pos(cur_pos - 1)]) {
        cur_pos--;
        count++;
        counted[act_pos(cur_pos)] = 1;
        if (!maj_found && s[act_pos(cur_pos)] != 'w') {
            maj_found = true;
            maj = s[act_pos(cur_pos)];
        }
    }
    return count;
}

int count_right(int cut_pos) {
    int cur_pos = act_pos(cut_pos), count = 1;
    bool maj_found = s[cur_pos] != 'w';
    char maj = s[cur_pos];

    if (counted[cur_pos]) return 0;
    counted[cur_pos] = 1;

    while(((maj_found && s[act_pos(cur_pos + 1)] == maj) || (!maj_found) || s[act_pos(cur_pos + 1)] == 'w') && !counted[act_pos(cur_pos + 1)]) {
        cur_pos++;
        count++;
        counted[act_pos(cur_pos)] = 1;
        if (!maj_found && s[act_pos(cur_pos)] != 'w') {
            maj_found = true;
            maj = s[act_pos(cur_pos)];
        }
    }
    return count;
}

void count_both(int cut_pos) {
    memset(counted, 0, sizeof(counted));
    int beads = count_left(cut_pos) + count_right(cut_pos);
    max_beads = max(beads, max_beads);
}

int main() {
    ofstream cout ("beads.out");
    ifstream cin ("beads.in");

    max_beads = 0;

    cin >> n >> s;
    for (int i = 0; i < n; i++) count_both(i);
    cout << max_beads << "\n";

}
