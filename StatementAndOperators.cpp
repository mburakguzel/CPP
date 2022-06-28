#include <iostream> 
using namespace std; 

int main() 
{
// EXPRESSIONS:
    // 34 => literal
    // favorite_number => variable
    // 1.5 + 2.8 => addition
    // a = b assignment

// STATEMENTS
// Statement is a complete line of code that performs some action! Ends with a semi colon:
    // int num1{10};   // This is not an assignment, this is initialization
    int x; // decleration
    // favorite_number = 12; // Assignment

    // int num1{10};   // This is not an assignment, this is initialization.
    // num1 = "Burak"; // would cause an error
    // 100 = num1; // would cause an error
// Once a variable is declared, it can not be assigned to diffeent type of variable.

// ARITHMETIC OPERATORS
    int num1{10};
    int num2{20};
    int result{0};
    result = num1 + num2;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " + " << num2 << " = " << result << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << num2 << " / " << num1 << " = " << num2 / num1 << endl;
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;

// % is the mode operator, it shows the reminder (kalan)!
    num1 = 5;
    num2 = 3;
    cout << num1 << " % " << num2 << " = " << num1 % num2 << endl;

// Priority in aritmatic operations:
// PEMDAS ==> Paranthesis > Exponents > Multiplication > Devision > Add > Substratcion

// Making calculation with integer, will not show after decimal point!

// INCREMENT AND DECREMENT
    // counter++ = ++counter = counter + 1
    // counter-- = --counter = counter - 1
    int counter{10};
    cout << "Counter: " << counter << endl;
    counter = counter + 1;
    cout << "Counter: " << counter << endl;
    counter++;    // same with counter = counter + 1;
    cout << "Counter: " << counter << endl;
    ++counter;    // same with counter = counter + 1;
    cout << "Counter: " << counter << endl;

// Difference between prefix (++counter) and postfix(counter++):
    // int counter{10};
    result = 0;
    result = ++counter;  // means counter = counter +1 
                         // After that result = counter 
                         // result = 11, counter =11
    result = counter++;  // means result = counter  
                         // After that counter = counter +1 
                         // result = 10, counter = 11
    result = ++counter + 10;  // means counter = counter +1
                              // After that result = counter + 10
                              // result = 21, counter = 11
    result = counter++ + 10;  // means result = counter + 10 
                              // After that counter = counter +1 
                              // result = 20, counter = 11   

// TYPE CASTING
// when aritmatical operators are tried on different types of variables, c++ will convert one or give error.
// Short and char types are always converted to int.   

    int total_amount {100};
    int total_number {8};
    double average1{0.0};
    double average2{0.0};
    average1 = total_amount / total_number; // displays 12 since both total_amount and tottal_number are integers!
// but
    average2 = static_cast<double> (total_amount) / total_number; // displays 12.5
    cout << "The average is: " << average1 << endl;
    cout << "The average is: " << average2 << endl;
// Here we are casting total_amount but we can cast total_num as well. It does not matter.
// For older C++ codes:
    // (double)total = static_cast <double>(total); 
    
    return (0);
}
// EQUALITY CHECKS
   equal_result = (num1 == num2); // equal_result is true if num1 = num2, false if not
   not_equal_result = (num1 != num2); // equal_result is false if num1 = num2, true if not

// Also works with char and double
// Comparing 12 == 11.99999999 will give true!

// RELATIONAL OPERATORS
    // >   ==> greater than 
    // >=  ==> greater or equal
    // <   ==> less than
    // <=  ==> less tah nor equal
    // <=> ==> three way comparison acclipable for C++20

// LOGICAL OPERATORS
    // !   ==> not 
    // &&  ==> and
    // ||  ==> or

// "Not" has higher precedence than "and",// "and" has higher precedence than "or"  

// COMPOUND ASSIGNMENT OPERATORS
// Operator  Example   Meaning
//   +=        a+=b    a = a + (b)   
//   -=        a-=b    a = a - (b)  
//   *=        a*=b    a = a * (b)  
//   /=        a/=b    a = a / (b)  
//   >>=       a>>=b   a = a >> (b) // Tam anlamadim! 
//   <<=       a<<=b   a = a << (b) // Tam anlamadim!
//   &         a&=b    a = a & (b)  
//   ^         a^=b    a = a ^ (b)  // exponential
//   |         a|=b    a = a | (b)  
// Ex: a*b+c; means a*(b+c)
// Ex: cost += items*tax means cost = cost + (items*tax)

// For operator precedence, check online tables!

