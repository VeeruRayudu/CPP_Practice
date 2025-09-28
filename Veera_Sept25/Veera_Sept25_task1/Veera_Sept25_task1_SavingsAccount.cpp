#include "Veera_Sept25_task1_SavingsAccount.h"

double SavingsAccount::annualInterestRate = 0.0;

// constructor initialization
SavingsAccount::SavingsAccount(double balance){
    savingsBalance = (balance>=0.0) ? balance : 0.0;
}

void SavingsAccount::calculateMonthlyInterest() {
    double monthlyInterest=(savingsBalance*annualInterestRate)/12;
    savingsBalance += monthlyInterest;
}

double SavingsAccount::getBalance() const {
    return savingsBalance;
}

void SavingsAccount::modifyInterestRate(double newRate) {
    annualInterestRate=(newRate>=0.0) ? newRate : 0.0;
}
