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
    cin >> num1;

    while(cin.fail()){
        cout <<"Invalid input. Try again: ";
        cin.clear();
        cin.ignore(10000, '\n');

        //THIS KEEPS SKIPPING
        cout << "Enter first number again: ";
        cin >> num1;
    }
// now pick the operator
    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

// now the second number
    cout << "Enter second number: ";
    cin >> num2;

      cout << fixed << setprecision(2);
      cout << "result: " << calculate(num1, num2, op) << endl;
    return 0;
}
}
