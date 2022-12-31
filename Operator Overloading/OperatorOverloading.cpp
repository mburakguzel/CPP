// Operator overloading is using traditional operators such as +,=,* etc. with user-defined types.
// Allows user defined types to behave similar to built-in types.
// Not done automatically (except assignment operator). They must be explicitly defined.
// These operators can be defined as function or object method, however overloading operators make our code more readable.
// The following operators can not be overloaded (::(double precision operator), :?(condition operator), .*(the pointer to member operator), .(dot operator), sizeof operator)

// Rules of overloading operaors:
    // Precedence and associativity of the overloaded operator can not be changed.
    // The arity cannot be changed. Can not make a binary operator unary or wise vesa.
    // We can not overload operators for primitive types.
    // Cannot create new operators.
    // C++ allows you to overload operaors using global functions or member methods.

// Defining our own string class
// Mystring.h
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                            // No-args contstructor
    Mystring(const char *s);                         // Overloaded contstructor              
    Mystring(const Mystring &source);        // Copy constructor
    ~Mystring();                                          // Destructor
    void display() const;
    int get_length() const;                           // getters
    const char *get_str() const;
  
};

#endif // _MYSTRING_H_

// Mystring.cpp
#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
     : str{nullptr} {
        str = new char[std::strlen(source.str )+ 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
 const char *Mystring::get_str() const { return str; }


//  Main.cpp
// Section 14
// Mystring - starting point
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    
    empty.display();
    larry.display();
    stooge.display();
    
    return 0;
}






