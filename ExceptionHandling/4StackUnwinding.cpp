// When we run the below code, we call main to stack fisrt, then func a, func b and fun c respectively. Please see below call stack structure for the program:
// |fun c     |
// |__________|
// |fun b     |
// |__________|
// |fun a     |
// |__________|
// |main      |
// |__________|

#include <iostream>

void func_a();
void func_b();
void func_c();

void func_a() {
    std::cout << "Starting func_a" << std::endl;
    func_b();
    std::cout << "Ending func_a" << std::endl;
}

void func_b() {
    std::cout << "Starting func_b" << std::endl;
    // If we do not add this exception catcher code here, last line of this function will not execure either, since progrem will be looking for a exception catcher.
    // It will go back to func a and the latest line will not be executed either since there is not excpetion catcher neither.
    // The program will go back to main to find a exception catcher. So, if we have any destructor at the end of the functions it will not be called as well since the code after this line will not be executed.
    // This will cause a memory leak since you will not destruct the objects! Comment out below code to see different behaviour of the code.
    // /* // comment out this
    try {
        func_c();
    }
    catch (int &ex) {
         std::cout << "Caught error in func_b" << std::endl;       
    }
    // */ // comment out this
    // func_c();  // comment out this!
    std::cout << "Ending func_b" << std::endl;
}

void func_c()  {
    std::cout << "Starting func_c" << std::endl;
    throw 100;  // This function is done here since it does not catches its exception. THis function will be pulled off the stack right now.
    std::cout << "Ending func_c" << std::endl; // This line will not be executed since we throw an exception above.
}

int main() {    
    
    std::cout << "Starting main" << std::endl;
    try {
        func_a();
    }
    catch (int &ex) {
        std::cout << "Caught error in main" << std::endl;
    }
    std::cout << "Finishing main" << std::endl;
    return 0;
}

/* without exception catcher in func_c! This is called stack unwinding! (unwind -> cozmek, gevsetmek (sarili biseyi))
Starting main
Starting func_a
Starting func_b
Starting func_c
Caught error in main
Finishing main
*/

/* with an exception catcher in func_c!
Starting main
Starting func_a
Starting func_b
Starting func_c
Caught error in func_b
Ending func_b
Ending func_a
Finishing main
*/