#include <iostream> 
using namespace std; 

int main() 
{
// Show output. 
    //  std::cout << "Hello world!" << std::endl; // without defining std namespace above
    //  cout << "Hello world!" << std::endl; // with std namespace defined

    //  cout << "Hello";
    //  cout << "World!" << endl; // No space between Hello and World!

    //  cout << "Hello world!" << endl; // with space
    //  cout << "Hello" << " World!" << endl; // with space
    //  cout << "Hello" << " World!\n";   // same as above

// Move to next row for each word!
    //  cout << "Hello\nOut\nThere\n" << endl; // Shows each word in next row

// Ask input from user!
    //    int num1;
    //    cout << "Enter an integer: ";
    //    cin >> num1;
    //    cout << "You entered: " << num1 << endl;

// Enter two integers by pressing space between them
    int num1;
    int num2;
    cout << "Enter the first integer: ";  // Enter two integers by pressing space between them
    cin >> num1;
    cout << "Enter the second first integer: ";
    cin >> num2;
    cout << "You entered " << num1 << " and " << num2 << endl;
 
    return 0;  
}
