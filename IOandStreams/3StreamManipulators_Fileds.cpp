#include <iostream>
#include <iomanip>

void ruler() {
    std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
}

int main() {
    int num1 { 1234 };
    double num2 {1234.5678};
    std::string hello  {"Hello"};
    
    // Defaults
    std::cout << "\n--Defaults -------------------------------------------------------------------" << std::endl;
    ruler();  // displays whole number given above in ruler func. This is just to show us how many whitespaces there are.
    std::cout << num1 
                   << num2 // 6 digits of precison by default an it will round!
                   << hello 
                   << std::endl; // will display "1234.57Hello" by default! 
    
    // Defaults - one per line
    std::cout << "\n--Defaults - one per line-----------------------------------------------------" << std::endl;
    ruler();   // displays whole number given above in ruler func.
    std::cout << num1 <<std::endl;   // 1234
    std::cout << num2 << std::endl;  // 1234.57
    std::cout << hello << std::endl; // Hello
    
    // Set field width to 10 
    // Note the default justification is right for num1 only!
    std::cout << "\n--width 10 for num1-----------------------------------------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10)  << num1 // We create a field width of 10 for num1 on the console. So, on the console we will see 6 whitespaces before num1.
                                        // By default data is at the right hand side of the field.
                   << num2          
                   << hello 
                   << std::endl; // Displays "      12341234.57Hello"
    
    // Set field width to 10 for the first 2 outputs
    // Note the default justification is right for both
    std::cout << "\n--width 10 for num1 and num2------------------------------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << num1 // We create a field width of 10 for num1 on the console. So, on the console we will see 6 whitespaces before num1. (Data is on the right by default.)
                   << std::setw(10) << num2 // We create a field width of 10 for num2 on the console. So, on the console we will see 3 whitespaces before num2. (Data is on the right by default.)
                   << hello 
                   << std::endl; // Displays "      1234   1234.57Hello"
                  
    // Set field width to 10 for all 3 outputs
    // Note the default justification is right for all
    std::cout << "\n--width 10 for num1 and num2 and hello--------------------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << num1 // We set the width of num1 as 10 in our console. So, on the console we will see 6 whitespaces before num1. (Data is on the right by default.)
                  << std::setw(10) << num2  // We set the width of num2 as 10 in our console. So, on the console we will see 3 whitespaces before num2. (Data is on the right by default.)
                  << std::setw(10) << hello // // We set the width of hello as 10 in our console. So, on the console we will see 5 whitespaces before hello. (Data is on the right by default.)
                  << std::endl;  // Displays "      1234   1234.57     Hello"
                  
    // Set field width to 10 for all 3 outputs and justify all left
    std::cout << "\n--width 10 for num1 and num2 and hello left for all---------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << std::left << num1 // Data is on the left with std::left command!
                   << std::setw(10) << std::left << num2  // Data is on the left with std::left command!
                   << std::setw(10) << std::left <<  hello // Data is on the left with std::left command!
                   << std::endl; // Displays "      1234   1234.57     Hello"
                  
    // setfill to a dash
    // this is persistent
    // Then repeat the previous display
    std::cout << std::setfill('-');  // by this command, we are replacing white spaces with dashes. Do not have to add all one by one. This is a permanent change.
    std::cout << "\n--width 10 for num1 and num2 and hello left for all setfill to dash------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << std::left << num1 
                   << std::setw(10) << std::left << num2  
                   << std::setw(10) << std::left <<  hello 
                   << std::endl; // Displays "1234------1234.57---Hello-----"
//    
    // Set width to 10 for all, left justify all and cary the setfill character
    std::cout << "\n--width 10 for num1 and num2 and hello - setfill varies------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << std::left << std::setfill('*') << num1 
                  << std::setw(10) << std::left << std::setfill('#' )<< num2  
                  << std::setw(10) << std::left <<  std::setfill('-') << hello 
                  << std::endl; // Displays "1234******1234.57###Hello-----"
//    
    std::cout << std::endl << std::endl;
    return 0;
}