#include <bits/stdc++.h>
using namespace std;

int x, y, z, spaces, arr[100][100][100];

void evacuate(int a, int b, int c) {
    if (arr[a][b][c]) return;
    
    arr[a][b][c] = 1;
    spaces--;
    
    if (a - 1 >= 0) evacuate(a - 1, b, c);
    if (a + 1 < x) evacuate(a + 1, b, c);
    if (b - 1 >= 0) evacuate(a, b - 1, c);
    if (b + 1 < y) evacuate(a, b + 1, c);
    if (c - 1 >= 0) evacuate(a, b, c - 1);
    if (c + 1 < z) evacuate(a, b, c + 1);
}

void evacuate_xy_planes(int k) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            evacuate(i, j, k);
        }
    }
}
void evacuate_xz_planes(int j) {
    for (int i = 0; i < x; i++) {
        for (int k = 1; k < z - 1; k++) {
            evacuate(i, j, k);
        }
    }
}
void evacuate_yz_planes(int i) {
    for (int j = 1; j < y - 1; j++) {
        for (int k = 1; k < z - 1; k++) {
            evacuate(i, j, k);
        }
    }
}

int find_air_volume() {
    
    evacuate_xy_planes(0);
    evacuate_xy_planes(z - 1);
    evacuate_xz_planes(0);
    evacuate_xz_planes(y - 1);
    evacuate_yz_planes(0);
    evacuate_yz_planes(x - 1);
    
    return spaces;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    spaces = 0;
	    cin >> x >> y >> z;
	    for (int i = 0; i < x; i++) {
	        for (int j = 0; j < y; j++) {
	            for (int k = 0; k < z; k++) {
	                cin >> arr[i][j][k];
	                if (!arr[i][j][k]) spaces++;
	            }
	        }
	    }
	    cout << find_air_volume() << "\n";
	}
	return 0;
}
