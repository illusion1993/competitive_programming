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

class Move {
    public:
        Move()

        int incentive, penalty, current_row, current_col, final_row, final_col;

        bool operator >(const Move& b) {
            return this->incentive - this->penalty > b.incentive - b.penalty;
        }
        bool operator <(const Move& b) {
            return this->incentive - this->penalty <= b.incentive - b.penalty;
        }
};

class Piece {
    public:
        Piece(int type, int row, int col, bool direction) : type(type), row(row), col(col), direction(direction) {
            //find_possible_moves();
        }

        void find_possible_moves(vector<pair<Piece *, Piece *> > threats) {
            if (type == 1) {

            }

            sort(possible_moves.begin(), possible_moves.end());
        }

        Move best_move(vector<pair<Piece *, Piece *> > threats) {
            find_possible_moves(threats);
            return possible_moves.back();
        }

    private:
        int type, row, col;
        bool direction;
        vector<Move> possible_moves;
};

class Player {
    public:
        Player(int board[10][4], int id) {

        }

        vector<int> play_move() {
            vector<int> my_move;    // r, c, r', c'
            vector<Move> pieces_best_moves;

            for (int i = 0; i < pieces.size(); i++) {
                pieces_best_moves.push_back(pieces[i].best_move(threats));
            }
            sort(pieces_best_moves.begin(), pieces_best_moves.end());
            my_move.push_back(pieces_best_moves.back().current_row);
            my_move.push_back(pieces_best_moves.back().current_col);
            my_move.push_back(pieces_best_moves.back().final_row);
            my_move.push_back(pieces_best_moves.back().final_col);
            return my_move;
        }

        void set_opponent(Player * opp) {
            opponent = opp;
        }

    private:
        vector<pair<Piece *, Piece *> > threats;      // Currently present threats to my pieces <threat_from, threat_to>
        vector<Piece> pieces;
        map<pair<int, int>, Piece * > piece_at;
        Player * opponent;
};

class Board {
    public:
        void init_board() {
            int chances;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 4; j++) cin >> board[i][j];
            }
            cin >> chances >> player_id;

            my_player = new Player(board, player_id);
            opponent = new Player(board, (player_id == 1) ? 2 : 1);

            my_player -> set_opponent(opponent);
            opponent -> set_opponent(my_player);
        }

        void play_move() {
            vector<int> my_played_move = my_player -> play_move();
            cout << my_played_move[0] << " " << my_played_move[1] << "\n" << my_played_move[2] << " " << my_played_move[3];
        }

    private:
        int board[10][4], player_id;
        Player * my_player;
        Player * opponent;
};

int main() {
    Board b;
    b.init_board();
    b.play_move();
}
