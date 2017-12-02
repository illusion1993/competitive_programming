#include <bits/stdc++.h>

int main() {
	int n, sum = 0;

	std::cin >> n;
	std::vector<int> arr(2 * n);

	for (int i = 0; i < 2 * n; i++)
		std::cin >> arr[i];
	
	std::sort(arr.begin(), arr.end());
	
	for (int i = 0; i < 2 * n; i += 2)
		sum += arr[i];
	
	std::cout << sum;
	return 0;
}