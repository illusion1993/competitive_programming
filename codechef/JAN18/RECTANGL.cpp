#include <bits/stdc++.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, in;
    unordered_map<int, int> counts;

    cin >> t;

    while (t--) {
    	counts.clear();
    	for (int i = 0; i < 4; i++) {
    		cin >> in;
    		if (!counts.count(in)) counts[in] = 0;
    		counts[in]++;
    	}
    	if (counts.size() > 2)
    		cout << "NO\n";
    	else if (counts.size() == 1)
    		cout << "YES\n";
    	else if (counts[in] == 2)
    		cout << "YES\n";
    	else 
    		cout << "NO\n";
    }

    return 0;
}