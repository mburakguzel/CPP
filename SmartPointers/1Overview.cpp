// Problems with raw pointer:
    // Uninitialized (wild) pointers.
    // Memory leaks (when we do not de-allocate the storage that we previously allocated on the heap.)
    // Dangling pointers: one pointer is pointing to storage that it thinks is valid but in fact has already been de-allocated.
    // Not exeption safe: our program could throw an exception and the code that releases our allocated memory never execute and we leak memory.
// Smart pointers can help us prevent these types of errors, they can help us be more clear about who owns the pointer and when a pointer should be deleted to free up allocated memory.

// WHAT ARE SMART POINTERS?
    // Smart pointers are objects. Smart pointers are implemented as c++ template class which we can instantiate (burda object olustumak anlaminda kullanilmis. Kanit gostermek, orneklendirmek).
    // Smart pointers can only point to heap allocated memory, and they automatically call delete when that`s no longer needed.
    // Smart pointers adhere(kurallara uymak, sozunde durmak) to RAII (resource acquisition(kazanc, edinim) is initialization) princiles. When a resource-owing stack object goes out of scope, its destructor is automatically invoked. In this way, garbage collection in C++ is closely related to object lifetime.
    // Smart pointer types:
        // Unique pointers (unique_ptr)
        // Shared pointers (shared_ptr)
        // Weak pointers (weak_ptr)
        // Auto pointers (auto_ptr)  deprecated (onaylanmamis, karsi cikilmis) KULLANILMASI ONERILMIYOR!
    
// WHAT IS RAII?
    // RAII (areyayay - areydubleay) == Resource Acquisition is Initialization
    // RAII objects are allocated on the stack.
    // Acquisiton means: RAII objects will acquire (elde etmek, edinmek, sahip olmak) some sort of resource, that could be opening a file, allocating memory, acquiring a lock and so forth.
    // Initialization means: the resource is acquired at object initialization time. In other words, it happens in the object's constructor.
    // At some point, we need to relinguish (feragat etmek, el cekmek) that source that we acquired and that happens in the destructor. Here we can close the file, de-allocate any allocated memory release locks and so forth.
    // Smart pointers are example of RAII classes.
    
// DEFINE SMART POINTER
    // First, we need to include the memory header file since it defines the smart pointer classes and functions we will use. 
    // Smart pointers are implemented as c++ class template, very similar to the vectors!
    // Smart pointers are basically wrapper (wrap (sargi, sarmak) - wrapper (esarp, atki)) classes that contain and manage a raw pointer.
    // The actual implementation of smart pointers are compiler dependent.
    // The smart pointer classes provide overloaded dereference and member selection operators as well as methods to get the raw pointer and more.
    // However, you can not do pointer arithmatic on smart pointers, like you can with raw pointers.
    // Smart pointers have custom deleters where we can explicitly define the exact behaviour we want when the pointer is about to be destroyed.

#include <iostream>
#include <memory>  // we need to include the memory header file since it defines the smart pointer classes and functions we will use.
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


int main() {
    Test *t1 = new Test {1000}; // This is a raw pointer example.
    delete t1;                  // If we do not type this statement, it will cause a memory lickage! This does not delte t1, only deallocates the memory it allocates.
                                // You can see that destructor is never called when you command out "delete t1". 
    
    // Declaring a smart pointer.
    std::unique_ptr<Test> t2 {new Test{100}};  // or
    std::unique_ptr<Test> t3 = std::make_unique<Test>(1000);    // make_unique function can be used to make unique smart pointers. You do not need to use new keyword!
    // no delete needed it will call destructer by itself.

    std::unique_ptr<Test> t4;
    // t4 = t2; // genereates an error since we can not assign smart pointers.
    t4 = std::move(t2); // instead we can move the smart pointer! t2 will have a null pointer in it because we are moving the ownership of t2 to t4. t2 becomes a null pointer.
    
    if (!t2) 
        std::cout << "t2 is nullptr" << std::endl;       
    
    return 0;
}