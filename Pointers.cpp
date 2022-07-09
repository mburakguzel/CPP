#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    // A pointer is a variable that stores the address of another variablor or function.
    // The pointer must be defined as same type what it points to.
    // If we can use the variable or function itself directly, it is better to use it insted of the pointer. 
    // For example: we can not use a variable defined outside of a function in the function. Then we need to use pointers
    // Another example: we can allocate memory dynamically on the heap(yigin) or free store (the memory does not been occupied by a variable.)


    // DECLARE POINTERS
    int *int_ptr{}; // or
    double* double_ptr{nullptr}; // Both are okay.
    char *char_ptr{nullptr};
    unsigned long long *p3 {nullptr};
    vector<string>  *p4{nullptr};
    string *string_ptr{nullptr};

    // Always initialize the pointer, otherwise it contains garbage data!
    // nullptr means zero (points nowehere) and available after c++11

    // & AMPERSAND OPERATOR - ADDRESS OPERATOR
    int num{10};
    cout << &num << endl; // shows address of the num 0x61ff1c hexadecimal number (16 base)
    cout << sizeof num << endl; // shows size of the num in bytes!

    int *p{};
    cout << &p << endl; // shows the address of the pointer, not the address of the variable it point to!
    cout << sizeof p << endl; // shows the size of pointer p!

    // All pointers in a program have the same size no matter which type they point to! (4 bytes)

    int score{10};
    double high_temp{100.7};
       
    int *score_ptr {nullptr};
       
    score_ptr = &score;
    cout << "Value of score is: " << score << endl; // 100
    cout << "Address of score is: " << &score << endl; // a hexadecimal number
    cout << "Value of score_ptr is: " << score_ptr << endl; // same hexadecimal number
    
      // score_ptr = &high_temp;     // Compiler error since the types are different

    // DEFERENCE A POINTER
    // This is done by using asteriks operator again.

    int score {100};
    int *score_ptr {&score};

    cout << *score_ptr << endl;		// 100 // would show address of score if we used without asteriks!

    *score_ptr = 200;
    
    cout << *score_ptr << endl;		// 200
    cout << score << endl; 			// 200

    // Deferencin Pointers with vectors example
    cout << "\n------------------------------" << endl;
    vector<string> stooges {"Larry", "Moe", "Curly"};
    vector<string> *vector_ptr {nullptr};
    
    vector_ptr = &stooges;
    
    cout << "First stooge: " << (*vector_ptr).at(0) << endl;    // Larry
    
    cout << "Stooges: ";
    for (auto stooge: *vector_ptr)  
        cout << stooge << " ";
    cout << endl;

    // DYNAMIC MEMORY ALLOCATION
    // Using new to allocate storage from heap(yigin - bos hafiza)
    // If we allocate storage in infinite loop, program will give error since we run out of memory!

    int *int_ptr {nullptr};
    int_ptr = new int;               // allocate the int on the heap
    cout << int_ptr << endl;         // Displays memory address, if we type *int_ptr instead, will show garbage data since it does not point to anythin yet!
    *int_ptr = 100;                  // Now a variable is defined to point!
    cout << *int_ptr << endl;        // Displays 100
    delete int_ptr;                  // frees the allocated address

    // Another example: Allocating memory for an array!

    int *array_ptr{nullptr};
    int size {};
    
    cout << "How big do you want the array? ";
    cin >> size;
    
    array_ptr = new int[size];      // allocate the storage on the heap
    cout << array_ptr << endl;      // Shows the address of the first integer in the array!
    delete [] array_ptr;            // frees the alocated array! MUST BE USED AS THIS, NO VARIABLE IN SQUARE BRACkETS!

    // ARRAYS AND POINTERS
    // As we can remember when we cout an array, it was showing the address of the array. This is because when we create an array, it also becomes pointer with the same name!
    int scores[] {100, 95, 89};
    
    cout << scores << endl;    // 0x61fec8 
    cout << *scores << endl;   // 100
    
    int *score_ptr {scores};
    cout << "Value of score_ptr: " << score_ptr << endl; // 0x61fec8 same as scores, no need to define a pointer for arrays seperately!

    // Another feature of arrays and pointers:

    int scores[] {100, 95, 89};

    int *scores_ptr{scores};

        cout << "\nArray subscript notation -------------------------" << endl;
    cout << scores[0] << endl;      // show 100,
    cout << scores[1] << endl;      // show 95,
    cout << scores[2] << endl;      // show 89,
    
    cout << "\nPointer subscript notation -------------------------" << endl;
    cout << score_ptr[0] << endl;   // show 100, strange but true. Since c++ does not have true arrays!
    cout << score_ptr[1] << endl;   // show 95,
    cout << score_ptr[2] << endl;   // show 89,
    
    cout << "\nPointer offset notation-------------------------" << endl;
    cout << *score_ptr << endl;             // show 100, becouse of the asteriks!
    cout << *(score_ptr + 1) << endl;       // show 95,  this is the value in the next address!
    cout << *(score_ptr +2) << endl;        // show 89,  this is the value in the next address!

    cout << score_ptr  << endl;       // shows address 0x61ff10
    cout << (score_ptr + 1)  << endl; // shows address 0x61ff14
    
    cout << "\nArray offset notation-------------------------" << endl;
    cout << *scores << endl;         // 100 since scores normally shows address, dereferencing it shows value
    cout << *(scores + 1) << endl;   //  89 this is the value in the next address!


    // POINTER ARITHMATICS!

    int_ptr++; // Increments the pointer to point to next array element!
    int_ptr--; // Decrements the pointer to point to previos array element!

    int_ptr += n; // adds n times size of pointer`s type to memory allocated. We add as much as memory that this pointer address to n more number of integer.
                  // Also can be defined as adding n * sizeof(pointer`stype)  

    int_ptr -= n; // Decrements n times size of pointer`s type to memory allocated. We substract as much as memory that this pointer address to n more number of integer.
                  // Also can be defined as substracting n * sizeof(pointer`stype)  

    // Substracting pointers
    int n = int_ptr2 - int_ptr1; // if both pointers have same type, number of elements between the two pointers! Not work with different type of pointers!
    // Example
    char name[]  {"Frank"};
    
    char *char_ptr1 {nullptr};
    char *char_ptr2{nullptr};
    
    char_ptr1 = &name[0];   // F
    char_ptr2 = &name[3];   // n

    cout << "In the string " << name << ",  " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " <<  *char_ptr1  << endl;
    
    // Comparing pointers - remember compares addresses not the values!
    string s1 {"Frank"};
    string s2 {"Frank"};

    string *p1 {&s1};  		
    string *p2 {&s2};
    string *p3 {&s1};

    cout << p1 == p2 << endl;   // false
    cout << p2 == p3 << endl;   // true
    cout << *p1 == *p2 << endl;   // true since now we compare values in these addresses!

    // Another example!
    int scores[] {100, 95, 89, 68, -1};
    int *score_ptr {scores};
    
    while (*score_ptr != -1) {
        cout << *score_ptr << endl;
        score_ptr++;
    }

    // CONSTS AND POINTERS

    int high_score {100};
    int low_score{65};

    const int *score_ptr{&high_score};

    *score_ptr = 86;         // ERROR we can not change data that pointer points because of const
    score_ptr = &low_score;  // OK! However we can assign a new address to pointer!

    // Another case, const is after int
    int *const  score_ptr{&high_score};

    *score_ptr = 86;         // OK! Biz bunu degistirince high_score degeri de degisiyor mu?? Bence degismez!
    score_ptr = &low_score;  // ERROR this time address become constant!
    
    // Last case, const is after int
    const int *const  score_ptr{&high_score};

    *score_ptr = 86;         // ERROR!
    score_ptr = &low_score;  // ERROR!
}