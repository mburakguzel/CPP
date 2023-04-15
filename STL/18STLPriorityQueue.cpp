// Priority_Queue is a STL adapter container.
// Container adaptors are constructed by taking one of the sequential containers and "adapting" (restricting/modifying) its interface to provide the desired behavior.
// Priority_Queue allows insertions and removal of elements in order from the front of the container.
// Elements are stored internally as a vector by default. But a data structure called the heap is used behind the scenes. (This is not the heap memory area!)
// Elemnts are inserted in priority order. (largest value will always be at the front)
// We can insert elements at the front and we get an element from the front, we're guaranteed that it will be the largest element in the container.
// No iterators are supported.
#include <iostream>
#include <queue>    // we have to include the queue header file to use priority_queue. 

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
    bool operator<(const Person &rhs) const {
        // return this->age < rhs.age;
        return this->name < rhs.name;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}
// This displays the priority queue by
// repeatedly topping and popping the priority queue
// It is being passed by value so we don't modify the 
// priority queue being passed in

template <typename T>
void display(std::priority_queue<T> pq)  {
    std::cout << "[ ";
    while (!pq.empty()) {
        T elem = pq.top();
        pq.pop();
        std::cout << elem << " ";
    }
    std::cout <<  "]" << std::endl;
}

void  test1() {
    std::cout << "\nTest1 =========================" << std::endl;

    std::priority_queue<int> pq;
    for (int i : {3,5,7,12,23,12,4,100,0, 3,5,7}) // it is ordered behind the scenes.
        pq.push(i);
        
    std::cout << "Size: " << pq.size() << std::endl;    // displays Size: 12
    std::cout << "Top: " << pq.top() << std::endl;      // displays Size: Top: 100 - the top element will always be the highest priority element which defaults to the element with the greates value.
        
    display(pq);        // displays [ 100 23 12 12 7 7 5 5 4 3 3 0 ]
    
    pq.pop();
    display(pq);        // displays [ 23 12 12 7 7 5 5 4 3 3 0 ]
}

void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});  
    pq.push(Person{"E", 7});  
    pq.push(Person{"F", 27});
    
    display(pq); // displays [ F:27 E:7 D:18 C:14 B:1 A:10 ]
}

int main() {
    test1();
    test2();
    return 0;
}

