#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;

vector<int> p;
void pushPal(int x) {
	if (x / 1000000 == 0 && x / 100000 != 0) {
		if (x % 10 == x / 100000 && (x / 10) % 10 == (x / 10000) % 10 && (x / 100) % 10 == (x / 1000) % 10) {
			p.push_back(x);
		}
	}
}
void findPals() {
	for (int i = 100; i < 1000; i++) {
		for (int j = i; j < 1000; j++) pushPal(i * j);
	}
	sort(p.begin(), p.end());
}
int countPals(int x) {
	for (int i = p.size() - 1; i >= 0; i--) if (p[i] < x) return p[i];
}

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	findPals();
	int t;
    cin >> t;
    while(t--) {
    	cin >> n;
    	cout << countPals(n) << "\n";
    }
    return 0;
}