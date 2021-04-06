// Alejandro Armas
// 915110085
#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>

class Fraction {

    private: 
        int numerator;
        int denominator;
        void handleNegativity(void);
        void reduceFraction(void);

    public:
        Fraction(){};
        Fraction(const int& num, const int& den);
        int getNum(void) const {    return numerator;   }
        int getDen(void) const {    return denominator; }
        void setNum(const int& number) {    numerator = number; }
        void setDen(const int& number);

        friend const Fraction operator + (const Fraction& x, const Fraction& y);
        friend const Fraction operator - (const Fraction& x, const Fraction& y);
        friend std::ostream& operator << (std::ostream& os, const Fraction& value);
        friend std::istream& operator >> (std::istream& is, Fraction& value);
};

#endif