#include <iostream>
using std::string;

//Move of each cell
enum Move {circle, Cross, Empty};

class Cell{
    private:
    Move move;

    public:

    Move getMove(){
        return this->move;
    }

    void setMove(Move move){
        this->move = move;
    }
};