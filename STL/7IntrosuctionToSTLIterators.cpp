// Iterators allow us to think of a container as a sequence of elements, it does not matter what the container is.
// For example we might have a vector or a set or a map. These are all very different containers. But iterators allow us to process sequence of elements from these containers without worrying or even needing to know about how the container is implemented behind the scenes.
// Iterators are implemented as template classes, so we create iterator objects and use them to iterate through our containers.
// The syntax we use with iterators is similar to pointers. We can use dereference operator, the increment and the decrement operators and so forth. This was done intentionelly.
// C++ programmers are confortable with the pointer syntax and it is very easy to learn how to use iterators without learning some other arbitrary syntax.
// Most of the STL containers can be traversed (ileri geri gezinmek) with iterators, stack and queue are exceptions.
// Vectors allow us to access their elements randomly, however other containers do not allow us to randomly access elements like a vector does. So for those containers, iterators are necessary.
// Declare iterator: Iterators must be declared based on the container type they will iterate over.
    // std::vector<int>::iterator it1;         // iterate over a vector of integers
    // std::list<std:string>::iterator it2;    // iterate over a list of strings
    // std::map<std:string, std:string>::iterator it3;  // iterate over a map(maps are like dictioneries.) from strings to strings
    // std::set<char>::iterator it4;       // iterate over a set of chars

    // std::vector<int> vec {1,2,3};
        // 1 2 3 _ this is how it is stored.
        // vec.begin() referst to first element
        // vec.end referes to the locaton after last element!!! See Video 244 - 3:00. This is same for sets!
        // Let's say that we have a set. A set may or may not be iplemented in contiguous memory, it does not matter, and that is the point.

    // Initializing Iterators:
        // std::vector<int>::iterator it = vec.begin();  // it will point to the element 1 in the vector! If the vector had been empty, then it would point to vec.end.
    // or
        // auto it = vec.begin(); // compiler deduces the type!

    // Operations with iterators: (Assume 'it' is an iterator and i is an integer)
    // ++it                                       Pre-increment
    // it++                                       Post-increment
    // --it                                       Pre-decrement
    // it--                                       Post-decrement
    // it + i, it += i                            Increment
    // it - i, it -= i                            Decrement
    // it = it1                                   Assignment 
    // *it                                        Dereference
    // it->                                       Arrow operator
    // it == it1 or it != it1                     Comparison for equality
    // it < it1, it <= it1, it > it1, it >= it1   Comparison for magnitude


#include <vector>
#include <iostream>
#include <iterator> 

int main(){

    // An example:
    std::vector<int> vec {1,2,3};
    std::vector<int>::iterator it = vec.begin();

    while (it != vec.end()){
        std::cout << *it << " ";
        ++it;
    }   // 1 2 3
    std::cout << std::endl;
    // Another example with for loop: this is how the range based for loop works!
    for (auto it1 = vec.begin(); it1 != vec.end(); it1++){
        std::cout << *it1 << " ";
    }   // 1 2 3

    // Reverse iterator: Below code does not work on my PC!
    // works in reverse, last element is the first, first element is the last
    // ++ moves backword, -- moves forward.
    // std::vector<int>::reverse_iterator it2 = vec.begin();
    // while (it2 != vec.end()) {
    //     std::cout << *it2 << " ";
    //     ++it2;
    // }  // 3 2 1
}