//
// Created by faraz098 on 2017-03-24.
//

#ifndef ASS5_HUMAN_PLAYER_H
#define ASS5_HUMAN_PLAYER_H

#include "Player.h"

#include "Tile.h"
using namespace std;
class human_player : public Player {


private:
    Tile c;
    Board& board;
    bool checker = true;
public:

    human_player( Board& b ,Tile x): c(x), board(b){   }
    ~human_player(){
        cout << " ";
    }
    Tile get_symbol()const {return c;}
    bool get_checker(){return checker;}
    void set_checker(bool x){checker =x; }
    void get_move( int col, int row) {

        string user_input;
        col = -97;
        row = -49;

        cout << "enter row then col (ex: a2) : ";
        cin >> user_input;


        for (int i = 97; i < 123; ++i) {
            if(user_input[0] == char(i)){
                col += i;
                cout << col << endl <<endl;
            }
        }

        for (int j = 48; j <= 48+board.width(); ++j) {

            if(user_input[1] == char(j)){
                row += j;
            }
        }


        if(board.has_legal_moves_remaining(get_symbol())) {
            if (board.is_legal_move(col, row, get_symbol())) {

                set_checker(true);
                board.play_move(col, row, get_symbol());
                board.possible_move(get_symbol());
            } else {
                cout << "\ninvalid point try again : \n\n";
                set_checker(false);
            }


        }else{
            set_checker(true);
        }




    }










};
#endif //ASS5_HUMAN_PLAYER_H
