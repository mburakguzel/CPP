#include <iostream>
// In computer science, a container is a class or a data structure whose instances are collections of other objects. 
// In other words, they store objects in an organized way that follows specific access rules. (Copied from wikipedia)
// below are the header files of the containers that we use in this example.
#include <vector>
#include <set>
#include <map>
#include <list>

// display any vector of integers using range-based for loop
void display(const std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto const &i: vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n=============================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.begin();            // we are creating the iterator here, this is the short way. By typing auto, we let compilet to deduce the type of the iterator. nums1.begin point to 1, first element of nums1 vecotr.
    std::cout << *it << std::endl;      // Dereferencing iterator to display it. it behavfes like a pointer but it is not a pointer, it is a iterator. 

    it++;                                           // point to 2
    std::cout << *it << std::endl;      

    it += 2;                                       // point to 4
    std::cout << *it << std::endl;

    it -= 2;                                        // point to 2
    std::cout << *it << std::endl;

    it = nums1.end() - 1;                   // point to 5, since the vector nums1 is stored as {1,2,3,4,5,_} end-1 will refer to 5.
    std::cout << *it << std::endl;
}

void test2() {
    std::cout << "\n=============================" << std::endl;
    // display all vector elements using an iterator
    
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    std::vector<int>::iterator it = nums1.begin(); // This is the long way of creating an iterator.
    
    while (it != nums1.end()) {  // while loop to display each element before the end.
        std::cout << *it << std::endl;
        it++;
    }
    
    // change all vector elements to 0
    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;   // storing 0 to where iterator points!
        it++;
    }

    display(nums1);
}

void test3() {
    
    // using a const_iterator
    std::cout << "\n=============================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it1 = nums1.begin();   // we can not change the varible that const iterator points to.
    // auto it1 = nums1.cbegin();   // we need use cbegin to have a constant iterator!
    
    while (it1 != nums1.end()) {
        std::cout << *it1 << std::endl;
        it1++;
    }
    
    // compiler error when we try to change element
    it1 = nums1.begin();
    while (it1 != nums1.end()) {
    //    *it1 = 0;   // Complier error - read only
        it1++;
    }

}

void test4() {
    // more iterators
    // using a reverse iterator
    std::vector<int> vec {1,2,3,4};
    auto it1  = vec.rbegin();       // Use rbegin to have a reverse iterator. This iterator is over vector of ints starts at 4.
    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    // const reverse iterator over a list
    // List is usually implemented as a doubly-linked list. Doubly linked lists can store each of the elements they contain in different and unrelated storage locations. 
    // The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it. (copied from a website)
    std::list<std::string> name {"Larry", "Moe", "Curly"}; // name is a list of strings.
    auto it2 =name.crbegin();    // Defininga constant reverse (crbegin) iterator over list of strings  point to Curly
    std::cout << *it2 << std::endl;
    it2++;  // point to Moe
    std::cout << *it2 << std::endl;

    // iterator over a map
    // Map is a data structure which stores data as pairs (a key and a value).
    std::map<std::string, std::string> favorites { // favorites is a map of string - string pairs. 
    // Maps stores the key values in ascending order by default. That is why we see them in different order when we display them. Displays Bill -Frank -James!
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    auto it3 = favorites.begin();   // iterator over map of string, string pairs
    while (it3 != favorites.end()) {
        std::cout << it3->first << " : " << it3->second << std::endl; // first and second refer to first and second variables of the related element of the map
        it3++;
    }
}

void test5() {
    // iterate over a subset of a container
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;
    
    while (start != finish) {
        std::cout << *start << std::endl;
        start++;
    }
    
}

int main() {

    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}