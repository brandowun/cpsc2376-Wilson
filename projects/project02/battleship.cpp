#include "battleship.h"
#include <iomanip>
using namespace std;

Game::Game() : player1Turn(true) {
    player1Board = vector<vector<Cell>>(10, vector<Cell>(10, EMPTY));
    player2Board = vector<vector<Cell>>(10, vector<Cell>(10, EMPTY));

//the amount of ships to use(i might want to make it an option to choose how many)
    player1Board[0][0] = SHIP;
    player1Board[1][1] = SHIP;
    player1Board[2][2] = SHIP;
    player2Board[3][3] = SHIP;
    player2Board[4][4] = SHIP;
}

Status Game::status() const {
    bool player1ships = false, player2ships = false;
//verifying if the attacks are accurate
    for (const auto& row : player1Board)
        for (Cell cell : row)
            if (cell == SHIP) player1ships = true;

    for (const auto& row : player2Board)
        for (Cell cell : row)
            if (cell == SHIP) player2ships = true;
//verifying the winnings
    if (!player1ships) return PLAYER_2_WINS;
    if (!player2ships) return PLAYER_1_WINS;
    return ONGOING;
}

void Game::play(int row, int col) {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) return; // Out of bounds

    auto& board = player1Turn ? player2Board : player1Board;

    if (board[row][col] == SHIP) board[row][col] = HIT;
    else if (board[row][col] == EMPTY) board[row][col] = MISS;

    player1Turn = !player1Turn;
}

void Game::display() const {
    const auto& board = player1Turn ? player2Board : player1Board;
// Was struggling with the display, with the spacing so had help here.
    cout << "  ";
    for (int i = 0; i < 10; i++) cout << i << " ";
    cout << "\n";

    for (int r = 0; r < 10; r++) {
        cout << r << " ";
        for (int c = 0; c < 10; c++) {
            if (board[r][c] == HIT) cout << "X ";
            else if (board[r][c] == MISS) cout << "O ";
            else cout << ". ";
        }
        cout << "\n";
    }
}

ostream& operator<<(ostream& os, const Game& game) {
    game.display();
    return os;
}
