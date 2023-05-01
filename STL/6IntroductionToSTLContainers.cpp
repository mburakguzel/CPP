// INTRODUCTION TO STL CONTAINERS:
// STL containers are data structures that can store almost any type of objects and they are implemented as template-based classes.
// Each container has a set of member functions that we can use. Some of these member functions are specific to a particular container. Few member functions that all containers implement.
// Each container has an associated header file that must be included in order to use the container. We have already sen this with vectors and strings.
// Common methods provided by STL containers:
    // Default constructor: Initialzies an empty constructor. All containers provide default constructors and it results in an empty container.
    // Overloaded constructor: Initialzies containers with many options. You have to refer to the specific container you want to use to see the various overloaded constructors.
    // Copy constructor: Initializes a container asa copy of another container.
    // Move constructor: Moves existing container to a new container.
    // Destructors: Destroys a container. Deletes all the objects in it.
    // Copy assignment (operator=): Copy one container to another existing container.
    // Move assignment (operator=): Move one container to another existing container.
    // size: returns the number of elements in the container.
    // empty: Returns boolean - whether the container is empty?
    // insert: Insert an element to the container.
    // operator< and operator<= : returns boolean - compare contents of 2 containers.
    // operator> and operator>= : returns boolean - compare contents of 2 containers.
    // operator== and operator!= : returns boolean - whether the contents of 2 containers are equal or not.
    // swap: swap the elements of 2 containers.
    // erase: Remove element(s) from a container
    // clear: Remove all elements from a container
    // begin and end: returns iterators to first element or end.
    // rbegin and rend: returns reverse iterators to first element or end.
    // cbegin and cend: returns constant iterators to first element or end.
    // crbegin and crend: returns constant reverse iterators to first element or end.
    
// What types of elements can we store in containers:
    // When we store an element in container, container makes copy of the element. Therefore;
    // All primitive types(int, float, double all of them) can be stored in containers.
    // For user type elements we have to make sure our element is copyable and assignable. This means they must have default copy constructors or our own copy constructors as well as copy assignment. We can also provide move semantics for efficiency.
    // The ordered associative containers must be able to compare objects. They do this using the less than and the equality operators. Your objects must support these operators via operator overloading.
    // In most cases we can use all of the compiler provided functionality unless we have raw pointers.