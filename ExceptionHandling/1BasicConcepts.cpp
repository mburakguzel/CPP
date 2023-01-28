// Writing exception safe code in c++ is extremely difficult. Only simple consepts will be explained.
// When and where to use excption handling in C++ is such a hotly debated(tartisilan) topic. (debate - tartisma, cekisme)

// What is exception handling?
    // Exceptions in C++ should be used only for synchronous code, not asynchronous code.
    // Exception handling is about dealing with extraordinary situations. How we define what an extraordinary situation is dependent on the application or designer.
    // There are different ways to deal with exceptions such as recover and continue or terminate the program. But we can decide how to terminate the program.

// What can cause extraordinary situations?
    // Insufficient resources: being out of memory or no external storage left.
    // Missing resources: we want to open and read a file but it does not exist.

// Terminology: it is consistent with other proggramming languages. However, the way it works with C++ tends to be different.
    // Exception: an object or primitive type(int, bool etc.) that signals that an error has occurred.
    // Throwing (raising) an exception: 
        // Your code detects that an error has occurred or will occur.
        // The place where where the error occurred may not know how to handle the error.
        // Code can throw an exception describing the error to another part of the program that knows how to handle the error.
    // Catching an exception: That is where catching an exception comes in:
        // Code that handles the execution.
        // May or may not cause the program terminate.

// Example:
    // Let's say we are allocating memory dynamically, however there is no memory left.
    // An exception can be thrown and some memory can be deallocated to solve this problem.

// Keywerds for exception handling:
    // throw:
        // Thrown an exception followed by an argument, which is the exception that we are throwing.
    // try {code that may throw an exception} keywrod is followed by a code block in curly braces.
        // The code that may throw an exception is placed in this curly braces.
        // If the code throws an exception, the try block is exited (the rest of the code in the block does not execute). If the code does not throw aan exception, then the code executes as normal.
        // C++ looks for a block of code that can handle that thrown exception.
        // If no catch handler exists the program terminates.
    // catch (type of exception object that handles) {code to handle the exception}
        // Catch block only execute if an exception is thrown and the type of the thrown exception matches the parameter in the catch block.
        // Can have multiple catch handlers that expect different types of exceptions.
        // May or may not cause the program to terminate.

#include <iostream>



int main() {    
    int miles {};
    int gallons {};
    double miles_per_gallon {};   
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;  // if we enter 0 here without exception handling codes in the program,    
    // std::cout << "Result: " << miles/gallons << std::endl;    // program crashes for this code.
    // std::cout << "Result: " << static_cast<double>(miles)/gallons << std::endl; // program gives inf as result, since deviding floating points to zero results inf. 0/0 results nan(not a number)

    try {
        if (gallons == 0)
            throw 0; // we throw the exeption here. Best practice to throw objects not primitives.
        miles_per_gallon = static_cast<double>(miles) / gallons; // if we throw exception above these two lines will not be executed.
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex) { // must be using same type with thrown argument (argument can be named as anyting we want.). If you do not catch the throw, program will be terminated.
        std::cerr << "Sorry, you can't divide by zero" << std::endl; // cerr is used to print error/warning messages in C++
    }

    std::cout << "Bye" << std::endl;

    return 0;
}
