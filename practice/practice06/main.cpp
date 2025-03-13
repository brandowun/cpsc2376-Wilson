#include "Fraction.h"
#include <iostream>

using namespace std;
//using chatgpt to help with the testing part, to make sure its working properly.
int main() {
    // Test default constructor
    Fraction f1;
    cout << "Default Fraction: " << f1.getNumerator() << "/" << f1.getDenominator() << endl; // Expected: 0/1

    // Test parameterized constructor
    Fraction f2(4, 8);
    cout << "Simplified Fraction: " << f2.getNumerator() << "/" << f2.getDenominator() << endl; // Expected: 1/2

    // Test denominator == 0 case
    Fraction f3(5, 0);
    cout << "Handled Invalid Fraction: " << f3.getNumerator() << "/" << f3.getDenominator() << endl; // Expected: 5/1

    // testing the setters
    f2.setNumerator(10);
    f2.setDenominator(20);
    cout << "Updated Fraction: " << f2.getNumerator() << "/" << f2.getDenominator() << endl; // Expected: 1/2
// testing overload operators
    Fraction f4(1,3);
    Fraction f5(2, 6);

    cout << "f3: " << f4 << "   f4: " << f5 << endl; // should show: 1/3

    cout << "Addition: " << (f4 + f5) << endl;  // should show: 2/3
    cout << "Subtraction: " << (f4 - f5) << endl;  //should show : 0/1
    cout << "Multiplication: " << (f4 * f5) << endl;  //should show : 1/9
    cout << "Division: " << (f4 / f5) << endl;  // should show: 1/1
    return 0;
}
