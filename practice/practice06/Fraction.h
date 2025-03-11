#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;
    void simplify();

public:
    Fraction();
    Fraction(int n, int d);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(int n);
    void setDenominator(int d);

};

#endif
