#include<bits/stdc++.h>
using namespace std;

int n, k;
long long pairs;
int has_parent[100001];

struct node {
    vector<int> children;
};
node * nodebook[100001];

void traverse(int node_index, vector<int> ancestors) {

    /*cout << "called for node " << node_index << endl;
    cout << "Ancestors are: ";
    for (int i = 0; i < ancestors.size(); i++) cout << ancestors[i] << " ";
    cout << endl;*/

    for (int i = 0; i < ancestors.size(); i++) {
        if (abs(ancestors[i] - node_index) <= k) {
            //cout << "One pair is " << ancestors[i] << ", " << node_index << endl;
            pairs++;
        }
    }

    ancestors.push_back(node_index);
    for (int i = 0; i < nodebook[node_index] -> children.size(); i++) {
        traverse(nodebook[node_index] -> children[i], ancestors);
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int par, chil, root_index;
    memset(has_parent, 0, sizeof(has_parent));
    pairs = 0;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        node * tmp = new node();
        nodebook[i] = tmp;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> par >> chil;
        nodebook[par] -> children.push_back(chil);
        has_parent[chil] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!has_parent[i]) {
            root_index = i;
            //cout << "Root is " << i << endl;
            break;
        }
    }

    vector<int> v;
    traverse(root_index, v);
    cout << pairs;
    return 0;
}
