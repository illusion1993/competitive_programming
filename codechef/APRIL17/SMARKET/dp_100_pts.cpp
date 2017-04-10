#include<bits/stdc++.h>
using namespace std;

int n, a[100000];
unordered_map<int, int> index_blocks;                 // 1 based index, 0 based block index
vector<pair<int, int> > block_terminals;    // 1 based start, end of each block's elems
vector<vector<int> > dp;                    // 1 based index, 1 based order

void clearPrevTestcase() {
    index_blocks.clear();
    block_terminals.clear();
    dp.clear();
}

void makeblocks() {
    clearPrevTestcase();
    pair<int, int> terminal;
    terminal.first = 1;
    index_blocks[1] = 0;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    
    for (int i = 1; i <= n; i++) {
        if (i < n && a[i] == a[i - 1]) {
            index_blocks[i + 1] = block_terminals.size();
            
            if (dp.size() && dp.back().size() > v.size()) {
                v.push_back(dp.back()[v.size()]);
                v[v.size() - 1]++;
            }
            else v.push_back(1);
        }
        else {
            terminal.second = i;
            block_terminals.push_back(terminal);
            index_blocks[i + 1] = block_terminals.size();
            terminal.first = i + 1;

            if (dp.size()) for (int j = v.size(); j < dp.back().size(); j++) v.push_back(dp.back()[j]);

            dp.push_back(v);
            v.clear();
            v.push_back(0);     // 0 order
            v.push_back(dp.back()[1] + 1);
        }
    }
}

int dpval(int block_index, int order) {
    if (block_index < 0 || dp[block_index].size() < order + 1) return 0;
    return dp[block_index][order];
}

int lposInBlock(int index, int block_index) {
    return index - block_terminals[block_index].first + 1;
}

int rposInBlock(int index, int block_index) {
    return block_terminals[block_index].second - index + 1;
}

int findBlocksOfOrder(int l_index, int r_index, int order) {
    int c, l_block, r_block;
    l_block = index_blocks[l_index];
    r_block = index_blocks[r_index];
    c = dpval(r_block, order) - dpval(l_block - 1, order);
    if (rposInBlock(l_index, l_block) < order && dpval(l_block, order) != dpval(l_block - 1, order)) c--;
    if (lposInBlock(r_index, r_block) < order && dpval(r_block, order) != dpval(r_block - 1, order)) c--;
    return c;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t, in, in1, in2, q;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) cin >> a[i];
        makeblocks();
        for (int i = 0; i < q; i++) {
            cin >> in >> in1 >> in2;
            cout << findBlocksOfOrder(in, in1, in2) << "\n";
        }
    }

    return 0;
}
