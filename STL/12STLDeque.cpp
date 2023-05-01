// The deque acts like an double ended queue.
// Deque size is dynamic and handled by STL.
// But unlike vectors, deque's element are not stored in contiguous memory. 
// Rapid insertation and deletion at the back(end) and front(top) (constant time).
// Inserting elements into any other part of the deque other than the back(end) is not as efficient. It happens in linear time, which means that the running time increases linearly with the size of the deque.
// The deque supports all of the iterators.
// Like all the STL containers, the deque supports copy and move semantics for initialization and assignment.
// IMPORTANT NOTE: If you will add new element to middle of the container, use list instead of deque.

// Unlike vectors, decques are implemented as a collection of memory blocks, these memory blocks contain elements that are in a contigous(komsu) memory. 
// But blocks themselves are not in contiguous memory.
// A good way to think of a deque is as a linked list of vectors.
// So when we add an element at the front or back, it adds it if there is space. If not, it will allocate a new block, add the element to that block and then link in the block.

#include <iostream>
#include <deque>  // this header file must be added to use deque.
#include <vector>
#include <algorithm>

// template function to display any deque
template <typename T>
void display(const std::deque<T> &d) {
    std::cout << "[";
    for (const auto &elem: d)
        std::cout << elem << " ";
    std::cout <<  "]"<< std::endl;
}

void test1() {
    std::cout << "\nTest1 =========================" << std::endl;

    std::deque<int> d {1,2,3,4,5};
    display(d);
    
    d = {2,4,5,6};
    display(d);

    std::deque<std::string> stooges{
        std::string("Larry"),
        "Moe", // c-style string
        std::string("Curly"),
    };
    display(stooges);  // displays [Larry Moe Curly ]

    std::deque<int> d1 (10, 100);    // ten 100s in the deque
    display(d1);
    
    d[0]  = 100;
    d.at(1) = 200;
    display(d);
}

void test2() {
    // push and pops
    std::cout << "\nTest2 =========================" << std::endl;

    std::deque<int> d {0,0,0};
    display(d);
    
    // Adds an element to end(back)
    d.push_back(10);
    d.push_back(20);
    display(d);
    
    // Adds an element to top(front)
    d.push_front(100);
    d.push_front(200);
    display(d);
    
    std::cout << "Front: " << d.front() << std::endl;   // displays Front: 200 - first element
    std::cout << "Back : " << d.back() << std::endl;    // displays Back : 20 - last element
    std::cout << "Size  : " << d.size() << std::endl;   // displays Size  : 7
    
    d.pop_back();  // removes one element from back (end)
    d.pop_front(); // removes one element from front (top)
    display(d);  // displays [100 0 0 0 10 ]
}

void test3() {
    // insert all even numbers into the back of a deque and all 
    // odd numbers into the front
    std::cout << "\nTest3 =========================" << std::endl;
    
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    for (const auto &elem: vec) {
        if (elem % 2 == 0)
            d.push_back(elem);
        else
            d.push_front(elem);
    }
    display(d);  // displays [9 7 5 3 1 2 4 6 8 10 ]
}

void test4() {
    // push front vs. back ordering
    std::cout << "\nTest4 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    for (const auto &elem: vec) {
        d.push_front(elem);
    }    
    display(d); // displays [10 9 8 7 6 5 4 3 2 1 ]
    
    d.clear();
    
     for (const auto &elem: vec) {
        d.push_back(elem);
    }
    display(d);  // displays [1 2 3 4 5 6 7 8 9 10 ]
}

void test5() {
    // Same as test4 using std::copy
    std::cout << "\nTest5 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);     // displays [10 9 8 7 6 5 4 3 2 1 ]
    
    d.clear();
    
    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);     // displays [1 2 3 4 5 6 7 8 9 10 ]
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

