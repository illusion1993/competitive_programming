// 272 - TEX Quotes
#include<bits/stdc++.h>
using namespace std;

int main() {
	string line, start = "``", end = "''";
	while (getline(cin, line)) {
		bool on = false;

		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '"') {
				line.erase(i, 1);
				if (on) line.insert(i, end);
				else line.insert(i, start);
				on = (!on);
			}
		}
		cout << line << endl;
	}
	return 0;
}