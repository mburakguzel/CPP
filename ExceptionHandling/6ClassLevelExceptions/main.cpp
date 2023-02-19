// Exceptions can be thrown from within a class:
    // Methods:
        // These work the same way as they do for functions as we have seen.
    // Constructor
        // Constructors may fail for many reasons and they can not return a value so we can not return a boolean or an error code.
        // An example to constructor fail: Suppose you are allocating memory dynamically and you are unable to allocate it.
        // Another example to constructor fail: if you open a file in the constructor but the file does not exist.
        // So throwing an exception from a constructer is good idea only for such cases (constructor failure), which means if you can not initialize an object.
    // Destructor:
        // DO NOT throw exceptions from destructor. The only time a destructor might throw an exception is if it handles it itself, and that's a very unlikely use case.

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "IllegalBalanceException.h"

using namespace std;

int main() {
    try {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0); // check Account.cpp to see how we throw an exception.
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << "Couldn't create account - negative balance" << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

