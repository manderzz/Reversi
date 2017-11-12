//
// Created by faraz098 on 2017-03-24.
//

#ifndef ASS5_BOARD_H
#define ASS5_BOARD_H

#include "ansiicodes.h"
#include "Tile.h"
using namespace std;

    //*~*~*~*~*~*~*~*~*~*~~* Directions *~*~*~*~*~*~*~*~*~*~~*
enum direction {N,NE,E,SE,S,SW,W,NW};

    //*~*~*~*~*~*~*~*~*~*~~* class board *~*~*~*~*~*~*~*~*~*~~*
class Board {

    //*~*~*~*~*~*~*~*~*~*~~* storing the board *~*~*~*~*~*~*~*~*~*~~*

private:
    vector<vector<Tile>> board;

public:
    //*~*~*~*~*~*~*~*~*~*~~* constructor that sets everything to dirt(empty) *~*~*~*~*~*~*~*~*~*~~*

    Board(int width, int height) : board(height)
    {

        assert(width > 1 && height > 1);

        // set all tiles to be dirt
        for(int i = 0; i < board.size(); ++i) {
            board[i] = vector<Tile >(width,Tile::dirt);
        }


    }

    //*~*~*~*~*~*~*~*~*~*~~* width of the board *~*~*~*~*~*~*~*~*~*~~*

    int width() const { return board[0].size(); }

    //*~*~*~*~*~*~*~*~*~*~~* height of the board *~*~*~*~*~*~*~*~*~*~~*

    int height() const { return board.size(); }

    //*~*~*~*~*~*~*~*~*~*~~* gets the cell value *~*~*~*~*~*~*~*~*~*~~*

    Tile get_cell(int col, int row ) const
    {
        assert((col >= 0) && (col < width()));
        assert((row >= 0) && (row < height()));
        return board[col][row];
    }

    //*~*~*~*~*~*~*~*~*~*~~* set the cells *~*~*~*~*~*~*~*~*~*~~*

    void set_cell(int col, int row, const Tile& symbol)
    {

        assert((col >= 0) && (col < width()));
        assert((row >= 0) && (row < height()));
        board[col][row] = symbol;
    }

    //*~*~*~*~*~*~*~*~*~*~~* checks to see if the cell is empty *~*~*~*~*~*~*~*~*~*~~*

    bool is_cell_empty(int col, int row) const
    {
        if (board[col][row] == Tile::dirt || board[col][row] == Tile::possible) {
            return true;
        } else {
            return false;
        }
    }

    //*~*~*~*~*~*~*~*~*~*~~* is it within the boarders *~*~*~*~*~*~*~*~*~*~~*

    bool is_in_bounds(int col, int row) const
    {
        if ((col >= 0) && (col < width()) && (row >= 0) && (row < height())) {
            return true;
        } else {
            return false;
        }
    }

    //*~*~*~*~*~*~*~*~*~*~~* sets all the directions *~*~*~*~*~*~*~*~*~*~~*

    void set_coords_in_direction(int col, int row, int& next_col,
                                 int& next_row, int dir) const
    {
        switch (dir) {
            case N:
                next_col = col;
                next_row = row + 1;
                break;
            case NE:
                next_col = col + 1;
                next_row = row + 1;
                break;
            case E:
                next_col = col + 1;
                next_row = row;
                break;
            case SE:
                next_col = col + 1;
                next_row = row - 1;
                break;
            case S:
                next_col = col;
                next_row = row - 1;
                break;
            case SW:
                next_col = col - 1;
                next_row = row - 1;
                break;
            case W:
                next_col = col - 1;
                next_row = row;
                break;
            case NW:
                next_col = col - 1;
                next_row = row + 1;
                break;
            default:
                assert("Invalid direction");
        }
    }

    //*~*~*~*~*~*~*~*~*~*~~* checking end point *~*~*~*~*~*~*~*~*~*~~*

    bool check_endpoint(int col, int row, Tile symbol, int dir,
                        bool match_symbol) const
    {
        int next_row = -1;
        int next_col = -1;

        if (!is_in_bounds(col, row) || is_cell_empty(col, row)) {
            return false;
        } else {
            if (match_symbol) {
                if (get_cell(col, row) == symbol) {
                    return true;
                } else {
                    set_coords_in_direction(col, row, next_col, next_row, dir);
                    return check_endpoint(next_col, next_row, symbol, dir,
                                          match_symbol);
                }
            } else {
                if (get_cell(col, row) == symbol) {
                    return false;
                } else {
                    set_coords_in_direction(col, row, next_col, next_row, dir);
                    return check_endpoint(next_col, next_row, symbol, dir,
                                          !match_symbol);
                }
            }
        }
    }

    //*~*~*~*~*~*~*~*~*~*~~* is it a legal move *~*~*~*~*~*~*~*~*~*~~*

    bool is_legal_move(int col, int row, Tile symbol) const
    {
        bool result = false;
        int next_row = -1;
        int next_col = -1;

        if (!is_in_bounds(col, row) || !is_cell_empty(col, row)) {
            return result;
        }

        for (int d = N; d <= NW; d++) {
            set_coords_in_direction(col, row, next_col, next_row, d);
            if (check_endpoint(next_col, next_row, symbol, d, false)) {
                result = true;
                break;
            }
        }
        return result;
    }

    //*~*~*~*~*~*~*~*~*~*~~* flip peices *~*~*~*~*~*~*~*~*~*~~*

    int flip_pieces_helper(int col, int row,Tile symbol, int dir)
    {
        int next_row = -1;
        int next_col = -1;

        if (get_cell(col, row) == symbol) {
            return 0;
        } else {
            set_cell(col, row, symbol);
            set_coords_in_direction(col, row, next_col, next_row, dir);
            return 1 + flip_pieces_helper(next_col, next_row, symbol, dir);
        }
    }

    //*~*~*~*~*~*~*~*~*~*~~* flip peices *~*~*~*~*~*~*~*~*~*~~*

    int flip_pieces(int col, int row, Tile symbol)
    {
        int pieces_flipped = 0;
        int next_row = -1;
        int next_col = -1;

        assert(is_in_bounds(col, row));
        for (int d = N; d <= NW; d++) {
            set_coords_in_direction(col, row, next_col, next_row, d);
            if (check_endpoint(next_col, next_row, symbol, d, false)) {
                pieces_flipped += flip_pieces_helper(next_col, next_row, symbol, d);
            }
        }
        return pieces_flipped;
    }

    //*~*~*~*~*~*~*~*~*~*~~* do you have legal moves left *~*~*~*~*~*~*~*~*~*~~*

    bool has_legal_moves_remaining(Tile symbol)
    {
        for (int c = 0; c < width(); c++) {
            for (int r = 0; r < height(); r++) {
                if (is_cell_empty(c, r) && is_legal_move(c, r, symbol)) {
                    return true;
                }
            }
        }
        return false;
    }

    //*~*~*~*~*~*~*~*~*~*~~* play move *~*~*~*~*~*~*~*~*~*~~*

    void play_move(int col, int row, Tile symbol)
    {

        if( is_legal_move(col,row,symbol) && has_legal_moves_remaining(symbol)){
            set_cell(col,row,symbol);
            flip_pieces(col,row,symbol);

        }else{
            cout << "invalid...\n";

        }

    }

    //*~*~*~*~*~*~*~*~*~*~~* possible moves *~*~*~*~*~*~*~*~*~*~~*

    void possible_move(Tile symbol)
    {
        for (int i = 0; i < width(); ++i) {
            for (int j = 0; j < height(); ++j) {
                if( board[i][j] == Tile::possible){
                    board[i][j] = Tile::dirt;
                }

            }
        }
        for (int i = 0; i < width(); ++i) {
            for (int j = 0; j < height(); ++j) {
                if(is_legal_move(i,j,symbol)){
                    board[i][j] = Tile::possible;
                }

            }
        }

    }

    //*~*~*~*~*~*~*~*~*~*~~* number of ai tiles *~*~*~*~*~*~*~*~*~*~~*

    int get_ai()
    {
        int score=0;
        for (int i = 0; i < width() ; ++i) {
            for (int j = 0; j < height(); ++j) {
                if(board[i][j] == Tile::ai){
                  score++;
                }
            }
        }
        return score;
    }

    //*~*~*~*~*~*~*~*~*~*~~* number of player tiles *~*~*~*~*~*~*~*~*~*~~*

    int get_p()
    {
        int score=0;
        for (int i = 0; i < width() ; ++i) {
            for (int j = 0; j < height(); ++j) {
                if(board[i][j] == Tile::player){
                    score++;
                }
            }
        }
        return score;
    }

    //*~*~*~*~*~*~*~*~*~*~~* displays *~*~*~*~*~*~*~*~*~*~~*

    void display() const
    {
        int alpha =97;
        for (int r =0; r < height(); r++) {
            cout << char(alpha) << ":| ";
            alpha++;
            for (int c = 0; c < width(); c++) {



                if(board[r][c]== Tile::ai) {
                    cout << ANSII_BACKGROUND_BLUE << ANSII_BOLD  << char(board[r][c]) << "  " << ANSII_NORMAL;
                }
                if(board[r][c]== Tile::player) {
                    cout << ANSII_BACKGROUND_RED << ANSII_BOLD  << char(board[r][c]) << "  " << ANSII_NORMAL;
                }
                if(board[r][c]== Tile::dirt|| board[r][c]== Tile::possible) {
                    cout << ANSII_BACKGROUND_BLACK << ANSII_BOLD << char(board[r][c]) << "  " << ANSII_NORMAL;
                }
            }
            cout << endl<< endl;
        }
        cout << "    ";
        for (int c = 0; c < width(); c++) {
            cout << "---";
        }
        cout << "\n";
        cout << "    ";
        for (int c = 1; c <= width(); c++) {
            cout << c << "  ";
        }
        cout << "\n\n";
        cout << "\"@\" is the symbol for player...\n\"O\" is the symbol for AI...\n\"x\" is possible moves for player...\n\n";
    }


    //*~*~*~*~*~*~*~*~*~*~~* initialize the board *~*~*~*~*~*~*~*~*~*~~*

    void initialize()
    {
        set_cell(width() / 2 - 1, height() / 2 - 1, Tile::ai);
        set_cell(width() / 2, height() / 2, Tile::ai);
        set_cell(width() / 2 - 1, height() / 2, Tile::player);
        set_cell(width() / 2,   height() / 2 - 1, Tile::player); }

    //*~*~*~*~*~*~*~*~*~*~~* destructor  *~*~*~*~*~*~*~*~*~*~~*

    ~Board()
    {

        cout << " ";}




};




#endif //ASS5_BOARD_H
