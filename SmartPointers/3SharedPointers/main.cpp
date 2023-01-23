// SHARED POINTERS
    // Use shared pointers when you have more complex object management semantics, involving shared ownership.
    // Provides shared ownership of heap objects.
    // Like a unique pointer, a shared pointer points to an object on the heap as well. However, unlike a unique pointer, that heap object may be shared among many shared pointers.
    // So, we can have one heap object referenced by multiple shared pointers that manage it.
    // Unlike unique pointers, shared pointers can be copied and assigned. Also supports move semantics.
    // While unique pointers can be used to allocate arrays of objects on the heap, shared pointers do not support this by default.
    // Since there can be more than one shared pointer to an object, you may think how we can destroy the heap object: by counting references!
        // Every time we instantiate (kanit sunmak, orneklerle desteklemek, somutlastirmak (obje olsuturmak anlaminda burada)) a shared pointer object and have it point or reference to the heap object, we increment the counter.
        // This counter simply has the number of shared pointers referencing the heap object. When the reference count become 0, then we know nothing is referring to the heap object, and it can be safely destroyed.

#include <iostream>
#include <memory>
#include <vector>
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};


void func(std::shared_ptr<Test> p) {
    std::cout << "Use count: " << p.use_count() << std::endl;
}

int main() {

// HOW TO DECLARE SHARED POINTERS:
    {
        std::shared_ptr<int> p1 {new int {100}};   // p1 is a shared pointer to an integer which is created new on the heap!
        std::cout << *p1 << std::endl;      //100
        *p1 = 200;
        std::cout << *p1 << std::endl;     // 200
    } // automatically deleted, no need to delete the shared pointer!

// Shared pointers with user defined types:
    {
        std::shared_ptr<Account> p2 {new Trust_Account {"Larry"}};   // p1 is a shared pointer to an integer which is created new on he heap!
        std::cout << *p2 << std::endl;      // displays account
        
        p2->deposit(1000);
        p2->withdraw(500);
    } // automatically deleted, no need to delete the shared pointer! 

// A better way of declaring shared pointers. make_shared function is introduced at c++11. This function returns a shared pointer of the specified type and it allows us to pass initialization values into the constructor for the managed object
    {
        std::shared_ptr<int> p1 = std::make_shared<int>(100);   //  use:count: 1. p1 is declared as a shared pointer to the integer. Not need to use new keyword. This is efficient also for the compiler.
        std::shared_ptr<int> p2 {p1}; // use:count: 2. p2 is a shared pointer to integer. Copy constructor is used to initialize the p2 to p1. p1 and p2 refers to the same integer on the heap!
        std::shared_ptr<int> p3;  // p3 is a shared pointer initialized to nullptr. (There is no chance we create an unitialized or wild pointer when we use smart pointers.)
        p3 = p1;      // use.count: 3. Now, p3 alos refers to the same integer that p1 refers to.
    }  // automatically deleted. When the use_count becomes 0, the heap opject is deallocated. 

    // Shared pointers can be copied and assigned as mentioned before.
    {
    std::vector<std::shared_ptr<int>> vec;   // here we declare a vector that will contain shared pointers to integers.
    std::shared_ptr<int> ptr {new int{100}}; // Define a pointer which is a shared pointer to an int. Points to an integer on the heap which is initilized to 100.
    vec.push_back(ptr);     // Okay - copy is allowed. 
    std:: cout << ptr.use_count() << std::endl; // 2 Since the integer on heap is pointed by two pointers one ptr and one vec
    }  // automatically deleted, integer on the heap will be deleted.

    // METHODS OF SHARED POINTERS:
    // USE_COUNT - the number of shared_ptr objects managing the heap object
    {
        std::shared_ptr<int> p1 {new int {100}};   // p1 is a shared pointer to an integer which is created new on he heap!
        std::cout << p1.use_count() << std::endl;     // 1

        std::shared_ptr<int> p2 {p1};   // shared ownership - copy constructor!
        std::cout << p1.use_count() << std::endl;     // 2

        p1.reset();  // decrement the use_count; p1 is nulled out. Does not mean that we deallocate the integer on the heap! (with a unique pointer, this destroyes the heap object and set the unique pointer to null!)
        std::cout << p1.use_count() << std::endl;     // 0
        std::cout << p2.use_count() << std::endl;     // 1
    } // automatically deleted, integer on the heap will be deleted.

// -------------*------------*------------------------*------------------------*---------------------*------------------------*-----------------------------*------------------

   std::shared_ptr<int> p1 {new int {100} };
   std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 1
  
   std::shared_ptr<int> p2 { p1 };			// shared ownwership
   std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 2

   p1.reset();	// decrement the use_count; p1 is nulled out
   std::cout << "Use count: "<< p1.use_count() << std::endl; 		// 0 
   std::cout << "Use count: "<< p2.use_count() << std::endl; 		// 1
    
   std::cout << "\n==========================================" << std::endl;
   std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
   func(ptr);   // func is defined before main just to print how many times a ptr is defined.
   std::cout << "Use count: " << ptr.use_count() << std::endl;   // 1 since the p in func is terminated!
   {
       std::shared_ptr<Test> ptr1 = ptr;
       std::cout << "Use count: " << ptr.use_count() << std::endl;  // 2
       {
           std::shared_ptr<Test> ptr2 = ptr;
           std::cout << "Use count: " << ptr.use_count() << std::endl;     // 3 
           ptr.reset();
       }
       std::cout << "Use count: " << ptr.use_count() << std::endl;  // 0 since we reset ptr in above block and ptr1 and ptr2 was assigned to ptr.

   }
   std::cout << "Use count: " << ptr.use_count() <<std:: endl; // again 0 since ptr does not points to any object in the heap!

// -----------*-------------------*-----------------*----------------*-----------------*---------------------*-------------------------*----------------------*

    std::cout << "\n==========================================" << std::endl;
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1); // count is 1 since these point to different objects!
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);   // count is 1
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);  // count is 1
    
    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3); // count for acc1, acc2 and act3 becomes 2 here. Since both the vector accounts and acc# are pointing to the same object.
    
    for (const auto &acc: accounts) {
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl; // 2
    }

    std::cout << "==========================================" << std::endl;
    return 0;

    // What happens when these three pointers go out of scope, the vector is going to go out of the scope first, so it's going to be destroyed.
    // But the objects that the trust account, checking account and savings account objects on the heap won't be destroyed yet. 
    // Then when acc3 2 and 1 are destroyed, that's when the heap storage will be dynamically de-allocated. 
}

