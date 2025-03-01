/*
Prompt 2a: Calculator (Support Both int and double)
Objective:
Modify calculate<T> to handle both int and double input.

If the user enters a decimal, it uses double.
Otherwise, it uses int.
*/



#include <iostream>
#include <iomanip>

using namespace std;

template <typename numType>
numType calculate(numType num1, numType num2, char op) {

  switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        return 0;
       }
}


int main() {
    double num1, num2;
    char op;

//user first number
    cout << "Enter first number: ";
    //had chatgpt help me with this error, couldn't get it to stop double typing
    while (!(cin >> num1)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input: Enter first number again: ";
    }

// Get the operator
    cout << "Enter one of these operations (+, -, *, /): ";
    cin >> op;
    while (op != '+' && op != '-' && op != '*' && op != '/') {
        cout << "Invalid operator. Try again: ";
        cin >> op;
    }

//2nd number
    cout << "Enter second number: ";
    while (!(cin >> num2)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input, Enter second number again: ";
    }

// division by 0 error
    while (op == '/' && num2 == 0) {
        cout << "Error undifined: Enter a new number: ";
        while (!(cin >> num2)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input,Enter second number again: ";
        }
    }

// deciding if it's a int or double
    cout << fixed << setprecision(2);
    if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2)) {
        cout << "Result: " << calculate(static_cast<int>(num1), static_cast<int>(num2), op) << endl;
    } else {
        cout << "Result: " << calculate(num1, num2, op) << endl;
    }

    return 0;
}
