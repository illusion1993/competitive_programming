#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int distances[50][3];
    string options[50];

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> options[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            distances[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((int)options[i][j] >= 48 && (int)options[i][j] <= 57) {
                distances[i][0] = min(min(j, m - j), distances[i][0]);
            }
            else if ((int)options[i][j] >= 97 && (int)options[i][j] <= 122) {
                distances[i][1] = min(min(j, m - j), distances[i][1]);
            }
            else if (options[i][j] == '#' || options[i][j] == '*' || options[i][j] == '&') {
                distances[i][2] = min(min(j, m - j), distances[i][2]);
            }
        }
    }

    int min_ops = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (distances[i][0] < INT_MAX) {
            for (int j = 0; j < n; j++) {
                if (distances[j][1] < INT_MAX && i != j) {
                    for (int k = 0; k < n; k++) {
                        if (distances[k][2] < INT_MAX && i != k && j != k) {
                            min_ops = min(min_ops, distances[i][0] + distances[j][1] + distances[k][2]);
                        }
                    }
                }
            }
        }
    }
    cout << min_ops;
}
