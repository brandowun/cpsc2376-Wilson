#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;
    void simplify();

public:
//Construct
    Fraction();
    Fraction(int n, int d);

//Get
    int getNumerator() const;
    int getDenominator() const;

//Set
    void setNumerator(int n);
    void setDenominator(int d);

//Overloading the operator
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const Fraction& b);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    friend class MixedFraction;
};

#endif
