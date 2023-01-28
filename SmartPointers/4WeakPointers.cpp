// WEAK POINTERS:
    // The weak pointer provides a non-owning or weak reference to a shared manage object. 
    // Like a shared pointer, weak pointer points to an object on the heap. But onlike a shared pointer, it does not participate in the owing relationship.
    // Weak pointers are always created from shared pointers. Since weak pointers are non owning references, they do not affect the reference count for the managed object.
    // So, weak pointers do not affect the lifetime of the objects they are pointing to.
    // There are a few use cases for weak pointer:
        // One is to prevent strong reference cyles between two objects. (Strong cercular references)
            // Sometimes in our programs we have two classes that each class refers to the other one. This implies a one to one relationship between classes and this will be reflected in the class objects when we instantiate them.
            // Let's say that we have two objects A and B, which were instantiated from two different classes. A has a shared pointer to B and B has a shared pointer to A.
            // When they go out of scope, they will be destroyed from the stack but their shared resource on the heap will not be destroyed and will leak memory. A keeps B alive, B keeps A alive. (chicken-egg problem)
            // Here is where weak pointer comes in. We need to decide who owns who. Let's say that A owns B, then we replace the shared pointer in B with a weak pointer. Then everything will work as expected, we will not leak any memory.
        // The other is is, when we have a pinter that we use to temporarily reference another object, something like an iterator pointer that traverses a list of nodes. I does not own them just visits them temporarily.

#include <iostream>
#include <memory>

class B;    // forward declaration. This is defined here since we will use class B in class A before we define it. Here we say compiler that we will have a class B. It is like a function prototype.

class A {
    std::shared_ptr<B> b_ptr;
public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr = b;
    }
    A() { std::cout << "A Constructor" << std::endl; }
    ~A() { std::cout << "A Destructor" << std::endl; }
};

class B {
    // std::shared_ptr<A> a_ptr;   // make weak to break the strong circular reference, this causes memory licage, deconstructor is never called.
    std::weak_ptr<A> a_ptr;     // This fixes  the problem.
public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() { std::cout << "B Constructor" << std::endl; }
    ~B() { std::cout << "B Destructor" << std::endl; }
};

int main() {
    std::shared_ptr<A> a  = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->set_B(b);
    b->set_A(a);
    
    return 0;
}

