#include<bits/stdc++.h>
using namespace std;

// Solution in C++
string bomber(string query) {
	int start = -1, end = -1;
	bool ended = false;
	string bombed_query = "";
    for (int i = 1; i < query.length(); i++) {
    	if (start != -1 && query[i] == query[start] && !ended) end = i;
    	else if (start != -1 && query[i] != query[start]) ended = true;
    	else if (start == -1 && query[i] == query[i - 1]) {
    		start = i - 1;
    		end = i;
    	}
    }
    if (start == -1) return query;
    else {
    	for (int i = 0; i < query.length(); i++) {
    		if (i < start || i > end) bombed_query += query[i];
    	}
    	return bomber(bombed_query);
    }
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	cout << bomber(s);
	return 0;
}