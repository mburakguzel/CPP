// Overloading Move Operator
    // If you do not define a move constructor, compiler will use copy constructor by default.
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                              // No-args constructor
    Mystring(const char *s);                 // Overloaded constructor
    Mystring(const Mystring &source);        // Copy constructor
    Mystring(Mystring &&source);             // Move constructor
    ~Mystring();                             // Destructor
    
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);      // Move assignment
    
    void display() const;
    
    int get_length() const;            // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_
