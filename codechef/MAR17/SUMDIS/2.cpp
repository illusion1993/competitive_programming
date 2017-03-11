#include<bits/stdc++.h>
using namespace std;

int t, n, in;
long long sumdis;
vector<vector<pair<int, int> > > neighbours;
map<int, int> distance_from_source;
map<int, int> parent_in_path_from_source;


void prepare_neighbours() {
    vector<pair<int, int> > v;
    neighbours.clear();
    distance_from_source.clear();
    parent_in_path_from_source.clear();
    for (int i = 0; i <= n; i++) neighbours.push_back(v);

    // Input
    for (int i = 1; i <= n - 1; i++) {
        cin >> in;
        neighbours[i].push_back({in, i + 1});
        sumdis += in;
    }
    for (int i = 1; i <= n - 2; i++) {
        cin >> in;
        neighbours[i].push_back({in, i + 2});
    }
    for (int i = 1; i <= n - 3; i++) {
        cin >> in;
        neighbours[i].push_back({in, i + 3});
    }
    //for (int i = 1; i < neighbours.size(); i++) sort(neighbours[i].rbegin(), neighbours[i].rend());
}

void find_distance_from_source(int source, int distance_so_far) {
    for (int i = neighbours[source].size() - 1; i >= 0; i--) {
        if (distance_from_source.count(neighbours[source][i].second) == 0 || distance_from_source[neighbours[source][i].second] >= distance_so_far + neighbours[source][i].first) {
            distance_from_source[neighbours[source][i].second] = distance_so_far + neighbours[source][i].first;
            parent_in_path_from_source[neighbours[source][i].second] = source;
            find_distance_from_source(neighbours[source][i].second, distance_so_far + neighbours[source][i].first);
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        sumdis = 0;
        cin >> n;
        prepare_neighbours();
        /*find_distance_from_source(1, 0);

        cout << "Distances from source: \n";
        for (int i = 2; i <= n; i++) cout << i << ": " << distance_from_source[i] << "\n";

        cout << "\nParent in path from source: \n";
        for (int i = 2; i <= n; i++) {
            cout << i << ": " << parent_in_path_from_source[i] << endl;
        }*/

        //cout << sumdis << "\n";
    }

    return 0;
}
