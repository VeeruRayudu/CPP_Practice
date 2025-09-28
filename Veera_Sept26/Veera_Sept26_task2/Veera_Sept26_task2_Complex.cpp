#include "Veera_Sept26_task2_Complex.h"

// constructor initialization
Complex::Complex(double real_, double imaginary_) : real(real_), imaginary(imaginary_) {}

// addition
Complex Complex::operator+(const Complex &c) const{
    return Complex(real + c.real, imaginary + c.imaginary);
}

// subtraction
Complex Complex::operator-(const Complex &c) const{
    return Complex(real - c.real, imaginary - c.imaginary);
}

// multiplication
Complex Complex::operator*(const Complex &c) const{
    return Complex(real*c.real - imaginary*c.imaginary, real*c.imaginary + imaginary*c.real);
}

// equality
bool Complex::operator==(const Complex &c) const{
    return (real==c.real && imaginary==c.imaginary);
}

// inequality
bool Complex::operator!=(const Complex &c) const{
    return !(*this == c);
}

// output operator
std::ostream &operator<<(std::ostream &out, const Complex &c) {
    out<<'('<<c.real<<", "<<c.imaginary<<')';
    return out;
}

// input operator
std::istream &operator>>(std::istream &in, Complex &c) {
    std::cout<<"Enter real part: ";
    in>>c.real;
    std::cout<<"Enter imaginary part: ";
    in>>c.imaginary;
    return in;
}
