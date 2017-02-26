#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n, in, perf_a[5], perf_b[5], swaps = 0, exchanges = 0;

    memset(perf_a, 0, sizeof(perf_a));
    memset(perf_b, 0, sizeof(perf_b));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> in;
        perf_a[in - 1]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> in;
        perf_b[in - 1]++;
    }

    for (int i = 0; i < 5; i++) {
        in = perf_a[i] - perf_b[i];
        if (abs(in) % 2) {
            exchanges = -1;
            break;
        }
        if (in > 0) swaps += in / 2;
        exchanges += in;
    }

    if (exchanges == 0) cout << swaps;
    else cout << "-1";

    return 0;
}
