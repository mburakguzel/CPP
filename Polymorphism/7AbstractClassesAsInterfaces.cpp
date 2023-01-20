// What is using a class as an interface?
    // An interface class is an abstract class that has only pure virtual functions.
    // These fucntions provide a general set of services to the user of the class.
    // These pure virtual functions must be declared as public.
    // Each subclass is free to override the pure virtual class and implement these services(methods) as needed.
    // Every service (method) must be implemened.
    // The service type information is strictly enforced (zorla yaptirmak).
    // Unlike java, C# and other languages, C++ does not provide a specific keyword or way to create an interface as part of the C++ core language.
    // So in C++, we use abstract classes with pure virtual functions to achieve the concept of an interface.
#include <iostream>

class I_Printable {  // this class is created to print user defined objects.
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj); // a friend function that we will use to allow us to print any type of object
    // that conforms to this interface. We are simply overloading the << operator here.
public:
    virtual void print(std::ostream &os) const = 0;  // this makes this class an abstract class.
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}


class Account : public I_Printable {  // any class to be printable, it must be derived from printable function and override the pure virtual function print that's
// in the printable interface.
// The capital I before printable is used to indicate that this is a interface class.
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override { // this must be overriden to grant dynamic polymorphism, otherwise the base classes print function will be called everytime.
        os << "Account display";
    }
    virtual ~Account() {  }
};

// We are doing the same thing, for all derived classes to make them printable.
class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Checking display";
    }
    virtual ~Checking() {  }
};


class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Savings display";
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Trust display";
    }
    virtual ~Trust() {  }
};

class Dog : public I_Printable {
public:
  virtual void print(std::ostream &os) const override {
        os << "Woof woof";
    } 
};

void print(const I_Printable &obj) {
    std::cout << obj << std::endl;
}


int main() {
    
    Dog *dog = new Dog();
    std::cout << *dog<< std::endl;  // prints woof woof
    
    print(*dog);  // prints woof woof
    
    Account *p1 = new Account();
    std::cout << *p1<< std::endl; // prints Account display
        
    Account *p2 = new Checking(); // prints Checking display        
    std::cout << *p2<< std::endl;  

//    Account a;
//    std::cout << a<< std::endl;
//    
//    Checking c;
//    std::cout << c << std::endl;
//
//    Savings s;
//    std::cout << s << std::endl;
//    
//    Trust t;
//    std::cout << t << std::endl;
        
    delete p1;
    delete p2;
    delete dog;
    return 0;
}
