#include "Fraction.h"
#include <iostream>
#include "MixedFraction.h"

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw invalid_argument("0 can't be in denominator");;
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
    int a = abs(numerator), b = abs(denominator);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;

    numerator /= gcd;
    denominator /= gcd;

    // Making sure denominator is positive
    if (denominator < 0 ) {
        numerator= -numerator;
        denominator= -denominator;
    }

    }

// add
Fraction operator + (const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.denominator + b.numerator * a.denominator,a.denominator * b.denominator);
}

// subtract
Fraction operator - (const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.denominator - b.numerator * a.denominator,a.denominator * b.denominator);
}

// Mulitply
Fraction operator * (const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}

// Divide
Fraction operator / (const Fraction& a, const Fraction& b) {
    if (b.numerator == 0) {
        throw invalid_argument("Can't divide by zero");
    }
    return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
}

ostream& operator << (ostream& out, const Fraction& fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}
