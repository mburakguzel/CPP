// Overloaded functions and overloaded operators are also polymorphism. These are considered as compile time polymorphism.
// Compile time / early binding / static binding all mean same thing. They simply mean before the program executes. Something compiler take cares of way before the program runs.
// Run time / late binding / dynamic binding all refer to the association of what the programmer wants to do with how to do it but at runtime.
// The default binding is static binding in order to make programs more efficient by making the binding during compile time.
// However, sometimes we want to defer(ertelemek, sonraya birakmak) decisions until run time. This can be done by using base class pointers or references and declaring our functions as virtual functions.
// There are two types of polymorphism in C++. Compile time and run time.
    // Compile time polymorphism includes what we have already learned in function overloading and operator overloading.
    // Run time polymorphism will be discussed in this section. Run time polymorphism can be achived by overriding functions, using inheritance, using virtual functions and then having base class pointers and references.
// An example to static binding, let's say we cerated a class Account and by inheriting this class we defined another class Savings. After that we defined a method 'withdraw' for each class.
// When we crete an object of both classes and call withdraw method, the method of each class will be called separetly. But this is decided before runtime.
    // Account a;
    // a.withdraw(1000);  // calls Account::withdraw

    // Savings b;
    // b.withdraw(1000);  // calls Savings::withdraw

// For dynamic polymorphism we must have:
    // Inheritance
    // Base class pointer or Base class reference
    // Virtual Functions

// Dynamic polimorphism example;
    // Account *p = new Savings();
    // p->withdraw(1000);      // this calls Account::withdraw(), however it should be Savings::withdraw()

// // Another example: Let's say Saving class given below is inherited from Account
//     void display_account(const Account &acc) {   // since the argument of this function is Account classs, all classes inherited from Account class can be passed to this function.
//         acc.display();    // however, it will always call Account::display unless dynamic polimorphism is used.
//     }

// Account a;
// display_account(a);

// Savings b;
// display_account (b);


#include <iostream>
#include <memory>  // included to use smart pointers.
class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello()  const {   
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj) {   // either drived or base function can be passed to this function. 
    std::cout << "Greetings: " ;
    obj.say_hello(); // But if we pass a derived objecct here, it will call base class say_hello method because static binding is default for C++. Since the arg is defined as Base.
}

int main() {
    Base b;
    b.say_hello();  // calls Base::say_hello
    
    Derived d;    // calls Derived::say_hello
    d.say_hello();
    
    greetings(b);  // calls Base::say_hello
    greetings(d);  // calls Base::say_hello even it is derived!
    
    Base *ptr = new Derived();
    ptr->say_hello();   // since ptr is a pointer to Base, this calls Base::say_hello
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>(); // This is also statically bounded. Calls Base::say_hello!
    ptr1->say_hello();   
    
    delete ptr;
    
    return 0;
}