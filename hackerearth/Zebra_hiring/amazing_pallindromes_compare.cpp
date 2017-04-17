#include<bits/stdc++.h>
using namespace std;

string s;
int m;

////////////////////////////////////////////////    BRUTE
int c;
bool isPal(int a, int b) {
    bool ans = true;
    if (a == b) return ans;
    string sn;

    sn += s[a];
    for (int i = a + 1; i <= b; i++) {
        if (sn[sn.length() - 1] != s[i]) sn += s[i];
    }

    for (int i = 0; i <= sn.length() / 2 && ans; i++) {
        if (sn[i] != sn[sn.length() - i - 1]) {
            ans = false;
        }
    }
    return ans;
}

void calc() {
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (isPal(i, j)) {
                c++;
            }
        }
    }
}

int brute() {
    c = 0;
    calc();
    return c;
}

//////////////////////////////////////////  OPT

int opt() {
    char prev = s[0];
    int count = 1, pals = 1, amaz_index = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        }
        else {
            pals += (count * (count - 1)) / 2;
            count = 1;
            amaz_index++;
        }
        pals += (amaz_index + (amaz_index % 2)) / 2;
    }
    if (count > 1) pals += (count * (count - 1)) / 2;
    return pals;
}

//////////////////////////////////////////  OPT1

int opt1() {
    vector<int> pals, c;
    int count = 1;
    m = 0;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) count++;
        else {
            c.push_back(count);
            count = 1;
        }
    }
    c.push_back(count);

    // cout << "c vector is : ";
    // for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
    // cout << endl;

    // cout << "pals vector is : ";
    
    for (int i = 0; i < c.size(); i++) {
        count = c[i] + ((c[i] * (c[i] - 1)) / 2);
        int pos = i - 2;
        while(pos >= 0) {
            count += (c[pos] * c[i]);
            pos -= 2;
        }
        if (pals.size()) count += pals.back();
        pals.push_back(count);
        // cout << count << " ";
    }
    // cout << endl;
    return pals.back();
}

/////////////////////////////////////////////

void makeTest(int l) {
    s = "";
    int curr_cnt = (rand() % (l / 2)) + 1;
    char curr = 'a' + (rand() % 2);

    while(s.length() != l) {
        if (curr_cnt) {
            curr_cnt--;
            s += curr;
        }
        else {
            curr = (curr == 'a') ? 'b' : 'a';
            curr_cnt = (rand() % (l / 2)) + 1;
        }
    }
    cout << s << "\n";
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    for (int i = 10; i <= 50; i++) {
        makeTest(i);
        // s = "aaaabbbbbaa";
        cout << brute() << " : " << opt() << " : " << opt1() << endl;
    }
    
    return 0;
}
 