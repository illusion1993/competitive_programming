#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &A, int i, int j) {
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

int main() {
	vector<int> A;
	A.push_back(9);
	A.push_back(8);
	A.push_back(7);
	A.push_back(6);
	A.push_back(5);
	A.push_back(4);

	bool found = false;
    for (int i = A.size() - 1; i > 0; i--) {
        if (A[i] > A[i - 1]) {
            for (int j = i; j < A.size(); j++) {
                if (j == A.size() - 1 || A[j + 1] < A[i - 1]) {
                    swap(A, i-1, j);
                    sort(A.begin() + i, A.end());
                    j = A.size();
                    i = 0;
                    found = true;
                }
            }
        }
    }
    if (!found) {
        sort(A.begin(), A.end());
    }
    for (int i = 0; i < A.size(); i++){
    	cout << A[i] << endl;
    }
	return 0;
}