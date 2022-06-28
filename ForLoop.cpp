#include <iostream>
#include <vector>

using namespace std;

int main() {

    for (int i{1} ; i <=10 ; ++i) // initialize i to 1, untill i = 10 runs code under for and i++ at the end) i++ or ++i does not matter in this case!
    // for (int i = 1 ; i <=10 ; ++i) also correct!
        cout << i << endl;

    cout << endl;
    return 0;
}
// i is only usable in loop, not outside of the loop!

// Increasig 2 by 2 is also possible! 
//    for (int i{1} ; i <=10 ; i+=2)
//        cout << i << endl;

// Decresasing from 10 another way of using for loop
//    for (int i {10}; i > 0; --i)
//        cout << i << endl;
//    cout << "Blastoff!" << endl; // this line is not in for loop since there is no curly bracets. Some IDEs can create a warning for this!

// Also possible
//    for (int i{10}; i<=100; i+=10) {
//        if (i % 15 == 0) 
//            cout << i << endl;
//    }

// For loop with arrays:
    for (int i{0}; i<=10; i+=1) {
            cout << scores[i] << endl;
    }
// Be careful with the array size, otherwise program may give error!

// For loop with vectors
    vector<int> nums { 10,20,30,40,50};
    for (unsigned i{0}; i < nums.size(); ++i) // checks size of vector! This code may generate a warning size vector.size is unsigned int and i is int. Change i to unsigned to delete that warning.
        cout << nums[i] << endl;

// FOR LOOP WITH MULTIPLE INDEX
    for (int i{1}, j{5} ; i<=5 ; ++i, ++j)
        cout << i << " + " << j << " = " << (i+j) << endl;

// ENDLESS FOR LOOP
    for(;;)
        cout << "Endless loop" << endl;

// RANGE BASED LOOP // like for loop of python!
    int scores[] {10, 20, 30};
    
    for (int  score: scores) // we can use auto instead of int to make C++ decide which type to use.
        cout << score << endl;
// Another Ex; summing elemnts of a vector!
    vector<double> temperatures {87.9, 77.9, 80.0, 72.5};
    double average_temp {};
    double total {};
    
    for (auto temp: temperatures)
        total += temp;
    
    if (temperatures.size() != 0)
        average_temp = total / temperatures.size();
        
    cout << fixed << setprecision(1); // this shows only on digit after decimal point, raunds the value. <iomanip> library must be added to use this! 
    cout << "Average temperature is " << average_temp << endl;

// CONTINUE
// No further statement in the body of the loop are executed.
// Control immediately goes directly to the beginning of the next iteration.
    continue;
// BREAK
// No further statement in the body of the loop are executed.
// Loop is immediately terminated.
// Control immediately goes directly to the statement following the loop construct.
    break;