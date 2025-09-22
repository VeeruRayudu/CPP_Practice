#include<stdexcept>
#include "Veera_Sept22_task2_Account.h"

//constructor 
Account::Account(int balance){
    if(balance >= 0){
        accountBalance = balance;
    } else{
        accountBalance = 0;
        throw std::invalid_argument("initial balance is invalid");
    } 
}

//credit func definition
void Account::credit(int amount){
    accountBalance = getBalance() + amount;
}

//debit func definition
void Account::debit(int amount){
    if(amount <= getBalance()){
        accountBalance = getBalance() - amount;
    }else{
        throw std::invalid_argument("Debit amount exceeded account balance");
    }
}

//getter
int Account::getBalance() const {
    return accountBalance;
}

