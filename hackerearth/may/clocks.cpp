#include <bits/stdc++.h>
using namespace std;


vector<int> clk_vec(string s) {
    vector<int> ans;
    ans.push_back(((int)s[0] - 48) * 10 + ((int)s[1] - 48));
    ans.push_back(((int)s[3] - 48) * 10 + ((int)s[4] - 48));
    ans.push_back(((int)s[6] - 48) * 10 + ((int)s[7] - 48));
    return ans;
}

int shift_hand(int hand_value, int hand_index, int shift) {
    if (hand_index) {
        if (shift > 0) {
            if (hand_value == 59) return 0;
            return hand_value + 1;
        }
        else {
            if (hand_value == 0) return 59;
            return hand_value - 1;
        }
    }
    else {
        if (shift > 0) {
            if (hand_value == 23) return 0;
            return hand_value + 1;
        }
        else {
            if (hand_value == 0) return 23;
            return hand_value - 1;
        }
    }
}

int set_alarm(vector<int> clk, vector<int> alm, int hand, int cost_so_far) {
    if (hand < 0) return cost_so_far;
    int direc, indirec, min_cost = INT_MAX;
    vector<int> clk_now;
    direc = abs(clk[hand] - alm[hand]);
    indirec = (hand) ? 60 - direc : 24 - direc;
    if (direc <= indirec) {
        clk_now = clk;
        clk_now[hand] = alm[hand];
        min_cost = min(min_cost, set_alarm(clk_now, alm, hand - 1, cost_so_far + direc));
    }
    if (indirec <= direc) {
        clk_now = clk;
        if (hand) {
            clk_now[hand - 1] = (clk[hand] > alm[hand]) ? 
                shift_hand(clk_now[hand - 1], hand - 1, 1) :
                shift_hand(clk_now[hand - 1], hand - 1, -1);
            if (hand - 1) {
                if (clk_now[hand - 1] == 0)
                    clk_now[hand - 2] = shift_hand(clk_now[hand - 2], hand - 2, 1);
                else if (clk_now[hand - 1] == 59)
                    clk_now[hand - 2] = shift_hand(clk_now[hand - 2], hand - 2, -1);
            }
        }
        min_cost = min(min_cost, set_alarm(clk_now, alm, hand - 1, cost_so_far + indirec));
    }
    return min_cost;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k, ops, alarm_ops;
    string s;
    vector<string> clocks;
    cin >> t;
    while(t--) {
        clocks.clear();
        ops = 0;
        cin >> n >> k;
        while(n--) {
            cin >> s;
            clocks.push_back(s);
        }
        while(k--) {
            alarm_ops = INT_MAX;
            cin >> s;
            for (int i = 0; i < clocks.size(); i++) {
                int cost = set_alarm(clk_vec(clocks[i]), clk_vec(s), 2, 0);
                alarm_ops = min(alarm_ops, cost);
            }
            ops += alarm_ops;
        }
        cout << ops << "\n";
    }
    return 0;
}

/*

6
1 1
11:59:59
12:00:00
1 1
06:09:48
05:04:52
1 1
07:00:28
06:59:58
1 1
07:00:29
06:59:58
1 1
07:00:28
07:00:58
1 1
10:10:10
05:02:58

*/