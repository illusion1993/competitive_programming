#include<bits/stdc++.h>
using namespace std;

int t, n, m, l1, r1, l2, r2, p[100000], s;   // q is current permutation, s is number of elements in q (window size)
long long perms;

vector<vector<int> > options;    // options available for each index in the permutation Q
vector<pair<int, int> > number_sets;

map<int, bool> perm;

bool sortPairFirst(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

void findOptions() {

    vector<int> current_options;
    options.clear();
    number_sets.clear();

    for (int i = 0; i < n; i++) {
        if (i >= l1 - 1 && i < r1)
            number_sets.push_back(make_pair(p[i], 1));
        else if (i >= l2 - 1 && i < r2)
            number_sets.push_back(make_pair(p[i], 2));
    }

    sort(number_sets.begin(), number_sets.end(), sortPairFirst);

    for (int i = 0; i < number_sets.size(); i++) {
        if (number_sets[i].second == 1) current_options.push_back(number_sets[i].first);
        else options.push_back(current_options);
    }

}

long long countPerms(int pos) {

    if (pos == s) return 1;

    long long perms_so_far = 0;

    for (int i = 0; i < options[pos].size(); i++) {
        if (!perm[options[pos][i]]) {
            perm[options[pos][i]] = true;
            perms_so_far = (perms_so_far + countPerms(pos + 1)) % 1000000007;
            perm[options[pos][i]] = false;
        }
    }

    return perms_so_far;

}

int main() {
    bool is_right;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> p[i];
        while(m--) {
            perms = 0;
            cin >> l1 >> r1 >> l2 >> r2;
            s = r1 - l1 + 1;
            findOptions();
            cout << countPerms(0) << endl;
        }
    }
    return 0;
}
