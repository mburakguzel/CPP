// Mystring.cpp
#include <cstring>
#include <iostream>
#include <cctype>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    :str{nullptr} {      // creating an empty object with a pointer inside whch is called str! Initializin str a null pointer. str is in stack, *str(data it points to) is in heap)!
    str = new char[1];    // Allocating memory from heap for a char.
    *str = '\0';          // Typing an empty string (\0) to address where str points to by dereferencing
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    :str{nullptr} {
        if (s==nullptr) {  // just checking if somebody passed an empty string here with a null pointer!
            str = new char[1];
            *str = '\0';
        } else {           // normally this part of the constructor will be working.
            str = new char[std::strlen(s)+1];   // allocating 1 more than argument, since we are working with C strings here.
            std::strcpy(str, s);    // copying sended char s to str!
        }
}

// Copy constructor - Deep copy, not sharing!
Mystring::Mystring(const Mystring &source) 
    :str{nullptr} {
        str = new char[std::strlen(source.str )+ 1];
        std::strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)    // checking if there is a self assignment: means checking if we are assigning same parameter to same one! p1 = p1
        return *this;
    
    delete [] str;  // same with below code!
    // delete [] this->str;    // first we need to deallocate the space where str points to! otherwise when we copy the new data over, we will orphan(osuz birakmak) this memory and end up with a memory leak.
    str = new char[std::strlen(rhs.str) + 1];  // allocating enough storage from the heap! size of rhs(right hand side) + 1 (for string terminator for C strings!)
    std::strcpy(this->str, rhs.str);
    return *this;  // this allows us to support chain assignment s1 = s2 = s3. We are returning the reference not the pointer.
}

// Move assignment operator
Mystring &Mystring::operator=(Mystring &&rhs) {  // we use two ampersand operators here to tell the compiler that the right hand-side object is an r-value.
                                                 // rhs object can not be const, since we will be modifying that data! in line 58!  
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)   // checking if there is a self assignment: means checking if we are assigning same parameter to same one! p1 = p1
        return *this;
    delete [] str;  // first we need to deallocate the space where str points to! otherwise when we copy the new data over, we will orphan(osuz birakmak) this memory and end up with a memory leak.
    str = rhs.str;  // steal the pointer
    rhs.str = nullptr; // null out the pointer of rhs, otherwise it would be a deep copy!
    return *this;    
}

// Equality (Binary Operator - have an argument) 
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Make lowercase (Unary Operator!)
Mystring Mystring::operator-() const {   // const sincce we do not want to modify current object, instead we want to cerate a new object!
    char *buff= new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Concatentate (Binary Operator - have an argument) 
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1]; // we create a new object to copy the argument. we do not want to change the argument.
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};  // creating a temporary objact at the stack
    delete [] buff;
    return temp;
}  // object on the left hand side must be a member object of a Mystring class

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
const char *Mystring::get_str() const { return str; }