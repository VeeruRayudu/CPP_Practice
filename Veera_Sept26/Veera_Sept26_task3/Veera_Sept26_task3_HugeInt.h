// Fig. 11.23: Hugeint.h 
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
    friend ostream &operator<<(ostream &, const HugeInt &);
public:
    static const int digits = 30; // maximum digits in a HugeInt

    HugeInt(long = 0); // conversion/default constructor
    HugeInt(const string &); // conversion constructor

    // addition operators
    HugeInt operator+(const HugeInt &) const;
    HugeInt operator+(int) const;            
    HugeInt operator+(const string &) const;

    // subtraction operators
    HugeInt operator-(const HugeInt &) const;
    HugeInt operator-(int) const;
    HugeInt operator-(const string &) const;

    // multiplication operators
    HugeInt operator*(const HugeInt &) const;
    HugeInt operator*(int) const;
    HugeInt operator*(const string &) const;

    // division operators  
    HugeInt operator/(const HugeInt &) const;
    HugeInt operator/(int) const;
    HugeInt operator/(const string &) const;

    // relational operators
    bool operator==(const HugeInt &) const;
    bool operator!=(const HugeInt &) const;
    bool operator<(const HugeInt &) const;
    bool operator>(const HugeInt &) const;
    bool operator<=(const HugeInt &) const;
    bool operator>=(const HugeInt &) const;

private:
    short integer[digits];
    
    // helper functions
    bool isZero() const;
    void shiftLeft(int positions = 1);
    int compare(const HugeInt &) const; // returns -1, 0, or 1
}; // end class HugeInt

#endif