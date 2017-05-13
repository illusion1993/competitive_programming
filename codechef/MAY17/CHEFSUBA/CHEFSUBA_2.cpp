#include<bits/stdc++.h>
using namespace std;

int n, k, p, rotations;
string s;
bool a[100000];
unordered_map<int, int> cache;

class SegmentTree {
    struct node {
        int _val, _from, _to;
        node * _left, * _right;
        node(int from, int to, int val) : _from(from) , _to(to), _val(val), _left(NULL), _right(NULL) {}
        node(int from, int to, node * left, node * right) : _from(from) , _to(to), _left(left), _right(right), _val(0) {}
        void findVal() { if (_left) _val = _left -> _val; if (_right) _val = max(_val, _right -> _val); }
        int query(int from, int to) {
            if (from > to) return 0;
            if (from == _from && to == _to) return _val;
            int l_child_end = (_from + _to) / 2;
            return max(_left -> query(from, min(l_child_end, to)), _right -> query(max(l_child_end + 1, from), to));
        }
    };
    node * _root;
    node * _createNode(int from, int to) {
        node * n = NULL;
        if (from == to) n = new node(from, to, _values[from]);
        else if (from < to) {
            int l_child_end = (from + to) / 2;
            n = new node(from, to, _createNode(from, l_child_end), _createNode(l_child_end + 1, to));
            n -> findVal();
        }
        return n;
    }
public:
    vector<int> _values;
    int queryMax(int from, int to) { return _root -> query(from, to); }
    void build() { _root = _createNode(0, _values.size() - 1); }
};
SegmentTree * st;

void findCounts() {
    rotations = 0;
    int count = 0;
    for (int i = 0; i < k; i++) count += a[i];
    st -> _values.push_back(count);
    for (int i = 1; i < n; i++) {
        count -= a[i - 1];
        count += a[(i + k - 1) % n];
        st -> _values.push_back(count);
    }
    st -> build();
}

int calc() {
    if (cache.count(rotations)) return cache[rotations];
    int qMax;
    qMax = (rotations <= n - k + 1) ? 
            max(st -> queryMax(0, n - k - rotations), st -> queryMax(n - rotations, n - 1)) 
            : st -> queryMax(n - rotations, n - k + n - rotations);
    
    cache[rotations] = qMax;
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
    st = new SegmentTree();
    cin >> n >> k >> p;
    k = min(n, k);
    for (int i = 0; i < n; i++) cin >> a[i];
    findCounts();
    cin >> s;
    for (int i = 0; i < s.length(); i++) process(s[i]);
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