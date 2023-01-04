#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

class Savings_Account: public Account   // public used here is a access specifier, can be public, private or protected.                            
{                                       // This establishes a "is-a" relationship between Account and Savings_Account. Savings account have attributes and methods of Account class.
public:                                 // But it also can have other attributes and methods.
    double int_rate;
    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);   // these are special methods of savings account. Not coming from account.
    void withdraw(double amount);
};

#endif // _SAVINGS_ACCOUNT_H_
