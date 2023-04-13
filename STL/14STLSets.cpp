// Sets and maps are associative containers; associative containers are collections of stored objects that allow for fast retrievel using a key.
// Both sets and maps are implemented as a balnced binary tree or hashtag.
// Most operations are very efficient with sets and maps.
// There are 4 types of set containers:
    // Set
    // Unordered_set
    // multiset
    // Unordered_multiset
// The elements of set are ordered by key and no duplicated elements are allowed.
// All iterators are available (can be used) with sets.
// No concept of front and back in the set.
// Sets do not allow direct access to elements, so we can not use the sunscript or .at method.
// MULTI_SET:
    // A multiset is a set that is ordered by key but it allows duplicate elements.
// UNORDERED_SET:
    // The unordered set and unordered_multiset are in the <unordered_set> header file.
    // Elements are unordered and no duplicated elemnt is allowed.
    // Elements can not be modified in place. An element must be erased to insert new element.
    // No reverse iterators are allowed.
//  UNORDERED_MULTI_SET:
    // A multiset is a set that is not ordered and it allows duplicate elements.

#include <iostream>
#include <set> // in order to use a set or multi_set, we need to include the set header file.


class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(const std::set<T> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    // Sets
    std::cout << "\nTest1 =========================" << std::endl;
    std::set<int> s1 {1, 4, 3, 5, 2}; // will be ordered
    display(s1); // displays [ 1 2 3 4 5 ]
    // The set class uses the overloaded less than operator to determine if the element exist in the set.
    s1 = {1,2,3,1,1,2,2,3,3,4,5};  // duplicated elements will be ignored.
    display(s1);  // displays [ 1 2 3 4 5 ]

    std::set<std::string> stooges{
        std::string("Larry"),
        "Moe", // c-style string
        std::string("Curly"),
    };
    
    // No pushback, pushfront etc, since no back and front concept.
    // We can use insert or emplace methods to add element to sets.
    s1.insert(0);
    s1.insert(10);
    
    display(s1);  // displays [0 1 2 3 4 5 10 ]
    // The insert method returns a std pair.
    // The returned pair object has its first attribute as an iterator to the element that we just inserted or an iterator to the duplicate element that's already in the set.
    // Returns std::pair<iterator, bool> ==> iterator explainded above, bool indicates if insertation was succesfull or failure.
    if (s1.count(10)) // since no duplicated element is allowed, count let us know if an element exis in the set or not.
        std::cout << "10 is in the set" << std::endl;
    else
        std::cout << "10 is NOT in the set" << std::endl;

    auto it = s1.find(5); // defining an iterator which points to 5!
    if (it != s1.end())
        std::cout << "Found: " << *it << std::endl; // displays Found: 5  
        
    s1.clear();
    
    display(s1); // displays [ ]
}

void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    std::set<Person> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges); // displays  [ Larry:1 Moe:2 Curly:3 ]         // Note the order of display!  overloaded operator<- in the class defined above, sorts elements up to their ages.

    stooges.emplace("James", 50);   
    display(stooges);  // displays  [ Larry:1 Moe:2 Curly:3 James:50 ]

    stooges.emplace("Frank", 50); // NO -- 50 already exists
    display(stooges); // displays [ Larry:1 Moe:2 Curly:3 James:50 ]
    
    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it); // erasing Moe
    
    display(stooges); // displays [ Larry:1 Curly:3 James:50 ]
    
    it = stooges.find(Person("XXXX", 50));      // Will remove James!!!! since checks if 50 exists.
                                                                     // uses operator<
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges); 
}

void test3() {
    std::cout << "\nTest3 =========================" << std::endl;
    
    std::set<std::string> s {"A", "B", "C"};
    display(s);  // displays [A B C]
    
    auto result = s.insert("D"); // returns pair first iterator to D, second bool shows if the insertaion was successfull.
    display(s);  // displays [A B C D]
    
    std::cout << std::boolalpha;
    std::cout << "first: " <<  *(result.first)<< std::endl; // displays first: D
    std::cout  << "second: " << result.second << std::endl; // displays second: true
    
    std::cout << std::endl;

    result = s.insert("A");
    display(s); // displays [A B C D]
    
    std::cout << std::boolalpha;
    std::cout << "first: " <<  *(result.first)<< std::endl; // displays first: A
    std::cout  << "second: " << result.second << std::endl; // displays second: false - since A was already there.
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}

