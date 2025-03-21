#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <vector>
using namespace std;


enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS };
enum Cell { EMPTY, SHIP, HIT, MISS };

class Game {
private:
    vector<vector<Cell>> player1Board;
    vector<vector<Cell>> player2Board;
    bool player1Turn;

public:
    Game();
    Status  status() const;
    void play (int row,int col);
    void display() const;

    friend ostream& operator<<(ostream& os, const Game& game);
};


#endif
