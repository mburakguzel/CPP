#include <iostream>
#include <vector>     // allows us to work with vectors
#include <algorithm>  // allows us to use stl algorithms
#include <string>
#include <memory>        // we need to include the memory header file since it defines the smart pointer classes and functions we will use.
#include <numeric>      // should be added to use accumulate!

using namespace std;     // DO NOT USE THIS IF YOU WANT TO BE A GOOD PROGRAMER!


int main(){
    // There are even written books only for STL so all of it can not be covered! Check books!
    // STL (Standard Template Library) includes powerful, reusable, adaptable, generic classes and and functions.
    // STL is an assortment(karisim) of commonly used containers (A container is an object that stores a collection of objects of a specific type. For example, if we need to store a list of names, we can use a vector.).
    // STL is extensible (genisletilebilir)
    // STL has three main elements:
        // Containers: are collection of objects or primitive(ilkel) types (array, vector, deque, stack, set, map etc.).
        // Algorithms: are functions for processing sequences of elements from containers such as find, max, count, accumulate, sort etc. STL has about 60 algorithms to use and extended to work with any type of data.
        // Iterators: generates sequences of element from containers. (forward, reverse, by value, by reference, constant etc.)
    // Containers, Algorithms and Iterators are designed totally independent from one another.
    // STL also contains a few mor compenents such as functors and allocators but they will not be discussed!
    // A simple example:

    std::vector<int> v {1,5,3};
    std::sort(v.begin(), v.end());   // sort algorithm helps us to sort elements of a vector but it needs a sequence of objects to sort, that's where the iterator comes in. We provide the sequence using v.begin and v.end.
                                     // We can sort just about any stl container exactly the same way. Also, we can extend the sort algorithm to tell it exactly how to compare the elements when sorting.
                                     // v.begin and v.end are iterators here!
    for (auto elem: v)    // range based for loop to display sorted elements of vector! Range based for loop is a iterator itself!
        std::cout << elem << std::endl;

    std:reverse(v.begin(), v.end());  // reverse algorithm to reverse the objects (write the vector upside down!)
    for (auto elem: v)    // range based for loop to display sorted elements of vector!
        std::cout << elem << std::endl;    
    
    int sum{};
    sum = std::accumulate(v.begin(), v.end(), 0); // parameters are where to start where to end and what is the initial value of sum respectively! If you want to sum doubles use 0.0!
                                                  // include numeric to use accumulate 
    std::cout << sum << std::endl;

    // TYPES OF CONTAINERS:
        // Sequence containers: array, vector, list, forward list, deque
        // Associative containers: insert elements in a predefined order or no order at all. E.g. set, multi set, map, multi map
            // A set is a collection of elements where there are no duplicates, but there may be an order associated with it or not. We have got the option to choose whatever one we want.
            // A map is like a dictionary, where we associate a word with its definition. 
            // There are many variants of this category such as ordered sets, unordered sets sets that allow dublicates, maps that allow dublicates and so forth.
            // These are very powerful data structures that are often underused.
        // Container adapters: are variation of other containers. stack, queue, priority queue.
            // This category does not support iterators so they can not be used with stl algorithms. But they are so commonly used in programming that the stl provides support for them.
    
    // TYPES OF ITERATORS:
        // Input iterators: from the container to the program. Make container elements available to your program.
        // Output iterators: from the program to container. Can iterate over a sequence and write an element to a container.
        // Forward iterators: navigate one item at a time in one direction. Can iterate forward over a sequence and can read or write any element.
        // Bi-directional iterators: Navigate one item at a time both directions. These are like forward iterators, but they can iterate a sequence in both directions.
        // Random access iterators: directly access a container item. can use the subscript operator to directly access elements. We saw that with vector class.
    
    // TYPES OF ALGORITHMS:
        // There are about 60 algorithms in STL. There are two major groups depending on whether the algorithm modifies the sequence:
            // Non-modifying algorithms:
            // Modifying algorithms:

    // GENERIC PROGRAMMING: 
        // Genering programing is writing code that works with a variety of types as arguments, as long as those argument types meet specific syntatic and semantic requirements.
        // Why generic programing is important: because if i have code that's written to be generic, then I should be able to use any types with that code as long as it makes sense and it should work.
        // Let's say that we typed a function which gets a number and returns square of it. With generic programing, I should be able to pass in any numeric type such as int, short int, long long, float, double etc.
        // But c++ compiler is statically typed, so it needs to know the type being passed into that function. If I create the function with an integer, I can not call it correctly with a double.
        // There are several ways to make this function work:

        // GENERIC PROGRAMMING WITH MACROS
            // First one is macros. BE VERY CAREFUL WHEN YOU USE MACROS IN PRACTISE, ESPECIALLY MACROS THAT USE ARGUMENTS!
            // Macros are used more extensively in C code!
            // The include guards that we add our header files, we used pound(#) to define, that's a macro!
            // Macros begin with pound sign (#) and we know all directives that begin with the pound sign are preprocessor directives. We also know that the preprocessor does not know C++. So, there is no type information associated with macros.
            // Preprocessor is simple substituting (yerine koyma)!
            #define MAX_SIZE 100 // 100 has no type associated with it. There is no semicolon, if you add it will also be copied to variable!
            #define PI 3.14159   // PI has no type associated with it.

            if (num > MAX_SIZE)
                std::cout << "Too big";
            
            double area = PI * r * r;

            // The preprocessor will remove the PI and MAX_SIZE from our program and replace the with the assigned numbers. Above code will be transformed to below.
            // #define MAX_SIZE 100 // removed
            // #define PI 3.14159   // removed

            if (num > 100)
                std::cout << "Too big";
            
            double area = 3.14159 * r * r;

            // Suppose we need a function to determine the max of 2 integers:            
            // We can write a generic macro with arguments instead:
            #define MAX(a, b) ((a > b) ? a : b)
            std::cout << MAX(10,20) << std::endl;   // 20
            std::cout << MAX(2.4,3.5) << std::endl;   // 3.5
            std::cout << MAX('A','C') << std::endl;   // C

            // An example that macros fail: In order to fix this fail always use paranthesis while defining Macros: But still do not use macros since it is processed by preprocessor and it does not know C++!
            #define SQUARE(a) a*a
            // #define SQUARE(a) ((a)*(a))   // this is the correct way to define a macro!
            result = SQUARE (5); // Expect 25
            result = 5*5;        // Get 25
            // but
            result = 100/SQUARE(5);  // expect 4, but remember preprocessing is simple substituting 
            result = 100/5*5;        // GET 100

            // Or we can make our code generic by overlapping functions:
            int max(int a, int b){
                return (a > b) ? a : b;
            }

            double max(double a, double b){
                return (a > b) ? a : b;
            }
            
            char max(char a, char b){
                return (a > b) ? a : b;
            } // ...

            int x = 100;
            int y = 200;
            cout << max(x,y);
        
        // GENERIC PROGRAMMING WITH FUNCTION TEMPLATES:
            // Best way for generic programming is function templates!
            // What is a C++ template: A template is a generic blueprint (sablon, model) that the compiler uses to generate specialized functions in classes. C++ supports function and class templates.
            // The idea with templates is that we define a template with a placeholder (ayrilmis bilgi alani, yer tutucu) type, then we plug in the actual type we want when we need it. Then the compiler generates the specific function or class that we need.
            // All of this happens at compile time. For some other programming languages, this happens during run time.
            // We get the benefit of the compiler performing type checking for us before the program executes.
            // C++ template supports the concept of generic programming or meta programming.
            // Since we are providing a generic representation of a function or class, and then the compiler writes the actual function or class for us.
            // Using c++ templates sometimes can be so complex. Also, the error message is provided by the compiler can be very difficult to understand.

            // Function templates:
            // We can replace type we want to generalize with a name, say T but we can use any valid identifier we wish.
            // We need to be careful while using user defined types! For below example user defined type must overload to greater than operator.
            // Templates must be defined out of the main function!!
            
            template <typename T>       // However below code will not compile with out this row, beacuse we need to tell the compiler that this is a template function.
            T max(T a, T b){            // This can be copmiled now, but not generate any code since it is simply a template or a blueprint. Code is not generated untill user uses a template.
                return (a > b) ? a : b;
            }

            // We may also use class instead of typename. They are essentially equalivalent.
            template <class T>       // However below code will not compile with out this row, beacuse we need to tell the compiler that this is a template function.
            T max(T a, T b){            // This can be copmiled now, but not generate any code since it is simply a template or a blueprint. Code is not generated untill user uses a template.
                return (a > b) ? a : b;
            }

            // How to use template function in code:
            std::cout << max<int>(a, b);
            std::cout << max<double>(a, b);
            std::cout << max(a, b);   // template parameter is not needed, depending on the type of a and b compiler will figure out. Above two lines are also fine.
                                      // Use <int> when template is complex, sometimes compiler can not understand which type to use.

            // we can have multiple template parameters and their types can be different.
           template <typename T1, typename T2> 
           void func(T1 a, T2 b){            // This can be copmiled now, but not generate any code since it is simply a template or a blueprint. Code is not generated untill user uses a template.
                std::cout << a << " " << b;
            }
            // Calling the function:
            func<int, double> (10, 20.2);
            func ('A', 12.4);

            // IDE Example:
            #include <iostream>
            #include <string>

            template <typename T>
            T min(T a, T b) {
                return (a < b) ? a : b;
            }

            template <typename T1, typename T2>
            void func(T1 a, T2 b) {
                std::cout << a << " " << b << std::endl;
            }

            struct Person {
                std::string name;
                int age;

                bool operator<(const Person &rhs) const {   // This code is needed to enter if we would like to compare two Person type data in min function.
                    return this->age < rhs.age;
                }
            };

            std::ostream &operator<<(std::ostream &os, const Person &p) {
                os << p.name;
                return os;
            }

            template <typename T>
            void my_swap(T &a, T &b) {
                T temp = a;
                a = b;
                b = temp;
            }

            int main() {

                
                Person p1 {"Curly", 15};
                Person p2 {"Moe", 30};
                
                Person p3 = min(p1, p2);   // This will generate error unless we do not define how two person type data is compared in the Person defined above. See where the Person was defined.
                std::cout << p3.name << " is younger" << std::endl;
                
                
                std::cout << min<int>(2,3) << std::endl;            // 2
                std::cout << min(2,3) << std::endl;                 // 2 use <int> when template is complex, sometimes compiler can not understand which type to use.
                std::cout << min('A', 'B') << std::endl;            // A
                std::cout << min(12.5, 9.2) << std::endl;        // 9.2
                std::cout << min(5+2*2, 7+40) << std::endl;      // 9 Unlike Macros, this worked correctly because compiler knows C++ while preprocessor does not.
                
                func<int,int>(10,20);   // Compiler deduces which type to use for all below codes:
                func(10,20);
                func<char, double>('A', 12.4);
                func('A', 12.4);
                func(1000, "Testing");
                func(2000, std::string{"Frank"});

                func(p1, p2);  // again this will not work since p1 and p2 are user defined types! In order to make this work, we need to add the code starting with std::ostream before main()!
                
                int x{100};
                int y{200};
                std::cout << x << ", " << y << std::endl;
                my_swap(x, y);    // swaps two variables!
                std::cout << x << ", " << y << std::endl;

                return 0;
            }

        // GENERIC PROGRAMMING WITH CLASS TEMPLATES:
        // What is a C++ class template: similar to function template, but instead of creating a generic function, will be creating a generic class.
        // So this implies generic attributes, constructors, destructors methods and so forth.
        // We can plug in any data type.
        // Vectors can be a good example.
        // Class templates are more complex than function templates by combining inheritance, dynamic polymorphism, operator overloading, templates and other advanced C++ features together. Super powerful but also complex.
        // Let's say that we want a class to hold items where the item has a name and an integer:
        class Item{
        private:
            std:string name;
            int value;
        public:
            Item(std::string name, int value)    // a constructor that initializes those attributes to those provided by the user, 
                : name{name}, value{value}
            {}
            std::string get_name() const {return name; }  // get_name method is defined.
            int get_value() const {return value;}         // get_value method is defined.
        };
        // Now let's say we need a same class but it will hold a double and a string instead of a string and an int.
        // We need to define it with a name other than Item, since we can not overload class names in the same namespace and we do not want to create a complex hierarchy with dynamic polymorphism.
        // So, how to create a class template, replace ints with T:
        template <typename T>   // but again we need to compiler that this is a template class.
        class Item{
        private:
            std:string name;
            T value;
        public:
            Item(std::string name, T value)    // a constructor that initializes those attributes to those provided by the user, 
                : name{name}, value{value}
            {}
            std::string get_name() const {return name; }  // get_name method is defined.
            T get_value() const {return value;}         // get_value method is defined.
        };
        
        // Calling this class in code: 
        Item<int> item1 {"Larry", 1};   
        Item<double> item2 {"House", 1000.0};   
        Item<std::string> item3 {"Frank", "Boss"};
        std::vector<Item<int>> vec;

        // C++ class template with multiple types:
        template <typename T1, typename T2>
        struct My_pair{
            T1 first;
            T2 second;
        };

        // How to call above object:
        My_pair <std::string, int> p1 {"Frank", 100};
        My_pair <double, int> p1 {13.6, 124};
        std::vector<My_pair<int, double>> vec;

        // This MY_pair class is already defined for us to use in std:
        #include<utility>    // we need to include utility header file to use pair function.
        std::pair<std::string, int> p1 {"Frank", 100};

        std::cout << p1.first;
        std::cout << p1.second;

        // C++ also has a template class named tuple (veri grubu), it allows you to have a fixed number of elements of any type. It is not just limited to 2 items like the pair class.

        // IDE Example:

        #include <iostream>
        #include <string>
        #include <vector>

        // Template classes are typically completely contained in header files
        // So, we would have the template class in Item.h and no Item.cpp file would be used. This makes sense since actually what we define is a blueprint.
        template <typename T>
        class Item {
        private:
            std::string name;
            T   value;
        public:
            Item(std::string name, T value) : name{name}, value{value} 
            {}
            std::string get_name() const {return name; }
            T get_value() const { return value; }
        };

        template <typename T1, typename T2>
        struct My_Pair {
            T1 first;
            T2 second;
        };

        int main() {
            
            Item<int> item1 {"Frank", 100};    // Item is defined to have a string and a T type, that is why it is defined as Item<int> here. String is default, int can change.
            std::cout << item1.get_name() << " " << item1.get_value() << std::endl;
            
            Item  <std::string> item2 {"Frank", "Professor"};  // this time both strings!
            std::cout << item2.get_name() << " " << item2.get_value() << std::endl;
            
            Item <Item<std::string>> item3 {"Frank",  {"C++", "Professor"}}; // String will be "Frank". Our second parameter is defined as item again here. So it will also have two elements, one string by default and one string as defined here.
            std::cout << item3.get_name() << " " 
                            << item3.get_value().get_name() << " "           // First string of the second element!
                            << item3.get_value().get_value() << std::endl;   // Second string of the second element!
            
            std::cout << "\n================================" << std::endl;
            std::vector<Item<double>> vec {};       // vector example with a template class!
            vec.push_back (Item<double>("Larry", 100.0));
            vec.push_back (Item<double>("Moe", 200.0));
            vec.push_back (Item<double>("Curly",300.0));
            
            for (const auto &item: vec) {
                std::cout << item.get_name() << " " << item.get_value() << std::endl;
            }
        
            std::cout << "\n================================" << std::endl;
            My_Pair <std::string, int> p1 {"Frank", 100};
            My_Pair <int, double> p2 {124, 13.6};

            std::cout << p1.first << ", " << p1.second << std::endl;
            std::cout << p2.first << ", " << p2.second << std::endl;
            
            return 0;
        }

        // CREATING A GENERIC ARRAY TEMPLATE CLASS:
        // C++ 11 already has this array class. We just define it here to learn!
        // If you need use array just use std::array, we just defined it here to learn!!!
        #include <iostream>
        #include <string>

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
    
    // INTRODUCTION TO STL CONTAINERS:
    // STL containers are data structures that can store almost any type of objecta and they are implemented as template-based classes.
    // Each container has a set of member functions that we can use. Some of these member functions are specific to a particular container. Few member functions that all containers implement.
    // Each container has an associated header file that must be included in order to use the container. We have already sen this with vectors and strings.
    // Common methods provided by STL containers:
        // Default constructor: Initialzies an empty constructor. All containers provide default constructors and it results in an empty container.
        // Overloaded constructor: Initialzies containers with many options. You have to refer to the specific container you want to use to see the various overloaded constructors.
        // Copy constructor: Initializes a container asa copy of another container.
        // Move constructor: Moves existing container to a new container.
        // Destructors: Destroys a container. Deletes all the objects in it.
        // Copy assignment (operator=): Copy one container to another existing container.
        // Move assignment (operator=): Move one container to another existing container.
        // size: returns the number of elements in the container.
        // empty: Returns boolean - whether the container is empty?
        // insert: Insert an element to the container.
        // operator< and operator<= : returns boolean - compare contents of 2 containers.
        // operator> and operator>= : returns boolean - compare contents of 2 containers.
        // operator== and operator!= : returns boolean - whether the contents of 2 containers are equal or not.
        // swap: swap the elements of 2 containers.
        // erase: Remove element(s) from a container
        // clear: Remove all elements from a container
        // begin and end: returns iterators to first element or end.
        // rbegin and rend: returns reverse iterators to first element or end.
        // cbegin and cend: returns constant iterators to first element or end.
        // crbegin and crend: returns constant reverse iterators to first element or end.
    
    // What types of elements can we store in containers:
        // When we store an element in container, container makes copy of the element. Therefore;
        // All primitive types(int, float, double all of them) can be stored in containers.
        // For user type elements we have to make sure our element is copyable and assignable. This means they must have default copy constructors or our own copy constructors as well as copy assignment. We can also provide move semantics for efficiency.
        // The ordered associative containers must be able to compare objects. They do this using the less than and the equality operators. Your objects must support these operators via operator overloading.
        // In most cases we can use all of the compiler provided functionality unless we have raw pointers.
    
    // INTRODUCTION TO STL ITERATORS:
    // Iterators allow us to think of a container as a sequence of elements, it does not matter what the container is.
    // For example we might have a vector or a set or a map. These are all very different containers. But iterators allow us to process sequence of elements from these containers without worrying or even needing to know about how the container is implemented behind the scenes.
    // Iterators are implemented as template classes, so we create iterator objects and use them to iterate through our containers.
    // The syntax we use with iterators is similar to pointers. We can use dereference operator, the increment and the decrement operators and so forth. This was done intentionelly.
    // C++ programmers areconfortable with the pointer syntax and it is very easy to learn how to use iterators without learning some other arbitrary syntax.
    // Most of the stl containers can be traversed with iterators, stack and queue are exceptions.
    // Vectors allow us to access their elements randomly, however other containers do not allow us to randomly access elements like a vector does. So for those containers, iterators are necessary.
    // Declare iterator: Iterators must be declared based on the container type they will iterate over.
        std::vector<int>::iterator it1;         // iterate over a vector of integers
        std::list<std:string>::iterator it2;    // iterate over a list of strings
        std::map<std:string, std:string>::iterator it3;  // iterate over a map(maps are like dictioneries.) from strings to strings
        std::set<char>::iterator it4;       // iterate over a set of chars

    std::vector<int> vec {1,2,3};
    // 1 2 3 _ this is how it is stored.
    // vec.begin() referst to first element
    // vec.end referes to the locaton after last element!!! See Video 244 - 3:00. This is same for sets!
    // Let's say that we have a set. A set may or may not be iplemented in contiguous memory, it does not matter, and that is the point.

    // Initializing Iterators:
    std::vector<int>::iterator it = vec.begin();  // it will point to the element 1 in the vector! If the vector had been empty, then it would point to vec.end.
    // or
    auto it = vec.begin(); // compiler deduces the type!

    // Operations with iterators: (Assume 'it' is an iterator and i is an integer)
    // ++it                                       Pre-increment
    // it++                                       Post-increment
    // --it                                       Pre-decrement
    // it--                                       Post-decrement
    // it + i, it += i                            Incremetn
    // it - i, it -= i                            Decrement
    // it = it1                                   Assignment 
    // *it                                        Dereference
    // it->                                       Arrow operator
    // it == it1 or it != it1                     Comparison for equality
    // it < it1, it <= it1, it > it1, it >= it1   Comparison for magnitude

    // An example:
    std::vector<int> vec {1,2,3};
    std::vector<int>::iterator it = vec.begin();

    while (it != vec.end()){
        std::cout << *it << " ";
        ++it;
    }   // 1 2 3

    // Another example with for loop: this is how the range based for loop works!
    std::vector<int> vec {1,2,3};

    for (auto it = vec.begin(); it != vec.end(); it++){
        std::cout << *it << " ";
    }   // 1 2 3

    // Reverse iterator:
    // works in reverse, last element is the first, first element is the last
    // ++ moves backword, -- moves forward.
    std::vector<int> vec {1, 2, 3};
    std::vector<int>::reverse_iterator it = vec.begin();
    while (it != vec.end()) {
        std::cout << *it << " ";
        ++it;
    }
}