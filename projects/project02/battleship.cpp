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
int Game::whoseTurn() const {
    return player1Turn ? 1 : 2;
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

string Game::play(int row, int col) {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) return "Out of bounds!";
    auto& board = player1Turn ? player2Board : player1Board;

    string result;
    if (board[row][col] == SHIP) {
        board[row][col] = HIT;
        result = "HIT!";
    } else if (board[row][col] == EMPTY) {
        board[row][col] = MISS;
        result = "Missed.";
    } else {
        result = "Already targeted.";
    }

    player1Turn = !player1Turn;
    return result;
}


void Game::display() const {
    //helped with dispaly since altering it from top to bottom to now side by side
    cout << "\n      Player 1 Board" << string(22, ' ') << "Player 2 Board\n";
    cout << "   ";
    for (int i = 0; i < 10; ++i) cout << i << " ";
    cout << "     ";
    for (int i = 0; i < 10; ++i) cout << i << " ";
    cout << "\n";

    for (int r = 0; r < 10; ++r) {
        cout << r << "  ";
        for (int c = 0; c < 10; ++c) {
            Cell cell = player1Board[r][c];
            if (cell == SHIP) cout << "S ";
            else if (cell == HIT) cout << "X ";
            else if (cell == MISS) cout << "O ";
            else cout << ". ";
        }

        cout << "   ";

        cout << r << "  ";
        for (int c = 0; c < 10; ++c) {
            Cell cell = player2Board[r][c];
            if (cell == HIT) cout << "X ";
            else if (cell == MISS) cout << "O ";
            else cout << ". "; // Needed a way to hide ships
        }
        cout << "\n";
    }
}


ostream& operator<<(ostream& os, const Game& game) {
    game.display();
    return os;
}

bool Game::isValidMove(int row, int col) const {
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
        return false;

    const auto& board = player1Turn ? player2Board : player1Board;
    return board[row][col] == EMPTY || board[row][col] == SHIP;
}
