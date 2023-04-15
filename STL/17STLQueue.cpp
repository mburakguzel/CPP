// Queue is a STL adapter container.
// Container adaptors are constructed by taking one of the sequential containers and "adapting" (restricting/modifying) its interface to provide the desired behavior.
// First in First out (FIFO) data structure.
// Queue is implemented as an adapter over other STL container, can be implemented list or deque.
// Elements are pushed at the back and popped from the front.
// No iterators are supported.
// You can think of a queue as a waiting line, elements enter on one end removed from the other.
// We can not use stacks with STL algorithms.
#include <iostream>
#include <queue> // we have to include the queue header file to use queue. 

// This function displays a queue of 
// by repeatedly removing elements from the front
// Note theat the queue is passed in by value so we
// don't affect the passed in queue.
template <typename T>
void display(std::queue<T> q) {
    std::cout << "[ ";
    while (!q.empty()) {
        T elem = q.front();
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::queue<int> q;
    
    for (int i: {1,2,3,4,5}) 
        q.push(i);
    display(q);     // displays [ 1 2 3 4 5 ]

    std::cout << "Front: " << q.front() << std::endl;       // displays Front: 1
    std::cout << "Back:  " << q.back() << std::endl;        // Back:  5

    q.push(100);
    display(q);     // displays [ 1 2 3 4 5 100 ]

    q.pop();
    q.pop();
    display(q);     // displays [ 3 4 5 100 ]
    
    while (!q.empty())
        q.pop();
    display(q);     // displays [ ]

    std::cout << "Size: " << q.size() << std::endl;     // displays Size: 0
    
    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);     // displays [ 10 100 1000 ]
    
    std::cout << "Front: " << q.front() << std::endl;       // displays Front: 10
    std::cout << "Back:  " << q.back() << std::endl;        // displays Back:  1000
    
    q.front() = 5;
    q.back() = 5000;
    
    display(q);     // displays [ 5 100 5000 ]
    std::cout << "Front: " << q.front() << std::endl;       // displays Front: 5
    std::cout << "Back:  " << q.back() << std::endl;        // displays Back:  5000
    
    return 0;
}

