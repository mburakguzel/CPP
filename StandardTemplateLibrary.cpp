#include <iostream>
#include <vector>     // allows us to work with vectors
#include <algorithm>  // allows us to use stl algorithms
#include <string>
#include <memory>        // we need to include the memory header file since it defines the smart pointer classes and functions we will use.
#include <numeric>      // should be added to use accumulate!

using namespace std;     // DO NOT USE THIS IF YOU WANT TO BE A GOOD PROGRAMER!


int main(){
    // There are even written books only for STL so all of it can not be covered! Check books!
    // STL (Standard Template Library) includes powerful, reusable, adaptable, generic classes and and functions.
    // STL is an assortment(karisim) of commonly used containers (A container is an object that stores a collection of objects of a specific type. For example, if we need to store a list of names, we can use a vector.).
    // STL is extensible (genisletilebilir)
    // STL has three main elements:
        // Containers: are collection of objects or primitive(ilkel) types (array, vector, deque, stack, set, map etc.).
        // Algorithms: are functions for processing sequences of elements from containers such as find, max, count, accumulate, sort etc. STL has about 60 algorithms to use and extended to work with any type of data.
        // Iterators: generates sequences of element from containers. (forward, reverse, by value, by reference, constant etc.)
    // Containers, Algorithms and Iterators are designed totally independent from one another.
    // STL also contains a few mor compenents such as functors and allocators but they will not be discussed!
    // A simple example:

    std::vector<int> v {1,5,3};
    std::sort(v.begin(), v.end());   // sort algorithm helps us to sort elements of a vector but it needs a sequence of objects to sort, that's where the iterator comes in. We provide the sequence using v.begin and v.end.
                                     // We can sort just about any stl container exactly the same way. Also, we can extend the sort algorithm to tell it exactly how to compare the elements when sorting.
                                     // v.begin and v.end are iterators here!
    for (auto elem: v)    // range based for loop to display sorted elements of vector! Range based for loop is a iterator itself!
        std::cout << elem << std::endl;

    std:reverse(v.begin(), v.end());  // reverse algorithm to reverse the objects (write the vector upside down!)
    for (auto elem: v)    // range based for loop to display sorted elements of vector!
        std::cout << elem << std::endl;    
    
    int sum{};
    sum = std::accumulate(v.begin(), v.end(), 0); // parameters are where to start where to end and what is the initial value of sum respectively! If you want to sum doubles use 0.0!
                                                  // include numeric to use accumulate 
    std::cout << sum << std::endl;

    // TYPES OF CONTAINERS:
        // Sequence containers: array, vector, list, forward list, deque
        // Associative containers: insert elements in a predefined order or no order at all. E.g. set, multi set, map, multi map
            // A set is a collection of elements where there are no duplicates, but there may be an order associated with it or not. We have got the option to choose whatever one we want.
            // A map is like a dictionary, where we associate a word with its definition. 
            // There are many variants of this category such as ordered sets, unordered sets sets that allow dublicates, maps that allow dublicates and so forth.
            // These are very powerful data structures that are often underused.
        // Container adapters: are variation of other containers. stack, queue, priority queue.
            // This category does not support iterators so they can not be used with stl algorithms. But they are so commonly used in programming that the stl provides support for them.
    
    // TYPES OF ITERATORS:
        // Input iterators: from the container to the program. Make container elements available to your program.
        // Output iterators: from the program to container. Can iterate over a sequence and write an element to a container.
        // Forward iterators: navigate one item at a time in one direction. Can iterate forward over a sequence and can read or write any element.
        // Bi-directional iterators: Navigate one item at a time both directions. These are like forward iterators, but they can iterate a sequence in both directions.
        // Random access iterators: directly access a container item. can use the subscript operator to directly access elements. We saw that with vector class.
    
    // TYPES OF ALGORITHMS:
        // There are about 60 algorithms in STL. There are two major groups depending on whether the algorithm modifies the sequence:
            // Non-modifying algorithms:
            // Modifying algorithms:

    // GENERIC PROGRAMMING: 
        // Genering programing is writing code that works with a variety of types as arguments, as long as those argument types meet specific syntatic and semantic requirements.
        // Why generic programing is important: because if i have code that's written to be generic, then I should be able to use any types with that code as long as it makes sense and it should work.
        // Let's say that we typed a function which gets a number and returns square of it. With generic programing, I should be able to pass in any numeric type such as int, short int, long long, float, double etc.
        // But c++ compiler is statically typed, so it needs to know the type being passed into that function. If I create the function with an integer, I can not call it correctly with a double.
        // There are several ways to make this function work.
            // First one is macros. BE VERY CAREFUL WHEN YOU USE MACROS IN PRACTISE, ESPECIALLY MACROS THAT USE ARGUMENTS!
            // Macros are used more extensively in C code!
            // The include guards that we add our header files, we used pound(#) to define, that's a macro!
            // Macros begin with pound sign (#) and we know all directives that begin with the pound sign are preprocessor directives. We also know that the preprocessor does not know C++. So, there is no type information associated with macros.
            // Preprocessor is simple substituting (yerine koyma)!
            #define MAX_SIZE 100 // 100 has no type associated with it. There is no semicolon, if you add it will also be copied to variable!
            #define PI 3.14159   // PI has no type associated with it.

            if (num > MAX_SIZE)
                std::cout << "Too big";
            
            double area = PI * r * r;

            // The preprocessor will remove the PI and MAX_SIZE from our program and replace the with the assigned numbers. Above code will be transformed to below.
            // #define MAX_SIZE 100 // removed
            // #define PI 3.14159   // removed

            if (num > 100)
                std::cout << "Too big";
            
            double area = 3.14159 * r * r;

            // Suppose we need a function to determine the max of 2 integers:            
            // We can write a generic macro with arguments instead:
            #define MAX(a, b) ((a > b) ? a : b)
            std::cout << MAX(10,20) << std::endl;   // 20
            std::cout << MAX(2.4,3.5) << std::endl;   // 3.5
            std::cout << MAX('A','C') << std::endl;   // C

            // An example that macros fail: In order to fix this fail always use paranthesis while defining Macros: But still do not use macros since it is processed by preprocessor and it does not know C++!
            #define SQUARE(a) a*a
            // #define SQUARE(a) ((a)*(a))   // this is the correct way to define a macro!
            result = SQUARE (5); // Expect 25
            result = 5*5;        // Get 25
            // but
            result = 100/SQUARE(5);  // expect 4, but remember preprocessing is simple substituting 
            result = 100/5*5;        // GET 100

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

            int x = 100;
            int y = 200;
            cout << max(x,y);

            // Best way is function templates!
}