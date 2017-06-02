#include<bits/stdc++.h>
using namespace std;

vector<int> v;
void create_set() {
	bool remove[501];
	memset(remove, 0, sizeof(remove));
	for (int i = 1; i <= 500; i++) {
		if (!remove[i]) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] + i > 500) break;
				remove[v[j] + i] = 1;
			}
			v.push_back(i);
		}
	}
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    create_set();
    
    int t, n;
    cin >> t;
    while(t--) {
    	cin >> n;
    	for (int i = 0; i < n; i++) cout << v[i] << " ";
    	cout << "\n";
    }

    return 0;
}
