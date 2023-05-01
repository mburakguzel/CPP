#include <iostream>

using namespace std;

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