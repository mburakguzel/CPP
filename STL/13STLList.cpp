// This document contains information about list and forward_list.
// These are both sequence containers and store their elements in non-contiguous memory.
// Contiguous memory allocation allows a single memory space to complete the tasks. On the other hand, non-contiguous memory allocation assigns the method to distinct memory sections at numerous memory locations.

// List and forward_list do not provide direct access to elements via the .at method or subscript operator.
// But they are very efficient when we need to insert and delete elements in the list once an element is found.
// List:
    // The list acts as a doubly linked list of elements, so we can go from element to element in either direction.
    // REMEMBER: List do not support direct element access.
    // Rapid insertation and deletion of elements anywhere in the container (constant time), once we have an iterator to one of the elements.
    // All iterators can be used with list.
    // Elements of list are not stored in contigious memory, they are stored separately but they have links to the elements before and after them.
    // That is why it's referred to as a doubly linked list.
    // We can efficiently remove and insert from anywhere in the list. All we really have to do is remove or insert the element and then re-link the links to the other elements around it.
    // If you need a container that you randomly add and remove elements but do not need to direct access to elemens, list is a good choice.

// Forward List:
    // Forward list was added to STL in C++11.
    // In order to use forward list we need to #include <forward_list> header file.
    // Forward list acts as a single linked list, so the list can only be traversed(elemanlar arasinda gezinmek) in one direction.
    // More efficint then list but only can be traversed in one direction.
    // Rapid insertation and deletion of elements anywhere in the container (constant time), once we have an iterator to one of the elements.
    // Does not support direct element access neither.
    // reverse iterators are not available for forward list.
    // Does not have concept of back, only has front method.
    // It has insert_after, emplace_after and erase_after methods so it adds a new element after an existig element not before.

#include <iostream>
#include <list> // in order to use list container, we need to add list header file.
#include <algorithm>
#include <iterator> // added for std::advance function

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
void display(const std::list<T> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1 =========================" << std::endl;

    std::list<int> l1 {1,2,3,4,5};
    display(l1);
    
    std::list<std::string> l2;
    l2.push_back("Back");       // Adds an element to end(back)
    l2.push_front("Front");     // Adds an element to top(front)
    display(l2);  // displays [ Front Back ]
    
    std::list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);  
    
    std::list<int> l4 (10, 100);
    display(l4);  // displays [ 100 100 100 100 100 100 100 100 100 100 ]
}

void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    std::cout << "Size: " << l.size() << std::endl;  // displays Size: 10 - returns number of element that are in the list
    
    std::cout << "Front : " << l.front() << std::endl; // displays Front : 1
    std::cout << "Back  : " << l.back() << std::endl;  // displays Back  : 10
    
    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl; // displays Size: 0
}

void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);  // displays [ 1 2 3 4 5 6 7 8 9 10 ]
    
    l.resize(5); //removes all elements after 5th element
    display(l);  // displays [ 1 2 3 4 5 ]
    
    l.resize(10);  // initializes new elements to 0 for integers
    display(l);    // displays [ 1 2 3 4 5 0 0 0 0 0 ]
    
    std::list<Person> persons;
    persons.resize(5);             // uses the Person default constructor
    display(persons); // displays [ Unknown:0 Unknown:0 Unknown:0 Unknown:0 Unknown:0 ] - because of the default constructor provided above.
    
}
void test4() {
    std::cout << "\nTest4 =========================" << std::endl;

    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end()) {
        l.insert(it, 100);    // insert method needs an iterator pointing to the element that we want to insert a new element before that element.
    }
    display(l); // displays [ 1 2 3 4 100 5 6 7 8 9 10 ]
    
    std::list<int> l2 {1000,2000,3000};
    l.insert(it, l2.begin(), l2.end());
    display(l); // displays [ 1 2 3 4 100 1000 2000 3000 5 6 7 8 9 10 ]
    
    std::advance(it, -4);       // point to the 100, it was pointing to 5 when we go -4 it points to 100!
    std::cout << *it << std::endl; // displays 100
    
    l.erase(it);                    // remove the 100 - iterator becomes invalid
    display(l);
    
}

void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    display(stooges);  // displays [ Larry:18 Moe:25 Curly:17 ]
    std::string name;
    int age{};
    std::cout << "\nEnter the name of the next stooge: ";
    getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;
    
    stooges.emplace_back(name, age); // creates an person object and adds it to stooges.
    display(stooges); // displays [ Larry:18 Moe:25 Curly:17 James:50 ]
    
    // Insert Frank before Moe
    auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if (it != stooges.end())
        stooges.emplace(it, "Frank", 18);
    display(stooges);     // displays [ Larry:18 Frank:18 Moe:25 Curly:17 James:50 ]
}

void test6() {
    std::cout << "\nTest6 =========================" << std::endl;
    
    std::list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    display(stooges); // displays [ Larry:18 Moe:25 Curly:17 ]
    stooges.sort();  // sorts depending on the overloaded < operator in person class defined above
    display(stooges); // displays [ Curly:17 Larry:18 Moe:25 ]
}


int main() {
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    std::cout << std::endl;
    return 0;
}

