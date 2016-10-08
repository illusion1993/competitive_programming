#include <bits/stdc++.h>
using namespace std;

int main(){

	int t, n, id, sum;
	vector<int> ids;

	cin >> t;
	while(t--){

        ids.clear();
		sum = 0;
		cin >> n;
		while(n--){
			cin >> id;
			ids.push_back(id);
			cin >> id;
			ids.push_back(id);
		}

		for(int i = 0; i < ids.size(); i++){
			if(i % 2 == 0) sum += ids[i];
			else sum -= ids[i];
		}

		cout << sum << endl;

	}

	return 0;

}
