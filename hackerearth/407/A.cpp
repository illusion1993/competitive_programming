#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, tmp;
	long long days = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		days += tmp / k;
		if (tmp % k) days++;
	}
	cout << (days / 2) + days % 2;

}