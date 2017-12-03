#include <bits/stdc++.h>
using namespace std;

int get_dist(int x, int y, int n) {
    int a = min(x, y), b = max(x, y);
    return min(b - a, n - b + a);
}

int main() {
    int n, q, q1, q2, arr;
    unordered_map< int, vector<int> > positions;
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr;
        if (!positions.count(arr)) {
            vector<int> v;
            positions[arr] = v;
        }
        positions[arr].push_back(i);
    }
    
    while (q--) {
        cin >> q1 >> q2;
        vector< pair<int, int> > vp;
        for (int i = 0; i < positions[q1].size(); i++)
            vp.push_back({positions[q1][i], q1});
        for (int i = 0; i < positions[q2].size(); i++)
            vp.push_back({positions[q2][i], q2});
            
        sort(vp.begin(), vp.end());
        
        int mindist = INT_MAX;
        for (int i = 0; i < vp.size() - 1; i++)
            if (vp[i].second != vp[i + 1].second)
                mindist = min(mindist, vp[i + 1].first - vp[i].first);
        if (vp[0].second != vp[vp.size() - 1].second)
            mindist = min(mindist, n - vp[vp.size() - 1].first + vp[0].first);
        cout << mindist / 2 << "\n";

        mindist = INT_MAX;
        for (int i = 0; i < positions[q1].size(); i++) {
        	for (int j = 0; j < positions[q2].size(); j++) {
        		mindist = min(mindist, get_dist(positions[q1][i], positions[q2][j], n));
        	}
        }
        cout << mindist / 2 << "\n\n";
    }
    
    return 0;
}