#include <iostream>
#include <string>


using namespace std;

int main() {
    float bluePotion{0.0f};
    float redPotion{0.0f};
    float* flask{nullptr};

string choice;

    while (true) {
    cout << "Which color potion to add liquid to? Type Red or blue or type done to quit): ";
    cin >> choice;

        if (choice == "Done" || choice == "done") {
            break;
        }

        if (choice == "Blue" || choice == "blue") {
            flask = &bluePotion;
        } else if (choice == "Red" || choice == "red") {
            flask = &redPotion;
        } else {
        cout << "Invalid choice. Try again.\n";
            continue;
        }

        //fix errors if  answer is like .00000001
        //fix if not a number
        float amount{0.0f};
    cout << "How many mL to add? ";
    cin >> amount;

        if (amount <= 0.0f) {
        cout << "Can't add a negative amount or nothing.\n";
            continue;
        }

        *flask += amount;

    cout << "Red Potion: " << redPotion << " mL\n";
    cout << "Blue Potion: " << bluePotion << " mL\n";
    }

cout << "Exiting lab.";
    return 0;
}
