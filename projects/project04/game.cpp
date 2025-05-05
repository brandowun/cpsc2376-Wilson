#include "game.h"
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL2_gfxPrimitives.h>

Game::Game() : playerTurn(true) {
    playerBoard = std::vector<std::vector<Cell>>(10, std::vector<Cell>(10, EMPTY));
    aiBoard = std::vector<std::vector<Cell>>(10, std::vector<Cell>(10, EMPTY));
    srand(static_cast<unsigned>(time(0)));
}

void Game::placeShips() {
    struct Ship { int length; bool horizontal; };
    std::vector<Ship> ships = {
        {3, true}, {2, true},  // horizontal ships
        {3, false}, {2, false} // vertical ships
    };

    for (const Ship& s : ships) {
        bool placed = false;
        while (!placed) {
            int row = rand() % 10;
            int col = rand() % 10;

            // Check bounds
            if (s.horizontal && col + s.length > 10) continue;
            if (!s.horizontal && row + s.length > 10) continue;

            // Check for overlap
            bool overlaps = false;
            for (int i = 0; i < s.length; ++i) {
                int r = row + (s.horizontal ? 0 : i);
                int c = col + (s.horizontal ? i : 0);
                if (playerBoard[r][c] != EMPTY) {
                    overlaps = true;
                    break;
                }
            }
            if (overlaps) continue;

            // Place ship
            for (int i = 0; i < s.length; ++i) {
                int r = row + (s.horizontal ? 0 : i);
                int c = col + (s.horizontal ? i : 0);
                playerBoard[r][c] = SHIP;
            }

            placed = true;
        }
    }
}

void Game::AIShips(int aiship) {
    struct Ship { int length; bool horizontal; };
    std::vector<Ship> ships = {
        {3, true}, {2, true},
        {3, false}, {2, false}
    };

    for (const Ship& s : ships) {
        bool placed = false;
        while (!placed) {
            int row = rand() % 10;
            int col = rand() % 10;

            if (s.horizontal && col + s.length > 10) continue;
            if (!s.horizontal && row + s.length > 10) continue;

            bool overlaps = false;
            for (int i = 0; i < s.length; ++i) {
                int r = row + (s.horizontal ? 0 : i);
                int c = col + (s.horizontal ? i : 0);
                if (aiBoard[r][c] != EMPTY) {
                    overlaps = true;
                    break;
                }
            }
            if (overlaps) continue;

            for (int i = 0; i < s.length; ++i) {
                int r = row + (s.horizontal ? 0 : i);
                int c = col + (s.horizontal ? i : 0);
                aiBoard[r][c] = SHIP;
            }

            placed = true;
        }
    }
}

std::string Game::play(int row, int col) {
    auto& board = playerTurn ? aiBoard : playerBoard;
    if (board[row][col] == SHIP) {
        board[row][col] = HIT;
        playerTurn = !playerTurn;
        return "HIT!";
    }
    else if (board[row][col] == EMPTY) {
        board[row][col] = MISS;
        playerTurn = !playerTurn;
        return "Miss.";
    }
    else {
        return "Already targeted.";
    }
}
//VERIFYING IF MOVE IS POSSIBLE
bool Game::isValidMove(int row, int col) const {
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
        return false;
    const auto& board = playerTurn ? aiBoard : playerBoard;
    return board[row][col] == EMPTY || board[row][col] == SHIP;
}
//GAME STATUS
Status Game::status() const {
    bool playerAlive = false, aiAlive = false;
    for (const auto& row : playerBoard)
        for (Cell cell : row)
            if (cell == SHIP) playerAlive = true;
    for (const auto& row : aiBoard)
        for (Cell cell : row)
            if (cell == SHIP) aiAlive = true;

    if (!playerAlive) return AI_Wins;
    if (!aiAlive) return PLAYER_1_WINS;
    return ONGOING;
}

//DRAW GAME
void Game::draw(SDL_Renderer* renderer) {
    int cellSize = 40;
    SDL_Color hitColor = { 255, 0, 0, 255 };
    SDL_Color missColor = { 0, 0, 255, 255 };
    SDL_Color shipColor = { 0, 255, 0, 255 };
    SDL_Color emptyColor = { 40, 40, 40, 255 };
    SDL_Color border = { 0, 0, 0, 255 };
    //CREATES THE BOARD
    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            SDL_Rect rect = { c * cellSize, r * cellSize, cellSize, cellSize };
            //COLORS
            SDL_Color color;
            Cell cell = playerBoard[r][c];
            if (cell == SHIP) color = shipColor;
            else if (cell == HIT) color = hitColor;
            else if (cell == MISS) color = missColor;
            else color = emptyColor;
            //RENDER COLORS
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, border.r, border.g, border.b, border.a);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
    //A.I BOARD & COLOR
    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            SDL_Rect rect = { 500 + c * cellSize, r * cellSize, cellSize, cellSize };
            SDL_Color color;
            Cell cell = aiBoard[r][c];
            if (cell == HIT) color = hitColor;
            else if (cell == MISS) color = missColor;
            else color = emptyColor;

            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, border.r, border.g, border.b, border.a);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
    //BOTTOM TEXT
    stringRGBA(renderer, 100, 420, "Your Board", 255, 255, 255, 255);
    stringRGBA(renderer, 600, 420, "Enemy Board ", 255, 255, 255, 255);
    stringRGBA(renderer, 600, 440, "Click the tiles here to destory your enemy", 255, 255, 255, 255);
}
