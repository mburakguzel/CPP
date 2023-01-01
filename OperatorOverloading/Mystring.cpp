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

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
const char *Mystring::get_str() const { return str; }