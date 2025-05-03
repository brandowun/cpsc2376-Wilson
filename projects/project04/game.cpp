#include "game.h"
#include <cstdlib>
#include <ctime>

Game::Game() : playerTurn(true) {
    playerBoard = std::vector<std::vector<Cell>>(10, std::vector<Cell>(10, EMPTY));
    aiBoard = std::vector<std::vector<Cell>>(10, std::vector<Cell>(10, EMPTY));
    srand(static_cast<unsigned>(time(0)));
}

void Game::placeShips() {
    int placed = 0;
    while (placed < 3) {
        int row = rand() % 10;
        int col = rand() % 10;
        if (playerBoard[row][col] == EMPTY) {
            playerBoard[row][col] = SHIP;
            ++placed;
        }
    }
}

void Game::AIShips(int count) {
    int placed = 0;
    while (placed < count) {
        int row = rand() % 10;
        int col = rand() % 10;
        if (aiBoard[row][col] == EMPTY) {
            aiBoard[row][col] = SHIP;
            ++placed;
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

bool Game::isValidMove(int row, int col) const {
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
        return false;
    const auto& board = playerTurn ? aiBoard : playerBoard;
    return board[row][col] == EMPTY || board[row][col] == SHIP;
}

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

void Game::draw(SDL_Renderer* renderer) {
    int cellSize = 40;
    SDL_Color hitColor = { 255, 0, 0, 255 };
    SDL_Color missColor = { 0, 0, 255, 255 };
    SDL_Color shipColor = { 0, 255, 0, 255 };
    SDL_Color emptyColor = { 40, 40, 40, 255 };
    SDL_Color border = { 0, 0, 0, 255 };

    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            SDL_Rect rect = { c * cellSize, r * cellSize, cellSize, cellSize };
            SDL_Color color;
            Cell cell = playerBoard[r][c];
            if (cell == SHIP) color = shipColor;
            else if (cell == HIT) color = hitColor;
            else if (cell == MISS) color = missColor;
            else color = emptyColor;

            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, border.r, border.g, border.b, border.a);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }

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
}
