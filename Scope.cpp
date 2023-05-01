#include<iostream>
using namespace std;

// There are three types od scopes in C++:
    // 1) Block scope defined in {} and is available in curlies


int main() {
    
    int num {100};  // Local to main
    int num1 {500}; // Local to main
    
    std::cout << "Local num is : " << num << " in main" << std::endl;
    
    {   // creates a new level of scope
        int num {200};  // local to this inner block
        std::cout << "Local num is: " << num << " in inner block in main" << std::endl; // prints out 200
        std::cout << "Inner block in main can see out - num1 is: " << num1 << std::endl; // checks num1 in outer block since there is not local num1
    }
    
    std::cout << "Local num is : " << num << " in main" << std::endl; // prints 100 since 200 is declared in another level of scope!
}
    
    // 2) Local scope static local variable are active and can be used between fuction calls.
    // static int value{10}; // being initialized to 0 if not initialized by user.

void local_example(int x) {
    int num {1000};     // local to local_example, 
    cout << "\nLocal num is: " << num << " in local_example - start" << endl;
    num=x;
    cout << "Local num is: " << num << " in local_example - end" << endl;
    // num1 in main is not within scope - so it can't be used here.
}

void static_local_example() {
    static int num {5000};      // local to static_local_example static - retains it value between calls. Only initialize very firs time, skip this line if function called again.
    cout << "\nLocal static  num is: " << num << " in static_local_example - start" << endl;
    num += 1000;
    cout << "Local static  num is: " << num << " in static_local_example - end" << endl;
}

int main() {
    

    local_example(10);
    // Displays: Local num is: 1000 in local_example - start
    // Displays: Local num is: 10 in local_example - end
    local_example(20);
    // Displays: Local num is: 1000 in local_example - start
    // Displays: Local num is: 20 in local_example - end    
    
    static_local_example();
    // Displays: Local static  num is: 5000 in static_local_example - start
    // Displays: Local static  num is: 6000 in static_local_example - end 
    static_local_example();
    // Displays: Local static  num is: 6000 in static_local_example - start
    // Displays: Local static  num is: 7000 in static_local_example - end 
    static_local_example();
    // Displays: Local static  num is: 7000 in static_local_example - start
    // Displays: Local static  num is: 8000 in static_local_example - end 

    cout << endl;
    return 0;
}


    // 3) Global scope: are available outside of the function or class as well.
int num {300};    // Global variable - declared outside any class or function

void global_example() {
    cout << "\nGlobal num is: " << num << " in global_example - start" << endl;
    num *= 2; // also modifies the global permanently, it becomes 600
    cout << "Global num is: " << num << " in global_example - end" << endl;
}

int main() {
    
    
    global_example();
    global_example();
    

    cout << endl;
    return 0;
}