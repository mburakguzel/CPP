// Access with public inheritence
    //    Base Class                   Derived Class
    //  public members         public and derived class has access
    //  protected members    protected and derived class has access
    //  Private  members        not accessible from derived class

// Access with protected inheritence
    //    Base Class                   Derived Class
    //  public members         protected and derived class has access
    //  protected members    protected and derived class has access
    //  Private  members        not accessible from derived class

// Access with private inheritence
    //    Base Class                   Derived Class
    //  public members         private and derived class has access
    //  protected members    private and derived class has access
    //  Private  members        not accessible from derived class

#include <iostream>

// using namespace std;

class Base {
    // Note friends of Base have access to all 
public:
    int a {0};
    void display() { std::cout << a << ", " << b << ", " << c << std::endl; } // member method has access to all
protected:          // This is how we define protected access specifier. Same as public and private.
    int b {0};          // Protected class members are accesible to all methods of the class itself.
                        // Also accesible from derived classes that derived from the same base class. 
                        // Not accesible, by objects of Base or derived classes.
private:            // Derived class can not gets the base's private members, but can not reach them!    
    int c {0};          
};

class Derived: public Base {
    // Note friends of Derived have access to only what Derived has access to

    // a will be public
    // b will be protected
    // c will not be accessible
public:
    void access_base_members() {
        a = 100;    // OK
        b = 200;    // OK  see above table for public inheritance!
     //   c = 300;    // not accessible
    }
    
};

int main() {
    
    std::cout << "=== Base member access from base objects ===========" << std::endl;
    Base base;    // when we debug with putting a breakpoint here, we will see base has all a, b and c. But no sccrd to b and c as seen below. They are inherited but not accesible!
    base.a = 100;   // OK
//    base.b = 200;   // Compiler Error because private and protected are same for objects.
//    base.c = 300;   // Compiler Error because it is private!
    
    std::cout << "=== Base member access from derived objects ===========" << std::endl;
    Derived d;   // when we debug with putting a breakpoint here, we will see base has all a, b and c. But no sccrd to b and c as seen below. They are inherited but not accesible!
    d.a = 100;  // OK
    // d.b = 200;  // Compiler Error
//    d.c = 300;  // Compiler Error
    return 0;
}

