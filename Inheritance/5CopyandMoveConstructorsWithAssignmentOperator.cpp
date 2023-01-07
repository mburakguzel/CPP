// Copy and move construcotrs and overloaded assignment operator are not automatically inherited from base class.
// We do not have to define these constructors and overloaded operators in the constructor depending on our design. The compiler will automatically call the one from base class.
// However, If we provide derived versions, we must invoke thes constructors and overloaded operators in base from our derived class explicitly!
// Be careful with raw pointers.
    // Especially if Base and Derived each have raw pointers.
    // Provide them with deep copy semantics.
#include <iostream>

// using namespace std;

class Base {
private:
    int value;
public:
   Base()
        : value {0}  { 
            std::cout << "Base no-args constructor" << std::endl; 
    }
    Base(int x) 
        : value {x} { 
            std::cout << "int Base constructor" << std::endl;
    }
    Base(const Base &other) // The compiler provided copy constructor is fine for this example. However, we just added this to see how it works.
        : value {other.value} {  // The move constructor works as same.
         std::cout << "Base copy constructor" << std::endl;     
    }
        
    Base &operator=(const Base &rhs)  {
    std::cout << "Base operator=" << std::endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }
            
   ~Base(){ std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived() : 
        Base {}  {
            std::cout << "Derived no-args constructor " << std::endl; 
    }
    Derived(int x) 
        : Base{x} , doubled_value {x * 2} { 
            std::cout << "int Derived constructor" << std::endl; 
    }
    Derived(const Derived &other)    // This pair of code must be added here to invoke the copy constructor from base explicitly.
        : Base(other), doubled_value {other.doubled_value} {    // The move constructor works as same. But also see below note in overloaded assignment.
         std::cout << "Derived copy constructor" << std::endl;     
    }
    
    Derived &operator=(const Derived &rhs) {
            std::cout << "Derived operator=" << std::endl;
        if (this == &rhs)
            return *this;    
        Base::operator=(rhs);   // It is important to handle base part first. If we do not explicitly call the base classes overloaded assignment operator, the base part will not be assigned!
        doubled_value = rhs.doubled_value; // Then assign the doubled_value! This two rules also applies for move constructor!!!
        return *this;
    }
   ~Derived(){ std::cout << "Derived destructor " << std::endl; } 
};


int main() {
//    Base b {100};   // Base Overloaded constructor(with arg)
//    Base b1 {b};    // Base Copy constructor
//    b = b1;         // base overloaded operator

    // Base destructor, Base destructor b - b1

    Derived d {100};    // Base Overloaded constructor(with arg), Derived Overloaded constructor(with arg), 
    Derived d1 {d};     // Base Copy constructor, Derived Copy Constructor
    d = d1;             // Derived overloaded operator, base overloaded operator

    // Derived  destructor, Base Destructor, Derived  destructor, Base Destructor, d - d1
    
    return 0;
}

