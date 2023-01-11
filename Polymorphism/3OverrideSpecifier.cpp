// We can override Base class virtual functions but the function signature and return must be exactly the same.
// If they are different then we have, this is redefenition not overriding.
// Redefinition is statically bound, overriding is dynamically bound.
// However, it is easy to make typo, and it is quite hard to find this error. Therefore it is better to use override specifier while overriding.
// C++ provides an override specifier to have the compiler ensure overriding. You can add this specifier to the method you are writing in your derived class, and the C++ compiler will ensure that you are indeed overriding not redefining.

#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    virtual void say_hello() const override  {             // Assume you did not put const here. This will be statically bound to base since signatrure is different. So, you do not override here instead redefinde.
        std::cout << "Hello - I'm a Derived class object" << std::endl; // Compiler will not generate any warning or error. But if you put that override specifier, compiler will generate an error if signature is different. So, you can not contine without fixing this problem.
    }
    virtual ~Derived() {}
};


int main() {
    
    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello()
    p2->say_hello();
    
    Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
    p3->say_hello();
    
   
    return 0;
}

