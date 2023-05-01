// There are even written books only for STL so all of it can not be covered! Check books!
// STL (Standard Template Library) includes powerful, reusable, adaptable, generic classes and and functions.
// STL is an assortment(karisim) of commonly used containers.
    // A container is an object that stores a collection of objects of a specific type. For example, if we need to store a list of names, we can use a vector.
// STL is extensible. (genisletilebilir)
// STL has three main elements:
    // Containers: are collection of objects or primitive(ilkel) types (array, vector, deque, stack, set, map etc.).
    // Algorithms: are functions for processing sequences of elements from containers such as find, max, count, accumulate, sort etc. STL has about 60 algorithms to use and extended to work with any type of data.
    // Iterators: generates sequences of element from containers. (forward, reverse, by value, by reference, constant etc.)
// Containers, Algorithms and Iterators are designed totally independent from one another.
// STL also contains a few more compenents such as functors and allocators but they will not be discussed!

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

#include <iostream>
#include <vector>     // allows us to work with vectors
#include <algorithm>  // allows us to use stl algorithms
#include <string>
#include <memory>       // we need to include the memory header file since it defines the smart pointer classes and functions we will use.
#include <numeric>      // should be added to use accumulate!



int main(){

    // A simple example:

    std::vector<int> v {1,5,3};
    std::sort(v.begin(), v.end());   // sort algorithm helps us to sort elements of a vector but it needs a sequence of objects to sort, that's where the iterator comes in. We provide the sequence using v.begin and v.end.
                                     // We can sort just about any stl container exactly the same way. Also, we can extend the sort algorithm to tell it exactly how to compare the elements when sorting.
                                     // v.begin and v.end are iterators here!
    for (auto elem: v)    // range based for loop to display sorted elements of vector! Range based for loop is a iterator itself!
        std::cout << elem << std::endl;

    std::cout << "------------Reverse---------------" << std::endl;
    std:reverse(v.begin(), v.end());  // reverse algorithm to reverse the objects (write the vector upside down!)
    for (auto elem: v)    // range based for loop to display sorted elements of vector!
        std::cout << elem << std::endl;    
    
    std::cout << "------------Sum---------------" << std::endl;
    int sum{};
    sum = std::accumulate(v.begin(), v.end(), 0); // parameters are where to start where to end and what is the initial value of sum respectively! If you want to sum doubles use 0.0!
                                                  // include numeric to use accumulate 
    std::cout << sum << std::endl;

    return 0;
}