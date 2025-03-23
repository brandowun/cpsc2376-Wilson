//shot should say if it's a hit or miss
//should state how many ships left
//Also need to account for more edge cases

//extras im thinking about
// maybe add a version with being able to just watch a game



#include "battleship.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void menu() {
    cout << "=== Welcome to Battleship ==="<< endl;
    cout << "1. Player vs Player"<< endl;
    cout << "2. Player vs AI"<< endl;
    cout << "3. Exit"<< endl;
    cout << "Enter your choice: "<< endl;
}

void playerVSplayer() {
    Game game;
    int row, col;

    while (game.status() == ONGOING) {
        cout << game;
        cout << (game.whoseTurn() ? "Player 1" : "Player 2") << "'s turn.\n";
        cout << "Enter attack coordinates (row col): ";
        cin >> row >> col;
        game.play(row, col);
    }

    cout << "Player " << game.whoseTurn() << "'s turn.\n";
}

void runPlayerVsAI() {
    Game game;
    int row, col;
// Chat helped me with the A.I section since using ctime
    while (game.status() == ONGOING) {
        if (game.whoseTurn() == 1){
            cout << game;
            cout << "Your turn.\n";
            cout << "Enter attack coordinates (row col): ";
            cin >> row >> col;
            cout << "You shot (" << row << ", " << col << ")";
            game.play(row, col);
        } else {
            int aiRow, aiCol;
            do {
                aiRow = rand() % 10;
                aiCol = rand() % 10;
            } while (!game.isValidMove(aiRow, aiCol));

            cout << "\nAI is attacking (" << aiRow << ", " << aiCol << ")\n";
            game.play(aiRow, aiCol);
        }
    }

    cout << game;
    cout << "Player " << game.whoseTurn() << "'s turn.\n";
}

int main() {
    //chatgpt helped getting the A.I setup since, i needed random time for different games then same type of random
    srand(static_cast<unsigned>(time(0)));
    int choice;

    while (true) {
        menu();
        cin >> choice;

        if (choice == 1) playerVSplayer();
        else if (choice == 2) runPlayerVsAI();
        else if (choice == 3) {
            cout << "You have retreated!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
