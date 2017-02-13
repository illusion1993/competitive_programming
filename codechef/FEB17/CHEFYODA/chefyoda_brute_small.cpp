#include<bits/stdc++.h>
using namespace std;

int n, m;
float prob, p, k;

map<pair<int, int>, bool> covered;  // x, y, covered?

int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

long long ncr(long long n, long long r) {

    if (n == r || r == 0) return 1;
    return (fact(n) / fact(r)) / fact(n - r);

}

int winner_at_pos(int x, int y, int player, bool rule_set) {

    bool win;
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return -1;
    }

    if (covered[make_pair(x, y)]) {
        return -2;
    }
    covered[make_pair(x, y)] = true;


    int move_winner;

    //cout << "Going up" << endl;
    if (!rule_set) {
        //path.push_back("Up");
        move_winner = winner_at_pos(x, y - 1, !player, rule_set);
    }
    else {
        //path.push_back("Up Left");
        move_winner = winner_at_pos(x - 1, y - 1, !player, rule_set);
    }

    //path.pop_back();
    //cout << "came back froum up" << endl;
    if (move_winner == player) {
        covered[make_pair(x, y)] = false;
        return player;
        //win = true;
    }

    //cout << "Going down" << endl;
    if (!rule_set) {
        //path.push_back("Down");
        move_winner = winner_at_pos(x, y + 1, !player, rule_set);
    }
    else {
        //path.push_back("Up Right");
        move_winner = winner_at_pos(x + 1, y - 1, !player, rule_set);
    }

    //path.pop_back();
    //cout << "Came back fom down" << endl;
    if (move_winner == player) {
        covered[make_pair(x, y)] = false;
        return player;
        //win = true;
    }

    //cout << "Going left" << endl;
    if (!rule_set) {
        //path.push_back("Left");
        move_winner = winner_at_pos(x - 1, y, !player, rule_set);
    }
    else {
        //path.push_back("Down Left");
        move_winner = winner_at_pos(x - 1, y + 1, !player, rule_set);
    }

    //path.pop_back();
    //cout << "Came back from left" << endl;
    if (move_winner == player) {
        covered[make_pair(x, y)] = false;
        return player;
        //win = true;
    }

    //cout << "Going right" << endl;
    if (!rule_set) {
        //path.push_back("Right");
        move_winner = winner_at_pos(x + 1, y, !player, rule_set);
    }
    else {
        //path.push_back("Down Right");
        move_winner = winner_at_pos(x + 1, y + 1, !player, rule_set);
    }

    //path.pop_back();
    //cout << "Came back from right" << endl;
    if (move_winner == player) {
        covered[make_pair(x, y)] = false;
        return player;
    }

    covered[make_pair(x, y)] = false;
    return !player;

}


int main() {

    int t, w1, w0;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> n >> m >> p >> k;

        w0 = winner_at_pos(0, 0, 0, 0);
        w1 = winner_at_pos(0, 0, 0, 1);
        prob = 0.0;

        if (w0 == 0 && w1 == 0) {
            prob = 1.0;
        }
        else if (w0 == 1 && w1 == 1) {
            prob = 0.0;
        }
        else {
            for (int i = p; i <= k; i++) prob += ncr(k, i);
            prob /= pow(2, k);
        }

        cout << fixed << std::setprecision(6) << prob << endl;

    }

    return 0;
}
