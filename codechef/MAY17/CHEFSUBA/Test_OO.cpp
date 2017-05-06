#include<bits/stdc++.h>
using namespace std;

class Brute {
    vector<bool> _a;
    int _n, _k;

public:
    void init(int n, int k, vector<bool> a) {
        _n = n; _k = k; _a = a;
    }
    void rotate() {
        int l = _a.back();
        _a.pop_back();
        _a.insert(_a.begin(), l);
    }
    int calc() {
        int ans = 0;
        for (int i = 0; i + _k <= _n; i++) {
            int count = 0;
            for (int j = 0; j < _k; j++) count += _a[i + j];
            ans = max(ans, count);
        }
        return ans;
    }
};

class Opt {
    struct node
    {
        int val, from, to;
        node * left, * right;
    };
    node * _root;
    unordered_map<int, int> _cache;
    vector<int> _counts;
    int _rotations, _n, _k;

    node * createNode(int from, int to) {
        node * me = new node();
        if (from == to) {
            me -> val = _counts[from];
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
    void findCounts(const vector<bool> &a) {
        // Find counts of 1's in all positions of window
        int count = 0;
        for (int i = 0; i < _k; i++) count += a[i];
        _counts.push_back(count);
        for (int i = 1; i < _n; i++) {
            count -= a[i - 1];
            count += a[(i + _k - 1) % _n];
            _counts.push_back(count);
        }
    }

public:
    void init(int n, int k, const vector<bool> &a) {
        _n = n; _k = k; _rotations = 0;
        findCounts(a);
        _root = createNode(0, a.size() - 1);
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

class Testcase {
    vector<bool> a;
    int _n, _k;
    bool _err;
    
    void rotationTest() {
        Brute sol1;
        Opt sol2;
        sol1.init(_n, _k, a);
        sol2.init(_n, _k, a);

        for (int i = 0; i < 2 * _n && !_err; i++) {
            sol1.rotate();
            sol2.rotate();

            int a1, a2;
            a1 = sol1.calc();
            a2 = sol2.calc();
            if (a1 != a2) {
                _err = true;

                cout << "\n\nERR--\n";
                for (int j = 0; j < a.size(); j++) cout << a[j] << " ";
                cout << "\n";
            }
            else {
                // cout << _n << " " << _k << "\n";
                // for (int j = 0; j < a.size(); j++) cout << a[j] << " ";
                // cout << "\n";
                cout << a1 << " - " << a2 << " - OKAY\n";
            }
        }
    }
    void windowTest() {
        for (int i = 1; i <= _n && !_err; i++) {
            _k = i;
            rotationTest();
        }
    }

public:
    void test(int n) {
        _err = false;
        _n = n;
        for (int i = 0; i < n * 5 && !_err; i++) {
            a.clear();
            for (int i = 0; i < n; i++) a.push_back(rand() % 2);
            windowTest();
        }
    }
};

Brute sol1;
Opt sol2;

int main(int argc, char const *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);

    srand(time(0));

    int n; cin >> n;
    Testcase t;
    t.test(n);
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