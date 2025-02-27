/*
 *Prompt 1a: Temperature Converter (Single Function, Both Ways)
Objective:
Modify convertTemp so the menu allows choosing Celsius → Fahrenheit or Fahrenheit → Celsius, but both use the same function.

convertTemp(double temp, char scale = 'F')
'F': Converts Celsius to Fahrenheit
'C': Converts Fahrenheit to Celsius
The UI offers both options, but both call the same function.
Example UI:
*/





#include <iostream>
#include <iomanip>

using namespace std;

double convertTemp(double temp, char scale = 'F') {
    if (scale == 'F') {
        // Celsius to Fahrenheit
        return (temp * 9.0 / 5.0) + 32.0;
    } else {
        // Fahrenheit to Celsius
        return (temp - 32.0) * 5.0 / 9.0;
    }
}

int main() {
    int choice;
    double temp;


    cout << "1. Convert Celsius to Fahrenheit\n";
    cout << "2. Convert Fahrenheit to Celsius\n";
    cout << "Choose an option: ";
    cin >> choice;
    //choice error checks
    while (cin.fail() || choice != 1 && choice != 2) {
        cin.clear();
        cin.ignore(1000,'\n');

        /* Couldn't figure out how to get it to stop doubling the error, so stuck it in chatgpt, and all i had to do was
         * swap the location of cin.clear()/cin.ignore and cout<< invalid/.....cin>>choice and it stopped. */

        cout << "Invalid option pick, please choose again: ";
        cin >> choice;
    }
    cout << "\n";

    cout << "Enter temperature you want to convert: ";
    cin >> temp;
    //temp error checks
    while (cin.fail() || temp == int()) {
        cout << "Invalid temp, try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> temp;
    }

    cout << fixed << setprecision(2);
    if (choice == 1) {
        cout << temp<< "°C converts to  "  << convertTemp(temp, 'F') << "°F\n";
    } else if (choice == 2) {
        cout <<  temp << "°F converts to " << convertTemp(temp, 'C') << "°C\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
