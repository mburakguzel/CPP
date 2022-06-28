#include <iostream> 
#include <iomanip>
using namespace std; 

int main() 
{
// Show output. 
    //  std::cout << "Hello world!" << std::endl; // without defining std namespace above
    //  cout << "Hello world!" << std::endl; // with std namespace defined

    //  cout << "Hello";
    //  cout << "World!" << endl; // No space between Hello and World!

    //  cout << "Hello world!" << endl; // with space
    //  cout << "Hello" << " World!" << endl; // with space. Adding endl and \n moves to next row for the next output. 
    //  cout << "Hello" << " World!\n";   // same as above
// Difference between \n and endl is that endl flushes the stram (akisi bosaltiyor), while \n does not!
// cin and cout have an associated buffer which in an area in memory where the data that we read or write is stored temporarily. When we flush the buffer, it simply cleans the buffer.

// Move to next row for each word!
    //  cout << "Hello\nOut\nThere\n" << endl; // Shows each word in next row

// Ask input from user!
    //    int num1;
    //    cout << "Enter an integer: ";
    //    cin >> num1;
    //    cout << "You entered: " << num1 << endl;
// If one type spaces before or after the input, program would ignore them.

// Show variables in output
    // int num1;
    // int num2;
    // cout << "Enter the first integer: ";  // Enter two integers by pressing space between them
    // cin >> num1;
    // cout << "Enter the second integer: ";
    // cin >> num2;
    // cout << "You entered " << num1 << " and " << num2 << endl;

// Enter two values by pressing space 
    // int num1;
    // int num2;
    // cout << "Enter 2 integers separated with space: ";
    // cin >> num1 >> num2;
    // cout << "You entered " << num1 << " and " << num2 << endl; 

// Enter a double
    //    double num3;
    //    cout << "Enter a double: ";
    //    cin >> num3;
    //    cout << "You entered: " << num3 << endl;

// If user enter a double to integer variable, program will not give any error but data become unreliable!
// This rule is same for all different kind of data types!

// MATH OPERATION CAN BE USED IN cout
//    cout << "The area of the room is: " << room_length*room_width << " square feet" << endl;

// Show only one digit after decimal point!

    cout << fixed << setprecision(1); // this shows only on digit after decimal point, raunds the value. 
    #include <iomanip> library must be added to use this!  


    return 0; 
}
