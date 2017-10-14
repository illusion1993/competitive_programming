#include <bits/stdc++.h>
using namespace std;

queue< pair<int, int> > two_coords;
int arr[1000][1000], dist[1000][1000];

int main() {
	memset(dist, 0, sizeof(dist));
	
	int r, c, tmp, max_dist = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
	    for (int j = 0; j < c; j++) {
	        cin >> arr[i][j];
	        if (arr[i][j] == 2) two_coords.push({i, j});
	    }
	}
	
	while (two_coords.size()) {
	    int x = two_coords.front().first, y = two_coords.front().second;
	    
        if (x - 1 >= 0 && arr[x - 1][y] == 1) {
            dist[x - 1][y] = dist[x][y] + 1;
            arr[x - 1][y] = 2;
            two_coords.push({x - 1, y});
            
            max_dist = max(max_dist, dist[x - 1][y]);
        }
        if (y - 1 >= 0 && arr[x][y - 1] == 1) {
            dist[x][y - 1] = dist[x][y] + 1;
            arr[x][y - 1] = 2;
            two_coords.push({x, y - 1});
            
            max_dist = max(max_dist, dist[x][y - 1]);
        }
        if (x + 1 < r && arr[x + 1][y] == 1) {
            dist[x + 1][y] = dist[x][y] + 1;
            arr[x + 1][y] = 2;
            two_coords.push({x + 1, y});
            
            max_dist = max(max_dist, dist[x + 1][y]);
        }
        if (y + 1 < c && arr[x][y + 1] == 1) {
            dist[x][y + 1] = dist[x][y] + 1;
            arr[x][y + 1] = 2;
            two_coords.push({x, y + 1});
            
            max_dist = max(max_dist, dist[x][y + 1]);
        }
	    
	    two_coords.pop();
	}
	
	cout << max_dist;
	
	return 0;
}
