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
        // Second parameter specifies the mode of the file that is being opened. For the above case, ::in means oppening the file in input mode. We will only read from this file.
    // std::fstream in_file {"../myfile.txt", std::ios:in | std::ios::binary}; here file is opened in input and binary mode. | is bitwise or operator.
        // Binary mode is necessary when reading non-text files that contain binary data. This is beyond the scope of this class.

// fstream can actually open up a file for reading and writing at the same time. But if we want to open a file only for input, it is more common to use ifstream.
    // std::ifstream in_file {"../myfile.txt", std::ios::in}; first parameter is the path of the file, ../ means it is in the same directory with the exe file.
    // std::ios:in is optioanl with ifstream since it is already the default!
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::ifstream in_file; // creating an ifstream object whose name is in_file
    std::string line;
    int num;
    double total;
    
    in_file.open("test.txt"); // opening the test.txt file. Bende VScode terminalinde gorulen pathte calisiyor. exe filein oldugu yerde degil! Yani test.txt VScode terminalindeki pathte olmali.
    // in_file.open("../test.txt"); // opening the test.txt file one directory above where .exe file is!. 
    // in_file.open("C:\burak\test.txt"); // this can cause some issues since "\b or \t" can also refer to a char. Instead use /
    // if (in_file.is_open()){  // another way of making sure if the file is opened!
    // The codelite IDE generates the exe file in debug folder of project, therefore program can not find the file!
    if (!in_file) {  // making sure if the file is opened!
        std::cerr << "Problem opening file" << std::endl;
        return 1;
        // std::exit(1); // also possible!
    }
    in_file >> line >> num >> total;  // we are reading the three seperated data in the test.txt. 
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;

    std::string line1{};
    // sometimes we want to read files an entire line at a time. But extraction operator will stop reading when they see any whitespace. In this case we can use the getline method.
    std::getline(in_file, line1);
    std::cout << line1 << std::endl;
    // Does not show anything for me!!


    in_file.close(); // once we winish with working with the file and we must close it.

// READING MORE DATA FROM A FILE
    in_file.open("test1.txt"); // opening the test.txt file. Bende VScode terminalinde gorulen pathte calisiyor. exe filein oldugu yerde degil! Yani test.txt VScode terminalindeki pathte olmali.
    if (!in_file) {  // making sure if the file is opened!
        std::cerr << "Problem opening file" << std::endl;
        return 1;
        // std::exit(1); // also possible!
    }
    // Different methods to read all lines from a file:
    while(!in_file.eof()){    // while not at the end of file
        in_file >> line >> num >> total;
        std::cout << std::setw(10) << std::left << line 
                       << std::setw(10) << num 
                       << std::setw(10)  << total
                       << std::endl;
    }

    // while(in_file >> line >> num >> total){    // while not at the end of file
    //     std::cout << std::setw(10) << std::left << line 
    //                    << std::setw(10) << num 
    //                    << std::setw(10)  << total
    //                    << std::endl;
    // }
    in_file.close(); // once we winish with working with the file and we must close it.

// READING DATA BY USING GETLINE METHOD
    in_file.open("poem.txt"); // opening the test.txt file. Bende VScode terminalinde gorulen pathte calisiyor. exe filein oldugu yerde degil! Yani test.txt VScode terminalindeki pathte olmali.
    if (!in_file) {  // making sure if the file is opened!
        std::cerr << "Problem opening file" << std::endl;
        return 1;
        // std::exit(1); // also possible!
    }
        while(!in_file.eof()){    // while not at the end of file
        std::getline(in_file, line); // we use getline becouse extraction operator stps reading when there is a whitespace
        std::cout << line << std::endl;
    }

    // while(std::getline(in_file, line)){     // read a line and returns true when read is succesfull, when we reach end of the file no true will be returned. // we use getline becouse extraction operator stps reading when there is a whitespace.
    //     std::cout << line << std::endl;
    // }
// READING DATA BY USING GET METHOD
    char c {}; // we are gonna read each char one by one! This allows us to use unformatted get.
    while (in_file.get(c)) { // reading each char one by one.
        std::cout << c;
    }
    std::cout << std::endl;

    in_file.close(); // once we winish with working with the file and we must close it.
    return 0;
}