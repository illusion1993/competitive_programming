#include<bits/stdc++.h>
using namespace std;

int n, k, p, rotations;
string s;
vector<int> counts;
bool a[100000];
unordered_map<int, int> ans;

struct node {
    int val, from, to;
    node * left, * right;
};

node * root;
node * createNode(int from, int to) {
    node * me = new node();
    if (from == to) {
        me -> val = counts[from];
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
    if (from > to) return 0;
    if (from == me -> from && to == me -> to) return me -> val;
    int qMax = 0;
    if (from <= (me -> from + me -> to) / 2) {
        qMax = max(qMax, queryMax(me -> left, from, min((me -> from + me -> to) / 2, to)));
    }
    if (to > (me -> from + me -> to) / 2) {
        qMax = max(qMax, queryMax(me -> right, max(from, ((me -> from + me -> to) / 2) + 1), to));
    }
    return qMax;
}
void findCounts() {
    rotations = 0;
    int count = 0;
    for (int i = 0; i < k; i++) count += a[i];
    counts.push_back(count);
    for (int i = 1; i < n; i++) {
        count -= a[i - 1];
        count += a[(i + k - 1) % n];
        counts.push_back(count);
    }
    root = createNode(0, counts.size() - 1);
}

int calc() {
    if (ans.count(rotations)) return ans[rotations];
    int qMax = 0;
    if (rotations <= n - k + 1) {
        qMax = max(qMax, queryMax(root, 0, n - k - rotations));
        qMax = max(qMax, queryMax(root, n - rotations, n - 1));
    }
    else {
        qMax = max(qMax, queryMax(root, n - rotations, n - k + n - rotations));
    }
    ans[rotations] = qMax;
    return qMax;
}

void process(char ch) {
    if (ch == '!') rotations = (rotations + 1) % n;
    else cout << calc() << "\n";
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> p;
    k = min(n, k);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    findCounts();
    for (int i = 0; i < p; i++) process(s[i]);
    return 0;
}

/*

19 3 2
0 0 1 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1
!?

15 5 60
0 1 1 0 1 1 1 0 0 1 1 1 1 1 0
!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?

*/