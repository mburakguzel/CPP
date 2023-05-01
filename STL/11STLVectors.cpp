// Vector is the main workhorse(bir isin esas yukunu ceken kisi) of the STL.
// It is dynamic in size.
// The vector elements themselves are stored in contigous memory. So, as the vector expands a new larger area in memory is allocated and current elements are moved to it.
// Like the array container, vector provides, fast direct access in constant time.
// Rapid insertation and deletion at the back(end) (constant time).
// Inserting elements into any other part of the vector other than the back(end) is not as efficient. It happens in linear time, which means that the running time increases linearly with the size of the vector.
// The vector supports all of the iterators.
// Usually, twice the amount of the current space is allocated, and the current elements are moved over to the newly allocated area and then the new element is placed at the back.
#include <iostream>
#include <vector>
#include <algorithm>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
    // Always overload less than and == operator to use user defined classes with STL algorithms.
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

// Use for_each and a lambda expression to display vector elements, this is created just to show how lamda functions are used.
void display2(const std::vector<int> &vec) {
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(),
        [](int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}

// template function to display any vector
template <typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &elem: vec)
        std::cout << elem << " ";
    std::cout <<  "]"<< std::endl;
}


void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    // Initialization of vectors:
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec = {2,4,5,6};
    display2(vec);
    
    std::vector<int> vec1 (10, 100);    // ten 100s in the vector
    display(vec1);  // displays [ 100 100 100 100 100 100 100 100 100 100 ]
}

void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;             // size returns number of elements in the vector.
    std::cout << "vec max size: " << vec.max_size() << std::endl;       // tells us what the max size of a vector would be in our system.
    std::cout << "vec capacity: " << vec.capacity() << std::endl;       // capacity tells us the capacity of the vector, when element number exceeds the capacity, vector will expand dynamically. 
    
    vec.push_back(6);
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;           // displays vec size: 6 - since we pushback one additional element
    std::cout << "vec max size: " << vec.max_size() << std::endl;     // displays vec max size: 2305843009213693951
    std::cout << "vec capacity: " << vec.capacity() << std::endl;     // displays vec capacity: 10 (allocates 2*5(doubled) as mentioned above)
    
    vec.shrink_to_fit();    // C++11  // this method shrinks the allocated memory amount to the exact element amount.
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;          // displays vec size: 6
    std::cout << "vec max size: " << vec.max_size() << std::endl;    // displays vec max size: 2305843009213693951
    std::cout << "vec capacity: " << vec.capacity() << std::endl;    // displays vec capacity: 6
    
    vec.reserve(100);  // allocates memory for 100 elements
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;          // displays vec size: 6
    std::cout << "vec max size: " << vec.max_size() << std::endl;    // displays vec max size: 2305843009213693951
    std::cout << "vec capacity: " << vec.capacity() << std::endl;    // displays vec capacity: 100
    
}
void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec[0] = 100;    // does not do any bounce checking
    vec.at(1) = 200;  // does the bounce checking
    
    display(vec);  // displays [ 100 200 3 4 5 ]
}

void test4() {
    std::cout << "\nTest4 =========================" << std::endl;
    std::vector<Person> stooges;
    
    Person p1 {"Larry", 18};
    display(stooges);   // displays [ ]
    
    stooges.push_back(p1);  // puchback method is used to add element at the back(end) of the vector.
    display(stooges);   // displays [ Larry:18 ]
    
    stooges.push_back(Person{"Moe", 25});
    display(stooges);   // displays [ Larry:18 Moe:25 ]
    
    stooges.emplace_back("Curly", 30);      // Use emplace_back!!! - it calls the constructor for us and creates a new object of person class.
        // This method expects the parameter that would normally be passed into the person constructor. 
        // It works like a constructor and constructs the person object using a person constructor right in place, where it is supposed to be in the vector.
    display(stooges);   // displays [ Larry:18 Moe:25 Curly:30 ]
}

void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };
    
    display(stooges);
    // Front method returns a reference to the front.
    // Back method returns a reference to the back.
    std::cout << "\nFront: " << stooges.front() << std::endl;    // displays Front: Larry:18 - since it is the front(first) element
    std::cout << "Back: " << stooges.back() << std::endl;        // displays Back: Curly:30 - since it is the back(last) element
    
    stooges.pop_back();  // removes one element from the back(end)
    display(stooges);    // displays [ Larry:18 Moe:25 ] - curly is gone

    std::cout << stooges.empty() << std::endl; // returns true if vector is empty.

}

void test6() {
    std::cout << "\nTest6 =========================" << std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec.clear();    // remove all elements
    display(vec);   // displays [ ]
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);  // displays [ 1 2 3 4 5 6 7 8 9 10 ]
    vec.erase(vec.begin(), vec.begin() + 2); // erases two elements
    display(vec);  // displays [ 3 4 5 6 7 8 9 10 ]
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    // erase all even numbers
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it %2 == 0)
            vec.erase(it);  
        else
            it++;   // only increment if not erased!
    }
    display(vec);
}

void test7() {
    std::cout << "\nTest7 =========================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    
    display(vec1);  // displays [ 1 2 3 4 5 ]
    display(vec2);  // displays [ 10 20 30 40 50 ]
    std::cout << std::endl;

    vec2.swap(vec1);  // swaps vector elements, elements must be same type but size can be different.
    display(vec1);  // displays [ 10 20 30 40 50 ]
    display(vec2);  // displays [ 1 2 3 4 5 ]
}

void test8() {
    std::cout << "\nTest8  =========================" << std::endl;

    std::vector<int> vec1 {1,21,3,40,12};    
    
    display(vec1);  // displays [ 1 21 3 40 12 ]
    std::sort(vec1.begin(), vec1.end());  // sorts elements of the vector
    display(vec1);  // displays [ 1 3 12 21 40 ]
}

void test9() {
    // std::back_inserter contructs a back-insert iterator that inserts new elements 
    // at the end of the container it applied to. It's a special output iterator
    // It's awesome!!!!   and  very efficient
    // There is also a front_inserter we can use with deques and lists
    // Copy one list to another using an iterator and back_inserter
    
    std::cout << "\nTest9  =========================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20};
    
    display(vec1);      // displays [ 1 2 3 4 5 ]
    display(vec2);      // displays [ 10 20 ]
    std::cout << std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2)); // copies vec1 to at the back(end) of vec2
    display(vec1);      // displays [ 1 2 3 4 5 ]
    display(vec2);      // displays [ 10 20 1 2 3 4 5 ]
    std::cout << std::endl;

    
    // Copy_if the element is even
    
    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
            [](int x) { return x%2 == 0; });
    display(vec1);  // displays [ 1 2 3 4 5 6 7 8 9 10 ]
    display(vec2);  // displays [ 10 20 2 4 6 8 10 ]
    
    
}

void test10() {
    std::cout << "\nTest10  =========================" << std::endl;
    // transform over 2 ranges
    
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3;
    
    
    // 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
        std::back_inserter(vec3),
        [](int x, int y) { return x * y;});
        
    display(vec3);  // displays [ 10 40 90 160 250 ]
    
}



// Insertion to anywhere other than back of the vector and from another vector
// Insert vec2 into vec1 before the 5
void test11() {
    std::cout << "\nTest11  =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    
    auto it = std::find(vec1.begin(), vec1.end(), 5);  // defining an iterator which points to the location of 5 in the vector
    if (it != vec1.end()) {
        std::cout << "inserting..." << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());   // vec1.insert(it, 10); if we want to enter only one parameter instead of an other vector.
    } else {
        std::cout << "Sorry, 5 not found" << std::endl;
    }
    display(vec1); // displays [ 1 2 3 4 100 200 300 400 5 6 7 8 9 10 ]
}

int main()  {    

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    
    return 0;
}