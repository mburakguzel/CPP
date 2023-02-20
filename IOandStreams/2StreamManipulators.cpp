// Can be used as member functions or as a manipulator:
    // std::cout.width(10);         // member function
    // std::cout << std::setw(10);  // manipulator
// To use manipulators, you must include #iomanip.

#include <iostream>
#include <iomanip>  // Must include for manipulators

int main() {

// BOOLEAN MANIPULATORS:  
// Default when displaying boolean values us 1 or 0.
// Sometimes the strings true or false are more appropriate.
// It is more common to use manipulators instead of the methods.

    std::cout << "noboolalpha - default  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "noboolalpha - default  (10 == 20) : " << (10 == 20)  << std::endl;
    
    // Set to true/false formatting for future outputs. All further values will be displayed this way (true-false).
    std::cout << std::boolalpha;    // change to true/false
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
    
     // setting still stays for future boolean insertions
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
    
    // Toggle to 0/1. All further values will be displayed this way (1-0).
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "noboolalpha  (10 == 20) : " << (10 == 20)  << std::endl;
    
    // Set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha); // std is the namespace, ios is the class and boolalpha is the flag that's defined in that class.
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
    
    // resets to default which is 0/1
    std::cout << std::resetiosflags(std::ios::boolalpha); // we are setting the default!
    std::cout << "Default  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "Default  (10 == 20) : " << (10 == 20)  << std::endl;

// INTEGER MANIPULATORS:
    int num {255};
 
    // Displaying using different bases - default is base 10 (dec).
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;  // base 16 - hexadecimal
    std::cout << std::oct << num << std::endl;  // base 8 - octal
    
    // Displaying showing the base prefix for hex and oct - hex values are shown starting with 0x and octal values are shown starting with 0. The default is not to show base.
        std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    
     // Display the hex value in uppercase - lowercase is the default.
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // Display the + sign in front of positive base 10 numbers. Default is not to display + sign.
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    
    // setting using the set method
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    // resetting to defaults
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "Enter an integer : ";
    std::cin >> num;
    
    std::cout << "Decimal default  : " << num << std::endl;
    
    std::cout << "Hexadecimal      : " << std::hex << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex  << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex << std::nouppercase << num << std::endl;

    std::cout << "Octal            : " << std::oct << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex << std::showbase << num << std::endl;
    std::cout << "Octal            : " << std::oct << num << std::endl;
    
    std::cout << std::endl << std::endl;

// FLOATING POINT MANIPULATORS:
    double num1 {123456789.987654321};
    double num2 {1234.5678};                     
    double num3 {1234.0};                          
 
    //using default settings - by default precision is 6 digits and rounding.
    std::cout << "--Defaults ----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 1.23457e+08
    std::cout << num2<< std::endl;	// 1234.57
    std::cout << num3<< std::endl;	// 1234
    
    //Note how since we can't display in precision 2 scientific notation is used
    std::cout << std::setprecision(2);
    std::cout << "--Precision 2----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 1.2e+08
    std::cout << num2<< std::endl;	// 1.2e+03
    std::cout << num3<< std::endl;	// 1.2e+03
    
    // Using precision 5
    std::cout << std::setprecision(5);
    std::cout << "--Precision 5----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 1.2346e+08
    std::cout << num2<< std::endl;	// 1234.6
    std::cout << num3<< std::endl;	// 1234

    // Using precision 9
    std::cout << std::setprecision(9);
    std::cout << "--Precision 9----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 123456790
    std::cout << num2<< std::endl;	// 1234.5678
    std::cout << num3<< std::endl;	// 1234

    // Using precision 3 and fixed - by default no fixed set size.
    std::cout << std::setprecision(3) << std::fixed;  // when fixed, the precision after the decimal part is set!
    std::cout << "--Precision 3 - fixed ----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 123456789.988
    std::cout << num2<< std::endl;	// 1234.568
    std::cout << num3<< std::endl;	// 1234.000
    
    // Using precision  3, fixed and scientific notation
    // Note precision is after the decimal
    std::cout << std::setprecision(3)<< std::scientific; // scientific notation is showing like 3e+10
    std::cout << "--Precision 3 - scientific  ----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 1.235e+08
    std::cout << num2<< std::endl;	// 1.235e+03
    std::cout << num3<< std::endl;	// 1.234e+03
    
    // Same but display capital 'E' in scientific 
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << "--Precision 3 - scientific - uppercase  ----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 1.235E+08
    std::cout << num2<< std::endl;	// 1.235E+03
    std::cout << num3<< std::endl;	// 1.234E+03
    
    // Show '+' symbol for positive numbers
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << "--Precision 3 - fixed - showpos ----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// +123456789.988
    std::cout << num2<< std::endl;	// +1234.568
    std::cout << num3<< std::endl;	// +1234.000
    
    
    // Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);
    
    // Show trailing zeroes up to precision 10    
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << "-- precision 10 - showpoint ----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 123456790.0
    std::cout << num2<< std::endl;	// 1234.567800
    std::cout << num3<< std::endl;	// 1234.000000

    // Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showpoint);

    std::cout << "--Back to defaults----------------------------" << std::endl;
    std::cout << num1 << std::endl;	// 1.23457E+08
    std::cout << num2<< std::endl;	// 1234.57
    std::cout << num3<< std::endl;	// 1234 
    
    return 0;
}