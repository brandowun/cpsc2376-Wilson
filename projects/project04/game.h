#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>

enum Cell { EMPTY, SHIP, HIT, MISS };
enum Status { ONGOING, PLAYER_1_WINS, AI_Wins };

class Game {
private:
    std::vector<std::vector<Cell>> playerBoard;
    std::vector<std::vector<Cell>> aiBoard;
    bool playerTurn;

public:
    Game();
    void placeShips();
    void AIShips(int count);
    std::string play(int row, int col);
    bool isValidMove(int row, int col) const;
    Status status() const;
    void draw(SDL_Renderer* renderer);
};
#endif
