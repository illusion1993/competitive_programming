#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 1) return 1;
    return n % 1000003 * factorial(n - 1) % 1000003;
}
int getIndexOf(char c) {
    if ((int)c <= 90) {
        return (int)c - 65;
    }
    return (int)c - 97 + 26;
}
char getCharAtIndex(int i) {
    if (i <= 25) {
        return (char)(i + 65);
    }
    return (char)(i + 97 - 26);
}
int countPerms(string sub, string sup) {
    // counting occurences
    int occurence[52];
    memset(occurence, 0, sizeof(occurence));
    for (int i = 0; i < sup.length(); i++){
        occurence[getIndexOf(sup[i])]++;
    }
    for (int i = 0; i <= sub.length(); i++) {
        occurence[getIndexOf(sub[i])]--;
    }

    // finding repetitions
    vector<int> repetitions;
    for (int i = 0; i < 52; i++) {
        if (occurence[i] > 1) {
            repetitions.push_back(occurence[i]);
        }
    }

    // calculating permutations
    int perms;
    perms = factorial(sup.length() - sub.length());
    for (int i = 0; i < repetitions.size(); i++) {
        perms /= factorial(repetitions[i]);
    }
    return perms;
}

int main () {

    string A;
    cin >> A;

    int sol = 0, pos = 0;
    string fixed;

    int occurence[52];
    memset(occurence, 0, sizeof(occurence));
    for (int i = 0; i < A.length(); i++) {
        occurence[getIndexOf(A[i])]++;
    }

    while (pos < A.length() - 1) {
        for (int i = 0 ; i < 52; i++) {
            if (i < getIndexOf(A[pos])) {
                if (occurence[i] != 0) {
                    cout << "fixed string " << fixed + getCharAtIndex(i) << ", " << countPerms(fixed + getCharAtIndex(i), A) << " permutations added " << endl;
                    sol = (sol + countPerms(fixed + getCharAtIndex(i), A)) % 1000003;
                }
            }
            else {
                break;
            }
        }
        fixed += A[pos];
        occurence[getIndexOf(A[pos])]--;
        pos++;
    }

    cout << (sol + 1) % 1000003 << endl;

    return 0;
}
