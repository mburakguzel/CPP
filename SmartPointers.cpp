#include <iostream>
#include <vector>
#include <string>
#include <memory>        // we need to include the memory header file since it defines the smart pointer classes and functions we will use.

using namespace std;     // DO NOT USE THIS IF YOU WANT TO BE A GOOD PROGRAMER!

// DECLARE CLASSES

int main(){
    // Problems with raw pointer:
        // Uninitialized (wild) pointers.
        // Memory leaks (when we do not de-allocate the storage that we previously allocated on the heap.)
        // Dangling pointers: one pointer is pointing to storage that it thinks is valid but in fact has already been de-allocated.
        // Not exeption safe: our program could throw an exception and the code that releases our allocated memory never execute and we leak memory.
    // Smart pointers can help us prevent these types of errors, they can help us be more clear about who owns the pointer and when a pointer should be deleted to free up allocated memory.

    // WHAT ARE SMART POINTERS?
    // Smart pointers are objects. Smart pointers are implemented as c++ template class which we can instantiate (kanit gostermek, orneklendirmek).
    // Smart pointers can only point to heap allocated memory, and they automatically call delete when that`s no longer needed.
    // Smart pointers adhere to RAII (resource acquisition is initializatin) princiles. When a resource-owing stack object goes out of scope, its destructor is automatically invoked. In this way, garbage collection in C++ is closely related to object lifetime.
    // Smart pointer types:
        // Unique pointers (unique_ptr)
        // Shared pointers (shared_ptr)
        // Weak pointers (weak_ptr)
        // Auto pointers (auto_ptr)  deprecated (onaylanmamis, karsi cikilmis) KULLANILMASI ONERILMIYOR!
    
    // WHAT IS RAII?
        // RAII (areyayay - areydubleay) == Resource Acquisition is Initialization
        // RAII objects are allocated on the stack.
        // Acquisiton means: RAII objects will acquire (elde etmek, edinmek, sahip olmak) some sort of resource, tht could be opening a file, allocating memory, acquiring a lock and so forth.
        // Initialization means: the resource is acquired at object initialization time. In other words, it happens in the object's constructor.
        // At some point, we need to relinguish (feragat etmek, el cekmek) that source that we acquired and that happens in the destructor. Here we can close the file, de-allocate any allocated memory release locks and so forth.
        // Smart ointers a re example of RAII classes.
    
    // DEFINE SMART POINTER
    // First, we need to include the memory header file since it defines the smart pointer classes and functions we will use. 
    // Smart pointers are implemented as c++ class template, very similar to the vecotrs!
    // Smart pointers are basically wrapper (wrap (sargi, sarmak) - wrapper (esarp, atki)) classes that contain and manage a raw pointer.
    // The actual implementation of smart pointers are compiler dependent.
    // The smart pointer classes provide overloaded dereference and member selection operators as well as methods to get the raw pointer and more.
    // However, you can not do pointer arithmatic on smart pointers, like you can with raw pointers.
    // Smart pointers have custom deleters where we can explicitly define the exact behaviour we want when the pointer is about to be destroyed.

#include <iostream>
#include <memory>
#include <vector>


class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main() {
    // Test *t1 = new Test {1000}; // This is a raw pointer example.
    // delete t1;                  // If we do not type this statement, it will cause a memory lickage!
    std::unique_ptr<Test> t1 {new Test{100}};
    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
  
    std::unique_ptr<Test> t3;
    // t3 = t1; // genereates an error since we can not assign smart pointers.
    t3 = std::move(t1); // instead we can move the smart pointer! t1 will have a null pointer in it.
    if (!t1) 
         std::cout << "t1 is nullptr" << std::endl;       
         return 0;
}

    // UNIQUE POINTERS:
    // Use unique pointers as often as you can, since they are simple efficient and in most cases they are drop ins for many of the common pointer use cases.
    // A unique pointer declaration uses a template parameter, which is the type of the object that the smart pointer will manage on the heap. So, this allows us to decleare unique pointer objects that points any type we need.
    // You can not have multiple unique pointers pointing to the same object on the heap.
    // Unique pointers can not be copied or assigned. So, their copy constructors and copy assignment operators are not available.
    // Since the ownership is unique you can guarantee that when the pointer goes out of scope, the object that it points to will automatically be cleaned up from the heap.
    // But unique pointers can be moved. So, they are great for placing in standard template library containers such as vectors.
    
    {
        std::unique_ptr<int> p1 {new int {100}};
        std::cout << *p1 << std::endl;  // 100
        *p1 = 200; 
        std::cout << *p1 << std::endl;  // 200
    }  // automatically deleted

    // Unique pointers as well as other smart pointer types allow us to pint to user-defined types. Example: Account class must be user defined class!
    {
    std::unique_ptr<Account> p1 {new Account {"Moe"}};   // unique pointer p1 will manage an Account object on the heap.
    std::cout << *p1 << std::endl; // displays account!
    // Alos access the account object member methhods via the member selection.
    p1->deposit();
    p1->withdraw();
    }  // automatically deleted
    
    // Unique pointers can not be copied or assigned as mentioned before.
    {
    std::vector<std::unique_ptr<int>> vec;   // here we declare a vector that will contain unique pointers to integers.
    std::unique_ptr<int> ptr {new int{100}}; // Define a pointer which is a unique pointer to an int. Points to an integer on the heap which is initilized to 100.
    vec.push_back(ptr);     // Error - copy not allowed. We can not pushback this unique pointer to vector becouse that imples a copy of the object!
    vec.push_back(std::move(ptr));  // we can use move semantics to move the object. ptr gives ownership of the pointer, and it is moved to the vector. The vector now owns the ponter and ptr will be set to null pointer.
    }  // automatically deleted

    // A better way of initializing a unique pointer. make_unique can be used after c++14. This function returns a unique pointer of the specified type and it allows us to pass initialization values into the constructor for the managed object
    {
        std::unique_ptr<int> p1 = make_unique<int>(100);   // p1 is delclared as a uniqe pointer to the integer. Not need to use new keyword.
        std::unique_ptr<Account> p2 = make_unique<Account>("Curly", 5000); // p2 is a uniqe pointer to Account object. Not need to use new keyword.
        auto p3 = make_unique<Player>("Hero", 100, 100);  // p3 is a uniqe pointer to Player object. We used auto keyword to let the compiler deduce the type of p3 based on what unique returns.
    }  // automatically deleted


    // METHODS OF UNIQUE POINTERS
    {
        std::unique_ptr<int> p1 {new int {100}};
        std::cout << p1.get() << std::endl; // 0x564388  get mothod returns a pointer to the manage object. Not used too much, can be used when using libraries working with raw pointers.
        p1.reset(); // p1 is now nullptr. Reset method sets the pointer as a null pointer and memory it points to will be released.
        // Below code is for checking if the pointer is initialized
        if (p1)
            std::cout << *p1 << std::endl;   // won't execute since p1 was set to a null pointer!
    }  // automatically deleted

// EXAMPLE: CHECK CODES IN SECTION 17 UNIQUE POINTERS! I DID NOT COPY THEM SINCE THERE ARE MULTIPLE HEADER FILES. Watch video 199 after 12:35!

       std::vector<std::unique_ptr<Account>> accounts;                       // we create a vector contains pointers.

       accounts.push_back( make_unique<Checking_Account>("James", 1000));    // adding new pointers to the vector. This was not possible in above example. This is the method!
       accounts.push_back( make_unique<Savings_Account>("Billy", 4000, 5.2));
       accounts.push_back( make_unique<Trust_Account>("Bobby", 5000, 4.5));

        for (const auto &acc: accounts)      // we need to pass by reference, otherwise it will genereate error because we can not copy unique pointers.
            std::cout << *acc << std::endl;     
       return 0;
    // SHARED POINTERS
    // Use shared pointers when you have more complex object management semantics, involving shared ownership.
    // Provides shared ownership of heap objects.
    // Like a unique pointer, a shared pointer points to an object on the heap as well. however, unlike a unique pointer, that heap object may be shared among many shared pointers.
    // So, we can have one heap object referenced by multiple shared pointers that manage it.
    // Unlike unique pointers, shared pointers can be copied and assigned. Also supports move semantics.
    // While unique pointers can be used to allocate arrays of objects on the heap, shared pointers do not support this by default.
    // Since there can be more than one shared pointer to an object, you may think how we can destroy the heap object: by counting references!
        // Every time we instantiate (kanit sunmak, orneklerle desteklemek, somutlastirmak) a shared pointer object and have it point or reference to the heap object, we increment the counter.
        // This counter simply has the number of shared pointers referencing the heap object. When the reference count become 0, then we know nothing is referring to the heap object, and it can be safely destroyed.

    // HOW TO DECLARE SHARED POINTERS:
    {
        std::shared_ptr<int> p1 {new int {100}};   // p1 is a shared pointer to an integer which is created new on he heap!
        std::cout << *p1 << std::endl;      //100
        *p1 = 200;
        std::cout << *p1 << std::endl;     // 200
    } // automatically deleted, no need to delete the shared pointer!

    // Shared pointers with user defined types:
    {
        std::shared_ptr<Account> p1 {new Account {"Larry"}};   // p1 is a shared pointer to an integer which is created new on he heap!
        std::cout << *p1 << std::endl;      // displays account
        
        p1->deposit(1000);
        p1->withdraw(500);
    } // automatically deleted, no need to delete the shared pointer! 

    // A better way of declaring shared pointers. make_shared function is introduced at c++11. This function returns a shared pointer of the specified type and it allows us to pass initialization values into the constructor for the managed object
    {
        std::shared_ptr<int> p1 = std::make_shared<int>(100);   //  use:count: 1. p1 is declared as a shared pointer to the integer. Not need to use new keyword. This is efficient also for the compiler.
        std::shared_ptr<int> p2 {p1}; // use:count: 2. p2 is a shared pointer to Account object. Copy constructor is used to initialize the p2 to p1. p1 and p2 refers to the same integer on the heap!
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

    // EXAMPLE IN IDE:
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
        std::cout << "Use count: " << p.use_count() << std::endl;   // 2 since we copied ptr here!
    }

    int main() {
    
        // use_count – the number of shared_ptr objects
        // managing the heap object
    
        // std::shared_ptr<int> p1 {new int {100} };
        // std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 1
      
        // std::shared_ptr<int> p2 { p1 };			// shared ownwership
        // std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 2
    
        // p1.reset();	// decrement the use_count; p1 is nulled out
        // std::cout << "Use count: "<< p1.use_count() << std::endl; 		// 0 
        // std::cout << "Use count: "<< p2.use_count() << std::endl; 		// 1
         
        // std::cout << "\n==========================================" << std::endl;
        // std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
        // func(ptr);
        // std::cout << "Use count: " << ptr.use_count() << std::endl;    // 1 since the p in func is terminated!
        // {
        //     std::shared_ptr<Test> ptr1 = ptr;
        //     std::cout << "Use count: " << ptr.use_count() << std::endl;   // 2
        //     {
        //         std::shared_ptr<Test> ptr2 = ptr;
        //         std::cout << "Use count: " << ptr.use_count() << std::endl;     // 3 
        //         ptr.reset();   // ptr will be null
        //     }
        //     std::cout << "Use count: " << ptr.use_count() << std::endl;      // 0 since we reset ptr in above block!
    
        // }
        // std::cout << "Use count: " << ptr.use_count() <<std:: endl;   // again 0 since ptr does not points to any object in the heap!

        std::cout << "\n==========================================" << std::endl;
        std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);  // count is 1 since these point to different objects!
        std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);       // count is 1
        std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);      // count is 1
        
        std::vector<std::shared_ptr<Account>> accounts;
        accounts.push_back(acc1);
        accounts.push_back(acc2);
        accounts.push_back(acc3);    // count for acc1, acc2 and act3 becomes 2 here. Since both the vector accounts and acc# are pointing to the same object.
        
        for (const auto &acc: accounts) {
            std::cout << *acc << std::endl;
            std::cout << "Use count: " << acc.use_count() << std::endl;   // 2
        }
        // What happens when these three pointers go out of scope, the vector is going to go out of the scope first, so it's going to be destroyed.
        // But the objects that the trust account, checking account and savings account objects on the heap won't be destroyed yet. 
        // Then when acc3 2 and 1 are destroyed, that's when the heap storage will be dynamically de-allocated.
        std::cout << "==========================================" << std::endl;
        return 0;
    }

    // WEAK POINTERS:
    // The weak pointer provides a non-owning or weak reference to a shared manage object. 
    // Like a shared pointer, weak pointer points to an object on the heap. But onlike a shared pointer, it does not participate in the owing relationship.
    // Weak pointers are always created from shared pointers. Since weak pointers are non owning reeferences, they do not affect the reference count for the managed object.
    // So, weak pointers do not affect the lifetime of the objects they are pointing to.
    // There are a few use cases for weak pointer:
        // One is to prevent strong reference cyles between two objects. (Strong cercular references)
            // Sometimes in our programs we have two classes that each class refers to the other one. This implies a one to one relationship between classes and this will be reflected in the class objects when we instantiate them.
            // let's say that we have two objects A and B, which were instantiated from two different classes. A has a shared pointer to B and B has a shared pointer to A.
            // When they go out of scope, they will be destroyed from the stack but their shared resource on the heap will not be destroyed and will leak memory. A keeps B alive, B keeps A alive. (chicken-egg problem)
            // Here is where weak pointer comes in. We need to decide who owns who. Let's say that A owns B, then we replace the shared pointer in B with a weak pointer. Then everything will work as expected, we will not leak any memory.
        // The other is is, when we have a pinter that we use to temporarily reference another object, something like an iterator pointer that traverses a list of nodes. I does not own them just visits them temporarily.

    // IDE Example:

    #include <iostream>
    #include <memory>

    using namespace std;

    class B;    // forward declaration. This is used since we use class B in class A before we define it. Here we say compiler that we will have a class B. It is like a function prototype.

    class A {
        std::shared_ptr<B> b_ptr;
    public:
        void set_B(std::shared_ptr<B> &b) {
            b_ptr = b;
        }
        A() { cout << "A Constructor" << endl; }
        ~A() { cout << "A Destructor" << endl; }
    };

    class B {
        // std::shared_ptr<A> a_ptr;     // make weak to break the strong circular reference, this causes memory licage, deconstructor is never called.
        std::weak_ptr<A> a_ptr;     // This fixes the problem.
    public:
        void set_A(std::shared_ptr<A> &a) {
            a_ptr = a;
        }
        B() { cout << "B Constructor" << endl; }
        ~B() { cout << "B Destructor" << endl; }
    };

    int main() {
        shared_ptr<A> a  = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();
        a->set_B(b);
        b->set_A(a);
        
        return 0;
    }

    // CUSTOM DELETERS FOR SMART POINTERS:
    // This is not something you are likely to see very often. However c++ smart pointers support this feature.
    // Sometimes when we destroy a smart pointer, we need more than to just destroy the object on the heap.
    // Sometimes when we use pointers to see structures from c frameworks, we have to provide a specilaized way of destroying them since in many cases they do not have descructors.
    // C++ smart pointers allow you to provide custom deleters that will be called when the smart pointer is destroyed. 
    // If you use custom deleters, you can not use make_shared or make_unique functions when you create smart pointer object. Thes fucntions do not support custom deleters.
    // There are a lot of wy of defining custom deleters. Two of them will be dsiscussed: a function and a lambda.
        // Function:
        void my_deleter (Some_Class *raw_pointer){ // deleter function will be called automatically when the smart pointer will be deleted. Function will be provided with a raw pointer 
                                                   // to the managed object that the smart pointer is referencing. then, in this function you do whatever you need to do to relinquish (el cekmek, feragat etmek) your resources.
            // your custom deleter code
            delete raw pointer;   // in this example we simply delete the raw pointer, that's it, But this function can do other things as well if needed.
        } 

        shared_ptr<Some_Class> ptr {new Some_Class{}, my_deleter};   // creating the managed object using new, also passing in the name of my custom deleter function. now when the pointer is destroyed, it will call my deleter.

        // Another example:
        void my_deleter (Test *ptr){    // raw pointer to test object. This pointer is the pointer that the smart pointer is managing.
            cout << "In my custom deleter" << endl;
            delete ptr;
        }

        shared_ptr<Test> ptr {new Test{}, my_deleter};   // this will also work for the unique pointers.

        // LAMDA EXPRESION
        // Lamda is an anonymous function that is a fucntion that has no name and can be defined in line right where you expect to use it.
        shared_ptr<Test> ptr (new Test{100}, [] (Test *ptr){ // Function name parameter is replaced with a code block that looks very similar to what we originally wrote in the my deleter function. This code will be executed whenever the pointer object is destroyed.
            cout << "\tUsing my custom deleter" << endl;
            delete ptr;
        });
    
    // EXAMPLE ON IDE

    #include <iostream>
    #include <memory>

    class Test {
    private:
        int data;
    public:
        Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
        Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
        int get_data() const {return data; }
        ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
    };

    void my_deleter(Test *ptr) {
        std::cout << "\tUsing my custom function deleter" << std::endl;
        delete ptr;
    }

    int main() {

        {
            // Using a function, ptr1 will be destroyed when this block ends! 
            std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter };
        }

        std::cout << "====================" << std::endl;
        {
            // Using a Lambda expression ptr2 will be destroyed when this block ends! 
            std::shared_ptr<Test> ptr2 (new Test{1000}, 
                [] (Test *ptr)  {
                    std::cout << "\tUsing my custom lamdba deleter" << std::endl;
                    delete ptr;
                });
        }
        
        return 0;
    }