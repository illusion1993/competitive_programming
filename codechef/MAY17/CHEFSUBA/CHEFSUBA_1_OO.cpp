#include<bits/stdc++.h>
using namespace std;

class Opt {
    struct node
    {
        int val, from, to;
        node * left, * right;
    };
    node * _root;
    unordered_map<int, int> _cache;
    int _rotations, _n, _k;
    node * createNode(int from, int to, const vector<int> &a) {
        node * me = new node();
        if (from == to) {
            me -> val = a[from];
            me -> left = me -> right = NULL;
            me -> from = from;
            me -> to = to;
            return me;
        }
        me -> left = createNode(from, (from + to) / 2, a);
        me -> right = createNode(((from + to) / 2) + 1, to, a);
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

public:
    void init(int n, int k, const vector<int> &a) {
        _n = n; _k = k; _rotations = 0;
        _root = createNode(0, a.size() - 1, a);
    }
    void rotate() { _rotations = (_rotations + 1) % _n; }
    int calc() {
        if (_cache.count(_rotations)) return _cache[_rotations];
        int qMax = 0;
        if (_rotations <= _n - _k + 1) {
            qMax = max(qMax, queryMax(_root, 0, _n - _k - _rotations));
            qMax = max(qMax, queryMax(_root, _n - _rotations, _n - 1));
        }
        else {
            qMax = max(qMax, queryMax(_root, _n - _rotations, _n - _k + _n - _rotations));
        }
        _cache[_rotations] = qMax;
        return qMax;
    }
};

Opt sol2;

int main(int argc, char const *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);

    int n, k, p, count;
    string s;
    vector<int> counts;
    vector<bool> a;

    // Input n,k,p and array
    cin >> n >> k >> p;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> count; a[i] = count;
    }
    
    // Find counts of 1's in all positions of window
    count = 0;
    for (int i = 0; i < k; i++) count += a[i];
    counts.push_back(count);
    for (int i = 1; i < n; i++) {
        count -= a[i - 1];
        count += a[(i + k - 1) % n];
        counts.push_back(count);
    }

    // Initialize solution
    sol2.init(n, k, counts);

    // Input query string and process it char by char
    cin >> s;
    for (int i = 0; i < p; i++) {
        if (s[i] == '!') {
            sol2.rotate();
        }
        else {
            cout << sol2.calc() << "\n";
        }
    }
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