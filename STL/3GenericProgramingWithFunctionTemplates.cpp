
// Best way for generic programming is function templates!
// What is a C++ template: A template is a generic blueprint (sablon, model) that the compiler uses to generate specialized functions in classes. C++ supports function and class templates.
// The idea with templates is that we define a template with a placeholder (ayrilmis bilgi alani, yer tutucu) type.
// Then we plug in the actual type we want when we need it. Then the compiler generates the specific function or class that we need.
// All of this happens at compile time. For some other programming languages, this happens during run time.
// We get the benefit of the compiler performing type checking for us before the program executes.
// C++ template supports the concept of generic programming or meta programming.
// Since we are providing a generic representation of a function or class, and then the compiler writes the actual function or class for us.
// Using c++ templates sometimes can be so complex. Also, the error message is provided by the compiler can be very difficult to understand.

// Function templates:
    // We can replace type we want to generalize with a name, say T but we can use any valid identifier we wish.
    // We need to be careful while using user defined types! For below example user defined type must overload to greater than operator.
    // Templates must be defined out of the main function!!

#include<iostream>
#include <string>

template <typename T>       // However below code will not compile without this row, beacuse we need to tell the compiler that this is a template function.
T max(T a, T b){            // This can be compiled now, but not generate any code since it is simply a template or a blueprint. Code is not generated untill user uses a template.
    return (a > b) ? a : b;
}

// We may also use class instead of typename. They are essentially equalivalent.
// template <class T>       // However below code will not compile with out this row, beacuse we need to tell the compiler that this is a template function.
// T max(T a, T b){            // This can be copmiled now, but not generate any code since it is simply a template or a blueprint. Code is not generated untill user uses a template.
//     return (a > b) ? a : b;
// }

// We can have multiple template parameters and their types can be different.
template <typename T1, typename T2> 
void func(T1 a, T2 b){            // This can be copmiled now, but not generate any code since it is simply a template or a blueprint. Code is not generated untill user uses a template.
    std::cout << a << " " << b << std::endl;
}

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}


struct Person {
    std::string name;
    int age;
    bool operator<(const Person &rhs) const {   // This code is needed to be entered if we would like to compare two Person type data in min function. Basically overlading < operator.
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) { // overloading << operator to printout name of a Person!
    os << p.name;
    return os;
}

template <typename T>
void my_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main(){
// How to use template function in code:
    int a{5}, b{3};
    std::cout << max<int>(a, b) << std::endl;
    std::cout << max<double>(a, b) << std::endl;
    std::cout << max(a, b) << std::endl;   // template parameter is not needed, depending on the type of a and b compiler will figure out. Above two lines are also fine.
    // Use <int> when template is complex, sometimes compiler can not understand which type to use.
    std::cout << "-------------------------------------------------------------" << std::endl;
// Calling the second function:
    func<int, double> (10, 20.2);
    func ('A', 12.4);

    std::cout << "-------------------------------------------------------------" << std::endl;

    Person p1 {"Curly", 15};
    Person p2 {"Moe", 30};
                
    Person p3 = min(p1, p2);   // This will generate error unless we do not define how two person type data is compared in the Person defined above. See where the Person was defined.
    std::cout << p3.name << " is younger" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;                
                
    std::cout << min<int>(2,3) << std::endl;         // 2
    std::cout << min(2,3) << std::endl;              // 2 use <int> when template is complex, sometimes compiler can not understand which type to use.
    std::cout << min('A', 'B') << std::endl;         // A
    std::cout << min(12.5, 9.2) << std::endl;        // 9.2
    std::cout << min(5+2*2, 7+40) << std::endl;      // 9 Unlike Macros, this worked correctly because compiler knows C++, while preprocessor does not.
    std::cout << "-------------------------------------------------------------" << std::endl;

    func<int,int>(10,20);   // Compiler deduces which type to use for all below codes:
    func(10,20);
    func<char, double>('A', 12.4);
    func('A', 12.4);
    func(1000, "Testing");
    func(2000, std::string{"Frank"});

    std::cout << "-------------------------------------------------------------" << std::endl;
    func(p1, p2);  // again this will not work since p1 and p2 are user defined types! 
    // In order to make this work, we need to add the code starting with std::ostream before main()! We need to overload << operator!

    std::cout << "------------------------------Swap--------------------------" << std::endl;                    
    int x{100};
    int y{200};
    std::cout << x << ", " << y << std::endl;
    my_swap(x, y);    // swaps two variables!
    std::cout << x << ", " << y << std::endl;

    return 0;
}








        //     int main() {

                

        //     }