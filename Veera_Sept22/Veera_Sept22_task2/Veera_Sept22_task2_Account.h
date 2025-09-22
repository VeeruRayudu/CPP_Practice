#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
    private:
    int accountBalance;

    public:
    //constructor
    Account(int balance);

    //credit function
    void credit(int amount);

    //debit
    void debit(int amount);

    //getter
    int getBalance() const ;
};

#endif