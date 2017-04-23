#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, k;

vector<pair<double, double> > points;
vector<string> parts;
double min_dist;
bool impossible;

void travel(int point_no, unordered_map<int, bool> parts_collected, unordered_map<int, bool> points_visited, int total_parts_collected, double dist) {

    // collect parts
    points_visited[point_no] = true;
    for (int i = 0; i < parts[point_no].length(); i++) {
        if (parts[point_no][i] == '1' && parts_collected.count(i) == 0) {
            parts_collected[i] = true;
            total_parts_collected++;
        }
    }

    if (total_parts_collected == k) {
        dist += sqrt((points[point_no].first * points[point_no].first) + (points[point_no].second * points[point_no].second));
        min_dist = min(min_dist, dist);
    }

    else {
        // traverse only those with new parts and not traversed, send new_dist
        int count = 0;
        for (int i = 0; i < points.size(); i++) {
            if (points_visited.count(i) == 0) {
                bool new_part = false;
                for (int j = 0; j < parts[i].length(); j++) {
                    if (parts[i][j] == '1' && parts_collected.count(j) == 0) new_part = true;
                }
                if (new_part) {
                    count++;
                    double new_dist = sqrt(((points[point_no].first - points[i].first) * (points[point_no].first - points[i].first)) + ((points[point_no].second - points[i].second) * (points[point_no].second - points[i].second)));
                    // traverse i
                    travel(i, parts_collected, points_visited, total_parts_collected, new_dist);
                }
            }
        }
        if (!count && total_parts_collected != k) impossible = true;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    double x, y;
    
    cin >> t;
    while(t--) {
        cin >> n >> k;
        min_dist = DBL_MAX;
        impossible = false;
        points.clear();
        parts.clear();
        // points.push_back({0.0, 0.0});
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            points.push_back({x, y});
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            parts.push_back(s);
        }
        unordered_map<int, bool> m;
        for (int i = 0; i < n; i++) {
            double dist;
            dist = sqrt((points[i].first * points[i].first) + (points[i].second * points[i].second));
            travel(i, m, m, 0, dist);
        }
        if (impossible) cout << "-1\n";
        else cout << min_dist << "\n";
    }
    return 0;
}
