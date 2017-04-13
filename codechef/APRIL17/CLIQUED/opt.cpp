#include<bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, k, x, m, s;
ll min_dist[100001];
bool traversed[100001];
unordered_map<int, map<int, vector<int> > > paths;
int closest_terminal;

void clear() {
	memset(min_dist, 0, sizeof(min_dist));
	memset(traversed, 0, sizeof(traversed));
	paths.clear();
	closest_terminal = INT_MAX;
}

void makePath(int v1, int v2, int dist) {
	map<int, vector<int> > m;
	vector<int> v;
	if (!paths.count(v1)) paths[v1] = m;
	if (!paths.count(v2)) paths[v2] = m;
	if (!paths[v1].count(dist)) paths[v1][dist] = v;
	if (!paths[v2].count(dist)) paths[v2][dist] = v;
	paths[v1][dist].push_back(v2);
	paths[v2][dist].push_back(v1);
}

void traverse(int source, ll dist_so_far, bool find_closest_terminal) {
	if (!traversed[source] || dist_so_far < min_dist[source]) {
		min_dist[source] = dist_so_far;
		traversed[source] = 1;
		if (source <= k && find_closest_terminal) closest_terminal = (closest_terminal == INT_MAX) ? source : (dist_so_far < min_dist[closest_terminal]) ? source : closest_terminal;
		for (map<int, vector<int> >::iterator it = paths[source].begin(); it != paths[source].end() ; it++) {
			for (int i = 0; i < it -> second.size(); i++) {
				traverse(it -> second[i], it -> first + dist_so_far, find_closest_terminal);
			}
		}
	}
}

void printDist() {
	for (int i = 1; i <= n; i++) cout << min_dist[i] << " ";
	cout << "\n";
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

    int tmp, tmp1, tmp2;
    cin >> t;
    while(t--) {
    	clear();
    	cin >> n >> k >> x >> m >> s;
    	while(m--) {
			cin >> tmp >> tmp1 >> tmp2;
			makePath(tmp, tmp1, tmp2);
		}
		traverse(s, 0, 1);
		// for (int i = 1; i <= k; i++) {
		// 	if (i != closest_terminal) {
		// 		traverse(i, min_dist[closest_terminal] + x, 0);
		// 	}
		// }
		printDist();
    }

	return 0;
}