// Using base class references is very useful when we pass objects to functions by reference, and the function expect a reference to a base class object.
#include <iostream>


class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);     // since the withdraw function is a virtual function, this will be bounded dynamically.
}

int main() {

    Account a;
    Account &ref = a;
    ref.withdraw(1000);		    // In Account::withdraw

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);        // In Trust::withdraw

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;
   
    do_withdraw(a1, 1000);       // In Account::withdraw
    do_withdraw(a2, 2000);       // In Savings::withdraw
    do_withdraw(a3, 3000);       // In Checking::withdraw
    do_withdraw(a4,  4000);      // In Trust::withdraw

    return 0;
}