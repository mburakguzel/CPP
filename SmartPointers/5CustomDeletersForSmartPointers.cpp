// CUSTOM DELETERS FOR SMART POINTERS:
    // This is not something you are likely to see very often. However c++ smart pointers support this feature.
    // Sometimes when we destroy a smart pointer, we need more than to just destroy the object on the heap.
    // Sometimes when we use pointers to see structures from c frameworks, we have to provide a specilaized way of destroying them since in many cases they do not have descructors.
    // C++ smart pointers allow you to provide custom deleters that will be called when the smart pointer is destroyed. 
    // If you use custom deleters, you can not use make_shared or make_unique functions when you create smart pointer object. These functions do not support custom deleters.
    // There are a lot of way of defining custom deleters. Two of them will be discussed: a function and a lambda.
    
        // // Function:
        // void my_deleter (Some_Class *raw_pointer){ // deleter function will be called automatically when the smart pointer will be deleted. Function will be provided with a raw pointer 
        //                                            // to the managed object that the smart pointer is referencing. then, in this function you do whatever you need to do to relinquish (el cekmek, feragat etmek) your resources.
        //     // your custom deleter code
        //     delete raw pointer;   // in this example we simply delete the raw pointer, that's it, But this function can do other things as well if needed.
        // } 

        // shared_ptr<Some_Class> ptr {new Some_Class{}, my_deleter};   // creating the managed object using new, also passing in the name of my custom deleter function. now when the pointer is destroyed, it will call my deleter.

        // // Another example:
        // void my_deleter (Test *ptr){    // raw pointer to test object. This pointer is the pointer that the smart pointer is managing.
        //     cout << "In my custom deleter" << endl;
        //     delete ptr;
        // }

        // shared_ptr<Test> ptr {new Test{}, my_deleter};   // this will also work for the unique pointers.

        // // LAMDA EXPRESION
        // // Lamda is an anonymous function that is a fucntion that has no name and can be defined in line right where you expect to use it.
        // shared_ptr<Test> ptr (new Test{100}, [] (Test *ptr){ // Function name parameter is replaced with a code block that looks very similar to what we originally wrote in the my deleter function. This code will be executed whenever the pointer object is destroyed.
        //     cout << "\tUsing my custom deleter" << endl;
        //     delete ptr;
        // });
// -----------------*---------------------*------------------------*-----------------------*----------------------------*--------------------------*-------------------*-

#include <iostream>
#include <memory>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

void my_deleter(Test *ptr) {
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}

int main() {

    {
        // Using a function, ptr1 will be destroyed when this block ends! 
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter};
    }

    std::cout << "====================" << std::endl;
    {
     // Using a Lambda expression ptr2 will be destroyed when this block ends! 
        std::shared_ptr<Test> ptr2 (new Test{1000}, 
                [] (Test *ptr)  {
                    std::cout << "\tUsing my custom lamdba deleter" << std::endl;
                    delete ptr;
                });
        }        
        return 0;
    }