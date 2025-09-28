#include <cctype> 
#include "Veera_Sept26_task3_HugeInt.h"
using namespace std;


HugeInt::HugeInt(long value)
{
    // initialize array to zero
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    // place digits of argument into array 
    for (int j = digits - 1; value != 0 && j >= 0; j--)
    {
        integer[j] = value % 10;
        value /= 10;
    } 
}

HugeInt::HugeInt(const string &number)
{
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    int length = number.size();

    for (int j = digits - length, k = 0; j < digits; j++, k++)
        if (isdigit(number[k])) 
            integer[j] = number[k] - '0';
} 

HugeInt HugeInt::operator+(const HugeInt &op2) const
{
    HugeInt temp; 
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--)
    {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;

        // determine whether to carry a 1
        if (temp.integer[i] > 9)
        {
            temp.integer[i] %= 10; // reduce to 0-9
            carry = 1;
        } 
        else 
            carry = 0;
    }

    return temp; 
} 

// HugeInt + int
HugeInt HugeInt::operator+(int op2) const
{
    return *this + HugeInt(op2); 
} 

// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+(const string &op2) const
{
    return *this + HugeInt(op2); 
}

//HugeInt - HugeInt
HugeInt HugeInt::operator-(const HugeInt &op2) const
{
    HugeInt result = *this; 
    
    for (int i = digits - 1; i >= 0; i--)
    {
        if (result.integer[i] < op2.integer[i])
        {
            int borrowFrom = i - 1;
            while (borrowFrom >= 0 && result.integer[borrowFrom] == 0)
            {
                borrowFrom--;
            }
            
            if (borrowFrom < 0)
            {
                return HugeInt(0);
            }
            
            // perform the borrow
            for (int j = borrowFrom + 1; j <= i; j++)
            {
                if (j == borrowFrom + 1)
                {
                    result.integer[j] += 9;
                }
                else
                {
                    result.integer[j] += 9;
                }
            }
            result.integer[borrowFrom]--;
        }
        
        // perform the subtraction for this digit
        result.integer[i] -= op2.integer[i];
    }
    
    return result;
}

//HugeInt - int
HugeInt HugeInt::operator-(int op2) const
{
    return *this - HugeInt(op2);
} 

// HugeInt - string
HugeInt HugeInt::operator-(const string &op2) const
{
    return *this - HugeInt(op2);
} 

//check if number is zero
bool HugeInt::isZero() const
{
    for (int i = 0; i < digits; i++)
        if (integer[i] != 0)
            return false;
    return true;
}

//function for comparison
int HugeInt::compare(const HugeInt &right) const
{
    for (int i = 0; i < digits; i++)
    {
        if (integer[i] != right.integer[i])
            return (integer[i] > right.integer[i]) ? 1 : -1;
    }
    return 0; // equal
}

//function to shift left
void HugeInt::shiftLeft(int positions)
{
    for (int i = 0; i < digits - positions; i++)
        integer[i] = integer[i + positions];
    
    for (int i = digits - positions; i < digits; i++)
        integer[i] = 0;
}

//HugeInt * HugeInt
HugeInt HugeInt::operator*(const HugeInt &op2) const
{
    HugeInt product;
    
    if (isZero() || op2.isZero())
        return product;
    
    HugeInt temp = *this;
    HugeInt multiplier = op2;
    
    HugeInt one(1);
    HugeInt zero(0);
    
    while (multiplier > zero)
    {
        product = product + temp;
        multiplier = multiplier - one;
    }
    
    return product;
} 

//HugeInt * int
HugeInt HugeInt::operator*(int op2) const
{
    return *this * HugeInt(op2);
} 

//HugeInt * string
HugeInt HugeInt::operator*(const string &op2) const
{
    return *this * HugeInt(op2);
}

//HugeInt / HugeInt
HugeInt HugeInt::operator/(const HugeInt &divisor) const
{
    if (divisor.isZero())
    {
        cerr << "Error: Division by zero!" << endl;
        return HugeInt(0);
    }
    
    HugeInt quotient;
    HugeInt remainder = *this;
    HugeInt one(1);
    
    while (remainder >= divisor)
    {
        remainder = remainder - divisor;
        quotient = quotient + one;
    }
    
    return quotient;
} 

//HugeInt / int
HugeInt HugeInt::operator/(int op2) const
{
    return *this / HugeInt(op2);
} 

//HugeInt / string
HugeInt HugeInt::operator/(const string &op2) const
{
    return *this / HugeInt(op2);
}

// equality operator
bool HugeInt::operator==(const HugeInt &right) const
{
    return compare(right) == 0;
}

// inequality operator
bool HugeInt::operator!=(const HugeInt &right) const
{
    return compare(right) != 0;
}

// less than operator
bool HugeInt::operator<(const HugeInt &right) const
{
    return compare(right) < 0;
}

// greater than operator
bool HugeInt::operator>(const HugeInt &right) const
{
    return compare(right) > 0;
}

// less than or equal operator
bool HugeInt::operator<=(const HugeInt &right) const
{
    return compare(right) <= 0;
}

// greater than or equal operator
bool HugeInt::operator>=(const HugeInt &right) const
{
    return compare(right) >= 0;
}

// overloaded output operator
ostream& operator<<(ostream &output, const HugeInt &num)
{
    int i;

    for (i = 0; (num.integer[i] == 0) && (i <= HugeInt::digits); i++)
        ; // skip leading zeros

    if (i == HugeInt::digits)
        output << 0;
    else
        for (; i < HugeInt::digits; i++)
            output << num.integer[i];

    return output;
} 