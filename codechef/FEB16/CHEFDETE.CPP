#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, reported[100001], tmp;
	cin >> n;
	memset(reported, 0, sizeof(reported));
	for(int i = 0; i < n; i++){
		cin >> tmp;
		reported[tmp] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(!reported[i])
			cout << i << " ";
	}
	return 0;
}
