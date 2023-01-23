// UNIQUE POINTERS:
    // Use unique pointers as often as you can, since they are simple efficient and in most cases they are drop ins for many of the common pointer use cases.
    // A unique pointer declaration uses a template parameter (std::inique_ptr<TemplateParameter>), which is the type of the object that the smart pointer will manage on the heap. So, this allows us to decleare unique pointer objects that points any type we need.
    // You can not have multiple unique pointers pointing to the same object on the heap.
    // Unique pointers can not be copied or assigned. So, their copy constructors and copy assignment operators are not available.
    // Since the ownership is unique you can guarantee that when the pointer goes out of scope, the object that it points to will automatically be cleaned up from the heap.
    // But unique pointers can be moved. So, they are great for placing in standard template library containers such as vectors.
    // Unique pointers as well as other smart pointer types allow us to point to user-defined types(classes).
// I_Printable is an interface explained in polymorphism, here we use dynamic polymorphism.

#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"


int main() {
    // Unique pointers can not be copied or assigned as mentioned before.
    {
    std::vector<std::unique_ptr<int>> vec;   // here we declare a vector that will contain unique pointers to integers.
    std::unique_ptr<int> ptr {new int{100}}; // Define a pointer which is a unique pointer to an int. Points to an integer on the heap which is initilized to 100.
    // vec.push_back(ptr);     // Error - copy not allowed. We can not pushback this unique pointer to vector becouse that imples a copy of the object!
    vec.push_back(std::move(ptr));  // we can use move semantics to move the object. ptr gives ownership of the pointer, and it is moved to the vector. The vector now owns the ponter and ptr will be set to null pointer.
    }  // automatically deleted

    // A better way of initializing a unique pointer, make_unique can be used after c++14. This function returns a unique pointer of the specified type and it allows us to pass initialization values into the constructor for the managed object.
    {
        std::unique_ptr<int> p1 = std::make_unique<int>(100);   // p1 is delclared as a uniqe pointer to the integer. Not need to use new keyword.
        std::unique_ptr<Account> p2 = std::make_unique<Savings_Account>("Curly", 5000); // p2 is a uniqe pointer to Account object. Not need to use new keyword.
        // auto p3 = std::make_unique<Player>("Hero", 100, 100);  // p3 is a uniqe pointer to Player object. We used auto keyword to let the compiler deduce the type of p3 based on what unique returns. Causes error since no player class is declared here.
    } // automatically deleted

    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000); // a1 is a base class pointer, we want dynamic polymorphosism here. Checking account is a concrete class here!
    std::cout << *a1 << std::endl; // dereferencing a1 gives us where it points to!
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts; // we are creating a vector of unique pointers.

    accounts.push_back(std::make_unique<Checking_Account>("James", 1000)); // adding new pointers to the vector. This was not possible in above example. Here we are not copying a pointer but declaring a pointer in vector!
    accounts.push_back(std::make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(std::make_unique<Trust_Account>("Bobby", 5000, 4.5));

    // for (const auto &acc: accounts) // this will not work with unique pointers, since unique pointers can not be copied!!! We need use references to pass by referance.
    for (const auto &acc: accounts) // we are using this range based for loop to print the accounts that we have.
        std::cout << *acc << std::endl;
    
    // METHODS OF UNIQUE POINTERS
    {
        std::unique_ptr<int> p1 {new int {100}};
        std::cout << p1.get() << std::endl; // 0x564388  get mothod returns a pointer to the manage object. Not used too much, can be used when using libraries working with raw pointers.
        p1.reset(); // p1 is now nullptr. Reset method sets the pointer as a null pointer and memory it points to will be released.
        // Below code is for checking if the pointer is initialized
        if (p1)
            std::cout << *p1 << std::endl;   // won't execute since p1 was set to a null pointer!
    }  // automatically deleted
    
    return 0;
}

