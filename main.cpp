// 
#include <iostream>
#include "game.cpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(){
    cout << "Welcome To Tic-Tac-Toe" << endl;
    string p1Name, p2Name;
    //Entering Player Names
    cout << "Please enter player 1 name:";
    cin >> p1Name;
    cout << endl;
    cout << "Please enter player 2 name:";
    cin >> p2Name;
    cout << endl;
    Game* game = new Game(p1Name, p2Name);
    game->gameGo();
    return 0;
}
