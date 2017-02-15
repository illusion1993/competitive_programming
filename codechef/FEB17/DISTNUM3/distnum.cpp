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

vector<int> traversal;
map<int, int> pos_in_traversal;     // index of node, first index in traversal vector

//map<int, map<int, bool> > loop_contents;
map<int, int> loop_close_index;

map<int, bool> cyclic_index_traversal(node * a, node * parent) {
    map<int, bool> ans;
    map<int, bool> subtree;

    int start1, close1, start2, close2;
    traversal.push_back(a -> index);
    pos_in_traversal[a -> index] = traversal.size() - 1;

    if (a -> paths.size() > 1) {
        start1 = traversal.size() - 1;
        //cout << "Loop begin at index " << traversal.size() - 1 << endl;
    }
    for (int i = 0; i < a -> paths.size(); i++) {
        if (a -> paths[i] != parent) {
            traversal.push_back(a -> index);
            start2 = traversal.size() - 1;

            //cout << "Loop begin at index " << traversal.size() - 1 << endl;
            subtree = cyclic_index_traversal(a -> paths[i], a);
            traversal.push_back(a -> index);
            close2 = traversal.size() - 1;
            //loop_contents[start2] = subtree;                // inserting the smaller loop in loop collection
            loop_close_index[start2] = close2;              // declaring the closing index of smaller loop
            ans.insert(subtree.begin(), subtree.end());     // merged subtree loop contents with outer loop

            //cout << "Loop end at index " << traversal.size() - 1 << endl;
        }
    }
    ans[a -> index] = true;
    if (a -> paths.size() > 1) {
        traversal.push_back(a -> index);
        close1 = traversal.size() - 1;
        //loop_contents[start1] = ans;
        loop_close_index[start1] = close1;

        //cout << "Loop end at index " << traversal.size() - 1 << endl;
    }
    return ans;
}

int findPathUniques(int a, int b) {
    int pos_a = -1, pos_b = -1, pos = 0;
    vector<int> path;
    map<int, bool> occured;

    pos_a = pos_in_traversal[a];
    pos_b = pos_in_traversal[b];

    for (int i = min(pos_a, pos_b); i <= max(pos_a, pos_b); i++) {
        /*
        if (path.size() >= 2 && path[path.size() - 2] == traversal[i]) path.pop_back();
        else path.push_back(traversal[i]);
        */
        path.push_back(traversal[i]);
        if (loop_close_index.count(i) && loop_close_index[i] < max(pos_a, pos_b)) i = loop_close_index[i];
    }

    for (int i = 0; i < path.size(); i++) occured[node_book[path[i]] -> value] = true;

    return occured.size();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    //cout << "Input taken" << endl;
    cyclic_index_traversal(node_book[1], NULL);
    //cout << "traversal done!" << endl;
    //for (int i = 0; i < traversal.size(); i++) cout << traversal[i] << " ";

    for (int i = 0; i < q; i++) {
        cin >> in1 >> in2 >> in3;
        if (in1 - 1) {
            *node_book[in2] = in3;
        }
        else {
            cout << findPathUniques(in2, in3) << "\n";
        }
    }

    return 0;
}
