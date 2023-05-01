// STRUCTURE OF LAMDA FUNCTIONS:
    // [] () -> return_type specifiers {};
    // [] => capture list; defines the start of the lambda.
    // () => parameter list; comma separated list of parameters. Every time the lambda executes, whatever parameter we specify in this parameter list will be passed into the lambda.
    //  -> return_type => the type that is returned by the lambda expression. If the return is void (gecersiz, hukumsuz), then we can omit(dahil etmemek) this.
    // specifiers => These are optional. The specifiers are mutable and constexpr.
    // {} => is the body, this is where we define the function.
    // Examples:
        // [] () {std::cout << "Hi";}(); ==> () intantiates a function object from this lambda expression by using overloaded function call operator().
        // [] (int x) {std::cout << x;}; x will be passed to lambda function.
        // [] (int x, int y) {std::cout << x+y;}; x+y will be passed to lambda function.
        // auto l = [] () { std::cout << "Hi";};
            // l() // displays Hi
        // auto l = [] (int x, int y) -> int {return x + y;}; // -> int is optional!
        // or
        // auto l = [] (int x, int y) {return x + y;};
            // std::cout << l(2,3); // displays 5

// Stateless Lambda Expressions:
    // [] emty capture list means that the expression captures no information from its environment and only knows about the information passed to it via the function parameter list.
    // This kind of lambda expressions are stateless lambda expression.
    // int x {10};
    // [] (int x) {std::cout << x;} (100); // which x will be used, since this is a stateless lambda it has no idea about its environment. SO, it will display 100.
    // We can also pass parameters by reference:
    // [] (int &x) {std::cout << x;} (100); // which will change the original parameter not copy of it.

    // It is also possible to use pointers to pass by reference:
    // auto l = [] (int *x) {std::cout << *x;}; // which will change the original parameter not copy of it. * is the dereferencing operator and & is the referencing operator.
    // l(&x);

#include <iostream>
#include <string>
#include <vector>
#include <functional>   // for std::function to pass lambda expression to functions
#include <algorithm>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name{name}, age{age} {};
    Person(const Person &p): name{p.name}, age{p.age} { }
    ~Person() = default;
    std::string get_name() const { return name; }
    void set_name(std::string name) {this->name = name; };
    int get_age() const {return age; }
    void set_age(int age) {this->age = age; }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}

void test1() {
    std::cout << "\n---Test1 --------------------------" << std::endl;

    [] () {std::cout << "Hi" << std::endl; }();         // displays Hi - if we do not add () at the end, this will not do anything!
    
    [] (int x) { std::cout << x << std::endl;}(100);    // displays 100
    
    [](int x, int y) { std::cout << x+y << std::endl; }(100,200);   // displays 300
}

// Using values and references as lambda parameters 
void test2() {
    std::cout << "\n---Test2 --------------------------" << std::endl;
    
    auto l1 =   [] () {std::cout << "Hi" << std::endl;};    // assigning the lamda expression to a variable! Notice no () at the end!
    l1();       // displays Hi
    
    int num1 {100};
    int num2 {100};

    auto l2 = [](int x, int y) { std::cout << x+y << std::endl; };      
    l2(10,20);          // displays 30
    l2(num1, num2);     // displays 200
    
    // example with references.
    auto l3 = [](int &x, int y) {
        std::cout << "x: " << x << " y: " << y << std::endl;        // x: 100 y: 100
        x = 1000;       // here we are changing the actual value of the x since it is passed by reference.
        y = 2000;       // here we are changing the local copy of the y since it is passed by value.
    };
    
    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;        // displays num1: 1000 num2: 100 - num2 does not change since the local copy was changed above!
}

// Using value and reference objects as lambda parameters
void test3() {
    // We use user defined objects instead of primitive types here!
    std::cout << "\n---Test3 --------------------------" << std::endl;
    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;       // displays [Person: Larry : 18]
    
    auto l4 = [] (Person p) {               // copied by value!
        std::cout << p << std::endl;        
    };
    l4(stooge);                             // displays [Person: Larry : 18]
    
    auto l5 = [] (const Person &p) {        // copied by reference! But since it is const, we can not change the object!
        std::cout << p << std::endl;        
    };
    l5(stooge);                             // displays [Person: Larry : 18]
    
    auto l6 = [] (Person &p) {              // copied by reference and we are changing the actual value!
        p.set_name("Frank");
        p.set_age(25);
        std::cout << p << std::endl;        
    };
    l6(stooge);                             // displays [Person: Frank : 25]
    
    std::cout << stooge << std::endl;       // displays [Person: Frank : 25]
    
}

// used for test4
// using std::function as a parameter in C++14 and greater
// or 
// auto as parameter type in C++20
// A predicate is a C++ function is that takes any number of arguments and returns a boolean value, so func(below) is a predicate function.
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func)   {  // std::function is defined after C++14
                                                                                    // bool is the return type of func, int is the parameter type of func
// The func function is not defined here. It is defined in test4 as a lambda function. Here it only show that filter_vector expects a function as an argument.
// or
// void filter_vector (const std::vector<int>  &vec, bool (*func) (int)) {          // bool is the return type of func, int is the parameter type of func, 
                                                                                    // this syntax is not used too much, it is coming from old c syntax. 
// or                                                                          
// void filter_vector (const std::vector<int>  &vec, auto func) {   // after C++20, above statement can be replaced with this one.
        std::cout <<"[ ";
    for (int i: vec) {
        if (func(i)) 
            std::cout << i  << " ";
    }
    std::cout << "]" << std::endl;
}

// passing a lambda to a function
void test4() {
    std::cout << "\n---Test4 --------------------------" << std::endl;
    std::vector<int> nums {10,20,30,40,50,60,70,80,90,100};     

    // The first argument of filter_vector is nums vector defined above and the second one is the lambda function. 
    // And this is exactly how the function defined above, it expects a vector of ints. and a function object, this is explained in 1FunctionObjects.cpp.
    filter_vector(nums, [](int x) {return x>50;});              // displays [ 60 70 80 90 100 ] - a predicate lambda expects one or more arguments and returns boolean!
    // Above lambda function gets x as argument and returns true if x>50, as it is defined in line 132: "if (func(i))" 
    // This only prints numbers which are greater than 50.

    
    filter_vector(nums, [](int x) {return x<=30;});             // displays [ 10 20 30 ]
    
    filter_vector(nums, [](int x) {return x>= 30 && x <=60;});  // displays [ 30 40 50 60 ]
}

// used for test5
auto make_lambda() {
	return [] () {std::cout << "This lambda was made using the make_lambda function!" << std::endl;};   // make_lambda function returns a lambda
}
// or
// std::function<void()> make_lambda(){
//     return [] () {std::cout << "This lambda was made using the make_lambda function!" << std::endl;};
// } 
// or
// void (*make_lambda())(){  // this syntax is not used too much, it is coming from old c syntax. 
//     return [] () {std::cout << "This lambda was made using the make_lambda function!" << std::endl;};
// } 



// returning a lambda from a function
void test5() {
	std::cout << "\n---Test5 --------------------------" << std::endl;
	
	auto l5 = make_lambda();    // since make_lmabda returns a lambda function, we can assign it to a value.
	
	l5();       // displays This lambda was made using the make_lambda function!
}

// using auto in the lambda parameter list
void test6() {
    std::cout << "\n---Test6 --------------------------" << std::endl;
    // If the lambda will be passed only one time to a function define it as above, if you will pass it several times, assign it to a variable so that you can call it again and again.
    auto l6 = [](auto x, auto y) {      // by defining everything as auto, we are defining a generic function which can work all type of data types.
        std::cout << "x: " << x << " y: " << y << std::endl;
    };
    
    l6(10,20);          // displays x: 10 y: 20
    l6(100.3, 200);     // displays x: 100.3 y: 200
    l6(12.5, 15.54);    // displays x: 12.5 y: 15.54
    
    l6 (Person("Larry", 18), Person("Curly", 22));  // displays x: [Person: Larry : 18] y: [Person: Curly : 22]
}

// Simple lambda examples with std::sort and std::for_each
void test7() {
      std::cout << "\n---Test7 --------------------------" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {    // std::sort is an stl algorithm. It expects a function object.
        return p1.get_name() < p2.get_name();       // defining the sort condition here!
    });
    
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {           // std::for_each is an stl algorithm. It expects a function object.
        std::cout << p << std::endl;        // displays [Person: Curly : 25], displays [Person: Larry : 18], displays [Person: Moe : 30] 
    });
    
    std::cout << std::endl;
    
     std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_age()< p2.get_age();  // defining the sort condition here!
    });
    
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << p << std::endl;        // displays [Person: Larry : 18], displays [Person: Curly : 25], displays [Person: Moe : 30]
    });
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
	test7();
    
    std::cout << std::endl;
	return 0;
}
