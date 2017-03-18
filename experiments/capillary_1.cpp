#include <bits/stdc++.h>
using namespace std;

int getPerms(vector<int> gems) {
    sort(gems.begin(), gems.end());
    if (!gems[3]) return 0;

    if (gems[3] == 2 && gems[2] == 1 && !gems[0] && !gems[1]) return 2;

    if (gems[3] && !gems[2]) {
        return (gems[3] == 1) ? 1 : 0;
    }

    int cav = gems[0] + gems[1] + gems[2] + gems[3];
    int forb = 2 * (gems[3] - 1);

    gems[3]--;

    int p = (getPerms(gems) * (cav - forb)) % 1000000007;
    cout << "for gems: ";
    for (int i = 0; i < 4; i++) cout << gems[i] << " ";
    cout << ", returning " << p << endl;
    return p;
}

int main()
{
    //makePerms();
    //int a, b, c, d;
    int tmp;
    vector<int> gems;
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        gems.push_back(tmp);
    }
    cout << getPerms(gems);

    return 0;
}

