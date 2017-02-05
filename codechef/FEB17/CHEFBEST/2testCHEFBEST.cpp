#include<bits/stdc++.h>
using namespace std;

int n, a[100000];


pair< pair<int, int>, int> findTimeAndDistance(int pos, int distance) {
    if (pos == n - 1){
        //cout << endl << "For pos " << pos << " & distance " << distance << ", returning 0, ";
        //if (a[pos]) cout << distance + 1;
        //else cout << distance;

        return (a[pos]) ? make_pair(make_pair(0, distance + 1), 0) : make_pair(make_pair(0, distance), 1);
        //return ans;
    }

    pair<pair<int, int>, int> ans;
    if (a[pos]) {
        ans = findTimeAndDistance(pos + 1, distance + 1);
        //cout << endl << "For pos " << pos << " & distance " << distance << ", returning " << ans.first << ", " << ans.second;
        return ans;
    }

    else {
        int tnext, shift, time, journey;
        pair<pair<int, int>, int> next;
        next = findTimeAndDistance(pos + 1, 0);
        tnext = next.first.first;
        shift = next.first.second;
        journey = n - 1 - next.second - pos;

        /*
        time = (shift) ? tnext + shift : tnext + 1;
        */

        if (tnext <= shift) {
            //cout << endl << "For pos " << pos << ", tnext is " << tnext << " and shift distance is " << shift << " hence unstopped.";
        }

        time = (tnext > shift) ? tnext + 1 : journey;

        //cout << endl << "For pos " << pos << " & distance " << distance << ", returning " << time << ", " << distance;
        return make_pair(make_pair(time, distance), next.second + 1);
    }

}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << findTimeAndDistance(0, -1).first.first << endl;
        //findTimeAndDistance(0, -1);
    }
    return 0;
}
