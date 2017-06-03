#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ofstream cout("tc.txt");
	srand(0);
	int t = 50, max_len = 100, max_number = 100000;

	cout << t << "\n";
	for (int tc = 0; tc < t; tc++) {
		int la, lb, lc;
		la = (rand() % (max_len / 2)) + (max_len / 2);
		lb = (rand() % (max_len / 2)) + (max_len / 2);
		lc = (rand() % (max_len / 2)) + (max_len / 2);
		cout << la << " " << lb << " " << lc << "\n";

		unordered_set<int> s;
		vector<int> v;

		for (int i = 0; i < 3; i++) {
			int l;
			if (i == 0) l = la;
			else if (i == 1) l = lb;
			else l = lc;

			while(s.size() < l) {
				int p = (rand() % max_number) + 1;
				if (!s.count(p)) {
					s.insert(p);
					v.push_back(p);
				}
			}
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
			cout << "\n";
			s.clear();
			v.clear();
		}
	}
	return 0;
}