#include <iostream>
#include "cell.cpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

#define SIZE 3

class Game{
    private:
        string p1;
        string p2;
        Cell** board;

    public:
    Game(string p1, string p2){
        //set player names
        this->p1 = p1;
        this->p2 = p2;

        // initialize the board
        this->board = new Cell*[SIZE];
        for(int i =0; i < SIZE; i++){
            this->board[i] = new Cell[SIZE];
        }

        gameGo();
    }

    void gameGo(){
        // bool gameWinState = false;
        // while(!gameWinState){

        // }
        gamePrinter();
    }

    void gamePrinter(){
        for(int i =0; i < SIZE; i++){
            cout << "|";
            for(int j =0; j < SIZE; j++){
                if(board[j][i].getMove() == Empty){ cout << " ";}
                else if(board[j][i].getMove() == Cross){ cout << "X";}
                else if(board[j][i].getMove() == Circle){ cout << "O";}
                cout << "|";
            }
            cout << endl;
        }
    }
};