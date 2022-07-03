#include <iostream> 
#include <cctype>    // In order to use char functions, we need to add cctype library
using namespace std; 

int main() 
{
    char c {};
    // In order to use char functions, we need to add cctype library:  #include <cctype>
    // Functions for testing char:
    isalpha(c); // true if c is a letter
    isalnum(c); // true if c is a letter or digit
    isdigit(c); // true if c is a digit
    islower(c); // true if c is a lowercase letter
    isprint(c); // true if c is a printable charecter
    ispunct(c); // true if c is a punctiation
    isupper(c); // true if c is a uppercase letter
    isspace(c); // true if c is a whitespace

    // Functions for converting char:
    tolower(c); // returns lowercase of c
    toupper(c); // returns uppercase of c


    return 0;  
}