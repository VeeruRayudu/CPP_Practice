#include <iostream>
#include "Veera_Oct6_task1_BasePlusCommissionEmployee.h"
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary )
    : commissionEmployee(first, last, ssn, sales, rate) 
{
    setBaseSalary(salary);
    cout << "BasePlusCommissionEmployee constructor:" << endl;
    print();
    cout << "\n\n";
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
    cout << "BasePlusCommissionEmployee destructor:" << endl;
    print();
    cout << "\n\n";
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + commissionEmployee.earnings();
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried ";
    commissionEmployee.print(); 
    cout << "\nbase salary: " << getBaseSalary();
}

// accessors
CommissionEmployee &BasePlusCommissionEmployee::getCommissionEmployee() {
    return commissionEmployee;
}
const CommissionEmployee &BasePlusCommissionEmployee::getCommissionEmployee() const {
    return commissionEmployee;
}
