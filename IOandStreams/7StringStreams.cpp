// String streams(akis) allow us to read or write from strings in memory much as we would read and write to files.
// There are three classes that we can use when using string streams: stringstream, istringstream and ostringstream.
// Using string streams:
    // #include <sstream>
    // Declare an stringstream, istringstream(read) or ostringstream(write) object.
    // Connect it to a std::string.
    // Read/write data from/to the string stream using formatted I/O.
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

int main() {
    int num{};
    double total{};
    std::string name{};
    
    std::string info {"Moe 100 1234.5"};
    std::istringstream iss {info};  // declare and object and connect it to the string.
    
    iss >> name  >> num >>  total;   // read data from string
    std::cout << std::setw(10) << std::left << name  
                   << std::setw(5) << num
                   << std::setw(10) << total << std::endl;
    
    std::cout << "\n---------------------------------------" << std::endl;
    
    std::ostringstream oss {};
    oss << std::setw(10) << std::left << name // writing to string
          << std::setw(5) << num
          << std::setw(10) << total << std::endl;
    std::cout << oss.str() << std::endl; // calling .str method of stream to print out!
    
    
    std::cout << "\n--- Data validation ------------------------------------" << std::endl;
    
    int value{};
    std::string entry {};
    bool done = false;
    do {
        std::cout << "Please enter an integer: ";
        std::cin >> entry;
        // Making sure if user entered an integer!
        std::istringstream validator {entry};  // create a istringstream object and connect it to entry entered by user.
        if (validator >> value) // store entered value to int value, if this can be done it means user entered an int.
            done = true;
        else 
            std::cout << "Sorry, that's not an integer" << std::endl;
            
         // discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Let's say user entered 12.18 or 12HelloBitch, above if statement will be true and value will take 12.
        // But rest will be stay in the stream. By using above line, we are clearing the rest from the stream. #limits is added for this code.
    } while (!done);
    
    std::cout << "You entered the integer: " << value << std::endl;
    
    std::cout << std::endl;
    return 0;
}

