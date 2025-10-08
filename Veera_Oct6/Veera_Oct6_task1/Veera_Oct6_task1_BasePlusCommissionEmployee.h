#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "Veera_Oct6_task1_CommissionEmployee.h"
using namespace std;

class BasePlusCommissionEmployee {
public:
    BasePlusCommissionEmployee(const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0);

    ~BasePlusCommissionEmployee();

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const; 
    void print() const;

    //accessors
    CommissionEmployee &getCommissionEmployee();
    const CommissionEmployee &getCommissionEmployee() const;

private:
    CommissionEmployee commissionEmployee; 
    double baseSalary;
};

#endif
