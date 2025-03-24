#include "battleship.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void menu() {
    cout << "=== Welcome to Battleship ==="<< endl;
    cout << "1. Play against A.I"<< endl;
    cout << "2. Exit"<< endl;
    cout << "Enter your choice: "<< endl;
}


void PlayerVsAI() {
    Game game;
    game.placeShips();
    game.AIShips(3);
    int row, col;
    string playerResult, aiResult;

    while (game.status() == ONGOING) {
        cout << game;
        cout << "Your turn.\n";

//players move
        do {
            cout << "Enter attack row: ";
            cin >> row;
            cout << "Enter attack col: ";
            cin >> col;
//error checking
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter numbers only.\n";
                continue;
            }
//veirfy inside game
            if (row < 0 || row >= 10 || col < 0 || col >= 10) {
                cout << "Out of bounds! Try again.\n";
                continue;
            }
//verifying in its a double placement
            if (!game.isValidMove(row, col)) {
                cout << "Already targeted! Try again.\n";
                continue;
            }
//if its good this will break and continue
            break;

        } while (true);
        playerResult = game.play(row, col);

//A.I moves
        int aiRow, aiCol;
        do {
            aiRow = rand() % 10;
            aiCol = rand() % 10;

        }while (!game.isValidMove(aiRow, aiCol));
        string aiResult = game.play(aiRow, aiCol);

        cout << "AI shot (" << aiRow << ", " << aiCol << ") → " << aiResult << "\n";
        cout << game;

//Where you shot at and A.i
        cout << "\nYou shot (" << row << ", " << col << ") " << playerResult << "\n";
        cout << "AI shot (" << aiRow << ", " << aiCol << ") " << aiResult << "\n";

// remaing ships left
        cout << "\nYour ships left: " << game.shipsLeft(true) << endl;
        cout << "AI ships left " << game.shipsLeft(false) << endl;
    }

    cout << game;
    if (game.status() == PLAYER_1_WINS)
        cout << "You win!\n";
    else if (game.status() == AI_Wins)
        cout << "AI wins!\n";
}

int main() {
    //chatgpt helped getting the A.I setup since, i needed random time for different games then same type of random
    srand(static_cast<unsigned>(time(0)));
    int choice;

    while (true) {
        menu();
        cin >> choice;

        if (choice == 1) PlayerVsAI();
        else if  (choice == 2) {
            cout << "You have retreated!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
        return 0;
    }
}
