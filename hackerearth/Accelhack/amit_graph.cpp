#include<bits/stdc++.h>
using namespace std;

bool is_cycle;
map<int, vector<int> > paths;
int req[100001], req_count, inc[100001], traversed[100001], traversed_count, in_pairs[100001], pair_nodes;

void traverse(int node) {
	if (traversed[node]) {
		is_cycle = true;
	}

	if (!is_cycle) {
		traversed[node] = 1;
		traversed_count++;
		for (int i = 0; i < paths[node].size(); i++) traverse(paths[node][i]);
	}
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, m, in1, in2;
    cin >> t;
    
    while(t--) {
    	is_cycle = false;
    	paths.clear();
    	traversed_count = 0;
    	req_count = 0;
    	pair_nodes = 0;
    	memset(req, 0, sizeof(req));
    	memset(inc, 0, sizeof(inc));
    	memset(traversed, 0, sizeof(traversed));
    	memset(in_pairs, 0, sizeof(in_pairs));

    	cin >> n >> m;
    	for (int i = 0; i < m; i++) {
    		cin >> in1 >> in2;
    		if (paths.count(in1)) paths[in1].push_back(in2);
    		else {
    			vector<int> v;
    			v.push_back(in2);
    			paths[in1] = v;
    		}
    		inc[in2] = 1;
    		if (req[in2]) {
    			req[in2] = 0;
    			req_count--;
    		}

    		if (inc[in1] == 0) {
    			if (req[in1] == 0) {
    				req_count++;
    				req[in1] = 1;
    			}
    		}
    		if (!in_pairs[in1]) pair_nodes++;
    		if (!in_pairs[in2]) pair_nodes++;
    		in_pairs[in1] = 1;
    		in_pairs[in2] = 1;
    	}
    	if (!req_count) cout << "0\n";
    	else {
    		for (int i = 1; i <= n; i++) {
    			if (req[i]) traverse(i);
    		}
    		if (is_cycle || traversed_count != pair_nodes) cout << "0\n";
    		else cout << "1\n";
    	}
    }

	return 0;
}