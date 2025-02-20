/*
/// connect 4
// steps players:2
//board length: 7x6
// Rules:
// 1.Players take turns dropping one disc into an open slot at the top of the board
// 2.The first player to get four disc in a row wins
/// If the board fills up before either player wins the game is a draw
/// Players can use strategy to block opponents
/// X's and O's
/// functions needed
/// A.  makeBoard() = initializes the game board and prepares it for play
/// B.  play() = handles turn logic, allowing players to tae actions on their turn
///C. gameStatus() = Determines if the game is still ongoing or if someone won
///     should return an enumeration representing the game state(e.g ongoing, player1wins, player 2 wins draw
///D. Input Handling and validation = no user input should crash the game.
///     Protect against mistype or invalid input by promopting users again if thy enter something unexpected.
///E.Rules explenation = Your program must printout the rules to the console at the begining so the user understands game
///F. Multiple games and exit option
///     after one game finishies, the user should be given the option to play again or exit
///G. proper code organiztion
/// The main() should be small and only handl high-level game flow
///     Most game logic should be implemented inside functions, rather than in main()
/// Core game functions(ex: makeBoard(), play(), gameStatus() should not handle user input directly- instead
/// get user input separetly and pass it into fucntions as needed.
///H. Use of Enumerations
///Use enumeratins(enum or enm class) to reperesent game tokens, game state, or board state. Instead of raw ints or chars
 Types of moves/varibles i might need
 * Display rules then pick
 * Player 1
 * Player 2
 * Pick X or O
 * Initialize board
 * Start game
 * Pick location
 * Drop
 * update board
 * (check if win/board full)
 * Switch to player 2
 * Repeat, till win or draw
 * Ask again to play , reset board
*/
#include <iostream>
#include <vector>

using namespace std;

const int rows = 6, columns = 7;
enum class gameState {onGoing,player1Wins,player2Wins,draw};

// Prints game rules
void rules() {
    cout << "\nWelcome to Connect 4! Here are the rules:\n";
    cout << "Tip: Player 1 is always X" << endl;
    cout << "----------------------------------------------------\n";
    cout << "1. 2 Players take turns dropping one disc into an open slot at the top of the board.\n";
    cout << "2. The first player to get four discs in a row wins!\n";
    cout << "3. If the board fills up before either player wins, it's a draw.\n";
    cout << "Tip: You can use strategy to block opponents.\n";
    cout << "Let the odds forever be in your favor!\n\n";
}

class connectFour {
private:
    vector<vector<char>> board;
    char player;
    gameState state;


public:
    connectFour() : board(rows, vector<char>(columns, ' ')), player('X'), state(gameState::onGoing) {}

    //Make the board
    void makeBoard() {
        cout << " 0 1 2 3 4 5 6 \n";
        cout << "---------------\n";


        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                cout << "|" << (board[r][c] == ' ' ? '_' : board[r][c]);
            }
            cout << "|\n";
        }
    }

    //Able to actually play
    void playTurn(int col) {
        for (int r = rows - 1; r >= 0; --r) {
            if (board[r][col] == ' ') {
                board[r][col] = player;
                break;
            }
        }
        //checking a winner
        makeBoard();
        state = gameStatus();
        if (state == gameState::onGoing) {
            switchPlayer();
            return;
        }
    }

    //collecitng player inputs
    int playerInputs() {
        int col;
        while (true) {
            cout << "Player " << player << ", choose a column (0-6): ";

            if (cin >> col && col >= 0 && col < columns)
                return col;

            //Error checking when player plays
            cin.clear();
            if (!cin.fail()) {
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter a column (0-6): ";
            }
        }
    }


    //Swap players
    void switchPlayer() {
        player = (player == 'X') ? 'O' : 'X';
    }
    gameState gameStatus() {
        if (winner()) {
            cout << "Player:" << player << " is the winner!!!!" << endl;
            return(player == 'X') ? gameState::player2Wins : gameState::player1Wins;

        }

        if (fullBoard()) {
            cout << "It's a draw!, Board is full\n";
            return gameState::draw;
        }
        return gameState::onGoing;
    }

    //check if the board is full or not
    bool fullBoard() {
        for (int c = 0; c < columns; c++) {
            if (board[0][c] == ' ' ) return false;
        }
        return true;
    }

    //checking if someone won
    bool winner() {
        bool winnerFound = false;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                if (board[r][c] == ' ') {
                    continue;
                }


                // horizontaal
                if (c + 3 < columns && board[r][c] == board[r][c+1] && board[r][c] == board[r][c+2] && board[r][c] == board[r][c+3]) {
                    winnerFound = true;
                }
                // vertcial
                if (r + 3 < rows && board[r][c] == board[r+1][c] && board[r][c] == board[r + 2][c] && board[r][c] == board[r+3][c]) {
                    winnerFound = true;
                }
                //diagonals down to bottom right
                if (r + 3 < rows && c + 3 < columns && board[r][c] == board[r+1][c+1] && board[r][c] == board[r+2][c+2] && board[r][c] == board[r+3][c+3]) {
                    winnerFound = true;
                }
                // bottom to top right
                if (r - 3 >= 0 && c + 3 < columns && board[r][c] == board[r - 1][c+1] && board[r][c] == board[r-2][c+2] && board[r][c] == board[r-3][c+3]) {
                    winnerFound = true;
                    }
                }
            }
        return winnerFound;
        }

    //game logic
    void playGame() {
        char restart;

        do {
            //reset the game
            board.assign(rows, vector<char>(columns, ' '));
            state = gameState::onGoing;
            player = 'X';

            rules();
            makeBoard();

            while (state == gameState::onGoing) {
                int col = playerInputs();
                playTurn(col);
                state = gameStatus();
            }
            //ask to reset
            cout << "Do you want to play again? (y/n): ";
            cin >> restart;
            cin.ignore(1000, '\n');

        } while (restart == 'y' || restart == 'Y');

        cout << "Exiting game!\n";
    }
};

int main() {
        connectFour game;
        game.playGame();
        return 0;
    }
