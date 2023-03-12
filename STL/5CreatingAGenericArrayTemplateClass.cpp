// C++ 11 already has this array class. We just define it here to learn!
// If you need use array just use std::array, we just defined it here to learn!!!
        
#include<iostream>
#include<string>

template <typename T, int N>
class Array {      // Not a dynamic array!
    int size {N};           // how do we get the N??? It can be defined in constructor, but compiler needs to know it here! This is not dynamic memory allocation, we are creating the array in stack.
                            // This can be done by defining this array as a template as shown above!    
    T values[N];        // the N needs to ne known at compile-time!

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {   // Here we define an operator to pass values to array
        os << "[ ";
        for (const auto &val: arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }
public:
    Array() = default;
    Array(T init_val) {
        for (auto &item: values)
            item = init_val;
    }
    void fill(T val) {
        for (auto &item: values )
            item = val;
    }
    int get_size() const {
        return size;
    }
    // overloaded subscript operator for easy use
    T &operator[](int index) {
        return values[index];
    }
};


int main() {
            
    Array<int, 5> nums;   // we enter array size here!!!! This is quite different than what we did before.
    std::cout << "The size of nums is: "<< nums.get_size() << std::endl;
    std::cout << nums << std::endl;  // will show garbage data since elemnts of nums were not initialized.
            
    nums.fill(0);   // we set all elements of nums to 0 here.
    std::cout << "The size of nums is: "<< nums.get_size() << std::endl;
    std::cout << nums << std::endl;
            
    nums.fill(10);  // we set all elements of nums to 10 here.
    std::cout << nums << std::endl;

    nums[0] = 1000;     // here we pass 1000 to the 0th element of array.
    nums[3] = 2000;
    std::cout << nums << std::endl;
            
    Array<int, 100> nums2 {1};   // we create an array with 100 elements and inititalize all to 1.
    std::cout << "The size of nums2 is: "<< nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings(std::string{"Frank"});   // we can pass string as an element since our array is generic. Values were defined as T in array class.
    std::cout << "The size of strings is: "<< strings.get_size() << std::endl;
    std::cout << strings << std::endl;
            
    strings[0] = std::string{"Larry"};
    std::cout << strings << std::endl;
            
    strings.fill(std::string{"X"});
    std::cout << strings << std::endl;
                
    return 0;
}