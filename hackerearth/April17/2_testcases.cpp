#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> generate(int size, int max_val, bool print) {
	vector<int> tc;
	while(tc.size() != size) {
		tc.push_back((rand() % max_val) + 1);
		if (print) cout << tc.back() << " ";
	}
	if (print) cout << ": ";
	return tc;
}

ll brute(vector<int> testcase) {
	ll prod = 1, ans = 1;
	for (int i = 0; i < testcase.size(); i++) prod *= testcase[i];
	while(pow(ans, testcase.size()) < prod) ans++;
	return ans;
}

ll opt(vector<int> testcase) {
	double prod_root = 1;
	for (int i = 0; i < testcase.size(); i++) {
		prod_root *= pow((double)testcase[i], ((double)1 / (double)testcase.size()));
	}
	return ceil(prod_root);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));

	vector<int> tc;
	ll a, b;
	for (int i = 0; i < 1000; i++) {
		tc = generate(10, 100, false);
		a = brute(tc);
		b = opt(tc);

		if (a != b) {
			for (int i = 0; i < tc.size(); i++) cout << tc[i] << " ";
			cout << "\n";
		}
		else cout << "OK ------> ";

		cout << a << ", " << b << "\n";
	}

	return 0;
}