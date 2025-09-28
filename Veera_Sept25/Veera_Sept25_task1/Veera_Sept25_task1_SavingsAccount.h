#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
    private:
    double savingsBalance;                 
    static double annualInterestRate;
    
    public:
    // constructor with initial balance
    SavingsAccount(double = 0.0); 

    void calculateMonthlyInterest();   

    double getBalance() const;        

    static void modifyInterestRate(double);
    
};

#endif
