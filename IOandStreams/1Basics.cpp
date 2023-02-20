// C++ uses streams as an interface between the program and input and output devices.
// A stream is a sequence of bytes.
// Input stream provides data to program while output stream receives data from the program. We can also use a stream that does both.
// Input can be coming from a keyboard, a connection to a web service etc.
// Output device can be a file, the console, a connection to a web service etc.
// Most commonly used c++ header files for streams:
    // iostream: provides definitions for formatted input output from/to streams.
    // fstream: provides definitions for formatted input and output from/to file streams.
    // iomanip: provides definitions to manipulators used to format stream I/O

// When we add these libraries to our program, we have a lot of c++ classes that we can use for file I/O. 
    // ios: provides basuc support for formatted and unformatted I/O operations. It serves as a base class for most other classes in the iostream hierarchy.
    // ifstream: provides for high-level input operations on file based streams. If you want to read from a file, you can declare your object to be an ifstream object.
    // ofstream: provides for high-level output operations on file based streams. If you want to create a new file or write to a file, you can declare it as an object of ofstream.
    // fstream: provides for high level I/O operations on file based streams. Derived from ofstream and ifstream using multiple inheritance.
        //  If we need to do both input nad output to a file at the same time, we can declare an fstream object to do it.
    // stringstream: provides for high-level I/O operations on memory based strings. Derived from istringstream and ostringstream.

// cin, cout cerr and clog are global objects and they are initialized before main begins to execute.
    // Best practice is to use cerr for error messages and clog for log messages.
    // cin and cout are buffered streams which means these are not read until user press enter or 
        // output to cout console occurs only when the stream buffer fills up or we provide a std endline or we flush the stream.
    // cerr and clog are standard error stream and standard log stream respectively. By default, they are both connected to the console.
        // They are both unbuffered, which means that we get input or output from them.