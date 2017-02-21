#include<bits/stdc++.h>
using namespace std;

int t, n, m, l1, r1, l2, r2, p[100000], s;   // q is current permutation, s is number of elements in q (window size)
long long perms;

vector<vector<int> > options;    // options available for each index in the permutation Q
vector<pair<int, int> > number_sets(100000);
int number_sets_size;

map<int, bool> perm;

bool sortPairFirst(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void findOptions() {

    vector<int> current_options;
    options.clear();
    number_sets.clear();
    number_sets_size = 0;

    for (int i = min(l1, l2) - 1; i < max(r1, r2); i++) {
        if (i >= l1 - 1 && i < r1) {
            number_sets[number_sets_size].first = p[i];
            number_sets[number_sets_size].second = 1;
            number_sets_size++;
        }
        else if (i >= l2 - 1 && i < r2) {
            number_sets[number_sets_size].first = p[i];
            number_sets[number_sets_size].second = 2;
            number_sets_size++;
        }
    }

    sort(number_sets.begin(), number_sets.begin() + number_sets_size, sortPairFirst);

    for (int i = 0; i < number_sets_size; i++) {
        if (number_sets[i].second == 1) current_options.push_back(number_sets[i].first);
        else {
            options.push_back(current_options);
            /*for (int i = 0; i < current_options.size(); i++) {
                cout << current_options[i] << " ";
            }
            cout << "\n";*/
        }
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
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    bool is_right;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> p[i];
        while(m--) {
            perms = 0;
            cin >> l1 >> r1 >> l2 >> r2;
            s = r1 - l1 + 1;
            //cout << "options are: \n";
            findOptions();
            cout << countPerms(0) << "\n";
        }
    }
    return 0;
}
