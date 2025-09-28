#include "Veera_Sept26_task4_RelationalNumber.h"

// Constructor initialization
RationalNumber::RationalNumber(int n, int d) {
    if(d == 0){
        throw std::invalid_argument("Denominator cannot be zero");
    }
    // Keep denominator positive
    if (d < 0) {
        n = -n;
        d = -d;
    }
    numerator = n;
    denominator = d;
    reduce();
}

//Reduce fraction
void RationalNumber::reduce() {
    int g = std::gcd(numerator, denominator);
    if (g != 0) {
        numerator /= g;
        denominator /= g;
    }
}

//Arithmetic
RationalNumber RationalNumber::operator+(const RationalNumber &rhs) const {
    return RationalNumber(numerator*rhs.denominator + rhs.numerator * denominator, denominator*rhs.denominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber &rhs) const {
    return RationalNumber(numerator * rhs.denominator - rhs.numerator * denominator, denominator*rhs.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber &rhs) const {
    return RationalNumber(numerator * rhs.numerator,denominator * rhs.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber &rhs) const {
    if (rhs.numerator == 0) {
        throw std::domain_error("Division by zero fraction");
    }
    return RationalNumber(numerator * rhs.denominator, denominator * rhs.numerator);
}

// Relational & equality
bool RationalNumber::operator==(const RationalNumber &rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool RationalNumber::operator!=(const RationalNumber &rhs) const {
    return !(*this == rhs);
}

bool RationalNumber::operator<(const RationalNumber &rhs) const {
    return numerator * rhs.denominator < rhs.numerator * denominator;
}

bool RationalNumber::operator<=(const RationalNumber &rhs) const {
    return *this < rhs || *this == rhs;
}

bool RationalNumber::operator>(const RationalNumber &rhs) const {
    return !(*this <= rhs);
}

bool RationalNumber::operator>=(const RationalNumber &rhs) const {
    return !(*this < rhs);
}

std::ostream& operator<<(std::ostream &os, const RationalNumber &r) {
    if(r.denominator == 1){
        os<<r.numerator;
    }else{
        os<<r.numerator<<"/"<<r.denominator;
    }
    return os;
}
