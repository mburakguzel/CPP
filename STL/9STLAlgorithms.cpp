// STL algorithms work on sequences of elements that are otained from STL containers using STL iterators.
// There are around 90 algorithms.
// http://en.cppreference.com/w/cpp/algorithm for details of STL algorithms.
// Different containers support different types of iterators.
// All STL algorithms expect iterators as argument.

// Iterator Invalidation:
    // Iterators point to container elements.
    // An iterator may become invalid during processing.
    // Ex: Suppose we are iterating over a vector of 10 elements. And we clear() the vector while iterating, iterator does not know about this.
        // This will lead a undefined behaviour that the iterator is pointing to invalid locations.
    // Every STL container has documentatnion about when iterator becomes invalid.

#include <algorithm> // in order to use STL algorithms, we must include the algorithms header file. 
#include <iostream>
#include <vector>
#include <list>
#include <cctype> // we need this library for converting lowercase to uppercase.

class Person {
    std::string name;
    int age;
public:
    Person() = default; // default constructor
    Person(std::string name, int age) // overloaded constructor
        : name{name}, age{age}  {}
    // Below we overload operators to make algorithms work on our used defined data types.
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Find an element in a container: Find algorithm tries to locate the first occurrencec of an element in a container.
// If the function finds the element, it returns an iterator that points to the element it just found.
// If the function does not find the element, it will return an iterator poinitng to the end of the container.
// IMPORTANT NOTE: Find uses equality operator to match the variables. For, user defined data structures or objects we need to overload the equality operator as defined in Person class above.
// Check bool operator==(const ...)
void find_test() {
    std::cout << "\n========================" << std::endl;

    // Finding in vector:
    std::vector<int> vec {1,2,3,4,5};
    
    auto loc = std::find(std::begin(vec), std::end(vec), 1);  // start, end point that we will search and the value that we want to find.
    
    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc <<  std::endl;
    else 
        std::cout << "Couldn't find the number" << std::endl;

    // Finding in list:    
    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };
    
    // Finding in map:
    // IMPORTANT NOTE: Find uses equality operator to match the variables. For, user defined data structures or objects we need to overload the equality operator as defined in Person class above.
    // Check bool operator==(const ...)
    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20}); // here find algorithm checkes both Moe and 20, so I change this to "Moe", 12, it will not find anything.
    if (loc1 != players.end())
        std::cout << "Found  Moe" << std::endl;
    else
        std::cout << "Moe not found" << std::endl;
}

// For_each algorithm
void square (int x){
    std::cout << x*x <<" " ;
}

void for_each_test() {
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec {1,2,3,4};
    
    std::for_each(vec.begin(), vec.end(), square);

    // for_each using lambda expression:
    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x*x << " ";});
    // Lambda expressions were introduced in c++11 and they are widely used in modern C++.
    // In other languages, they are also called as closures, blocks or anynymous functions.
    // One of the benefits of lambda expressions is that we can define them right where they are being used.
}

// Count the number of elements in a container
void count_test() {
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,1,2,1};
     
    int num = std::count(vec.begin(), vec.end(), 1);   // counts how many times 1 appear in this container
    std::cout << num << " occurrences found" << std::endl;
}


// Count the number of occurences of an element in a container based on a predicate(condition) using a lambda expression
void count_if_test() {
    std::cout << "\n========================" << std::endl;

    // count only if the element is even
    std::vector<int> vec {1,2,3,4,5,1,2,1,100};
    int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x %2 == 0; });
    std::cout << num << " even numbers found" << std::endl;
    
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x %2 != 0; });
    std::cout << num << " odd numbers found" << std::endl;
    
    // how can we determine how many elements in vec are >= 5?
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x>=5;   });
    std::cout << num << "  numbers are >= 5" << std::endl;

}

// Replace occurrences of elements in a container
void replace_test() {
    std::cout << "\n========================" << std::endl;

     std::vector<int> vec {1,2,3,4,5,1,2,1};
     for (auto i: vec) {
         std::cout << i << " ";
     }
     std::cout << std::endl;
     
    std::replace(vec.begin(), vec.end(), 1, 100);   // replaces 1 with 100
    for (auto i: vec) {
         std::cout << i << " ";
     }
    std::cout << std::endl;
}

void all_of_test() {
    std::vector<int> vec1 {1,3,5,7,9,1,3,13,19,5};
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x > 10; })) // checks all of the elements one by one to see if they match with the given predicate (condition)
        std::cout << "All the elements are > 10" << std::endl;
    else    
        std::cout << "Not all the elements are > 10" << std::endl;
    
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x < 20; })) // checks all of the elements one by one to see if they match with the given predicate (condition)
        std::cout << "All the elements are < 20" << std::endl;
    else    
        std::cout << "Not all the elements are < 20" << std::endl;        
}

// Transform elements in a container - string in this example
void string_transform_test() {
    std::cout << "\n========================" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); // starts from begin to end, and start to store from begin, transfomrs lower to upper.
    std::cout << "After transform: " << str1 << std::endl;
}

int main() {
    find_test();
    // for_each_test();
    // count_test();
    // count_if_test();
    // replace_test();
    // all_of_test();
    // string_transform_test();

    return 0;
}
