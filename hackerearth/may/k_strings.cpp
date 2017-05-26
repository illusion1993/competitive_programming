#include <bits/stdc++.h>
using namespace std;

unordered_set<int> search_for;

string rev(string s) {
    string ans = "";
    for (int i = s.length() - 1; i >= 0; i--) ans += s[i];
    return ans;
}

struct node {
    node * _links[26];
    int _index;
    node () : _index(0) {}
};
node * _roots[26];
node * insert_string(node * n, const string &s, int pos, int index) {
    if (!n) n = new node();
    if (pos == s.length() - 1) 
        n -> _index = index;
    else
        n -> _links[s[pos + 1] - 'a'] = insert_string(n -> _links[s[pos + 1] - 'a'], s, pos+1, index);
    return n;
}
int count_pref(node * n, bool found) {
    int c = 0;
    found = (found || search_for.count(n -> _index));
    for (int i = 0; i < 26; i++) {
        if (n -> _links[i]) {
            int nxt = count_pref(n -> _links[i], found);
            c = (found) ? c + nxt : max(c, nxt);
        }
    }
    return (search_for.count(n -> _index)) ? c + 1 : c;
}

int count_max() {
    int c = 0;
    for (int i = 0; i < 26; i++) {
        if (_roots[i]) c = max(c, count_pref(_roots[i], 0));
    }
    return c;
}

int main()
{
    int n, q, tmp;
    string s;
    cin >> n >> q;
    for (int i = 0; i < n; i++) { cin >> s; s = rev(s); _roots[s[0] - 'a'] = insert_string(_roots[s[0] - 'a'], s, 0, i+1); }
    for (int i = 0; i < q; i++) {
        search_for.clear();
        cin >> n;
        for (int j = 0; j < n; j++) { cin >> tmp; search_for.insert(tmp); }
        cout << count_max() << "\n";
    }
    return 0;
}
