#include<bits/stdc++.h>
using namespace std;

int n, m, p, k;
vector<vector<int> > results;       // x, y, player, up, down, left, right
map<pair<int, int>, bool> covered;  // x, y, covered?

void print_results() {

    for (int i = 0; i < results.size(); i++) {
        cout << "For position " << results[i][0] << ", " << results[i][1] << " player " << results[i][2] << " played: " << endl;

        cout << "- Up move: ";
        if (results[i][3] == -1) cout << "Out of board!" << endl;
        else if (results[i][3] == -2) cout << "Already covered!" << endl;
        else cout << results[i][3] << " wins" << endl;

        cout << "- Down move: ";
        if (results[i][4] == -1) cout << "Out of board!" << endl;
        else if (results[i][4] == -2) cout << "Already covered!" << endl;
        else cout << results[i][4] << " wins" << endl;

        cout << "- Left move: ";
        if (results[i][5] == -1) cout << "Out of board!" << endl;
        else if (results[i][5] == -2) cout << "Already covered!" << endl;
        else cout << results[i][5] << " wins" << endl;

        cout << "- Right move: ";
        if (results[i][6] == -1) cout << "Out of board!" << endl;
        else if (results[i][6] == -2) cout << "Already covered!" << endl;
        else cout << results[i][6] << " wins" << endl;

    }

}

int winner_at_pos(int x, int y, int player, vector<string> path, bool rule_set) {

    bool win;
    if (x < 0 || x >= m || y < 0 || y >= n) {
        //cout << "out of board" << endl;
        return -1;
    }

    if (covered[make_pair(x, y)]) {
        return -2;
    }
    covered[make_pair(x, y)] = true;


    vector<int> result;
    result.push_back(x);
    result.push_back(y);
    result.push_back(player);
    result.push_back(-1);
    result.push_back(-1);
    result.push_back(-1);
    result.push_back(-1);

    //cout << "Going up" << endl;
    if (!rule_set) {
        path.push_back("Up");
        result[3] = winner_at_pos(x, y - 1, !player, path, rule_set);
    }
    else {
        path.push_back("Up Left");
        result[3] = winner_at_pos(x - 1, y - 1, !player, path, rule_set);
    }

    path.pop_back();
    //cout << "came back froum up" << endl;
    if (result[3] == player) {
        covered[make_pair(x, y)] = false;
        return player;
        //win = true;
    }

    //cout << "Going down" << endl;
    if (!rule_set) {
        path.push_back("Down");
        result[4] = winner_at_pos(x, y + 1, !player, path, rule_set);
    }
    else {
        path.push_back("Up Right");
        result[4] = winner_at_pos(x + 1, y - 1, !player, path, rule_set);
    }

    path.pop_back();
    //cout << "Came back fom down" << endl;
    if (result[4] == player) {
        covered[make_pair(x, y)] = false;
        return player;
        //win = true;
    }

    //cout << "Going left" << endl;
    if (!rule_set) {
        path.push_back("Left");
        result[5] = winner_at_pos(x - 1, y, !player, path, rule_set);
    }
    else {
        path.push_back("Down Left");
        result[5] = winner_at_pos(x - 1, y + 1, !player, path, rule_set);
    }

    path.pop_back();
    //cout << "Came back from left" << endl;
    if (result[5] == player) {
        covered[make_pair(x, y)] = false;
        return player;
        //win = true;
    }

    //cout << "Going right" << endl;
    if (!rule_set) {
        path.push_back("Right");
        result[6] = winner_at_pos(x + 1, y, !player, path, rule_set);
    }
    else {
        path.push_back("Down Right");
        result[6] = winner_at_pos(x + 1, y + 1, !player, path, rule_set);
    }

    path.pop_back();
    //cout << "Came back from right" << endl;
    if (result[6] == player) {
        covered[make_pair(x, y)] = false;
        return player;
        //win = true;
    }

    covered[make_pair(x, y)] = false;
    //results.push_back(result);
    //if (win) return player;

    /*
    if (result[3] != !player && result[4] != !player && result[5] != !player && result[6] != !player) {
        cout << "For Path: ";
        for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
        cout << ", Winner is " << !player << endl;
    }
    */

    return !player;

}


int main() {

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<string> path;
        cout << "Winner is: " << winner_at_pos(0, 0, 0, path, 0) << endl;
        cout << "Winner is: " << winner_at_pos(0, 0, 0, path, 1) << endl;
    }

    return 0;
}
