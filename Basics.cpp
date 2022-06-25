// Part starts with # is called as preprocessor. This is a program that preprocess your program before compiler sees it.
// These directives starts with #(hashtag or paund) as shown below.
// #if #elif #else can be used to run only a pair of the code!
#include <iostream> // is a header file in which we have I/O library, without this we can not define I/O 
using namespace std; // if you type this at the beginning of your code you do not have to type std:: shown below everytime!

int main() // Computer always start from main! Every C++ program must have a main function! main must be typed in lowercase 
{
    std::cout << "Hello World" << std::endl; // std means standard. It is a namespace. Let`s say that cout is defined in any other libreay as well, program can get confused.
// I can define a new namespace with any name. Since there are lots of names defined in standard namespace, this can cause problems for bigger projects! Instead:
// std::cout std::cin std::endl can be used.  
    return 0;  // since main is defined as integer we add this to give 0 as a result. If program ends with 0, we can understand it works fine!
}
// When a code is run, main function is called by OS. There are two versions of main

int main() // Does not expect any information from OS
{
    return 0;  
}

int main(int argc, char *argv[]) // Expects information from OS. argc is number of parameters passed by OS. 
                                                             //argv argument vector data passed by OS! (bunch of strings!)
{
    return 0;  
}

/*
To build the code Terminal ==> Run Build Task or Ctrl+Shift+B, this creates an exe file!

Syntax error means something wrong with structure missin : or > etc.

Linker error means compiler fails to find an object or library used in project. For instance if we define a variable outside main but use it in main!

Run time error divide by zero, file not found

Semmatic error means this code does not make sense for compiler.

Printing a parameter w/o defining it creates warning.

Defining a parameter w/o using it also creates warning.

C++ has 90 keywords (include, cin, cout, favorite_number endl are not keyword, these are created by programmers.)

+, -, *, /, >>, <<, : are oprators.

;, }, "" are punctiotions.
*/