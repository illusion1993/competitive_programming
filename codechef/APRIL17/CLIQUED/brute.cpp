#include<bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, k, x, m, s;
ll min_dist[100001];
bool traversed[100001];
unordered_map<int, map<int, vector<int> > > paths;

void clear() {
	memset(min_dist, 0, sizeof(min_dist));
	memset(traversed, 0, sizeof(traversed));
	paths.clear();
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

void traverse(int source, ll dist_so_far) {
	if (!traversed[source] || dist_so_far < min_dist[source]) {
		min_dist[source] = dist_so_far;
		traversed[source] = 1;
		int halt_at = (source <= k) ? x : paths[source].end() -> first;

		map<int, vector<int> >::iterator it;
		for (it = paths[source].begin(); it != paths[source].end() && it -> first <= halt_at ; it++) {
			for (int i = 0; i < it -> second.size(); i++) {
				traverse(it -> second[i], it -> first + dist_so_far);
			}
		}

		if (source <= k) {
			for (int i = 1; i <= k; i++) {
				if ((!traversed[i] || min_dist[i] > dist_so_far + x) && i != source) {
					traverse(i, dist_so_far + x);
				}
			}
		}

		while(it != paths[source].end()) {
			for (int i = 0; i < it -> second.size(); i++) {
				traverse(it -> second[i], it -> first + dist_so_far);
			}
			it++;
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
		traverse(s, 0);
		printDist();
    }

	return 0;
}