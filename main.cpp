#include <iostream>
#include "Board.h"
#include "human_player.h"
#include "Ai.h"
#include "Tile.h"

using namespace std;
int main() {




    cout << "\n\n~~~~~~~~~~~~~~~~~~~ Welcome to the game of Reversi :) ~~~~~~~~~~~~~~~~~~~ \n";
//         << "\"@\" is the symbol for player...\n\"O\" is the symbol for AI...\n\"x\" is possible moves for player...\n";


    int size_board = 0;
    cout << "\nHow what would you like to be the board size? ";
    cin >>size_board;
    Board bob (size_board,size_board);
    bob.initialize();



    Tile player1 = Tile::player;
    Tile player2 = Tile::ai;

    human_player p1(bob,player1);
    Ai p2(bob, player2);


    while (bob.has_legal_moves_remaining(p1.get_symbol()) || bob.has_legal_moves_remaining(p2.get_symbol())) {
        bool test = true;



        if (bob.has_legal_moves_remaining(p1.get_symbol()) && test == true) {



            cout << "Player 1 (" << " @ " << ") move\n\n";
            bob.possible_move(player1);
            bob.display();
            p1.get_move(0, 0);
            bob.display();
            while (!p1.get_checker()) {

                p1.get_move(0, 0);
                bob.display();
            }
            test = false;
        }
            test = true;
        if ( bob.has_legal_moves_remaining(p2.get_symbol())&& test == true){


                cout << "Player 2 (" << " O " << ") move:\n\n";
                p2.get_move(0,0);
                bob.display();
                test = false;

        }






    }
    string play_again;
    cout << "**************** SUMMARY *****************\n\n";
    if(bob.get_ai() == bob.get_p()){
        cout << "\t\tTied game!!\n";
        cout << "\t\ttotal score \n";
        cout << "\t\tAi score = " << bob.get_ai() << endl;
        cout << "\t\tPlayer score = " << bob.get_p() << endl;
     }else  if(bob.get_ai() > bob.get_p()){
        cout << "\t\tAi won !!!\n";
        cout << "\t\ttotal score \n";
        cout << "\t\tAi score = " << bob.get_ai() << endl;
        cout << "\t\tPlayer score = " << bob.get_p() << endl;
    }else if(bob.get_ai() < bob.get_p()){
        cout << "\t\tPlayer won !!\n";
        cout << "\t\ttotal score \n";
        cout << "\t\tAi score = " << bob.get_ai() << endl;
        cout << "\t\tPlayer score = " << bob.get_p() << endl;
    }




    cout << "\n\n Would you like to play again ? ";
    cin >> play_again;
    if (play_again[0] == 'y' || play_again[0] == 'Y'){
        main();
    }else{
        return 0;
    }




    return 0;
}