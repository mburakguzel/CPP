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

    // A better way of initializing a unique pointer. make_unique can be used after c++14. This function returns a unique pointer of the specified type and allows us to pass initialization values into the constructor for the manage object
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

