// Can the threatening piece of opponent be eliminated by any move? if yes, then add the number of threats eliminated into incentive + 1(capture)
/*
    Incentives:
        1. Capture opponent's piece
        2. Eliminate threats (to self or other brothers)
    Penalties:
        1. Moved to a threatening position
        2. After this move, any specific move of opponent could threaten this and a brother of this piece
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > get_steps(int r, int c, int ptype, int dir) {
    vector<pair<int, int> > steps;

    if (ptype == 1) {
        if (c != 0) steps.push_back({r, c - 1});
        if (c != 3) steps.push_back({r, c + 1});
        if (r != 0) steps.push_back({r - 1, c});
        if (r != 9) steps.push_back({r + 1, c});
    }
    else if (ptype == 2) {
        if (c != 0) steps.push_back({r, c - 1});
        if (c != 3) steps.push_back({r, c + 1});

        if (dir && r <= 7) {
            // Downward
            steps.push_back({r + 2, c});
        }
        else if (!dir && r >= 2) {
            // Upward
            steps.push_back({r - 2, c});
        }
    }
    else if (ptype == 3) {
        if (c != 0) {
            if (dir) {
                steps.push_back({r + 1, c - 1});    // DL for col 1, 2, 3
            }
            else {
                steps.push_back({r - 1, c - 1});    // UL for col 1, 2, 3
            }
        }
        if (c != 3) {
            if (dir) {
                steps.push_back({r + 1, c + 1});    // DR for col 0, 1, 2
            }
            else {
                steps.push_back({r - 1, c + 1});    // UR for col 0, 1, 2
            }
        }
        if (c == 0 || c == 1) {
            if (dir) {
                if (r <= 7) steps.push_back({r + 2, c + 2});
                if (r == 8) steps.push_back({r, c + 2});
            }
            else {
                if (r >= 2) steps.push_back({r - 2, c + 2});
                if (r == 1) steps.push_back({r, c + 2});
            }
        }
        if (c == 2 || c == 3) {
            if (dir) {
                if (r <= 7) steps.push_back({r + 2, c - 2});
                if (r == 8) steps.push_back({r, c - 2});
            }
            else {
                if (r >= 2) steps.push_back({r - 2, c - 2});
                if (r == 1) steps.push_back({r, c - 2});
            }
        }
        if (c == 1 || c == 2) {
            if (dir && r <= 7) steps.push_back({r + 2, c});
            else if (!dir && r >= 2) steps.push_back({r - 2, c});
        }
    }

    cout << "For " << r << ", " << c << " holes are:\n";
    for (int i = 0; i < steps.size(); i++) cout << steps[i].first << ", " << steps[i].second << "\n";

    return steps;
}

class Move {
    public:
        // incentive = number_of_captures + number_of_eliminated_threats(my pieces saved) - moved_to_threat_pos
        Move(int r, int c, int rr, int cc) : current_row(r), current_col(c), final_row(rr), final_col(cc) {
            incentive = 0;
        }
        int incentive, current_row, current_col, final_row, final_col;

        bool operator >(const Move& b) {
            return this->incentive > b.incentive;
        }
        bool operator <(const Move& b) {
            return this->incentive <= b.incentive;
        }
};

class Board {
    public:
        Board();                                     // Takes input, assigns board and player id
        void play_move();
        void print();

    private:
        int board[10][4], player_id;
        map<pair<int, int>, bool> is_hole;           // True if a pos is threatening already
        map<pair<int, int>, bool> is_rival;          // True if a pos is threatening already
        map<pair<int, int>, bool> is_self;           // True if a pos hsa my piece already
        vector<vector<int> > threats;                // Oppressor row, Oppressor col, threatened row, threatened col
        vector<pair<int, int> > rival_pos;           // List of all positions of rival pieces
        vector<Move> possible_moves;                 // All physically possible moves for all pieces

        void find_holes_threats_rivalpos();             // Finds out forbidden cells and threats
        void find_piece_possible_moves(int r, int c);   // Finds out all possible moves for my piece with incentives
};

Board::Board() {
    int chances;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) cin >> board[i][j];
    }
    cin >> chances >> player_id;
    find_holes_threats_rivalpos();
}

void Board::find_holes_threats_rivalpos() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] / 100 != player_id && board[i][j] / 100 != 0) {                 // If is rival piece
                //cout << "Enemy at " << i << j << endl;
                int ptype = (board[i][j] / 10) % 10;                                            // Determine piece type
                bool dir = board[i][j] % 10;                                                    // Determine piece direction
                rival_pos.push_back({i, j});                                                    // Add to rival pos
                is_rival[{i, j}] = true;                                                        // Add to is_rival map

                vector<pair<int, int> > new_holes;
                new_holes = get_steps(i, j, ptype, dir);
                for (int h = 0; h < new_holes.size(); h++) {
                    is_hole[new_holes[h]] = true;                                               // Add to hole map

                    //cout << "At hole " << new_holes[h].first << ", " << new_holes[h].second << " player id is " << board[new_holes[h].first][new_holes[h].second] / 100 << endl;

                    if (board[new_holes[h].first][new_holes[h].second] / 100 == player_id) {    // Check if hole is a threat
                        //cout << ""
                        vector<int> threat;
                        threat.push_back(i);
                        threat.push_back(j);
                        threat.push_back(new_holes[h].first);
                        threat.push_back(new_holes[h].second);

                        threats.push_back(threat);
                    }
                }
            }
            if (board[i][j] / 100 == player_id) {                                      // If is self piece
                is_self[{i, j}] = true;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] / 100 == player_id) {                                      // If is self piece
                find_piece_possible_moves(i, j);
            }
        }
    }

    sort(possible_moves.begin(), possible_moves.end());
}

void Board::find_piece_possible_moves(int r, int c) {
    int ptype = (board[r][c] / 10) % 10;                                            // Determine piece type
    bool dir = board[r][c] % 10;                                                    // Determine piece direction

    if (ptype == 1) {
        // Left
        if (c >= 1 && is_self.count({r, c - 1}) == 0) {
            Move * m = new Move(r, c, r, c - 1);

            // Capture
            if (is_rival[{m -> final_row, m -> final_col}]) {
                m -> incentive++;
                // calculate threats given by this captured piece
                for (int i = 0; i < threats.size(); i++) {
                    if (threats[i][0] == m -> final_row && threats[i][1] == m -> final_col && threats[i][2] != m -> current_row && threats[i][3] != m -> current_col) {
                        m -> incentive++;
                    }
                }
            }
            // Moved to hole
            if (is_hole[{m -> final_row, m -> final_col}]) m -> incentive--;
            // Eliminated threat to self?
            if (is_hole[{m -> current_row, m -> current_col}]) incentive++;

            possible_moves.push_back(*m);
        }
        // Right
        if (c >= 1 && is_self.count({r, c - 1}) == 0) {
            Move * m = new Move(r, c, r, c - 1);
            possible_moves.push_back(*m);
        }
    }

    // push in possible_moves
}

void Board::play_move() {}

void Board::print() {
    cout << "Info processed------------\nThreats:\n";
    for (int i = 0; i < threats.size(); i++) {
        cout << "From: " << threats[i][0] << ", " << threats[i][1] << " To: " << threats[i][2] << ", " << threats[i][3] << "\n";
    }
    cout << "Holes:\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) if (is_hole[{i, j}]) cout << i << ", " << j << "\n";
    }
    cout << "Rival Pos:\n";
    for (int i = 0; i < rival_pos.size(); i++) cout << rival_pos[i].first << ", " << rival_pos[i].second << "\n";
    cout << "Possible moves are:\n";
    for (int i = 0; i < possible_moves.size(); i++) {
        cout << "From " << possible_moves[i].current_row << ", " << possible_moves[i].current_col << " to " << possible_moves[i].final_row << ", " << possible_moves[i].final_col << "\n";
    }
}

int main() {
    Board b;
    b.print();
    //b.play_move();
}
