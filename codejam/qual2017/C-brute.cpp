#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// std::ios::sync_with_stdio(false);
    // cin.tie(0);

    // ofstream cout ("B-large.out");
    // ifstream cin ("B-large.in");

    long long x;
    cin >> x;
    cout << floor(log2(x));
    return 0;

    int t, in, in1;
    pair<int, int> ans;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
    	cin >> in >> in1;
    	//ans = solve(in, in1);
    	//cout << "Case #" << tc << ": " << solve(in, in1) << "\n";
    }

	return 0;
}