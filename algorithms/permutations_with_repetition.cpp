#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main () {
    // string in lowercase, alphabets only
    string s;
    cin >> s;

    // counting occurences
    int occurence[26];
    memset(occurence, 0, sizeof(occurence));
    for (int i = 0; i < s.length(); i++) occurence[(int)s[i] - 97]++;

    // finding repetitions
    vector<int> repetitions;
    for (int i = 0; i < 26; i++) {
        if (occurence[i] > 1) {
            repetitions.push_back(occurence[i]);
        }
    }

    // calculating permutations
    int perms;
    perms = factorial(s.length());
    for (int i = 0; i < repetitions.size(); i++) {
        perms /= factorial(repetitions[i]);
    }
    cout << perms;

    return 0;
}
