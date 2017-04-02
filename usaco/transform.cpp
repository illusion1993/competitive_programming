/*
ID: rathore1
PROG: transform
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> before, after;

bool isTransform1() {
    // 90 deg
    bool is_it = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (before[i][j] != after[j][n - 1 - i]) is_it = false;
    return is_it;
}

bool isTransform2() {
    // 180 deg
    bool is_it = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (before[i][j] != after[n - 1 - i][n - 1 - j]) is_it = false;
    return is_it;
}

bool isTransform3() {
    // 270 deg
    bool is_it = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (before[i][j] != after[n - 1 - j][i]) is_it = false;
    return is_it;
}

bool isTransform6() {
    // Same
    bool is_it = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (before[i][j] != after[i][j]) is_it = false;
    return is_it;
}

bool isTransform4() {
    // mirror
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            tmp = before[i][j];
            before[i][j] = before[i][n - 1 - j];
            before[i][n - 1 - j] = tmp;
        }
    }
    return isTransform6();
}

bool isTransform5() {
    return isTransform1() || isTransform2() || isTransform3();
}

int checkTransformNumber() {
    if (isTransform1()) return 1;
    else if (isTransform2()) return 2;
    else if (isTransform3()) return 3;
    else if (isTransform6()) return 6;
    else if (isTransform4()) return 4;
    else if (isTransform5()) return 5;
    else return 7;
}

int main() {
    ofstream cout ("transform.out");
    ifstream cin ("transform.in");
    string s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        before.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        cin >> s;
        after.push_back(s);
    }

    cout << checkTransformNumber() << "\n";

    return 0;
}
