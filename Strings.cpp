#include <iostream> 
#include <cctype>    // In order to use c-style strings, we need to add cctype library #include <cctype>
#include <cstring>   // Library to use c-style string functions. (e.g strlen)
// #include <cstlib>  // Library to convert strings to other types!  Not works!   
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
        char my_name [8] {"Burak"};
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

    



   
    




    return 0;  
}