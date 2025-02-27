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

template <typename T>
T calculate(T a, T b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}


int main() {
    double num1, num2;
    char op;

    cout <<"Enter first number: ";
    cin >>num1;

    return 0;
}
