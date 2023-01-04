// Constructor:
    // In order to initialie an objec, constructors should be executed. Since derived classes has members and methods from bse classs, in order to initialize them the constructor of the base class should be executed first.
    // After that drive constructor should be executed.
// Destructor:
    // Class destructors are invoked in the reverse order as constructors. First derived class must be destroyed then base class constructor is invoked.
    // Each destructor should free resources allocated in it's own constructors. 

// A derived class does not inherit:
    // Base class constructors.
    // Base class destructors.
    // Base class overloaded assignment operators.
    // Base class friend functions.

// However, the derived class constructors, destructors, and overloaded assignment operators can invoke the base-calss versions.
// C++11 allows explicit inheritance of base 'non-special' constructors with 'using Base::Base;'(see below) anywhere in the derived class decleration. However, it is better to define constructors yourself.

#include <iostream>

// using namespace std;

class Base {
private:
    int value;
public:
   Base() : value{0} { std::cout << "Base no-args constructor" << std::endl; }
   Base(int x) : value{x} { std::cout << "Base (int) overloaded constructor" << std::endl; }
   ~Base(){ std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
    // using Base::Base; // this allows us to inherit non-special constructors from base. Coment this out to see below code woeks as intended (Derived d{1000};)
    // Special constructors are default constructor or copy constructor.
private:
    int doubled_value;
public:
    Derived() : doubled_value {0} { std::cout << "Derived no-args constructor " << std::endl; } 
    Derived(int x) : doubled_value {x*2}  { std::cout << "Derived (int) overloaded constructor" << std::endl; }
    ~Derived() { std::cout << "Derived destructor " << std::endl; } 
};

int main() {
//   Base b;
//    Base b{100};

//   Derived d; // base non arg const, derrved non args constr, 

Derived d {1000};  // generates error if derived int overloaded constructor is not defined.
// base no arg const (THIS IS BECAUSE WE DID NOT DEFINE IT EXPLICITLY IN DERIVED CONSTR. WE will see it in next video), derived non args constr, 
// Since it calls base no args constructor first, it sets value to 0. However, it should be 1000!!!
// After we enable using Base:Base, we make constructors inherited so it will work!
    
    return 0;
}