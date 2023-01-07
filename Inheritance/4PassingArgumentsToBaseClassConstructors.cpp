// In the previous code, we mentioned that although we are calling the constructor with arg from derived class, it was calling nor args constructor from base.
// In this code, we will learn how to call the whatever constructor we want from base. 
// Passing arguments to base class constructors:
    // The base part of a Derived class must be initialized first.
    // How can we control exactly which Base class constructor is used during initialization.
        // We can invoke the whichever Base class constructor we wish in the initialization list of the Derived class.

#include <iostream>

// using namespace std;

class Base {
private:
    int value;
public:
   Base() : value {0}  { 
            std::cout << "Base no-args constructor" << std::endl; 
    }
    Base(int x)  : value {x} { 
            std::cout << "Base (int) overloaded constructor" << std::endl;
    }
   ~Base() { 
       std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived()
        :Base {}, doubled_value {0} {  // :Base added to call no arg constructor from base when it is called from derived class.
            std::cout << "Derived no-args constructor " << std::endl; 
    }
    Derived(int x) // :Base added to call constructor with args from base when it is called from derived class.
        :  Base{x},  doubled_value {x * 2} { 
            std::cout << "Derived (int) constructor" << std::endl; 
    }
    ~Derived() { 
        std::cout << "Derived destructor " << std::endl; 
    } 
};

int main() {
   //  Derived d;  // base non arg const, derived non args constr, derived destructor, base destructor.
   Derived d {1000}; // base with arg const, derived with args constr, derived destructor, base destructor.
    return 0;
}