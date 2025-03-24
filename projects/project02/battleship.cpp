#include "battleship.h"
#include <iomanip>
using namespace std;

//let chatgpt just reorganzie it, becasue it was a mess and it needed some TLC for organization
Game::Game() : player1Turn(true) {
    player1Board = vector<vector<Cell>>(10, vector<Cell>(10, EMPTY));
    aiBoard = vector<vector<Cell>>(10, vector<Cell>(10, EMPTY));
}

void Game::placeShips() {
    int placeShips = 3;
    int row, col;

    cout << "Place your " << placeShips << " ships.\n";
    for (int i = 0; i < placeShips; ++i) {
        do {
            cout << "There are 10 rows and 10 columns. Enter two numbers from 0 to 9.\n";
            cout << "Enter coordinates for ship #" << (i + 1);
            cout << "\nrow:";
            cin >> row;
            cout << "\ncol:";
            cin >> col;
//error handling
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please only enter numbers.\n";
                continue;
            }
//out of bounds checking
            if (row < 0 || row >= 10 || col < 0 || col >= 10) {
                cout << "Out of bounds! Try again.\n";
                continue;
            }
//double placement prevention
            if (player1Board[row][col] == SHIP) {
                cout << "Already placed a ship there. Try again.\n";
                continue;
            }

            player1Board[row][col] = SHIP;
            break;

        } while (true);
    }
}

void Game::AIShips(int shipCount) {
    int row, col;
    int placed = 0;

    while (placed < shipCount) {
        row = rand() % 10;
        col = rand() % 10;

        if (aiBoard[row][col] == EMPTY) {
            aiBoard[row][col] = SHIP;
            placed++;
        }
    }
}

string Game::play(int row, int col) {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) return "That's the edge of the world you can't hit there!";
    auto& board = player1Turn ? aiBoard : player1Board;

    string result;
    if (board[row][col] == SHIP) {
        board[row][col] = HIT;
        result = "HIT!";
        player1Turn = !player1Turn;//prevents bad shots & swapping turns

    } else if (board[row][col] == EMPTY) {
        board[row][col] = MISS;
        result = "Missed.";
        player1Turn = !player1Turn;//prevents bad shot & swapping turns
    } else {
        result = "Already targeted.";
    }
    return result;
}

bool Game::isValidMove(int row, int col) const {
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
        return false;

    const auto& board = player1Turn ? aiBoard : player1Board;
    return board[row][col] == EMPTY || board[row][col] == SHIP;
}

Status Game::status() const {
    bool player1ships = false, aiShips = false;
//verifying if the attacks are accurate
    for (const auto& row : player1Board)
        for (Cell cell : row)
            if (cell == SHIP) player1ships = true;

    for (const auto& row : aiBoard)
        for (Cell cell : row)
            if (cell == SHIP) aiShips = true;

//verifying the winnings
    if (!player1ships) return AI_Wins;
    if (!aiShips) return PLAYER_1_WINS;
    return ONGOING;
}

int Game::shipsLeft(bool forPlayer1) const {
    const auto& board = forPlayer1 ? player1Board : aiBoard;
    int count = 0;
    for (const auto& row : board)
        for (Cell cell : row)
            if (cell == SHIP) count++;
    return count;
}

int Game::whoseTurn() const {
    return player1Turn ? 1 : 2;
}

void Game::display() const {
//helped with display since altering it from top to bottom to now side by side
    cout << "\n      Your Board" << string(22, ' ') << "A.I\n";
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
            Cell cell = aiBoard[r][c];
            if (cell == HIT) cout << "X ";
            else if (cell == MISS) cout << "O ";
            else cout << ". ";
        }
        cout << "\n";
    }
}

ostream& operator<<(ostream& os, const Game& game) {
    game.display();
    return os;
}
