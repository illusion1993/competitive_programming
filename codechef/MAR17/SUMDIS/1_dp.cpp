#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, in;
    long long sumdis, tmp;
    map<int, map<int, long long> > dist;

    sumdis = 0;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> in;
        dist[i][i + 1] = in;
        sumdis += in;
        //cout << "Adding " << i << " -> " << i + 1 << ": " << in << "\n";
    }
    for (int i = 1; i <= n - 2; i++) {
        cin >> in;
        dist[i][i + 2] = in;
    }
    for (int i = 1; i <= n - 3; i++) {
        cin >> in;
        dist[i][i + 3] = in;
    }


    for (int i = n - 1; i > 0; i--) {
        if (i + 4 < n) dist.erase(i + 4);

        if (i + 2 <= n) {
            dist[i][i + 2] = min(dist[i][i + 2], dist[i][i + 1] + dist[i + 1][i + 2]);
            sumdis += dist[i][i + 2];
            //cout << "Adding " << i << " -> " << i + 2 << ": " << dist[i][i + 2] << "\n";
        }

        if (i + 3 <= n) {
            dist[i][i + 3] = min(dist[i][i + 3], dist[i][i + 1] + dist[i + 1][i + 3]);
            dist[i][i + 3] = min(dist[i][i + 3], dist[i][i + 2] + dist[i + 2][i + 3]);
            sumdis += dist[i][i + 3];
            //cout << "Adding " << i << " -> " << i + 2 << ": " << dist[i][i + 2] << "\n";
        }

        for (int j = i + 4; j <= n; j++) {
            tmp = INT_MAX;
            tmp = min(tmp, dist[i][i + 1] + dist[i + 1][j]);
            tmp = min(tmp, dist[i][i + 2] + dist[i + 2][j]);
            tmp = min(tmp, dist[i][i + 3] + dist[i + 3][j]);
            dist[i][j] = tmp;
            sumdis += tmp;
        }
    }
    cout << sumdis << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
