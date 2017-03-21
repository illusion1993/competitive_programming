/*
ID: rathore1
PROG: milk2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout ("milk2.out");
    ifstream cin ("milk2.in");

    int n, milking = 0, no_milking = 0, tmp1, tmp2;
    vector<pair<int, int> > times;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2;
        times.push_back({tmp1, tmp2});
    }
    sort(times.begin(), times.end());

    int covered = times[0].first, this_milking = 0;
    for (int i = 0; i < times.size(); i++) {
        if (times[i].first <= covered) {
            if (times[i].second > covered) {
                this_milking += times[i].second - covered;
                covered = times[i].second;
            }
        }
        else {
            milking = max(milking, this_milking);
            no_milking = max(no_milking, times[i].first - covered);

            this_milking = times[i].second - times[i].first;
            covered = times[i].second;
        }
    }
    milking = max(milking, this_milking);

    cout << milking << " " << no_milking << endl;

    return 0;
}
