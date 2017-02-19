/// Crossing the paths of both vertices as the edge is inserted
#include<bits/stdc++.h>
using namespace std;

int n, q, in1, in2, in3;

struct node {
    int value, index;
    vector<node*> paths;

    node(int v, int i) : value(v), index(i) {}

    void operator+(node * b) {
        paths.push_back(b);
    }

    void operator=(int v) {
        value = v;
    }
};

node *node_book[100001];
map<int, vector<vector<int> > > paths;
map<int, vector<pair<int, int> > > paths_with_vertex_terminal;       // {int(index of vertex): [pair<int(path_begin), int(path_end)]>}

void create_cross_paths(int a, int b) {                              // where a can go, b can go and vice-versa (used as edges inserted)

}

vector<vector<int> > get_subtree_path_nodes(node * a, node * parent) {
    vector<vector<int> > ans;        // from, to, index, index...
    vector<vector<int> > new_paths;
    vector<int> tmp;

    if (a -> paths.size() == 1) {
        for (int i = 0; i < 3; i++)
            tmp.push_back(a -> index);
        ans.push_back(tmp);
        return ans;
    }

    for (int i = 0; i < a -> paths.size(); i++) {
        if (a -> paths[i] != parent) {
            new_paths = get_subtree_path_nodes(a -> paths[i], a);

            /*
            cout << "New paths given to " << a->index << " by " << a->paths[i]->index << " are: ";
            for (int x = 0; x < new_paths.size(); x++) cout << new_paths[x][0] << " - " << new_paths[x][1] << " , ";
            cout << endl << "Now Hijacking all these paths!" << endl;
            */

            for (int j = 0; j < new_paths.size(); j++) {
                new_paths[j][0] = a -> index;
                new_paths[j].push_back(a -> index);
            }
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; k < new_paths.size(); k++) {
                    tmp.clear();
                    tmp.insert(tmp.end(), ans[j].begin() + 2, ans[j].end());
                    tmp.insert(tmp.end(), new_paths[k].begin() + 2, new_paths[k].end() - 1);
                    path_nodes[{ans[j][1], new_paths[k][1]}] = tmp;
                    path_nodes[{new_paths[k][1], ans[j][1]}] = tmp;
                    /*
                    cout << "Path " << ans[j][1] << " - " << new_paths[k][1] << " , " << new_paths[k][1] << " - " << ans[j][1] << ": ";
                    for (int x = 0; x < tmp.size(); x++) cout << tmp[x] << " ";
                    cout << endl;
                    */
                }
            }
            ans.insert(ans.end(), new_paths.begin(), new_paths.end());
        }
    }

    tmp.clear();
    for (int i = 0; i < 3; i++)
        tmp.push_back(a -> index);
    ans.push_back(tmp);

    for (int i = 0; i < ans.size(); i++) {
        tmp.clear();
        tmp.insert(tmp.end(), ans[i].begin() + 2, ans[i].end());
        path_nodes[{ans[i][0], ans[i][1]}] = tmp;
        path_nodes[{ans[i][1], ans[i][0]}] = tmp;
        /*
        cout << "Path " << ans[i][0] << " - " << ans[i][1] << " , " << ans[i][1] << " - " << ans[i][0] << ": ";
        for (int x = 0; x < tmp.size(); x++) cout << tmp[x] << " ";
        cout << endl;
        */
    }
    return ans;
}

int main() {
    cin >> n >> q;
    node_book[0] = NULL;
    node * tmp;
    for (int i = 1; i <= n; i++) {
        cin >> in1;
        tmp = new node(in1, i);
        node_book[i] = tmp;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> in1 >> in2;
        *node_book[in1] + node_book[in2];
        *node_book[in2] + node_book[in1];
    }

    for (int i = 0; i < q; i++) {
        cin >> in1 >> in2 >> in3;
        if (in1 - 1) {
            *node_book[in2] = in3;
        }
        else {

        }
    }

    return 0;
}
