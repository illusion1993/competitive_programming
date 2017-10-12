#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, k, arr[200001], tmp;
	cin >> t;
	while(t--) {
	    cin >> n >> k;
	    memset(arr, 0, sizeof(arr));
	    while(n--) {
	        cin >> tmp;
	        arr[tmp] = 1;
	    }
	    tmp = 0;
	    while (k) {
	        if (!arr[tmp]) {
	            k--;
	        }
	        tmp++;
	    }
	    while (tmp <= 200000 && arr[tmp]) {
	        tmp++;
	    }
	    cout << tmp << "\n";
	}
	return 0;
}
