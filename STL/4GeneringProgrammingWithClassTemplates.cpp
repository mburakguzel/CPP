// What is a C++ class template: similar to function template, but instead of creating a generic function, will be creating a generic class.
// So this implies generic attributes, constructors, destructors methods and so forth.
// We can plug in any data type.
// Vectors can be a good example.
// Class templates are more complex than function templates by combining inheritance, dynamic polymorphism, operator overloading, templates and other advanced C++ features together. Super powerful but also complex.
// Let's say that we want a class to hold items where the item has a name and an integer:
#include <iostream>
#include <string>
#include <vector>

// class Item{
// private:
//     std:string name;
//     int value;
// public:
//     Item(std::string name, int value)    // a constructor that initializes those attributes to those provided by the user 
//         : name{name}, value{value}
//     {}
//     std::string get_name() const {return name;}   // get_name method is defined.
//     int get_value() const {return value;}         // get_value method is defined.
// };

// Now let's say we need a same class but it will hold a double and a string instead of a string and an int.
// We need to define it with a name other than Item, since we can not overload class names in the same namespace and we do not want to create a complex hierarchy with dynamic polymorphism.
// So, how to create a class template, replace ints with T:
// Template classes are typically completely contained in header files
// So, we would have the template class in Item.h and no Item.cpp file would be used. This makes sense since actually what we define is a blueprint.
template <typename T>   // but again we need to tell the compiler that this is a template class.
class Item{
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value) : name{name}, value{value}   // a constructor that initializes those attributes to those provided by the user, 
    {}
    std::string get_name() const {return name; }  // get_name method is defined.
    T get_value() const {return value;}         // get_value method is defined.
};

// C++ class template with multiple types:
template <typename T1, typename T2>
struct My_pair{
    T1 first;
    T2 second;
};

// This My_pair class is already defined for us to use in std:
#include<utility>    // we need to include utility header file to use pair function.

int main(){

// Calling Item class in code: 
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
// How to call class template with multiple types:
    My_pair <std::string, int> p1 {"Frank", 100};
    My_pair <double, int> p2 {13.6, 124};
    std::vector<My_pair<int, double>> vec2;

    std::cout << p1.first;
    std::cout << p1.second << std::endl;

// This My_pair class is already defined for us to use in std:
    std::pair<std::string, int> p3 {"Frank", 100};

    std::cout << p3.first;
    std::cout << p3.second << std::endl;
// C++ also has a template class named tuple (veri grubu), it allows you to have a fixed number of elements of any type. It is not just limited to 2 items like the pair class.

    return 0;
} 

