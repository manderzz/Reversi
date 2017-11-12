//
// Created by faraz098 on 2017-03-24.
//

#ifndef ASS5_PLAYER_H
#define ASS5_PLAYER_H

#include "Tile.h"
#include "Board.h"

class Player  {
private:

    Tile symbol;

public:


    virtual ~Player(){}
    virtual Tile get_symbol()const =0;
    virtual void get_move(int col, int row) = 0;





};
#endif //ASS5_PLAYER_H
