//need to update where the boards message and viewing
//Also need to account for more edge cases
//need to display whose turn it is when choosing instead of making it an assumption




//extras im thinking about
// if P2P then be able to name player 1 and 2, to make it better or give them options(like real warship names)
//different amount of ships or board sizes
// i want to add an ai part where you can go against a bot(random)
// maybe add a version with being able to just watch a game



#include "battleship.h"
using namespace std;

int main() {
    Game game;
    int  row, col;

    while (game.status() == ONGOING) {
        cout <<game;
        cout << "Enter attack coordinates (row col)(ex: 0 (space) 1 or 1 enter 2 enter: ";
        cin  >>  row >> col;
        game.play (row, col);
    }

    cout << (game.status () == PLAYER_1_WINS ? "Player 1 Wins!" : "Player 2 Wins!");
}
