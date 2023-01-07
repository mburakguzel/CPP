// One of the most powerful features of inheritance is that base class member functions are available at the derived class.
// But a drived class can override or redefine base class' methods.
// In order to redefine or override a method, you simply provide, a method in the derived class with the same name and signature as a method in the base class.

// STATIC BINDING:
    // By default, C++ does static binding of method calls. That means the compiler determines which method are called based on what it sees at compile time.
    // If compiler sees b is a defined as a base object, adn when we call b.deposit, it will call base classes' deposit.
    // Same is correct for derived object. If compiler sees d is a defined as a drived object, and when we call d.deposit, it will call derived classes' deposit.
    // But we can explicitly invoke Base::deposit from Derived::deposit. This is dynamic binding. This will be discussed in Polimorphism.

// MULTIPLE INHERITANCE: A complex topic which is out of scope!
    // This has not related with this example. This is another topic.
    // Multiple inheritance is inheriting a class from more than one classes.
    // How to define multiple inheritence:
    // class Savings_Account: public Account, public Administrator {
        // ...
    // }

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>

// Simple Account class
class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
protected:
    double balance;
public:
    Account();
    Account(double balance);            
    void deposit(double amount); 
    void withdraw(double amount);
};

#endif // _ACCOUNT_H_
