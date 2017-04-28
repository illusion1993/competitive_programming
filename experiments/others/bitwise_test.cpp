#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(0));
	int n, w;
	n = 20;
	w = 4;

	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = ((rand() % (2*n)) + 1);
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) cout << v[i] << " ";
	cout << endl << endl;

	for (int i = 0; i <= n - w; i++) {
		int a = v[i] & v[i + 1];
		for (int j = 2; j < w; j++) {
			a = a & v[j];
		}
		cout << "AND value from elem " << i << " to " << i + 3 << ": " << a << endl;
	}
	return 0;
}