// GENERIC PROGRAMMING: 
    // Genering programing is writing code that works with a variety of types as arguments, as long as those argument types meet specific syntatic and semantic requirements.
    // Why generic programing is important: because if i have code that's written to be generic, then I should be able to use any types with that code as long as it makes sense and it should work.
    // Let's say that we typed a function which gets a number and returns square of it. With generic programing, I should be able to pass in any numeric type such as int, short int, long long, float, double etc.
    // But c++ compiler is statically typed, so it needs to know the type being passed into that function. If I create the function with an integer, I can not call it correctly with a double.
    // There are several ways to make this function work:

// GENERIC PROGRAMMING WITH MACROS
    // First one is macros. BE VERY CAREFUL WHEN YOU USE MACROS IN PRACTISE, ESPECIALLY MACROS THAT USE ARGUMENTS!
    // Macros are used more extensively in C code!
    // The include guards that we add our header files, we used pound(#) to define, that's a macro!
    // Macros begin with pound sign (#) and we know all directives that begin with the pound sign are preprocessor directives. We also know that the preprocessor does not know C++. So, there is no type information associated with macros.
    // Preprocessor is simple substituting (yerine koyma)!
// Example:
    // #define MAX_SIZE 100 // 100 has no type associated with it. There is no semicolon, if you add it will also be copied to variable!
    // #define PI 3.14159   // PI has no type associated with it.

    // if (num > MAX_SIZE)
    //     std::cout << "Too big";
    // double area = PI * r * r;

// The preprocessor will remove the PI and MAX_SIZE from our program and replace the with the assigned numbers. Above code will be transformed to below.
    // #define MAX_SIZE 100 // removed
    // #define PI 3.14159   // removed
    // if (num > 100)
    //     std::cout << "Too big";
    // double area = 3.14159 * r * r;

// Suppose we need a function to determine the max of 2 integers:            
// We can write a generic macro with arguments instead:
#include <iostream>
#define MAX(a, b) ((a > b) ? a : b)

// An example that macros fail: In order to fix this fail always use paranthesis while defining Macros.
    // But still do not use macros since it is processed by preprocessor and preprocessor does not know C++!
// #define SQUARE(a) a*a
#define SQUARE(a) ((a)*(a))   // this is the correct way to define a macro!

// Or we can make our code generic by overlapping functions:
int max(int a, int b){
    return (a > b) ? a : b;
}

double max(double a, double b){
    return (a > b) ? a : b;
}
                
char max(char a, char b){
    return (a > b) ? a : b;
} // ...

int main(){

    std::cout << MAX(10,20) << std::endl;   // 20
    std::cout << MAX(2.4,3.5) << std::endl;   // 3.5
    std::cout << MAX('A','C') << std::endl;   // C

    double result{0};
    result = SQUARE (5); // Expect 25
    std::cout << result << std::endl;   // This will show 25, but below code not!

    result = 100/SQUARE(5);  // expect 4, but remember preprocessing is simple substituting, this ends up as 100! 
    // But if you activate the correct way of declaring macro above, it shows 4.
    std::cout << result << std::endl;  

// Overlapping functions:
    int x = 100;
    int y = 200;
    std::cout << max(x,y); // shows 200!

    return 0;
}

    
    





