// Stack is a STL adapter container.
// Container adaptors are constructed by taking one of the sequential containers and "adapting" (restricting/modifying) its interface to provide the desired behavior.
// Last in First out (LIFO) data structure.
// Stack is implemented as an adapter over other STL container, can be implemented as vector, list or deque.
// All operations occur on one end of the stack (top), we can easily implement a stack based on any container that has a back.
// No iterators are supported.
// You can think of a stack as a stack of books or a stack of plates, if we stack plates on top of each other, we can not pull out a plate from the middle or from the bottom.
// We can not use stacks with STL algorithms.

#include <iostream>
#include <stack>        // we have to include the stack header file to use stack. 
#include <vector>
#include <list>

// This function displays a stack of 
// by repeatedly topping and popping the stack
// Note theat the stack is passed in by value so we
// don't affect the passed in stack.
template <typename T>
void display(std::stack<T> s) {
    std::cout << "[ ";
    while (!s.empty()) {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::stack<int> s;     // if no underlying container is defined, it is deque by default.
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;
    std::stack<int, std::deque<int>> s3;
    
    for (int i: {1,2,3,4,5}) 
        s.push(i); // insert an element at the top of the stack
    display(s);     // displays [ 5 4 3 2 1 ]

    s.push(100);
    display(s);     // displays [ 100 5 4 3 2 1 ]
    
    s.pop();  // remove an element at the top of the stack
    s.pop();
    display(s);     // displays [ 4 3 2 1 ]
    
    while (!s.empty()) // checks if the stack empty
        s.pop();
    display(s);  // displays [ ]
    
    std::cout << "Size: " << s.size() << std::endl; // displays Size: 0 - number of elements in the stack
    
    s.push(10);
    display(s); // displays [ 10 ]
    
    s.top() = 100; // access the top element of the stack
    display(s); // displays [ 100 ]
    return 0;
}

