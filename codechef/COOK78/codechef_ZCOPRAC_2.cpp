#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, H, h, command, pos = 0;
    bool box_up;
    vector<int> stacks;

	cin >> n >> H;
	for (int i = 0; i < n; i++) {
        cin >> h;
        stacks.push_back(h);
	}

    do {
        cin >> command;

        switch(command) {
            case 1:
                if (pos != 0) pos--;
                break;
            case 2:
                if (pos != n - 1) pos++;
                break;
            case 3:
                if (!box_up && stacks[pos]) {
                    box_up = true;
                    stacks[pos]--;
                }
                break;
            case 4:
                if (box_up && stacks[pos] < H) {
                    box_up = false;
                    stacks[pos]++;
                }
                break;
        }
    }
    while (command);

    for (int i = 0; i < stacks.size(); i++) {
        cout << stacks[i] << " ";
    }

	return 0;
}
