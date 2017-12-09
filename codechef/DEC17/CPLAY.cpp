#include <bits/stdc++.h>
using namespace std;

void play(string s) {
	int rema, remb, scra, scrb;
	rema = remb = 5;
	scra = scrb = 0;

	for (int i = 0; i < 10; i++) {
		if (i % 2) {
			remb--;
			if (s[i] == '1')
				scrb++;
		}
		else {
			rema--;
			if (s[i] == '1')
				scra++;
		}

		if (scra - scrb > remb) {
			cout << "TEAM-A " << i + 1 << "\n";
			return;
		}
		else if (scrb - scra > rema) {
			cout << "TEAM-B " << i + 1 << "\n";
			return;
		}
	}

	if (scra > scrb) {
		cout << "TEAM-A 10\n";
		return;
	}
	else if (scrb > scra) {
		cout << "TEAM-B 10\n";
		return;
	}

	for (int i = 10; i < 20; i++) {
		if (i % 2) {
			if (s[i] == '1')
				scrb++;

			if (scrb > scra) {
				cout << "TEAM-B " << i + 1 << "\n";
				return;
			}
			if (scra > scrb) {
				cout << "TEAM-A " << i + 1 << "\n";
				return;
			}
		}
		else {
			if (s[i] == '1')
				scra++;
		}
	}
	cout << "TIE\n";
}

int main() {

	string s;
	
	while (getline(cin, s)) {
		play(s);
	}

	return 0;
}