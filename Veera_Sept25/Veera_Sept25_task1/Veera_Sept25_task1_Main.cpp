#include<iostream>
#include<iomanip>
#include "Veera_Sept25_task1_SavingsAccount.h"

int main() {
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout<<std::fixed<<std::setprecision(2);
    std::cout<<"Balance after 1 month at 3% annual interest:"<<std::endl;
    std::cout<<"Saver1: $"<<saver1.getBalance()<<std::endl;
    std::cout<<"Saver2: $"<<saver2.getBalance()<<std::endl;

    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout<<"\nBalance after next month at 4% annual interest:"<<std::endl;
    std::cout<<"Saver1: $"<<saver1.getBalance()<<std::endl;
    std::cout<<"Saver2: $"<<saver2.getBalance()<<std::endl;

    return 0;
}
