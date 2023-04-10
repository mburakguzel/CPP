// Array container allows us ti create fixed size rrays of any type.
// Array container is different than the raw array that we used before. Differences:
    // Array container is an object type!
    // Unlike a raw array, an array container does not decay to a pointer to the first element of the array when we pass it into a function.
    // The time it takes to access an element is independent of the number of elements in the cotainer.
    // A array container is created based on a raw array behind scenes by STL. We can reach that raw array if we want.
    // Since array container is part of the STL, we can use them with iterators and algorithms.
    // Use array container instead of a raw array when possible.
// https://en.cppreference.com/w/cpp/container/array for detailed information.

#include <iostream>
#include <array>       // we must include array header file to use array container.
#include <algorithm>
#include <numeric>  // for more algorithms like accumulate

// Display the array -- note the size MUST be included
// when passing a std::array to a function
void display(const std::array<int, 5> &arr) {
    std::cout << "[ ";
    for (const auto &i: arr)
        std::cout << i << " ";
    std::cout <<  "]"<< std::endl;
}

void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    // When we create an array container, we need to define the type and number of elements.
    std::array<int, 5> arr1 {1,2,3,4,5};    // In c++ 11, you need to provide double {{ }}, in C++ 14 and forward you dont, just a single curly.
    std::array<int, 5> arr2;                // not initilalizng the elements, garbage data!
    
    // Below function is defined by us above!
    display(arr1);
    display(arr2);          // Elements are not initialized (contain 'garbage')
        
    arr2  = {10,20,30,40,50};

    display(arr1);
    display(arr2);
    
    // Size method for arrays:
    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;       //5 
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;       //5
    
    // At method for arrays:
    arr1[0] = 1000;         // No bounce checking
    arr1.at(1) = 2000;      // Bounce checking
    display(arr1);

    // Front and back methods for arrays:
    std::cout << "Front of arr2: " << arr2.front() << std::endl;        // 10 - first element
    std::cout << "Back of arr2: " << arr2.back() << std::endl;          // 50 - last element

    // Empty method for arrays: returns true if array is empty
    std::cout << "Array is empty: " << arr2.empty() << std::endl;          

    // Max_size method for arrays: 
    std::cout << "Array's max size: " << arr2.max_size() << std::endl;    // same with size of the array!
}
 
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} is C++ 11
    std::array<int, 5> arr2 {10,20,30,40,50};
    
    display(arr1);  // displays [1,2,3,4,5]
    display(arr2);  // displays [10,20,30,40,50]
    
    // Fills the array with given value.
    arr1.fill(0);
    
    display(arr1);  // displays [ 0 0 0 0 0 ]
    display(arr2);  // displays [ 10 20 30 40 50 ]
    
    // Swaps 2 arrays
    arr1.swap(arr2);
    
    display(arr1); // displays [ 10 20 30 40 50 ]
    display(arr2); // displays [ 0 0 0 0 0 ]
}

void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} is C++ 11

    // .data method is used to reach underlying raw array, behind scenes!
    int *ptr = arr1.data();  // we get address of the first element of the raw array.
    std::cout << ptr << std::endl; // displays 0x7cfdd0 address of the pointer
    *ptr = 10000;
    
    display(arr1); // displays [ 10000 2 3 4 5 ]
}

void test4() {
    std::cout << "\nTest4 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,4,5,3};     // double {{ }} is C++ 11
    display(arr1);
    
    // sort method sorts elements of the array!
    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,4,5,3};     // double {{ }} is C++ 11

    // Min and max element to find the minimum element: returns a iterator to minimum element and max element
    std::array<int,5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());  // ugly way
    auto max_num = std::max_element(arr1.begin(), arr1.end());                         // handsome way 
    std::cout << "min: " << *min_num << " , max: " << *max_num << std::endl;
}

void test6() {
    std::cout << "\nTest6 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,3,3,5};     // double {{ }} is C++ 11
    // adjacent (birbirine komsu) method, we need to overload the = operator for user defined types. Returns iterator! We dereference iterator below to display!
    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end()) 
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl; // displays Adjacent element found with value: 3, since there are two 3s adjacent to eachother.
    else 
        std::cout << "No adjacent elements found" << std::endl;
}

void test7() {
    std::cout << "\nTest7 =========================" << std::endl;

    //accumulate is from #include <numeric>
    std::array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} is C++ 11

    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);  // start from 1st element till last element and sum them with 0! The number we add at the end must be same type with array. 
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl; // displays Sum of the elements in arr1 is: 15
}

void test8() {
    std::cout << "\nTest8 =========================" << std::endl;
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};
    // count method shows how many times an element reoccurs in the array.
    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3 : " << count << " times" << std::endl; // displays Found 3 : 6 times
}

void test9() {
    std::cout << "\nTest9 =========================" << std::endl;
    std::array<int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300 ,400};
    // find how many numbers are between 10 and 200 ->  50,60,70,80
    
    int count = std::count_if(arr1.begin(), arr1.end(), 
                                            [](int x) { return x>10 && x<200; }); // displays Found  4 matches
                                            
    std::cout << "Found  " << count << " matches" << std::endl;
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
    
    return 0;
}

