//  Main.cpp
// Section 14
// Mystring - starting point
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor, with an arg.
    Mystring stooge {larry};             // copy constructor, copies larry to stooge 
    
    empty.display();
    larry.display();
    stooge.display();
    
    return 0;
}






