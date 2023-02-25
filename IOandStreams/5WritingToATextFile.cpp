// fstream and ofstream are commonly used for output files. We must always include fstream.
// fstream class can read and write to a file at the same time.
// ofstream are commonly used for output files only.
// Steps to write to a file:
    // #include <fstream>
    // Declare an fstream or ofstream object
    // Connect it to a file on your file system (opens it for writing). 
        // By default c++ wil create a new file if the file does not exist. If it exist, the content of the file will be truncated or removed unless we specify that we want to append to the contents of existing file.
    // Write data to the file via the stream
    // Close the stream

#include <iostream>
#include <fstream>
#include <string>

int main()  {
    // std::ofstream out_file {"./IOandStreams/output.txt", std::ios::app};  // we are creating an object of fstream type. First argument is the name of the file, second is the mode.
    // std::ofstream out_file {"output.txt", std::ios::out | std::ios::binary};  // Binary mode is necessary when we are writing non-text files that contain binary data.
    // std::ofstream out_file {"output.txt", std::ios::trunc};  // Truncate (kesmek, budamak) is also default mode for output files.
    // std::ofstream out_file {"output.txt", std::ios::app};  // We use std::ios::app flag, if we want to append some data to file.
    // std::ofstream out_file {"output.txt", std::ios::ate};  // We use std::ios::ate flag, if we want to set the initial position of the current data in file to the end of the existing file.
    std::ofstream out_file {"./IOandStreams/output.txt", std::ios::out};  // Output mode to only write do file, not read. std::ios::out is optional since it is already the default.
    // std::ofstream out_file {"output.txt", std::ios::out};  // This creates the text file to the default path on your terminal.
// To get the file name from user
    // std::ofstream out_file;  // create an object
    // std::string filename;    // create file name string
    // std::cin >> filename;    // get the file name

// Three different ways of checking if the file opened successfully.
    if (!out_file) {
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }

    // if (out_file) {
    //     // Read from it
    // } else {
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    // if (out_file.is_open()) {
    //     // Read from it
    // } else {
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    std::string line;
    std::cout << "Enter something to write to the file: ";
    std::getline(std::cin, line);
    out_file << line << std::endl;
    
    out_file.close(); // always close the file after you are done with it.
   
    return 0;
}