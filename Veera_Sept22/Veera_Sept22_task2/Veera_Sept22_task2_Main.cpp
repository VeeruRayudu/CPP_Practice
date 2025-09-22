#include<iostream>
#include "Veera_Sept22_task2_Account.h"

int main(){
    Account account1(1000);
    Account account2(500);

    //displaying initial balance
    std::cout<<"Initial Balance of account1: "<<account1.getBalance()<<std::endl;
    std::cout<<"Initial Balance of account1: "<<account2.getBalance()<<std::endl;

    //credit operations
    account1.credit(500);
    std::cout<<"After crediting 500 to account1 the balance is "<<account1.getBalance()<<std::endl;

    account2.credit(500);
    std::cout<<"After crediting 500 to account2 the balance is "<<account2.getBalance()<<std::endl;

    //debit operations
    account1.debit(1000);
    std::cout<<"After debiting 1000 from account1 the balance is "<<account1.getBalance()<<std::endl;

    account2.debit(1000);
    std::cout<<"After debiting 1000 from account2 the balance is "<<account2.getBalance()<<std::endl;
}