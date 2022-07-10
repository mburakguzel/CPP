#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    // References are different then pointers, they are a alias(sahte isim, takma isim) for a variable.
    // Must be initialized to a variable when declared.
    // Can not be null.
    // Once initialized, canot be made to refer to a different variable.

    int num {100};
    int &ref {num};
    
    cout << num << endl;    // 100
    cout << ref << endl;    // 100
    
    num  = 200;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;    // 200
    cout << ref << endl;    // 200
    
    ref = 300;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;    // 300
    cout << ref << endl;    // 300

    // Range based for loop with references!
    vector<string> stooges {"Larry", "Moe", "Curly"};

    for (auto str: stooges)     
        str = "Funny";              // str is a COPY of the each vector element
    
    for (auto str:stooges)        // No change, shows Larry, Moe, Curly
        cout << str << endl;
    
        cout << "\n---------------------------------" << endl;
    for (auto &str: stooges)  // str is a reference to each vector element
        str = "Funny";        // changes all of them to funny

    for (auto const &str:stooges)   // notice we are using const
        cout << str << endl;            // now the vector elements have changed

    // L values and R values
    // L values are the values that have names and addressable!
    int x{100}; // is a L value!

    100 = x; // is not an L value since it is not addressable!
    
    // R values are non-addressable and non-assignable!
    int x{100}; // 100 is a R value
    int y = x + 200; // x+200 is a R value!

    // L-value references
    int x{100};
    int &ref1 = x; // ref1 is reference to L-value

    int &ref2 = 100; // Error, 100 is an R-value!

    // Another example
        int square (int&n) {
            return n*n;
        }
        // in main
        int num{10};
        square(num); // OK!
        square(5); // NOT OK, CANT REFERENCE R_VALUE 5

    


}