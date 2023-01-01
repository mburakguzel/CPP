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