#include<bits/stdc++.h>
using namespace std;

string to_string(int n, int id) {

    string s1 = "";
    string s2 = "";

    while(n) {
        s1 = (char)((n % 10) + 48) + s1;
        n /= 10;
    }

    s1 += '_';

    while(id) {
        s2 = (char)((id % 10) + 48) + s2;
        id /= 10;
    }

    return s1 + s2;

}

map<int, bool> vertices;
map<pair<int, int>, bool> edges;

vector<int> v;
vector<pair<int, int> > e;

int covered = 1, expanded = 0;

int main() {
    int n, tmp1, tmp2;
    cin >> n;

    while(vertices.size() < n) {
        tmp1 = (rand() % n) + 1;
        if (vertices.count(tmp1) == 0) {
            vertices[tmp1] = true;
            v.push_back(tmp1);
        }
    }

    while(covered < n) {
        expanded++;
        for (int i = 0; i < 3; i++) {
            covered++;
            if (covered <= n)
                e.push_back({expanded, covered});
        }
    }

    //string filename = "tests/test" + to_string(n, 0) + ".txt";
    freopen("testcase.txt","w",stdout);

    cout << n << " 0" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < e.size(); i++) {
        cout << e[i].first << " " << e[i].second << endl;
    }
}
