#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

// using namespace std;

int main() { 
    
    // Use the Account class
    std::cout << "\n=== Account ==================================" << std::endl;
    Account acc {};
    acc.deposit(2000.0);               
    acc.withdraw(500.0);
    
    std::cout << std::endl;
    
    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

// Use the Savings Account class
    
    std::cout << "\n=== Savings Account ==========================" << std::endl;
    Savings_Account sav_acc {};
    sav_acc.deposit(2000.0);               
    sav_acc.withdraw(500.0);
    
    std::cout << std::endl;
    
    Savings_Account *p_sav_acc {nullptr};   // when you put a break point here and debug, you will see attributes ofAccount is also created under Savings_Account object.
    p_sav_acc = new Savings_Account();      // Because it was inherited from Account(parent) and has its attributes.
    p_sav_acc->deposit(1000.0);             // And balance and name initialized to 0 and An account since it was implemented as such in Account.cpp.
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;

    std::cout << "\n==============================================" << std::endl;
    return 0;
}

