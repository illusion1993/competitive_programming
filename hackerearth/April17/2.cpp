#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll opt(vector<int> testcase) {
	double prod_root = 1;
	int f = testcase[0];
	bool equal = true;
	for (int i = 0; i < testcase.size(); i++) {
		prod_root *= pow((double)testcase[i], ((double)1 / (double)testcase.size()));
		if (testcase[i] != f) equal = false;
	}
	return (equal) ? f + 1 : ceil(prod_root);
}

int main()
{
    int n, tmp;
    vector<int> a;
    cin >> n;
    while(n--) {
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << opt(a);
    return 0;
}
