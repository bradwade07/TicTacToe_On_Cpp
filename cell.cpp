#include <iostream>
using std::string;

//Move of each cell
enum Move {Circle, Cross, Empty};

class Cell{
    private:
    Move move;

    public:
    Cell(){
        this->move = Empty;
    }
    Move getMove(){
        return this->move;
    }

    void setMove(Move move){
        this->move = move;
    }
};