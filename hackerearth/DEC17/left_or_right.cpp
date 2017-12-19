#include <bits/stdc++.h>
using namespace std;
 
int n;
 
unordered_map<int, vector<int> > pos_of;
void add_pos(int type, int pos) {
    if (!pos_of.count(type)) {
        vector<int> v;
        pos_of[type] = v;
    }
    pos_of[type].push_back(pos);
}
 
int calc(int from_pos, int to_type, char dir) {
    if (!pos_of.count(to_type))
        return -1;
    int dist = n;
    for (int i = 0; i < pos_of[to_type].size(); i++) {
        if (pos_of[to_type][i] == from_pos)
            return 0;
        int d;
        
        if (dir == 'L') {
            if (pos_of[to_type][i] > from_pos) d = n - pos_of[to_type][i] + from_pos;
            else d = from_pos - pos_of[to_type][i];
        }
        else {
            if (pos_of[to_type][i] < from_pos) d = n - from_pos + pos_of[to_type][i];
            else d = pos_of[to_type][i] - from_pos;
        }
        dist = min(dist, d);
    }
    return dist;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q, q1, q2;
    char ch;
    
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> q1;
        add_pos(q1, i);
    }
    for (int i = 0; i < q; i++) {
        cin >> q1 >> q2 >> ch;
        cout << calc(q1, q2, ch) << "\n";
    }
    
    return 0;
}