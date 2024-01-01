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
        bool gameWinState;

    public:
    Game(string p1, string p2){
        //set player names and gameWinState
        this->p1 = p1;
        this->p2 = p2;
        gameWinState = false;

        // initialize the board
        this->board = new Cell*[SIZE];
        for(int i =0; i < SIZE; i++){
            this->board[i] = new Cell[SIZE];
        }
    }

    void gameGo(){
        while(!this->gameWinState){
            askMoveP1();
            gamePrinter();
            stateChecker(p1);
            if(this->gameWinState){break;}
            askMoveP2();
            gamePrinter();
            stateChecker(p2);
        }
    }

    void askMoveP1(){ //move for p1
        string p1RowString, p1ColString;
        int p1Row,p1Col;
        bool possible;
        do{
            do{
                cout << p1 << " (who is X), please enter your row and column values (between 1 and 3):" << endl << endl;
                cout << "Enter Row: ";
                cin >> p1RowString;
                cout << "Enter Col: ";
                cin >> p1ColString;
                cout << endl;
                p1Row = stoi(p1RowString);
                p1Col = stoi(p1ColString);
            }while(p1Row < 1 || p1Row > 3 || p1Col < 1 || p1Col > 3);
            possible = makeMove(p1Row, p1Col, Cross); // if the move is possible or not. If is, makes it
        }while(!possible);
    }

    void askMoveP2(){ //move for p2
        string p2RowString, p2ColString;
        int p2Row,p2Col;
        bool possible;
        do{
            do{
                cout << p2 << " (who is O), please enter your row and column values (between 1 and 3):" << endl << endl;
                cout << "Enter Row: ";
                cin >> p2RowString;
                cout << "Enter Col: ";
                cin >> p2ColString;
                cout << endl;
                p2Row = stoi(p2RowString);
                p2Col = stoi(p2ColString);
            }while(p2Row < 1 || p2Row > 3 || p2Col < 1 || p2Col > 3);
            possible = makeMove(p2Row, p2Col, Circle); // if the move is possible or not. If is, makes it
        }while(!possible);
    }

    bool makeMove(int row, int col, Move move){ //place the move on the board. -1 for indexing
        if(board[row-1][col-1].getMove() == Empty){
            board[row-1][col-1].setMove(move);
            return true;
        }
        cout << "Incorrect Move! Cell contains previous move" << endl << endl;
        return false;
    }

    void stateChecker(string name){ // check win state
        //Row check
        for(int i =0; i < SIZE; i++){
            if(this->board[i][0].getMove() == this->board[i][1].getMove() && this->board[i][0].getMove() == this->board[i][2].getMove() && this->board[i][0].getMove() != Empty){
                this->gameWinState = true;
                cout << "Congratulations " << name << " won!" << endl;
                return;
            }
        }

        //Col check
        for(int i =0; i < SIZE; i++){
            if(this->board[0][i].getMove() == this->board[1][i].getMove() && this->board[0][i].getMove() == this->board[2][i].getMove() && this->board[0][i].getMove() != Empty){
                this->gameWinState = true;
                cout << "Congratulations " << name << " won!" << endl;
                return;
            }
        }

        //diagonal check
        if(this->board[0][0].getMove() == this->board[1][1].getMove() && this->board[0][0].getMove() == this->board[2][2].getMove() && this->board[0][0].getMove() != Empty){
            this->gameWinState = true;
            cout << "Congratulations " << name << " won!" << endl;
            return;
        }
        if(this->board[0][2].getMove() == this->board[1][1].getMove() && this->board[0][2].getMove() == this->board[2][0].getMove() && this->board[0][2].getMove() != Empty){
            this->gameWinState = true;
            cout << "Congratulations " << name << " won!" << endl;
            return;
        }
    }

    void gamePrinter(){
        for(int i =0; i < SIZE;){
            for(int j =0; j < SIZE;){
                if(board[i][j].getMove() == Empty){ cout << " ";}
                else if(board[i][j].getMove() == Cross){ cout << "X";}
                else if(board[i][j].getMove() == Circle){ cout << "O";}
                j++;
                if(j < SIZE){
                cout << "|";
            }
            }
            cout << endl;
            i++;
            if(i < SIZE){
                cout << "-----" << endl;
            }
        }
        cout << endl;
    }
};