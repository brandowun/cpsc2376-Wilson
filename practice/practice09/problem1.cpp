#include <iostream>
#include <string>


using namespace std;

int main() {
    float bluePotion{0.0f};
    float redPotion{0.0f};
    float greenPotion{0.0f};
    float* flask{nullptr};

string choice;
string action;


    while (true) {
        cout << "Which color potion to add liquid to? Type red/blue/green or type done to quit): ";
        cin >> choice;

        if (choice == "Done" || choice == "done") {
            break;
        }

        if (choice == "Blue" || choice == "blue") {
            flask = &bluePotion;
        } else if (choice == "Red" || choice == "red") {
            flask = &redPotion;
        } else if (choice == "Green" || choice == "green") {
            flask = &greenPotion;
        } else {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        cout << "Add or remove a liquid?" ;
        cin >> action;

        if (!(action == "Add" || action == "add" || action == "Remove" || action == "remove")) {
            cout << "Invalid action. Type add or remove.\n";
            continue;
        }
        float amount{0.0f};
    cout << "How many mL to add? ";

        while (true) {
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid number. Enter a valid amount in mL: ";
            } else {
                break;
            }
        }

        if (amount <= 0.0f) {
        cout << "Can't add a negative amount or nothing.\n";
            continue;
        }
//ADD
        if (action == "Add" || action == "add") {
            if (*flask + amount > 100.0f) {
                cout << "That will overfill the flask, max amount is 100mL. \n";
                continue;
            }
            *flask += amount;
//REMOVE
        } else if (action == "Remove" || action == "remove") {
            if (*flask - amount < 0.0f) {
                cout << "The flask is already empty\n";
                continue;
            }
            *flask += amount;
//Broken
        }else {
            cout << "Invalid action. Type add or remove.\n";
            continue;
        }

    cout << "Levels of each potion: \n";
    cout << "Red Potion: " << redPotion << " mL\n";
    cout << "Blue Potion: " << bluePotion << " mL\n";
    cout << "Green Potion: " << greenPotion << "mL\n";

        float total = redPotion + bluePotion + greenPotion;
        cout << "Total: " << total << " mL\n";
    }

cout << "Exiting lab.";
    return 0;
}
