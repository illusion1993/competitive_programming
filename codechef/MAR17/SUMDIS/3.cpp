#include<bits/stdc++.h>
using namespace std;

int t, n, in, distance_from_source[100001], parent_in_path_from_source[100001], neighbours[100001][3];
map<int, vector<pair<int, int> > >shortest_path_segments; // source: <dest, distance> <dest, distance>
bool inside_queue[100001];
queue <pair<int, int> > to_traverse;    // node number to traverse, dist so far till this node
long long sumdis;

void clear_history() {
    memset(distance_from_source, 0, sizeof(distance_from_source));
    memset(inside_queue, 0, sizeof(inside_queue));
}

void prepare_neighbours() {
    shortest_path_segments.clear();
    for (int i = 1; i <= n - 1; i++) {
        cin >> in;
        neighbours[i][0] = in;
        sumdis += in;
    }
    for (int i = 1; i <= n - 2; i++) {
        cin >> in;
        neighbours[i][1] = in;
    }
    for (int i = 1; i <= n - 3; i++) {
        cin >> in;
        neighbours[i][2] = in;
    }
}

void traverse() {
    if (!to_traverse.size()) return;
    int source = to_traverse.front().first, distance_so_far = to_traverse.front().second;
    to_traverse.pop();
    for (int i = 0; i < 3; i++) {
        int this_node = source + i + 1, this_distance = distance_so_far + neighbours[source][i];
        if ((!inside_queue[this_node] || this_distance < distance_from_source[this_node]) && this_node <= n) {
            distance_from_source[this_node] = this_distance;
            parent_in_path_from_source[this_node] = source;

            if (shortest_path_segments.count(source)) shortest_path_segments[source].push_back({this_node,this_distance});
            else {
                vector<pair<int, int> > x;
                x.push_back({this_node, this_distance});
                shortest_path_segments[source] = x;
            }

            to_traverse.push({this_node, this_distance});
            inside_queue[this_node] = true;
        }
    }
    traverse();
}

bool segments_from_node(int node) {
    if (node == n) return true;
    return (shortest_path_segments.count(node) && shortest_path_segments[node].size());
}

int main() {
    cin >> t;
    while(t--) {
        sumdis = 0;
        cin >> n;
        prepare_neighbours();

        for (int source = 1; source < n; source++) {
            if (!segments_from_node(source)) {
                cout << "Source is " << source << ": \n";
                cout << "Distances from source: \n";
                clear_history();
                to_traverse.push({source, 0});
                traverse();
                for (int i = 2; i <= n; i++) cout << i << ": " << distance_from_source[i] << "\n";
                cout << "\nParent in path from source: \n";
                for (int i = 2; i <= n; i++) {
                    cout << i << ": " << parent_in_path_from_source[i] << endl;
                }
                cout << "\nShortest path segments: \n";
                for (int i = 2; i <= n; i++) {
                    if (shortest_path_segments.count(i)) {
                        for (int j = 0; j < shortest_path_segments[i].size(); j++) {
                            cout << i << " - " << shortest_path_segments[i][j].first << ": " << shortest_path_segments[i][j].second << "\n";
                        }
                    }
                }
            }
        }

        //cout << sumdis << "\n";
    }

    return 0;
}
