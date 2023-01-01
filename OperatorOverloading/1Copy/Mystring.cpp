// Mystring.cpp
#include <cstring>
#include <iostream>
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

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
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

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
const char *Mystring::get_str() const { return str; }