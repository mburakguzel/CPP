#include <iostream> 
using namespace std; 

int main() 
{
// Integer is a whole number  without decimal!
// Floating point is a whole number with a decimal point
// Ex: 5.5, 0.25 -103.142
// 31 or 0 is not floating point!
// 1.0 is a floating point number (If you define as 1 it becomes integer)
// 0.0 is a floating point number
// -0.0 is a floating point number. - will be ignored!

// VARIABLE TYPES
    // boolean       one byte(8 bits)   true or false
    // char          one byte(8 bits)   a single char, number or letter (There are 256 different chars)
    // int           at least 16 bits          whole number without decimal point
    // float         4 bytes            with decimal point, sufficient to store 7 decimal digits
    // double        8 bytes            same as float, 15 decimal digits
    // long double                      19 decimal points
    // string                           sequence of chars
    // char16_t      at least 16 bits
    // char32_t      at least 32 bits
    // short int     at least 16 bits 
    // long int      at least 32 bits
    // long long int at least 64 bits
// long double > double > float > unsigned long > long > unsigned int > int 

// Unsigned can be added before to all integer types (0 and positive integers).
// After short, long, long long, unsigned we do not have to type int!
// For signed integers we do not have type signed, it is automatically assigned as signed!

// If user enter a double to integer variable, program will not give any error but data become unreliable!
// This rule is same for all different kind of data types!    



// NAME VARIABLE
    // Variable names can contain nummbers, letters, 
    // First letter can not be a number, can be a letter or underscore.
    // C++ keywords can not be used as variable names.
    // C++ is case sensitive. AGE =! age

// DECLARE VARIABLE
    // int age = 21;
    // int age(21);
    // int age{21}; // This is suggested! 
    // int age{}; // use this if initial value is not important, program assigns automatically zero
// This is suggested because for only this type of decleration, compilers warns us for overflow. Not for other decleration types.
    // char middle_initial{'J'};
    // unsigned short int exam_score{55};
    // long people_in_florida{20610000};
    // long long people_on_earth{7600000000};
    // float car_payment{401.23};
    // double pi{3.14159};
    // long double large_amount{2.7e120}; (2.7x10^120)
    // bool game_over{true};

// Variables must be declared before they used in C++ program.
// Declare variables just before you use them, easy to track!

// Initalizing a value to a variable is important, if we do not, value can be anything!

// GLOBAL VARIABLES
    // Variables which are declared in functions are local variables. Variable which are declared out of the functions (even main) are global variables.
    // Global variables can be used in any function. They are automatically initialized to "0".

// SIZEOF - MIN - MAX
    //    cout << "char: " << sizeof(char) << endl; // gives us size of char occupies in memory for this machine in bytes!
    //    cout << "int: " << sizeof(int) << endl; // gives us size of int occupies in memory for this machine in bytes!
    //    cout << "float: " << sizeof(float) << endl; // gives us size of float occupies in memory for this machine in bytes!


    //    cout << "char: " << CHAR_MIN << endl; // gives minimum value that a char can get
    //    cout << "int: " << INT_MIN << endl;  // gives minimum value that an int can get
    //    cout << "float: " << SHRT_MIN << endl; // gives minimum value that a short can get

    //    cout << "char: " << CHAR_MAX << endl; // gives maximum value that a char can get
    //    cout << "int: " << INT_MAX << endl; // gives maximum value that an int can get
    //    cout << "float: " << SHRT_MAX << endl; // gives maximum value that a short can get

// In order to use the commands given abive, climits and cfloat libraries must be added to code.
//#include <climits>
//#include <cfloat>

// CONSTANTS
// A constant`s value can not be changed after declaration.

    // const variabletype(int, char, etc.) variablename = data;
    // const int width = 5;
    // const double pi {3.1415926}
    // #define pi 3.141592 (do not use this in modern C++)
    // const int days_in_year [365]; // array with size 365 but constantt
    


    return 0;  
}
