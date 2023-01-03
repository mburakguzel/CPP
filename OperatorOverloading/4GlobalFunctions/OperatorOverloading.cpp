#include <iostream>
#include <vector>
#include "Mystring.h"

// using namespace std;

int main() {
    
    Mystring larry {"Larry"};
    larry.display();                                        // Larry
    
    larry = -larry;
    larry.display();                                        // larry
    
    std::cout << std::boolalpha << std::endl; // shows boolen values as true or false instead of 1 or 0
    std::cout << std::noboolalpha << std::endl; // shows boolen values as 0 or 1 instead of true or false
    Mystring moe{"Moe"};
    Mystring stooge = larry;
    
    std::cout << (larry == moe) << std::endl;             // false
    std::cout << (larry == stooge) << std::endl;          // true
        
  //  Mystring stooges = larry + "Moe";   
    Mystring stooges = "Larry" + moe;           // Now OK with non-member function. This was not okay with member functions.
    stooges.display();                                      // LarryMoe
    
    Mystring two_stooges = moe + " " + "Larry";     
    two_stooges.display();                               // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                            // Moe larry Curly             

    return 0;
}






