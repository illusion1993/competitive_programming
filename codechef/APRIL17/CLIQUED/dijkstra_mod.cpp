#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define F first
#define S second

#define MAX_SIZE 100001

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ll> ill;
typedef vector<ii> vii;
typedef vector<ill> vill;

bool *traversed;
vill *adj;
ll min_dist[MAX_SIZE];
int t, n, k, x, m, s, a, b, c, closest_terminal;

void clear() {
	adj = new vill[MAX_SIZE];
	traversed = new bool[MAX_SIZE];
	closest_terminal = -1;
	for(int i = 0; i < MAX_SIZE; i++)
        min_dist[i]=INF;
}
 
void Dijkstra(int source, ll dist_so_far, bool find_closest_terminal)
{
	if (min_dist[source] <= dist_so_far) {
		return;
	}
    class prioritize{public: bool operator ()(ill &p1 ,ill &p2){return p1.S > p2.S;}};
    priority_queue<ill ,vill, prioritize> pq;
    pq.push({source, min_dist[source] = dist_so_far});
    if (find_closest_terminal && source <= k && (closest_terminal == -1 || min_dist[source] < min_dist[closest_terminal])) 
    	closest_terminal = source;
    
    while(!pq.empty())
    {
        ill current = pq.top();
        pq.pop();
        int this_vertex = current.F;
        ll this_dist = current.S;

        if (find_closest_terminal && this_vertex <= k && (closest_terminal == -1 || this_dist < min_dist[closest_terminal])) 
        	closest_terminal = this_vertex;
        
        if(traversed[this_vertex])
            {
            	continue;
            }
        
        traversed[this_vertex] = true;
        for(int i = 0; i < adj[this_vertex].size(); i++) {
        	if(!traversed[adj[this_vertex][i].F] && adj[this_vertex][i].S + this_dist < min_dist[adj[this_vertex][i].F]) {
        		pq.push({adj[this_vertex][i].F, (min_dist[adj[this_vertex][i].F] = adj[this_vertex][i].S + this_dist)});
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
	    for(int i = 0; i < m; i++)
	    {
	        cin >> a >> b >> c;
	        adj[a].push_back({b, c});
	        adj[b].push_back({a, c});
	    }

	    Dijkstra(s, 0, 1);
	    for (int i = 1; i <= k; i++) {
	    	if (i != closest_terminal) {
	    		traversed = new bool[MAX_SIZE];
	    		Dijkstra(i, min_dist[closest_terminal] + x, 0);
	    	}
	    }
	    for(int i = 1; i <= n; i++) cout << min_dist[i] << " ";
    	cout << "\n";
	}

    return 0;
}