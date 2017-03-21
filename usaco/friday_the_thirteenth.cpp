/*
ID: rathore1
PROG: friday
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout ("friday.out");
    ifstream cin ("friday.in");

    int count[7], n, days_passed = 0;
    memset(count, 0, sizeof(count));
    cin >> n;

    for (int year = 1900; year < 1900 + n; year++) {
        for (int month = 0; month < 12; month++) {
            count[(days_passed + 13) % 7]++;
            if (month == 1) {
                if (year % 4 == 0 && year % 100) days_passed += 29;
                else if (year % 4 == 0 && year % 100 == 0) {
                    if (year % 400 == 0) days_passed += 29;
                    else days_passed += 28;
                }
                else days_passed += 28;
            }
            else if (month == 3 || month == 5 || month == 8 || month == 10) {
                days_passed += 30;
            }
            else days_passed += 31;
        }
    }

    cout << count[6];
    for (int i = 0; i < 6; i++) cout << " " << count[i];
    cout << "\n";

}
