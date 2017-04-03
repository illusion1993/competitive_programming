/*
ID: rathore1
PROG: dualpal
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

char itob(int a) {
    return (char)(a + 48);
}
int btoi(char a) {
    return (int)(a - 48);
}

class Number {
public:
    int self_i;
    Number(int s_i){
        self_i = s_i;

        for (int base = 2; base <= 10; base++) {
            string rpr = "";
            int tmp = self_i;
            while(tmp) {
                rpr += itob(tmp % base);
                tmp /= base;
            }
            for (int i = 0; i < rpr.length() / 2; i++) {
                tmp = (int)rpr[i];
                rpr[i] = rpr[rpr.length() - i - 1];
                rpr[rpr.length() - i - 1] = (char)tmp;
            }
            repr[base] = rpr;
        }
    }
    void increment(){
        self_i++;
        for (int base = 2; base <= 10; base++) {
            string self = repr[base];
            if (btoi(self[self.length() - 1]) < base - 1) {
                self[self.length() - 1] = itob(btoi(self[self.length() - 1]) + 1);
            }
            else {
                int pos = self.length() - 1;
                bool carry = 1;
                while(pos >= 0 && carry) {
                    self[pos] = itob(0);
                    if (pos == 0) {
                        self = "1" + self;
                        carry = 0;
                    }
                    else if (btoi(self[pos - 1]) < base - 1) {
                        self[pos - 1] = itob(btoi(self[pos - 1]) + 1);
                        carry = 0;
                    }
                    pos--;
                }
            }
            repr[base] = self;
        }
    }
    int countPals(){
        int pals = 0;
        for (int i = 2; i < 11; i++) {
            if (pals == 2) break;
            bool ispal = true;
            for (int j = 0; j < repr[i].length() / 2; j++) if (repr[i][j] != repr[i][repr[i].length() - 1 - j]) ispal = 0;
            pals += ispal;
        }
        return pals;
    }

private:
    string repr[11];
};

int main() {
    ofstream cout ("dualpal.out");
    ifstream cin ("dualpal.in");

    int N, S, count = 0;
    cin >> N >> S;
    Number n(S + 1);
    while(count != N) {
        if (n.countPals() >= 2) {
            cout << n.self_i << "\n";
            count++;
        }
        n.increment();
    }
}
