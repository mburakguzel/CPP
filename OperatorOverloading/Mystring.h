// Operator overloading is using traditional operators such as +,=,* etc. with user-defined types. Because this operatros are normally created for primitive data types such as (int, char etc.)
// Allows user defined types to behave similar to built-in types.
// Not done automatically (except assignment operator). They must be explicitly defined.
// These operators can be defined as member or a non-member method of an object, however we are used to use + as sum operator. So, whe do not we use it with our objects!
    // Assume, we have a class deined with name Number, we can define non-member functions or member functions as such:
    // Number result = multiply(add(a,b), divide(c,d)); or using member methods Number result = (a.add(b)).multiply(c.divide(d));
    // Instead overloaded operators: Number result = (a+b)*(c/d);
// The following operators can not be overloaded (::(double precision operator), :?(condition operator), .*(the pointer to member operator), .(dot operator), sizeof operator)

// Rules of overloading operaors:
    // Precedence and associativity of the overloaded operator can not be changed.
    // The arity cannot be changed. Can not make a binary operator unary or wise vesa.
    // We can not overload operators for primitive types.
    // Cannot create new operators.
    // C++ allows you to overload operators using global functions or member methods. However there are several operators that must be implemented as member methods such a [], (), -> and =(assignment operator)

// Defining our own string class
// Mystring.h
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                              // No-args contstructor
    Mystring(const char *s);                 // Overloaded contstructor              
    Mystring(const Mystring &source);        // Copy constructor
    ~Mystring();                             // Destructor
    void display() const;
    int get_length() const;                  // getters
    const char *get_str() const;
  
};

#endif // _MYSTRING_H_