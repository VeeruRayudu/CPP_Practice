#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>

class Complex{
    private:
    double real;
    double imaginary;
    
    public:
    //constructor
    Complex(double r = 0.0, double i = 0.0);

    // arithmetic operators
    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    Complex operator*(const Complex &c) const;

    // comparison operators
    bool operator==(const Complex &c) const;
    bool operator!=(const Complex &c) const;

    // friend I/O operators
    friend std::ostream &operator<<(std::ostream &out, const Complex &c);
    friend std::istream &operator>>(std::istream &in, Complex &c);
};

#endif
