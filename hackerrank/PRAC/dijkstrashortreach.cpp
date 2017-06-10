#include<bits/stdc++.h>

using namespace std;
int t, n, m, s, in1, in2, in3;
long long distances[3000];
vector< pair< pair<int, int>, int> > paths;

int computeDistances(int root, int distance) {
    for (int i = 0; i < paths.size(); i++) {
        if (paths[i].first.first == root && distances[paths[i].first.second - 1] > distance + paths[i].second) {
            distances[paths[i].first.second - 1] = distance + paths[i].second;
            computeDistances(paths[i].first.second, distance + paths[i].second);
        }
        else if (paths[i].first.second == root && distances[paths[i].first.first - 1] > distance + paths[i].second) {
            distances[paths[i].first.first - 1] = distance + paths[i].second;
            computeDistances(paths[i].first.first, distance + paths[i].second);
        }
    }
    return 0;
}

int main(){
    cin >> t;
    while(t--) {
        for (int i = 0; i < 3000; i++) distances[i] = INT_MAX;
        paths.clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> in1 >> in2 >> in3;
            paths.push_back(make_pair(make_pair(in1, in2), in3));
        }
        cin >> s;
        distances[s - 1] = 0;

        computeDistances(s, 0);
        for (int i = 0; i < n; i++) {
            if (i != s - 1) cout << distances[i] << " ";
        }
    }
    return 0;
}

