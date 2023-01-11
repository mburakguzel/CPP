// When we derive a class from a base class, we can redefine the base classes functions behaviours in the derived class. This creates a specializaed version of the function specific to the derived class.
// However, if we do not use the virtual keyword with these functions, then they are statically bound at compile time.
    // Redefined functions are bound statically.
    // Overriden functions are bound dynamically.
    // Virtual functions are overriden.
    // Virtual functions allow us to treat all objects generally as objects of the Base class.
// Virtual functions are dynamically bound only when we call them via a base class pointer or reference, otherwise they are statically bound.
// Whenever you have a virtual function, you need to have virtual destructors. Otherwise, compiler generates warnings.
// If a derived class is destroyed by deleting its storage via the base class pointer and the class a non-virtual destructor. Then, the behaviour is undefined in the C++ standards.
// If base class destructor is virtual then all derived class destructors are also virtual. We do not use the virtual keyword again, but it is better to use.
// We can not have virtual constructors.

#include <iostream>
#include <vector>

class Account {
public:
    virtual void withdraw(double amount) {  // we need to define the function that we want to overriden as virtual. 
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {  // The drived function will be implicitly virtual, no need to use virtual again. But this is the best practise. 
        std::cout << "In Checking::withdraw" << std::endl;  // Function signature and return type must match  exactly, otherwise compiler will consoder it as redefinition and statically bound.
    }
    
    virtual ~Checking() {  } // Whenever you have a virtual function, you need to have virtual destructors. Otherwise, compiler generates warnings.
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

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    // Since we design our polymorphism correctly, we will get correct withdraw method of each class. 
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    
    // Since we design our polymorphism correctly, we will get correct withdraw method of each class. 
    std::cout << "\n === Array ==== " << std::endl;
    Account *array [] = {p1,p2,p3,p4};
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);

    // Changin the first element to trust account, and we see correct withdraw method is called again.
    std::cout << "\n === Array ==== " << std::endl;
    array[0] = p4;
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);
    
    // If you work with raw pointers in vectors, it can be complicated. Better to use smart pointers. 
    std::cout << "\n === Vector ==== " << std::endl;
    std::vector<Account *> accounts {p1,p2,p3,p4}; // putting a new here to allocate memory, may cause problems since we need to free the hep in the loop.
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    // We add two Trust objects at the end of the vector, still works fine. 
    std::cout << "\n === Vector ==== " << std::endl;
    accounts.push_back(p4);
    accounts.push_back(p4);
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}