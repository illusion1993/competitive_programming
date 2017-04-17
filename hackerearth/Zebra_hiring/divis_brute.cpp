#include<bits/stdc++.h>
using namespace std;

bool found;
vector<int> number, digits;
int sum, n, k;

void brute(int pos) {
    if (pos == k) {
        cout << "Sum: " << sum << ": ";
        for (int i = 0; i < number.size(); i++) cout << number[i];
        if (sum % 3 == 0) {
            found = true;
            for (int i = 0; i < number.size(); i++) cout << number[i];
            cout << " -> ans";
        }
        cout << endl;
    }
    if (!found) {
        for (int i = 0; i < digits.size(); i++) {
            if (!(pos == 0 && digits[i] == 0)) {
                int d = digits[i];
                
                number.push_back(d);
                sum += d;
                
                // cout << "pushed " << digits[i] << " at pos " << pos << " sum became " << sum << endl;
                
                brute(pos + 1);
                // cout << "popped " << number.back() << " at pos " << pos << " sum became " << sum - digits[i] << endl;
                sum -= d;
                number.pop_back();
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        digits.push_back(tmp);
    }
    sort(digits.begin(), digits.end());
    cin >> k;

    found = false;
    sum = 0;
    brute(0);
    
    return 0;
}
 