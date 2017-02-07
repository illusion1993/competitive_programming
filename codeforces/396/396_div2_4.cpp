#include<bits/stdc++.h>
using namespace std;

int n, m, q, paths[100000][3], traveled[100000];
map<string, int> indices;

int distanceBetween(int a, int b) {
    traveled[a] = 1;
    int d;

    if (a == b) return 0;
    for (int i = 0; i < m; i++) {

        if (paths[i][0] == a && !traveled[paths[i][1]]) {
            d = distanceBetween(paths[i][1], b);
            if (d != -1) return d + paths[i][2];
        }

        else if (paths[i][1] == a && !traveled[paths[i][0]]) {
            d = distanceBetween(paths[i][0], b);
            if (d != -1) return d + paths[i][2];
        }

    }
    return -1;
}

int getRelation(string s1, string s2) {
    memset(traveled, 0, sizeof(traveled));
    int a, b, dist;
    a = indices[s1];
    b = indices[s2];
    dist = distanceBetween(a, b);
    if (dist == -1) return 3;
    return (dist % 2) + 1;
}

int main() {

    string s1, s2;
    int relation, previous_relation;

    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> s1;
        indices[s1] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> relation >> s1 >> s2;
        previous_relation = getRelation(s1, s2);
        if (previous_relation != relation && previous_relation != 3) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            if (previous_relation == 3) {
                paths[i][0] = indices[s1];
                paths[i][1] = indices[s2];
                paths[i][2] = relation - 1;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> s1 >> s2;
        cout << getRelation(s1, s2) << endl;
    }

    return 0;
}
