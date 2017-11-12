//
// Created by faraz098 on 2017-03-24.
//

#ifndef ASS5_AI_H
#define ASS5_AI_H

#include "Player.h"

#include "Tile.h"
class Ai : public Player{

private:
    Tile c;
    Board& board;
public:



    Ai( Board& b ,Tile x): c(x), board(b){}
    ~Ai(){}
    Tile get_symbol()const {return c;}
    void get_move(int col, int row)  {
        bool checker = true;
        if (board.is_legal_move(col,row,Tile::ai) && board.is_cell_empty(0,0)){
            if(checker == true){

                board.play_move(0,0,Tile::ai);
                checker = false;
            }
        }
        if (board.is_legal_move(0,board.width(),Tile::ai) && board.is_cell_empty(0,board.width())){
            if(checker == true){


                board.play_move(0,board.width(),Tile::ai);
                checker = false;
            }
        }
         if (board.is_legal_move(board.height(),1,Tile::ai) && board.is_cell_empty(board.height(),0)){
            if(checker == true){


                board.play_move(board.height(),0,Tile::ai);
                checker = false;
            }
        }
       if (board.is_legal_move(board.height(),board.width(),Tile::ai) && board.is_cell_empty(board.height(),board.width())){
            if(checker == true){


                board.play_move(board.height(),board.width(),Tile::ai);
                checker = false;
            }
        }



        bool check = 0;
        for (int r = 0; r <= board.width(); r++) {

                for (int c = 0; c <= board.height(); c++) {
                    if (board.is_legal_move(c, r, Tile::ai)) {

                        if(checker == true) {
                            board.play_move(c, r, Tile::ai);
                            check = 1;
                            checker = false;
                        }
                        else{ continue;}
                    } else {
                        if (!check) {

                            continue;
                        } else {
                            break;
                        }
                    }
                }



        }
            checker = true;






    }







};
#endif //ASS5_AI_H
