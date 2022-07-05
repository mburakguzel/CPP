#include <iostream> 
#include <cctype>    // In order to use c-style strings, we need to add cctype library #include <cctype>
#include <cstring>   // Library to use c-style string functions. (e.g strlen)
// #include <cstlib>  // Library to convert strings to other types!  Not works!   
#include <string> // String header file must be added to use C++ strings!
using namespace std; 

int main() 
{
    // There are two types of strings 
        // C style strings
        // C++ Strings
    
    // C-STYLE STRINGS
    // In order to use c-style strings, we need to add cctype library #include <cctype>
    // C style strings are like arrays contains chars in them. We can reach each element by using subindex [] as we do in arrays.
    // C-style strings ends with null "\0" char to make program find end of the string. THIS IS IMPORTANT TO KNOW< OTHERWISE WE WOLD HAVE A LOT OF ERROR!    
    // Size of c-style strings are fixed and can not be altered like arays.
    // Defining a c-style string can w/o initializing may cause problems, because there can be no null char or a null char before the end of the string! If you print it, you will see garbage data.
        // Lets say that we have a string as "C++ is fun", on memory it is stored as "C++ is fun\0"
        // Therefore a string with 10 cahrs, occupies memory of 11 chars.
        // Let`s say that we initialize a string with 8 elements:
        char my_name [8] {"Burak"}; // Does not work w/o [] size. Always define length one more than string for \0 null char!!!!
        // in memory this is creates as "Burak\0\0\0"
        my_name [5] = 'y'; // will not cause an error!
    

    // INITIALIZE C-style string:
        char my_name [8] {"Burak"}; // this is the correct way!
        char my_name = "Burak"; // cause an error! Because c-style strings and arrays are stored in differetn memory areas. So, here it is tried to store a c-style array into wrong memory.
    
    // DETERMINE LENGTH OF A CHAR - strlen FUNCTION -
    // Ex:
        char first_name[20] {};
        char last_name[20] {}; 
        char full_name[50] {};  
        char temp[50] {};
        
        cout << "Please enter your first name: ";
        cin >> first_name;     
        cout << "Please enter your last name: ";
        cin >> last_name;

        cout << "-------------------------------" << endl;  
        cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters" << endl; // strlen function gives us lengt of the c-style string!
        cout << "and your last name, " << last_name << " has " << strlen(last_name) << " characters" << endl;    
    // strlen returns size_t type (a special type), not unsigned int! size_t can be an unsigned int or unsigned long based on our system!

    // FUNCTIONS THAT WORK WITH C-STYLE STRINGS
    // To use them we need to include two libraries: 
        #include <cstring> //
        #include <cstlib>  // Library to convert strings to other types!  

    // COPY AND ADD ONE STRING TO OTHER - strcpy - strcat
        strcpy(full_name, first_name);                // copy first_name to full_name
        strcat(full_name, " ");                       // concatenate (add) full_name and a space   // concatenate: baglamak, birlestirmek
        strcat(full_name, last_name);                 // concatenate (add) last_name to full_name  // concatenate: baglamak, birlestirmek
        cout << "Your full name is " << full_name << endl;
    
    // GET INPUT FROM USER WITH A SPACE - cingetline
    // If you ask user to enter a string and user type space in this string, cin command will get only the part before space!
        cout << "Enter your full name: ";
        cin >> full_name;     
        cout << "Your full name is " << full_name << endl;

    // cin.getline allows us to get string with spaces. Program reads 50(define as much as you want) chars or stops reading when user press enter!
        cout << "Enter your full name: ";
        cin.getline(full_name, 50);
        cout << "Your full name is " << full_name << endl;
    
    // COMPARE C_STYLE STRINGS
        strcmp(temp, full_name); // returns 0 if strings are same SENSITIVE TO UPPERCASE - LOWERCASE (BURAK != Burak)
        // If the first string is lexically comes before the second, returns less than zero.
        // If the first string is lexically comes after the second, returns greater than zero.

    // CONVERT ALL STRING TO UPPERCASE
        for(size_t i{ 0 }; i < strlen(full_name); ++i) {
            if(isalpha(full_name[i]))
                full_name[i] = toupper(full_name[i]);
        }

    // -------------o-------------------o---------------------------o-------------------------------o---------------------------------o--------------------------------------o

    // C++ STRINGS
    // C++ string is a class in the C++ standard template library or stl.
    // String header file must be added to use C++ strings!
        #include <string>
    // C++ strings are in standard namespace so define it or type std:: everytime before use them! This is also true for functions and methods of C++ strings!
    // Strings can grow and shrink as needed at runtime!
    // C++ strings can easily converted to c-style strings and converted back again!

    // DECLARE C++ STRING
        string s1;          // Unlike c-style strings, C++ strings are always initialized. This is initialized as empty string! No garbage in memory!
        sring s2 {"Burak"}; // Initilaized as c-style literal, it is okay, converted to c++ string automatically!
        string s3 {s2};     // Initialized as s2 - Burak
        string s4 {"Burak", 3};  // First three letters of string will be "Bur"
        string s5 {s3, 0, 2};  // 0 is  startin index, 2 is length "Bu"
        string s6 (3, 'X'); // three times 'X' will be "XXX", be aware that uses paranthesis instad of curlies! 

    // ASSIGN C++ STRINGS
        string s1;
        s1 = "C++ rocks!";
        s2 = s1;            // Another way of assigment!

    // CONCATENATE (ADD) STRINGS
        string part1 {"C++"};
        string part2 {"rocks"};
        string sentence;
        sentence = part1 + " " + part2; + "!";

        sentence = "C++" + " rocks!" // Will not compile since two c-style literals can not be concatenated. But if we put a c++ string as shown above it would be compiled!

        string s1 = "Burak";
        s1 += " Guzel";   // Burak Guzel   

    // REACH ELEMENT OF A STRING
        cout << part1[0] << endl; // or
        cout << part.at(0) << endl; // as vectors! Performs bounds checking!!!
        
        for(size_t i{0}; i < part1.length(); ++i) {
            cout << part1.at(i);
        }

    // Range based for loop can be used to reach elemnts:
        for (char c: s1)   // If we use int instead of char here, it will show integer value(ASCI codes of those chars) that represents those characters.
            cout << c << endl;

    // COMPARE C++ STRINGS
    // Use ==, !=, >, <, >=, or <=
    // Capital a is less than a capital Z. Capital leaders are > lowercase!
    // Two c++ strings, one c++ string and one c-style string, one c++ string or one c-style lateral can be compared with these operators. Two c-style strings or laterlas can NOT be compared.

        string s0;
        string s1 {"Apple"};
        string s2 {"Banana"};
        string s3 {"Kiwi"};
        string s4 {"apple"};
        string s5 {s1};         // Apple
        string s6 {s1, 0, 3};   // App
        string s7 (10, 'X');    // XXXXXXXXXX

        s1 == s5 // True
        s1 == s2 // False
        s1 != s2 // True
        s1 < s2  // True
        s2 > s1  // True
        s4 < s5  // False because uppercase letters come befor lowercase letters in ASCI table
        s1 == "Apple" // True

    // METHODS OF C++ STRINGS
    // Substring - substr() - 

        string s1 = {"This is a test"};
        cout << s1.substr(0,4);    // This (starts from 0 and subs 4 chars)
        cout << s1.substr(5,2);    // is (starts from 5 and subs 2 chars)
        cout << s1.substr(10,4);    // test (starts from 10 and subs 4 chars)

        
        cout << s0 << endl;                  // No garbage
        cout << s0.length() << endl;     // empty string

    // Search - find() - Returns the beggining of the string or caharcter that is searched!
        string s1 = {"This is a test"};
        cout << s1.find("This");     // 0 -- starts in index 0
        cout << s1.find("is");       // 2
        cout << s1.find("test");     // 10
        cout << s1.find('e');        // 11
        cout << s1.find("is", 4);    // 5  -- Starts from index 4!
        cout << s1.find("XX");       // string::npos means no positin, not found!

        s1.rfind('t') // 13 -- rfind is a string class member function that is used to search the last occurrence of any character in the string

        s1 = "The secret word is Boo";
        string word {};
           
        cout << "Enter the word to find: ";
        cin >> word;
           
        size_t position = s1.find(word);
        if (position != string::npos)    // This can be handy!
           cout << "Found " << word << " at position: " << position << endl;
        else
           cout << "Sorry, " << word <<  " not found" << endl;

    // Remove Char -erase() and clear()
        string s1 = {"This is a test"};
        cout << s1.erase(0,5);   // is a test - erases starting from 0 and 5 elements!
        cout << s1.erase(5,4);   // is a - Reminder string was is a test, this deleted test!

        s1.clear();  // deletes all elements of string, string becomes and empty string

    // Length of a string - length()
        string s1 = "Burak";
        cout << s1.length() << endl; // 5

    // Insert a char or string inside a string - insert -
        string unformatted_full_name {"StephenHawking"};
        unformatted_full_name.insert(7, " ");     // Inserts a space before 7th element of the string! Become ==> Stephen Hawking
    
    // Swap two strings - swap -
        string journal_entry_1 {"Newton"};
        string journal_entry_2 {"Leibniz"};
        if (journal_entry_2 < journal_entry_1)
            journal_entry_2.swap(journal_entry_1); // Swaps newton to entry2 and Leibniz to entry1

    // Input with C++ Strings
    // If you ask user to enter a string and user type space in this string, cin command will get only the part before space!
        cout << "Enter your full name: ";
        cin >> full_name;     
        cout << "Your full name is " << full_name << endl;

    // getline allows us to get string with spaces. Reads entire line untill \n
        cout << "Enter your full name: ";
        getline(cin, s1); // first one is input stream (cin since user enter from keyboard), second one where to store entered input.
        cout << "Your full name is " << full_name << endl;
    
    // Another type of getline
        getline (cin, s1, 'x'); // Program accept input untill x is typed.



 








   
    




    return 0;  
}