#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
	long long profit = 0, profit_tmp, budget_n;
	vector<long long> budget;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> budget_n;
		budget.push_back(budget_n);
	}
	sort(budget.begin(), budget.end());
	for (int i = 0; i < budget.size(); i++) {
		profit_tmp = budget[i] * (budget.size() - i);
		profit = max(profit, profit_tmp);
	}
	cout << profit;
	return 0;
}
