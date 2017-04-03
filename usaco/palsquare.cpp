/*
ID: rathore1
PROG: palsquare
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

map<int, char> itob;
map<char, int> btoi;

void makeBaseNumbers() {
    for (int i = 0; i <= 10; i++) {
        itob[i] = (char)(i + 48);
        btoi[(char)(i + 48)] = i;
    }
    char ch = 'A';
    for (int i = 10; i < 20; i++) {
        itob[i] = ch;
        btoi[ch] = i;
        ch++;
    }
}

class Number {
public:
    Number(int b){
        base = b;
        self_i = 1;
        self = "1";
        square = "1";
    }
    void increment(){
        if (btoi[self[self.length() - 1]] < base - 1) {
            self[self.length() - 1] = itob[btoi[self[self.length() - 1]] + 1];
        }
        else {
            int pos = self.length() - 1;
            bool carry = 1;
            while(pos >= 0 && carry) {
                self[pos] = itob[0];
                if (pos == 0) {
                    self = "1" + self;
                    carry = 0;
                }
                else if (btoi[self[pos - 1]] < base - 1) {
                    self[pos - 1] = itob[btoi[self[pos - 1]] + 1];
                    carry = 0;
                }
                pos--;
            }
        }
        self_i++;
        square = "";
        int sq = self_i * self_i;
        while(sq) {
            square += itob[sq % base];
            sq /= base;
        }
        for (int i = 0; i < square.length() / 2; i++) {
            sq = (int)square[i];
            square[i] = square[square.length() - i - 1];
            square[square.length() - i - 1] = (char)sq;
        }
    }
    bool isSquarePallindrome(){
        bool ans = true;
        for (int i = 0; i < square.length() / 2; i++) {
            if (square[i] != square[square.length() - 1 - i]) ans = false;
        }
        return ans;
    }
    string selfSquare(){
        return self + " " + square + "\n";
    }

private:
    int base, self_i;
    string self, square;
};

int main() {
    ofstream cout ("palsquare.out");
    ifstream cin ("palsquare.in");
    makeBaseNumbers();

    int base;
    cin >> base;
    Number n(base);
    for (int i = 0; i < 300; i++) {
        if (n.isSquarePallindrome()) cout << n.selfSquare();
        n.increment();
    }
}
