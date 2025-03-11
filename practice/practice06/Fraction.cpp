#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(int n, int d) {
    if (d == 0) {
        d = 1;
    }
    numerator = n;
    denominator = d;
    simplify();
}

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

void Fraction::setNumerator(int n) {
    numerator = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0 ) {
        d = 1;
    }
    denominator = d;
    simplify();
}

void Fraction::simplify() {
    int n = numerator, d = denominator;
    while (n != 0) {
        int temp = d;
        d = n % d;
        n = temp;
    }
    int gcd = d;
    numerator /= gcd;
    denominator /= gcd;
}
