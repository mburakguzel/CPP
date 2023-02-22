// fstream and ifstream are commonly used for input files.

// Steps to read from file: 
    // #include <fstream>
    // Declare an fstream or ifstream object.
    // Connect it to a file on your file system (opens it for reading).
    // Read data from the file via the stream
    // Close the stream.

// Creating object to read from a file
    // std::fstream in_file {"../myfile.txt", std::ios::in}; first parameter is the path of the file, ../ means it is in the same directory with the exe file.
        // The path can be vary depending on OS type or IDE!
        // Second parameter specifies the mode of the file that is being opened. For the above case it is in which means we will only read from this file.
    // std::fstream in_file {"../myfile.txt"}
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    
    in_file.open("../test.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    in_file.close();
    return 0;
}