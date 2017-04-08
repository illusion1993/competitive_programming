#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll min_dist[100000];
int n, k, x, m, s;

map<int, vector<pair<int, int> > > paths;   // node: < <dist, node> , ... >

void traverse(int node, ll dist_so_far, int parent) {
    min_dist[node] = dist_so_far;
    
    sort(paths[node].begin(), paths[node].end());
    for (int i = 0; i < paths[node].size(); i++) {
        if (paths[node][i].second != parent) {
            if (dist_so_far + (ll)paths[node][i].first < min_dist[paths[node][i].second]) 
                traverse(paths[node][i].second, dist_so_far + (ll)paths[node][i].first, node);
        }
    }
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k >> x >> m >> s;
        paths.clear();
        for (int i = 0; i < n; i++) min_dist[i] = INT_MAX;

        vector<pair<int, int> > p;
        for (int i = 0; i < k; i++) {
            p.clear();
            for (int j = 0; j < k; j++) {
                if (i != j) {
                    p.push_back({x, j});
                }
            }
            paths[i] = p;
        }

        int tmp1, tmp2, tmp3;
        for (int i = 0; i < m; i++) {
            cin >> tmp1 >> tmp2 >> tmp3;
            if (paths.count(tmp1 - 1)) paths[tmp1 - 1].push_back({tmp3, tmp2 - 1});
            else {
                p.clear();
                p.push_back({tmp3, tmp2 - 1});
                paths[tmp1 - 1] = p;
            }
            if (paths.count(tmp2 - 1)) paths[tmp2 - 1].push_back({tmp3, tmp1 - 1});
            else {
                vector<pair<int, int> > p;
                p.push_back({tmp3, tmp1 - 1});
                paths[tmp2 - 1] = p;
            }
        }
        traverse(s - 1, 0, -1);
        for (int i = 0; i < n; i++) cout << min_dist[i] << " ";
        cout << "\n";
    }

    return 0;
}
