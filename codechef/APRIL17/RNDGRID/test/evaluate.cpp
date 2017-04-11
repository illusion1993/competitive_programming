#include<bits/stdc++.h>
using namespace std;

int t, m, n, prob;
string path;
char board[1000][1000];

int main(int argc, char const *argv[])
{
    ifstream tin ("testcases.in");
    ifstream ain ("brute.out");
    ifstream bin ("opt.out");

    ofstream cout ("evaluate.out");

    int c = 0, a, b;
    tin >> t;
    while(t--) {
        tin >> m >> n >> path;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) tin >> board[i][j];

        ain >> a;
        bin >> b;
        if (a != b) {
            c++;
            cout << m << " " << n << endl << path << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) cout << board[i][j];
                cout << endl;
            }
        }
    }
    cout << "\nTotal: " << c;

    return 0;
}
