#include<bits/stdc++.h>
using namespace std;
int n, m, board[101][101];



int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, x, y, z;
    cin >> t;
    while(t--) {
        memset(board, 0, sizeof(board));
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> z;
            board[x][y] = z;
        }
    }

    return 0;
}
