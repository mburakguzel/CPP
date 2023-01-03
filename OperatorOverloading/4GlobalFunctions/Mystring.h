// Overloading Operators with Global Functions
    // Since we do not have this pointer as member functions does, we need do define global functions as a friend to classes.
    // Using getter member functions is also possible, but mostly we see them implementes as friends. 
    // For unery operators we need to define one object in parameter list (arguments of function). For binary two objects.
    // We can not use member function and global function at the same time for overloading the same operator! 

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {  // functions are defined as friend to make them reach elements of class
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);  // since this is not a member function, it needs two args, two objects to compare! 
    // For member functions, they need only one since one is the class that member function(method) belongs to!
    friend Mystring operator-(const Mystring &obj); // unary operator needs one object only!
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs); // again binary operator, needs 2 args!
private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring( Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
   
    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif // _MYSTRING_H_

