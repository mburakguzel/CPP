// Maps are associative containers.
// The difference between sequence containers and associative containers is the way how the data is stored in memory. For sequence containers, data are stored in contiguous (birbirine komsu) memory.
// For associative containers elements can be stored as a group in different places of the memory and a key to link these groups to eachother. 
// Associative containers are designed to be especially efficient in accessing its elements by their key, as opposed to sequence containers which are more efficient in accessing elements by their position.   
// ASSOCIATIVE CONTAINERS:
    // Collection of stored objects that allow fast retrieval using a key.
    // STL provides sets and maps as associated containers.
    // Associated containers are usually implemented as a balanced binary tree or hashsets.
    // Most operations are very efficient.
// There are four times of maps:
    // std::map - most used
    // std::unordered_map
    // std::multimap
    // std::unordered_multimap
// The map is like a dictionary, where we have a key, a word in the case of a dictionary and an associated value, which would be its definition.
// Maps store their elements as key value pairs using the std::pair objects. We can directly access an element in the map using the key and all iterators are available.
// The elements in the map are ordered by key, and no duplicate keys are allowed.

// MULTI_MAP:
    // #include <map>
    // Ordered by key but allows duplicated elements.
    // All iterators are allowed.
// UNORDERED_MAP:
    // #include <unordered_map>
    // Elements are unordered.
    // No duplicate elements are allowed.
    // No reverse iterators are allowed.   
// UNORDERED_MULTIMAP:
    // #include <unordered_map>
    // Elements are unordered.
    // Duplicate elements are allowed.
    // No reverse iterators are allowed.     
#include <iostream>
#include <map> // in order to use map, we must inculde the map header file.
#include <set>


void display(const std::map<std::string, std::set<int>> &m) {
    std::cout << "[ ";
    for (const auto &elem: m) {
        std::cout << elem.first << ": [ " ;
            for (const auto &set_elem : elem.second)
                 std::cout << set_elem <<  " ";
            std::cout << "] " ;
    }
    std::cout << "]  " << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "]  " << std::endl;
}

void test1() {
    // Maps
    std::cout << "\nTest1 =========================" << std::endl;
    std::map<std::string, int> m {    // the key is the string and value is the integer. First attribute is the key and secon attribute is the value.
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m);     // displays [ Curly:2 Larry:3 Moe:1 ]
    
    // Maps have no concept of front and back. We can use insert method to insert element to the map. No push_back or front_back!
    m.insert( std::pair<std::string, int>("Anna", 10)); // or
    // std::pair<std::string, int> p1 {"Anna", 10};
    // m.insert(p1);
    display(m);     // displays [ Anna:10 Curly:2 Larry:3 Moe:1 ]
    
    m.insert(std::make_pair("Joe", 5));
    display(m);     // displays [ Anna:10 Curly:2 Joe:5 Larry:3 Moe:1 ]
    
    m["Frank"] = 18; // key works like a subscrpot operator here.
    // m.at("Frank") = 18;  // also works fine, throws an exception if the Frank is not in the map!
    display(m);     // displays [ Anna:10 Curly:2 Frank:18 Joe:5 Larry:3 Moe:1 ] 
    
    m["Frank"] += 10;               
    display(m);     // displays [ Anna:10 Curly:2 Frank:28 Joe:5 Larry:3 Moe:1 ] 
    
    m.erase("Frank"); // erases Frank
    display(m);     // displays [ Anna:10 Curly:2 Joe:5 Larry:3 Moe:1 ]
    
    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;      // displays Count for Joe: 1 - since no duplicated element is allowed.
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;  // displays Count for Frank: 0
    
    auto it = m.find("Larry"); //Defining an iterator for Larry, as with the set for efficiency, use the member method find, not the one in algorithm library.
    if (it != m.end())
        std::cout << "Found: " << it->first << " : " << it->second << std::endl;       // displays Found: Larry : 3 - first to key, second to value
        
    m.clear();
    
    display(m);     // displays [ ]

}

void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    
    std::map<std::string, std::set<int>> grades  {
        {"Larry", {100, 90} },
        {"Moe",  {94} },
        {"Curly", {80, 90, 100} }
    };
    
    display(grades);  // displays [ Curly: [ 80 90 100 ] Larry: [ 90 100 ] Moe: [ 94 ] ]
    
    grades["Larry"].insert(95);                 // insert 95 into the set of grades for "Larry"
    
    display(grades); // displays [ Curly: [ 80 90 100 ] Larry: [ 90 95 100 ] Moe: [ 94 ] ]
    
    auto it = grades.find("Moe");
    if (it != grades.end())                         // found "Moe"
    {
            it->second.insert(1000);            // insert 1000 into Moe's set of grades
    }                                                         // it->first is the key, it->second is the value (set)
    display(grades); // displays [ Curly: [ 80 90 100 ] Larry: [ 90 95 100 ] Moe: [ 94 1000 ] ]
}




int main() {
    test1();
    test2();
    return 0;
}

