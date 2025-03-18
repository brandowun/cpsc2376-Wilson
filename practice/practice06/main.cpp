#include "Fraction.h"
#include "MixedFraction.h"
#include <iostream>


using namespace std;


void displayMenu() {
        cout << "\nOptions:"<< endl;
        cout << "1. Enter a fraction manually"<< endl;
        cout << "2. Add a fraction"<< endl;
        cout << "3. Subtract a fraction"<< endl;
        cout << "4. Multiply by a fraction"<< endl;
        cout << "5. Divide by a fraction"<< endl;
        cout << "6. Display as Mixed Fraction"<< endl;
        cout << "7. Clear Fraction"<< endl;
        cout << "8. Exit"<< endl;
        cout << "Enter your choice: "<< endl;
}

Fraction getFractionInput() {
        int num, den;
            cout << "Enter fraction (numerator denominator): ";
            cin >> num >> den;

        while (den == 0) {
            cout << "Denominator cant be zero. Enter again: ";
            cin >> den;
    }
    return Fraction(num, den);
}

int main() {
    Fraction currentFraction(0, 1);
    int choice;


    do {
        cout << "Current Fraction: " << currentFraction << endl;
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                currentFraction = getFractionInput();
                break;

            case 2:
                currentFraction = currentFraction + getFractionInput();
            break;

            case 3:
                currentFraction = currentFraction - getFractionInput();
            break;

            case 4:
                currentFraction = currentFraction * getFractionInput();
            break;

            case 5:
            {
                Fraction divisor = getFractionInput();
                if (divisor.getNumerator() == 0) {
                    cout << "Cannot divide by zero. Try again.\n";
                } else {
                    currentFraction = currentFraction / divisor;
                }
            }
            break;

            case 6:
                cout << "Mixed Fraction: " << MixedFraction(currentFraction) << endl;
            break;

            case 7:
                currentFraction = Fraction(0, 1);
                cout << "Fraction reset to 0/1.\n";
            break;

            case 8:
                cout << "Exiting program.\n";
            break;

        default:
        cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

        return 0;
}
