#include <bits/stdc++.h>

using namespace std;

string vowels = "aeiou";
string consonants = "bcdfghjklmnpqrstvwxz";

void printPasses(int length, bool vowel, string pass) {
    if (!length) {
        cout << pass << "\n";
        return;
    }
    string cases = (vowel) ? vowels : consonants;
    for (int i = 0; i < cases.length(); i++) {
        pass += cases[i];
        printPasses(length - 1, !vowel, pass);
        pass.erase(pass.length() - 1);
    }
}

int main(){
    int n;
    cin >> n;
    printPasses(n, false, "");
    printPasses(n, true, "");
    return 0;
}
