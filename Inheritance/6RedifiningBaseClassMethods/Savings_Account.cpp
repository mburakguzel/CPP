#include "Savings_Account.h"

Savings_Account::Savings_Account(double balance, double int_rate)
    : Account(balance), int_rate{int_rate} {
        
    }

Savings_Account::Savings_Account() 
    : Savings_Account{0.0, 0.0} {
        
    }
    
void Savings_Account::deposit(double amount) {
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);  // This code will do exactly what deosit method does in Account class.
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate; // this is also redefined to printout interest rate additional to Account class.
    return os;
}