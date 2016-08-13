#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    unsigned votes[m][n];
    int winnerIndex, wins[n];

    for(int i = 0; i < n; i++){
        wins[i] = 0;
    }

    for(int i = 0; i < m; i++){

        winnerIndex = 0;
        for(int j = 0; j < n; j++){
            cin >> votes[i][j];
            if(votes[i][j] > votes[i][winnerIndex]) winnerIndex = j;
        }
        wins[winnerIndex]++;

    }

    winnerIndex = 0;
    for(int i = 0; i < n; i++){

        if(wins[i] > wins[winnerIndex]) winnerIndex = i;

    }

    cout<<winnerIndex + 1;

    return 0;

}
