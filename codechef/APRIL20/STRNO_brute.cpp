//
// Created by Vikram Singh Rathore
//

#include<bits/stdc++.h>
using namespace std;

#define limit 100

vector<int> getPrimes() {
	vector<int> ans;
	int j;
	bitset<limit + 1> composite(0);
	for (int i = 2; i <= limit; i++) {
		if (!composite[i]) {
			ans.push_back(i);
			j = i + i;
			while (j <= limit) {
				composite[j] = 1;
				j += i;
			}
		}
	}
	return ans;
}

int main() {
    vector<int> primes = getPrimes();
    for (int i = 0; i < primes.size(); i++) cout << primes[i] << " ";
    return 0;
}