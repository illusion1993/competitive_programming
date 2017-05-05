#include<bits/stdc++.h>
using namespace std;


vector<int> a;
struct node {
    int val, from, to;
    node * left, * right;
};

node * createNode(int from, int to) {
    node * me = new node();
    if (from == to) {
        me -> val = a[from];
        me -> left = me -> right = NULL;
        me -> from = from;
        me -> to = to;
        return me;
    }
    me -> left = createNode(from, (from + to) / 2);
    me -> right = createNode(((from + to) / 2) + 1, to);
    me -> val = max(me -> left -> val, me -> right -> val);
    me -> from = from;
    me -> to = to;
    return me;
}

int queryMax(node * me, int from, int to) {
    if (from == me -> from && to == me -> to) return me -> val;
    int qMax = INT_MIN;
    if (from <= (me -> from + me -> to) / 2) {
        qMax = max(qMax, queryMax(me -> left, from, min((me -> from + me -> to) / 2, to)));
    }
    if (to > (me -> from + me -> to) / 2) {
        qMax = max(qMax, queryMax(me -> right, max(from, ((me -> from + me -> to) / 2) + 1), to));
    }
    return qMax;
}

void inorder(node * me) {
    if (!me) return;
    inorder(me -> left);
    cout << "(" << me -> from << "-" << me -> to << ":" << me -> val << ")  ";
    inorder(me -> right);
}

void makeVector() {
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(4);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(2);
}

int main(int argc, char const *argv[])
{
    int tc, f, t;
    cin >> tc;

    makeVector();
    node * root = createNode(0, a.size() - 1);
    cout << "INORDER:\n";
    inorder(root);

    for (int i = 0; i < tc; i++) {
        cin >> f >> t;
        cout << queryMax(root, f, t) << "\n";
    }
    return 0;
}