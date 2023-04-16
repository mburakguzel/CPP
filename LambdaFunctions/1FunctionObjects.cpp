// Lambda functions were introduced in C++11. Before we were using function objects or function pointers.
// Motivation of lambda functions:
    // Many times the classes and the functions are defined far away from when they are used, and this can lead to problems with modifying, maintaining and testing our code.
    // Best practice with lambda expressions is to use them when the amount of code is a statement or a few statements. If you have a more complex code, you should consider using a function object.
    // One other benefit of a lambda expression is that the compiler creates a closure object from the lambda expression. This means that we can gain access to the environment in which the lambda exists.


// FUNCTION OBJECTS:
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// In order to create a function object, we need to overload the () operator which is the function call operator.
struct Square_Functor {     // All this structure makes is overloading the function call operator. () is the function call operator.
    void operator() (int x) {       // getting an integer as an argument
            std::cout << x * x  << " ";     // displaying the square of the argument.
    }
};

template <typename T>       // a template class that expects a template parameter T.
struct Displayer {
    void operator() (const T &data) {       // overloading the () operator again! It expects a T.
        std::cout << data << " ";           // displaying the data entered to object.
    }
};

class Multiplier {
private:
    int num{};
public:
    Multiplier(int n) : num{n} {}
    int operator()(int n) const {
        return n * num;
    }
};

int main()
{
    std::cout << "\nTest1 =================" << std::endl;
    Square_Functor square;
    square(4);      // displays 16. This looks like exactly a function call, but square is not a function, it is an object.
                    // So, actually behind the scenes we call square.operator()(4) function(method) and pass 4 into it. But since we overloaded the () operator above in the object, we can use square(4).
                    // This kind of objects are called function objects.
    // We are doing the same thing below with Displayer class this time.
    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);                // displays 100
    d2("Frank");          // displays Frank
    
    std::cout << "\nTest2 =================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};
    
    std::for_each(vec1.begin(), vec1.end(), square);        // 1 4 9 16 25 - for each element from begin to end, takes square of it! 
    std::cout << std::endl;
    
    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());  // 1 2 3 4 5 - for each element from begin to end, displays it! 
    std::cout << std::endl;
    
    std::for_each(vec1.begin(), vec1.end(), d1);                    // 1 2 3 4 5 - for each element from begin to end, displays it! d1 is the displayer!
    std::cout << std::endl;
    
    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());  // Larry Moe Curly - for each element from begin to end, displays it! 
    std::cout << std::endl;                                             // () at the end of Displayer makes it a constructor not a function object! With every element it constructes and object.
    
    std::for_each(vec2.begin(), vec2.end(), d2);    // Larry Moe Curly - for each element from begin to end, displays it! 
    std::cout << std::endl;
    
    // In test3, we are doing the same thing that we did in test2 by using lambda functions! 
    // So, we do not have to go back to source file(the header file that the function object is created, ussually in a different file unlike this one) to check the function object.
    std::cout << "\nTest3 =================" << std::endl;
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * x  << " "; });  // 1 4 9 16 25
    std::cout << std::endl;
    
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * 10  << " "; }); // 10 20 30 40 50
    std::cout << std::endl;
    
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " ";});    // 1 2 3 4 5
    std::cout << std::endl;
    
    std::for_each(vec2.begin(), vec2.end(), [](std::string  s) {std::cout << s  << " "; }); // Larry Moe Curly
    std::cout << std::endl;

    std::cout << "\nTest4 =================" << std::endl;
    Multiplier mult(100);
    vec1 = {1,2,3,4};
    
    // transform changes the vector!
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);   // transforms the passed value by multiplying 100 as defined 4 rows above. 
                                                                    // Parameters: where to start, where to end, where to start changes, how to change respectively.
    std::for_each(vec1.begin(), vec1.end(),  d1);                           // displays 100 200 300 400
    std::cout << std::endl;

    vec1 = {1,2,3,4};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) { return x * 100;});
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x   << " "; });   // displays 100 200 300 400 500
  
    std::cout << std::endl;
    
    return 0;
}
