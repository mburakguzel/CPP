#include <iostream>
#include <vector>
#include "Mystring.h"

// using namespace std;

int main() {
    std::cout << std::boolalpha << std::endl;
    
    Mystring larry{"Larry"}; 
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();                        // Larry
    moe.display();                          // Moe
    
    std::cout << (larry == moe) << std::endl;         // false
    std::cout << (larry == stooge) << std::endl;      // true

    larry.display();                        // Larry
    Mystring larry2 = -larry;               
    larry2.display();                       // larry
     
    Mystring stooges = larry + "Moe";       // ok with member function
    //Mystring stooges = "Larry" + moe;     // Compiler error
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();      
                                                   // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                //  Moe Larry Curly
    
    return 0;
}






