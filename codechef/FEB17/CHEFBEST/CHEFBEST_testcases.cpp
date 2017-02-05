#include<bits/stdc++.h>
using namespace std;

int t, n[10], a[10][100000];

pair<int, int> findTimeAndDistance(int testcase, int pos, int distance) {
    if (pos == n[testcase] - 1){
        //cout << endl << "Pos: " << pos << ", returning ";
        //if (a[testcase][pos]) cout << "0, " << distance + 1;
        //else cout << "0, " << distance;
        return (a[testcase][pos]) ? make_pair(0, distance + 1) : make_pair(0, distance);
    }


    /*
    if (a[testcase][pos]) {
        cout << endl << "Pos: " << pos << ", returning ";
        cout << findTimeAndDistance(testcase, pos + 1, distance + 1).first << ", " << findTimeAndDistance(testcase, pos + 1, distance + 1).second;
    }
    */
    if (a[testcase][pos]) return findTimeAndDistance(testcase, pos + 1, distance + 1);

    else {
        int tnext, shift, time;
        pair<int, int> next;
        next = findTimeAndDistance(testcase, pos + 1, 0);
        tnext = next.first;
        shift = next.second;
        time = (shift) ? tnext + shift : tnext + 1;

        //cout << endl << "Pos: " << pos << ", returning ";
        //cout << time << ", " << distance;

        return make_pair(time, distance);
    }
}

vector<int> recursion() {
    vector<int> ans;
    for(int tc = 0; tc < t; tc++) {
        cout << "Testcase: ";
        for (int i = 0; i < n[tc]; i++) cout << a[tc][i];
        cout << " : ";

        ans.push_back(findTimeAndDistance(tc, 0, -1).first);
        cout << ans[tc] << endl;
    }
    return ans;
}

vector<int> iteration() {
    vector<int> outputs;
    int dist_so_far, time, expected_pos;

    for (int tc = 0; tc < t; tc++) {
        cout << "Testcase: ";
        for (int i = 0; i < n[tc]; i++) cout << a[tc][i];
        cout << " : ";

        dist_so_far = 0;
        time = -1;
        expected_pos = n[tc] - 1;

        for (int i = n[tc] - 1; i > -1; i--) {
            if (!a[tc][i] && i != expected_pos) {
                if (time == -1) {
                    time = dist_so_far;
                }
                else {
                    time = max(time + 1, time + dist_so_far);
                }
                dist_so_far = -1;
            }

            else if (!a[tc][i]) {
                expected_pos--;
                dist_so_far = -1;
            }

            dist_so_far++;
        }
        cout << max(0, time) << endl;
        outputs.push_back(max(0, time));
    }
    return outputs;
}

vector<int> bruteForce() {
    vector<int> outputs;
    int z_count, seconds;
    bool isSorted;

    for (int tc = 0; tc < t; tc++) {
        cout << "Testcase: ";
        for (int i = 0; i < n[tc]; i++) cout << a[tc][i];
        cout << " : ";

        isSorted = false;
        seconds = 0;
        while(!isSorted) {
            z_count = 0;
            for (int i = 0; i < n[tc] - 1; i++) {
                if (!a[tc][i] && a[tc][i + 1]) {
                    z_count++;
                    a[tc][i] = !a[tc][i];
                    a[tc][i + 1] = !a[tc][i + 1];
                    i++;
                }
            }

            if (z_count) seconds++;
            else isSorted = true;
        }
        outputs.push_back(seconds);
        cout << seconds << endl;
    }
    return outputs;
}

void prepareTestcases() {
    int nmin, nmax;
    t = 1;
    cout << "Range of length of array N in each testcase (Nmin, Nmax): ";
    cin >> nmin >> nmax;

    for (int i = 0; i < t; i++) {
        n[i] = nmin + (rand() % (nmax - nmin + 1));
        for (int j = 0; j < n[i]; j++) a[i][j] = rand() % 2;
    }
}

int main() {
    vector<int> ans1;
    vector<int> ans2;
    char ch;

    do {
        system("clear");
        prepareTestcases();
        cout << endl << "Iteration results: " << endl;
        iteration();
        cout << endl << "Recursion results: " << endl;
        recursion();
        cout << endl << "Bruteforce results: " << endl;
        bruteForce();

        cout << endl << endl << "More? (y/n) ";
        cin >> ch;
    }
    while (ch == 'y' || ch == 'Y');

    return 0;
}
