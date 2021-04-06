// Alejandro Armas
// 915110085
#include "Fraction.h"
#include <stdexcept>
#include <iostream>

namespace helperFunctions {

    int getGreatestCommonDivisor(int n1, int n2) {
        
        int gcd, remainder;
        n1 = n1 < 0 ? -n1 : n1; 
        n2 = n2 < 0 ? -n2 : n2;
        
        remainder = n1 % n2;

        while (remainder) {
            n1 = n2;
            n2 = remainder; 
            remainder = n1 % n2; 
        } 
        
        gcd = n2; 

        return gcd;
        }


    bool canSimplifyFraction(const int& numberOne, const int& numberTwo) {
        return helperFunctions::getGreatestCommonDivisor(numberOne, numberTwo) == 1;
    }
}


Fraction::Fraction(const int& num, const int& den) {
    setNum(num);
    setDen(den);
    reduceFraction();
}


void Fraction::setDen(const int& number){
    

    if (number == 0) {
            throw std::invalid_argument("zero denominator");
        }
    denominator = number;
}


void Fraction::reduceFraction(void){

    const int gcd = helperFunctions::getGreatestCommonDivisor(numerator, denominator);
    
    if (gcd != 1) {
        setNum(numerator / gcd);
        setDen(denominator / gcd);
    }

    handleNegativity();
}

void Fraction::handleNegativity(void) {
    
    int numerator = getNum();
    int denominator = getDen();

    bool numeratorIsPositive, denominatorIsPositive; 

    numeratorIsPositive = numerator > 0;
    denominatorIsPositive = denominator > 0;

    numerator = numeratorIsPositive ? numerator : -numerator;
    denominator = denominatorIsPositive ? denominator: -denominator;

    if (numeratorIsPositive && denominatorIsPositive || !numeratorIsPositive && !denominatorIsPositive) {
        setNum(numerator);
        setDen(denominator);
    }
    else if (numeratorIsPositive && !denominatorIsPositive || !numeratorIsPositive && denominatorIsPositive) {
        setNum(-numerator);
        setDen(denominator);
    }
}

const Fraction operator + (const Fraction& x, const Fraction& y) {
    
    int numerator_1, numerator_2, denominator_1, denominator_2;

    numerator_1 = x.getNum();
    numerator_2 = y.getNum();

    denominator_1 = x.getDen();
    denominator_2 = y.getDen();

    return Fraction(numerator_1 * denominator_2 + numerator_2 * denominator_1, denominator_1 * denominator_2);
}

const Fraction operator - (const Fraction& x, const Fraction& y) {
    
    int numerator_1, numerator_2, denominator_1, denominator_2;

    numerator_1 = x.getNum();
    numerator_2 = y.getNum();

    denominator_1 = x.getDen();
    denominator_2 = y.getDen();

    return Fraction(numerator_1 * denominator_2 - numerator_2 * denominator_1, denominator_1 * denominator_2);
}



std::ostream& operator << (std::ostream& os, const Fraction& value){

    bool denominatorNotNecessary = value.getDen() == 1;
    
    denominatorNotNecessary ? os << value.getNum() :  os << value.getNum() << "/" << value.getDen();
    
    return os;
}


std::istream& operator >> (std::istream& is, Fraction& value) {
    int numerator, denominator;
    char forwardslash;
    // NEEDS input Validation!! 
    is >> numerator >> forwardslash >> denominator;
    value.setNum(numerator);
    value.setDen(denominator);
    value.reduceFraction();
    return is;
    }




