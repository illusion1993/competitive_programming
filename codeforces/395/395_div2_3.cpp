#include<bits/stdc++.h>

using namespace std;

int n, paths[100000][2], color[100000];
map< pair<int, int>, int> subtree_color;    // common color, else -1

int getSubtreeColor(int node, int parent) {
    pair<int, int> key;
    key = make_pair(node, parent);

    if (subtree_color[key]) {
        //cout << "at node " << node << " for parent " << parent << " is already " << subtree_color[key] << endl;
        return subtree_color[key];
    }

    //cout << "at node " << node << " for parent " << parent << " is computing " << endl;
    int color_so_far = color[node - 1];
    //cout << "color so far is " << color_so_far << endl;
    for (int i = 0; i < n - 1; i++) {
        if (paths[i][0] == node && paths[i][1] != parent) {
            color_so_far = (color_so_far == getSubtreeColor(paths[i][1], node)) ? color_so_far : -1;
            //cout << "after checking color for child node " << paths[i][1] << ", color so far is " << color_so_far << endl;
        }
        else if (paths[i][1] == node && paths[i][0] != parent) {
            color_so_far = (color_so_far == getSubtreeColor(paths[i][0], node)) ? color_so_far : -1;
            //cout << "after checking color for child node " << paths[i][0] << ", color so far is " << color_so_far << endl;
        }
    }
    subtree_color[key] = color_so_far;
    //cout << "COMPUTED: subtree color at node " << node << " with parent " << parent << " is " << color_so_far << endl;
    return color_so_far;
}

bool isGoodTree(int root) {
    bool is_good = true;
    for (int i = 0; i < n - 1; i++) {
        if (paths[i][0] == root && getSubtreeColor(paths[i][1], root) < 1) is_good = false;
        if (paths[i][1] == root && getSubtreeColor(paths[i][0], root) < 1) is_good = false;
    }
    return is_good;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> paths[i][0] >> paths[i][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    for (int i = 1; i <= n; i++) {
        if (isGoodTree(i)) {
            cout << "YES\n" << i;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
