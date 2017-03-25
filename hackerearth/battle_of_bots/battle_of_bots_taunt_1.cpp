#include<bits/stdc++.h>
using namespace std;

int total_moves, max_chances = 7;

void play(vector<vector<int> > pieces, map<pair<int, int>, bool > occupied, int chance_number) {

    if (chance_number > max_chances) return;
    //cout << "Chance #" << chance_number << endl;

    vector<vector<int> > pieces_now;
    map<pair<int, int>, bool > occupied_now;

    for (int i = 0; i < pieces.size(); i++) {
        if (chance_number == 1) cout << "Piece #" << i << "\n";
        if (pieces[i][0] == 1) {
            // Left
            if (pieces[i][3] > 0 && occupied.count({pieces[i][2], pieces[i][3] - 1}) == 0) {
                pieces_now = pieces;
                occupied_now = occupied;

                occupied_now.erase({pieces[i][2], pieces[i][3]});
                occupied_now[{pieces[i][2], pieces[i][3] - 1}] = 1;
                pieces_now[i][3]--;

                total_moves++;
                play(pieces_now, occupied_now, chance_number + 1);
            }
            // Right
            if (pieces[i][3] < 3 && occupied.count({pieces[i][2], pieces[i][3] + 1}) == 0) {
                pieces_now = pieces;
                occupied_now = occupied;

                occupied_now.erase({pieces[i][2], pieces[i][3]});
                occupied_now[{pieces[i][2], pieces[i][3] + 1}] = 1;
                pieces_now[i][3]++;

                total_moves++;
                play(pieces_now, occupied_now, chance_number + 1);
            }
            // Up
            if (pieces[i][2] > 0 && occupied.count({pieces[i][2] - 1, pieces[i][3]}) == 0) {
                pieces_now = pieces;
                occupied_now = occupied;

                occupied_now.erase({pieces[i][2], pieces[i][3]});
                occupied_now[{pieces[i][2] - 1, pieces[i][3]}] = 1;
                pieces_now[i][2]--;

                total_moves++;
                play(pieces_now, occupied_now, chance_number + 1);
            }
            // Down
            if (pieces[i][2] < 9 && occupied.count({pieces[i][2] + 1, pieces[i][3]}) == 0) {
                pieces_now = pieces;
                occupied_now = occupied;

                occupied_now.erase({pieces[i][2], pieces[i][3]});
                occupied_now[{pieces[i][2] + 1, pieces[i][3]}] = 1;
                pieces_now[i][2]++;

                total_moves++;
                play(pieces_now, occupied_now, chance_number + 1);
            }
        }
        else if (pieces[i][0] == 2) {

        }
        else if (pieces[i][0] == 3) {

        }
        else if (pieces[i][0] == 4) {

        }
    }
}

int main() {

    total_moves = 0;
    vector<vector<int> > pieces;    // piece_type, direction, row, col
    map<pair<int, int>, bool > occupied;  // row, col, occupied

    for (int i = 0; i < 9; i++) {
        vector<int> piece;
        piece.push_back(3 - (i / 3));
        piece.push_back(1);
        piece.push_back(i / 4);
        piece.push_back(i % 4);

        pieces.push_back(piece);
        occupied[{i / 4, i % 4}] = 1;
    }

    play(pieces, occupied, 1);
    cout << total_moves;
}
