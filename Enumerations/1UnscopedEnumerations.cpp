// Enumerations a.k.a enumaration data types or enums.
// Enumeration is a user-defined type that models a set of constant integral values.
// Ex: Suppose we want to define a type that holds a value, that represents a day of the week. (Mon, Tue, Wed, ..)
// Enumerations are introduced in order to increase the readability of the codes.
// Many elements of enumerations are optional. We may see enumerations without names, types or attributes.

// STRUCTURE OF ENUMERATIONS:
    // enum-key enum-name : enumerator-type { };
    // enum-key defines the scope of the enumeration, can be scoped or unscoped.
    // enum-name is optional name of the enumeration.
    // enumerator-type: specified type serves as the fixed underlying type of the enumerations enumerators. This is also optional but can be used to reduce the amount of space that enum uses.
    // { } enumerator list: The last part of the enumeration is a set of curly braces, and this is the enumerations enumerator. This is where we define the names and integral values of the enumerators.
// Examples:
    // enum {Red, Green, Blue} // no name, no fixed underlying type! Compiler will automatically initializes to 0, 1 and 2, unless there is a initiazlization. Implicit initialization.
    // enum {Red = 1, Green = 2, Blue = 3} // Explicit initialization. - underlying type will be determined based on the magnitude of numbers, for this one it is integer.
    // enum {Red = 1, Green, Blue} // Explicit/Implicit initialization.
// Nameless enumerations are often referred to as anonymous enumerations. Since they have no name, it is not possible to declare variables of that enumeration type.
    // enum {Red, Green, Blue};
    // int my_color;
    // my_color = Green;        // Valid
    // my_color = 4;            // Also valid - but can cause confusion.
// By providing a name we define the enumeration asa uniqe type that can only assume its enumerated. Unlike the previous example withno name:
    // enum Color {Red, Green, Blue};
    // Color my_color;
    // my_color = Green;        // Valid
    // my_color = 4;               // Not valid!

// UNSCOPED ENUMERATIONS:
    // BETTER TO USE SCOPED ENUMS!
    // When an enumeration is unscoped, its enumerators are unqualified and they are visible throughout the entire scope in which theenumeration was declared.
    // This means that if we want to use an enumerations enumerators, it is not necessary to specify which enumeration the enumerator belongs to.
#include <iostream>
#include <vector>
#include <string>

// Used for test1
enum Direction {North =1, South=10, East, West };
// enum Street {Main, North, Elm};   // Error, can't use North again


// Used for test1
// This function expects a Direction paramater and returns its string representation
// Defined as string to cout, otherwise it is needed to overload the << operator.
std::string direction_to_string(Direction direction) {
    std::string result;
    switch (direction) {
        case North:
            result = "North";
            break;
        case South:
            result = "South";
            break;
        case East:
            result = "East";
            break;
        case West:
            result = "West";
            break;
        default:
            result = "Unknown direction";
    }
    return result;
}

// Simple example that shows the use of an unscoped enumeration
void test1() {
   	std::cout << "\n--- Test1 --------------------------\n" << std::endl;

    Direction direction {North};
    std::cout << "\nDirection " << direction << std::endl;          // displays Direction 1
    std::cout << direction_to_string(direction) << std::endl;       // displays North
    
    direction = West;
    std::cout << "\nDirection " << direction << std::endl;          // displays Direction 12 - since south was initialized to 10 above
    std::cout << direction_to_string(direction) << std::endl;       // displays West

    
    // direction = 5;  // Compiler Error
    
    // Be careful casting since the compiler will assume you know what you are doing!
    direction = Direction(100);                                     // do not cause any error!
    std::cout << "\nDirection " << direction << std::endl;          // displays Direction 100
    std::cout << direction_to_string(direction) << std::endl;       // displays Unknown direction

    
    direction = static_cast<Direction>(100);
    std::cout << "\nDirection " << direction << std::endl;          // Displays Direction 100
    std::cout << direction_to_string(direction) << std::endl;       // displays Unknown direction
}

// Used for test2
// Unscoped enumeration representing items for a grocery shopping list
enum Grocery_Item {Milk, Bread, Apple, Orange};

// Overloading the stream insertion operator to insert the string representation of the provided Grovery_Item parameter into the output stream
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)   // oerloading the << operator to use Grocery_Item with cout <<
{
	switch (grocery_item) {
	    case Milk:      
            os << "Milk"; 
            break;
		case Bread:     
            os << "Bread"; 
            break;
		case Apple:     
            os << "Apple"; 
            break;
		case Orange:    
            os << "Orange"; 
            break;
		default:        
            os << "Invalid item"; 
	}
	return os;
}

// Used for test2
// Returns a boolean depending on whether the Grocery_Item paramter is a valid enumerator or not.

bool is_valid_grocery_item(Grocery_Item grocery_item)
{
	switch (grocery_item) {
	    case Milk:  
        case Bread:
        case Apple:
        case Orange:
            return true;    // returns true if Milk, Bread, Apple or Orange is entered.
		default:        
            return false;   // returns false otherwise.
	}
}

// Used for test2
// Given a vector of Grocery_Items, this function displays the string representation of each item using the overloaded operator<< function.
// This function also keeps track of how many valid and invalid items are in the provided vector by using the is_valid_grocery_item function written above.
void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
	std::cout << "Grocery List" << "\n==============================" << std::endl;
    int invalid_item_count{0};
    int valid_item_count {0};
	for (Grocery_Item grocery_item : grocery_list)
	{
		std::cout << grocery_item << std::endl;  // User the overloaded operator<<
		
		// Check that grocery is valid grocery item
		if (is_valid_grocery_item(grocery_item))
            valid_item_count++;
        else
			invalid_item_count++;
	}
	
	std::cout << "==============================" << std::endl;
    std::cout << "Valid items: " <<  valid_item_count << std::endl;
    std::cout << "Invalid items: " <<  invalid_item_count << std::endl;
	std::cout << "Total items: " <<  valid_item_count +invalid_item_count << std::endl;
}

// Using an unscoped enumeration to model grocery items
void test2() {
	std::cout << "\n--- Test2 --------------------------\n" << std::endl;
	
	std::vector<Grocery_Item> shopping_list;
    
	shopping_list.push_back(Apple);
	shopping_list.push_back(Apple);
	shopping_list.push_back(Milk);
	shopping_list.push_back(Orange);
	
    // Grocery_Item item = 100;                         // Compiler error
    
    // Be careful when casting
    int Helicopter {1000};
    
	shopping_list.push_back(Grocery_Item(Helicopter));  // Invalid item
    shopping_list.push_back(Grocery_Item(0));           // Will add Milk again!
    
	display_grocery_list(shopping_list);
    // displays Apple
    // displays Apple
    // displays Milk
    // displays Orange
    // displays Invalid item - because of Helicopter!
    // displays Milk
    // ========================================
    // Valid items: 5
    // Invalid items: 1
    // Total items: 6

}

// Used for test3
// Unscoped enumerations holding the possible states and sequences of a rocket launch.
// Note the addition of the Unknown enumerator for the State enumeration.
enum State {Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence{Abort, Hold, Launch};


// Used for test3
// Overloading the stream extraction operator to allow a user to enter the state of State enumeration.
// Note the use of underlying_type_t.

std::istream &operator>>(std::istream &is, State &state) 
{
    // int user_input;   // Will also work
    std::underlying_type_t<State> user_input;       //std::underlying_type_t allows user to type in data to user_input
    is >> user_input;
	
    switch (user_input) {
        case Engine_Failure:       
        case Inclement_Weather:
        case Nominal:
        case Unknown:
            state = State(user_input);
            break;
        default:                   
            std::cout << "User input is not a valid launch state." << std::endl;
            state = Unknown;
    }
	
    return is;
}

// Used for test3
// Overloading the stream insertion operator to insert the string representation of the provided Sequence parameter into the output stream.
std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
	switch (sequence) {
	    case Abort:    
            os << "Abort"; 
            break;
		case Hold:      
            os << "Hold"; 
            break;
		case Launch:    
            os << "Launch"; 
            break;
    }
	
	return os;
}

// Used for test3
// Displays an information message given the sequence parameter.
void initiate(Sequence sequence)
{
	std::cout << "Initiate " << sequence << " sequence!" << std::endl;   // Uses overloaded operator<<
}

// Using unscoped enums to control a rocket launch Reads input from the user for the State of the rocket launch, and then determines wich Sequence to execute.
void test3() {
	std::cout << "\n--- Test3 --------------------------\n" << std::endl;
	
	State state;
	std::cout << "Launch state: ";
	std::cin >> state;               // users the overloaded operator>>
	
	switch (state) {
		case Engine_Failure:        // Abort if Engine Failure
        case Unknown:               // or Unknown!
            initiate(Abort); 
            break;
		case Inclement_Weather:    
            initiate(Hold); 
            break;
		case Nominal:              
            initiate(Launch); 
            break;
	}    
}

int main()
{
    test1();
	test2();
	test3();
	
	std::cout << "\n";
	return 0;
}