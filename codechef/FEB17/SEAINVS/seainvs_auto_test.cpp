#include<bits/stdc++.h>
using namespace std;

int n, m, l1, r1, l2, r2, a[100000], s;

vector<vector<int> > errors;

// Vars for small solution
vector<vector<int> > small_options;
vector<pair<int, int> > small_number_sets(100000);
map<int, bool> small_perm;
int small_number_sets_size;

bool sortPairFirst(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
void smallHelperFindOptions() {
    vector<int> current_options;
    small_options.clear();
    small_number_sets.clear();
    small_number_sets_size = 0;
    for (int i = min(l1, l2) - 1; i < max(r1, r2); i++) {
        if (i >= l1 - 1 && i < r1) {
            small_number_sets[small_number_sets_size].first = a[i];
            small_number_sets[small_number_sets_size].second = 1;
            small_number_sets_size++;
        }
        else if (i >= l2 - 1 && i < r2) {
            small_number_sets[small_number_sets_size].first = a[i];
            small_number_sets[small_number_sets_size].second = 2;
            small_number_sets_size++;
        }
    }
    sort(small_number_sets.begin(), small_number_sets.begin() + small_number_sets_size, sortPairFirst);
    for (int i = 0; i < small_number_sets_size; i++) {
        if (small_number_sets[i].second == 1) current_options.push_back(small_number_sets[i].first);
        else small_options.push_back(current_options);
    }
}
long long smallHelperCountPerms(int pos) {
    if (pos == s) return 1;
    long long perms_so_far = 0;
    for (int i = 0; i < small_options[pos].size(); i++) {
        if (!small_perm[small_options[pos][i]]) {
            small_perm[small_options[pos][i]] = true;
            perms_so_far = (perms_so_far + smallHelperCountPerms(pos + 1)) % 1000000007;
            small_perm[small_options[pos][i]] = false;
        }
    }
    return perms_so_far;
}
long long findAnswerSmall() {
    s = r1 - l1 + 1;
    smallHelperFindOptions();
    return smallHelperCountPerms(0);
}


vector<pair<int, int> > large_number_range;
vector<int> large_options_count;
bool sortNumberRange(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
void largeBuildNumberRange(int l1, int r1, int l2, int r2) {
    large_number_range.clear();
    for (int i = 0; i < max(r1, r2); i++) {
        if (i >= l1 - 1 && i <= r1 - 1) large_number_range.push_back({a[i], 0});
        else if (i >= l2 - 1 && i <= r2 - 1) large_number_range.push_back({a[i], 1});
    }
    sort(large_number_range.begin(), large_number_range.end(), sortNumberRange);
}
void largeFindOptionsCount() {
    large_options_count.clear();
    for (int i = 0; i < large_number_range.size(); i++) {
        if (large_number_range[i].second) large_options_count.push_back(i - large_options_count.size());
    }
}
int findAnswerLarge() {
    int perms;
    largeBuildNumberRange(l1, r1, l2, r2);
    largeFindOptionsCount();
    perms = large_options_count[0];
    for (int i = 1; i < large_options_count.size(); i++) {
        perms = (perms * (large_options_count[i] - i)) % 1000000007;
    }
    return perms;
}


int main() {
    int t;
    cin >> t;
    n = 20;
    m = 5;
    long long a1, a2;

    for (int i = 0; i < t; i++) {
        cout << "Testcase #" << i + 1 << ": " << endl;

        for (int i = 0; i < n; i++) {
            a[i] = rand() % (2 * n) + 1;
        }
        for (int i = 0; i < m; i++) {
            l1 = rand() % (n / 4);
            r1 = l1 + (n / 4);
            l2 = (n / 2) + (rand() * rand()) % (n / 4);
            r2 = l2 + (n / 4);
            a1 = findAnswerSmall();
            a2 = findAnswerLarge();
            cout << a1 << " " << a2;
            cout << endl;

            if (a1 != a2) {
                vector<int> tmp;
                for (int i = 0; i < n; i++) tmp.push_back(a[i]);
                errors.push_back(tmp);
                tmp.clear();
                tmp.push_back(l1);
                tmp.push_back(r1);
                tmp.push_back(l2);
                tmp.push_back(r2);
                errors.push_back(tmp);
            }
        }
    }

    char ch;
    cout << "View errors? ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y') {
        for (int i = 0; i < errors.size(); i++) {
            for (int j = 0; j < errors[i].size(); j++) {
                cout << errors[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
