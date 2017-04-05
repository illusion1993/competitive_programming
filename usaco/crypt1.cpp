/*
ID: rathore1
PROG: crypt1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int ans, n;
vector<int> options, so_far;
map<int, bool> moptions;

void check() {
    int n1, n2, p1, p2, p, len;
    n1 = (so_far[0] * 100) + (so_far[1] * 10) + so_far[2];
    n2 = (so_far[3] * 10) + so_far[4];

    p1 = n1 * so_far[4];
    p2 = n1 * so_far[3];
    p = n1*n2;

    bool is_ok = true;

    len = 0;
    while(p1 && is_ok) {
        if (!moptions.count(p1 % 10)) is_ok = false;
        p1 /= 10;
        len++;
    }
    if (len != 3) is_ok = false;

    len = 0;
    while(p2 && is_ok) {
        if (!moptions.count(p2 % 10)) is_ok = false;
        p2 /= 10;
        len++;
    }
    if (len != 3) is_ok = false;

    len = 0;
    while(p && is_ok) {
        if (!moptions.count(p % 10)) is_ok = false;
        p /= 10;
        len++;
    }
    if (len != 4) is_ok = false;

    if (is_ok) {
        // cout << n1 << endl << n2 << "\n_____" << endl << n1 * so_far[4] << endl << n1 * so_far[3] << "\n_____" << endl << n1*n2 << "\n\n\n";
        ans++;
    }
}

void fill(int pos) {
    if (pos == 5) check();
    else {
        for(int i = 0; i < n; i++) {
            so_far.push_back(options[i]);
            fill(pos + 1);
            so_far.pop_back();
        }
    }
}

int main() {
    ofstream cout ("crypt1.out");
    ifstream cin ("crypt1.in");
    ans = 0;
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        options.push_back(tmp);
        moptions[tmp] = true;
    }
    fill(0);
    cout << ans << endl;
    return 0;
}
