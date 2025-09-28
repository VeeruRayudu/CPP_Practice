#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include<iostream>
#include<numeric>

class RationalNumber {
    public:
    // Constructor
    RationalNumber(int n = 0, int d = 1);

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber &rhs) const;
    RationalNumber operator-(const RationalNumber &rhs) const;
    RationalNumber operator*(const RationalNumber &rhs) const;
    RationalNumber operator/(const RationalNumber &rhs) const;

    // Relational operators
    bool operator==(const RationalNumber &rhs) const;
    bool operator!=(const RationalNumber &rhs) const;
    bool operator<(const RationalNumber &rhs) const;
    bool operator<=(const RationalNumber &rhs) const;
    bool operator>(const RationalNumber &rhs) const;
    bool operator>=(const RationalNumber &rhs) const;

    // Output
    friend std::ostream& operator<<(std::ostream &os, const RationalNumber &r);

private:
    int numerator;
    int denominator;

    void reduce();//to reduce fractions
};

#endif
