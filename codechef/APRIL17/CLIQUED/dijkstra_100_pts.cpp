#include<bits/stdc++.h>
using namespace std;
#define ll long long

set<pair<int, int> > *adj;

int t, n, k, x, m, s, a, b, c, closest_terminal;
ll *min_dist;

void clear() {
	min_dist = new ll[n + 1];
	for (int i = 0; i <= n; i++) min_dist[i] = LLONG_MAX;
	adj = new set<pair<int, int> >[n + 1];
	closest_terminal = 0;
}

void dijkstra(int source, ll dist_so_far, bool find_closest_terminal) {
	if (dist_so_far < min_dist[source]) {
		min_dist[source] = dist_so_far;
		set<pair<ll, int> > targets;
		targets.insert({dist_so_far, source});

		while(!targets.empty()) {
			int this_vertex = targets.begin() -> second;
			ll this_dist = targets.begin() -> first;
			targets.erase(targets.begin());

			if (find_closest_terminal && this_vertex <= k) 
				closest_terminal = 
				(!closest_terminal) ? this_vertex : (min_dist[closest_terminal] > min_dist[this_vertex]) ? this_vertex : closest_terminal;

			for (auto p : adj[this_vertex]) {
				if (min_dist[p.second] > this_dist + p.first) {
					min_dist[p.second] = this_dist + p.first;
					targets.insert({this_dist + p.first, p.second});
				}
			}
		}
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n >> k >> x >> m >> s;
		clear();
	    for(int i = 0; i < m; i++){
	        cin >> a >> b >> c;
	        adj[a].insert({c, b});
	        adj[b].insert({c, a});
	    }

	    dijkstra(s, 0, 1);
	    for (int i = 1; i <= k; i++) {
	    	if (i != closest_terminal) {
	    		dijkstra(i, min_dist[closest_terminal] + x, 0);
	    	}
	    }

	    for(int i = 1; i <= n; i++) cout << min_dist[i] << " ";
    	cout << "\n";
	}

    return 0;
}