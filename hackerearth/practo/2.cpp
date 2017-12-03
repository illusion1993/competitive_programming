#include <bits/stdc++.h>
using namespace std;

string str;
int s[100001], e[100001], max_len;

void precomp() {
	for (int i = 0; i < 100001; i++) {
		s[i] = e[i] = -1;
	}
	int f = -1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '1') {
			if (f == -1) {
				f = i;
				s[i] = i;
			}
		}
		else {
			if (f != -1) {
				s[i - 1] = f;
				e[i - 1] = i - 1;
				e[f] = i - 1;
				max_len = max(max_len, i - f);
				f = -1;
			}
		}
	}
	if (f != -1) {
		s[str.length() - 1] = f;
		e[str.length() - 1] = str.length() - 1;
		e[f] = str.length() - 1;
		max_len = max(max_len, (int)str.length() - f);
	}
}

void mark(int pos) {
	if (str[pos] != '1') {
		str[pos] = '1';
		if (pos != 0 && pos != str.length() - 1 && str[pos - 1] == '1' && str[pos + 1] == '1') {
			e[s[pos - 1]] = e[pos + 1];
			s[e[pos + 1]] = s[pos - 1];
			max_len = max(max_len, e[pos + 1] - s[pos - 1] + 1);
		}
		else if (pos != 0 && str[pos - 1] == '1') {
			e[s[pos - 1]] = pos;
			s[pos] = s[pos - 1];
			e[pos] = pos;
			max_len = max(max_len, pos - s[pos] + 1);
		}
		else if (pos != str.length() && str[pos + 1] == '1') {
			e[pos] = e[pos + 1];
			s[pos] = pos;
			s[e[pos]] = pos;
			max_len = max(max_len, e[pos] - pos + 1);
		}
		else {
			s[pos] = e[pos] = pos;
			max_len = max(max_len, 1);
		}
	}
}

int main() {
	int n, k, q1, q2;
	max_len = 0;
	
	cin >> n >> k >> str;
	precomp();
	for (int i = 0; i < k; i++) {
		cin >> q1;
		if (q1 == 1) {
			cout << max_len << "\n";
		}
		else {
			cin >> q2;
			mark(q2 - 1);
		}
	}

	return 0;
}