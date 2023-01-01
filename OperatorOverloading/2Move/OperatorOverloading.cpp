#include <iostream>
#include <vector>
#include "Mystring.h"

// using namespace std;

int main() {
    Mystring a {"Hello"};                // overloaded constructor
    a = Mystring{"Hola"};                // Overloaded constructor then move assignment
    a = "Bonjour";                       // Overloaded constructor then move assignment
    
/*  
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};             // copy constructor 
    Mystring stooges;                    // no-args constructor
    
    empty = stooge;                      // copy assignment operator
    
    empty.display();                      // Larry : 5
    larry.display();                      // Larry : 5
    stooge.display();                     // Larry : 5
    empty.display();                      // Larry : 5
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();                              // Larry, Moe, and Curly : 21
    
    std::vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    std::cout << "=== Loop 1 ==================" << std::endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                        // Larry
                                                                // Moe
                                                                //Curly
    std::cout << "=== Loop 2 ==================" << std::endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";                              // copy assignment
        
    std::cout << "=== Loop 3 ================" << std::endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                     // Changed
                                                            // Changed
                                                            // Changed
*/    
    return 0;
}






