#include "MixedFraction.h"
#include <iostream>

using namespace std;

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(whole * d + n, d) {}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {}

ostream& operator<<(ostream& cout, const MixedFraction& mf) {
    int whole = mf.getNumerator() / mf.getDenominator();
    int remainder = mf.getNumerator() % mf.getDenominator();

    if (whole != 0 && remainder != 0) {
        cout << whole << " " << remainder << "/" << mf.getDenominator();

    } else if (whole != 0){
        cout << whole;

    } else {
        cout << mf.getNumerator() << "/" << mf.getDenominator();
    }

    return cout;
}
