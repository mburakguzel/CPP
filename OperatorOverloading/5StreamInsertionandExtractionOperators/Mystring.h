// Overloading Stream Insertion and Extraction Operator
    // It does not make sense to implement the insertion and extraction operators as member methods.
    // Because when we overload an operator as a member method, the left hand side object must be an object of the class we are overloading.
    // So we need to write the comment reverse as shown below: It would work but it is not recommended.
    // Mystring larry;
    // larry << cout;
    // or 
    // Player hero;
    // hero >> cin; 

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);       // Move assignment
    
    void display() const;
    
    int get_length() const;                                       // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_

