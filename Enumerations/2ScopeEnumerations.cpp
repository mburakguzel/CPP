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

// SCOPED ENUMERATIONS:
    // BETTER TO USE SCOPED ENUMS!
    // That is the enumerations whose enumerators are qualified and therefore they are only visible by using the scope resolution operator. 
    // We declare scoped enumerations using the enum class key: enum class{Red, Green, Blue}; or enum struct{Red, Green, Blue};
    // Unscoped enumerations can cause some issues that can only be handled by using scoped enumerations.
    // Ex:
    // enum Whale {Blue, Beluga, Gray};
    // enum Shark {Greatwhite, Hammerhead, Bull, Blue};     // will cause error since blue was declared above. Scoped enumerations solves this issue.
    // if (Beluga == Hammerhead)        // this will be true since both Belluga and Hammerhead is 1. Scoped enumerations solves this issue.
        // std::cout << "...";
    // The one difference between scoped enumerators and unscoped enumerators is casting:
        // Ex: enum class Item {Milk = 350, Bread = 250, Apple = 132}
        // int milk_code = Item::Milk;          // Generates error cannot convert Item to int. This is not the case with unscoped enumerations.
        // int milk_code = int(Item::Milk);     // This is fine!
        // int milk_code = static_cast<int>(Item::Milk);     // This is also fine!

#include <iostream>
#include <vector>

// Used for test1
// Scoped enumeration holding the items for a grocery list. The value of the enumerator could be the item code
enum class Grocery_Item {Milk=350, Bread=250, Apple=132, Orange=100};

// Used for test1
// Overloaded stream insertion operator.
// Inserts the name grocery item paramter to the input stream
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_item);
	switch (grocery_item) {
	    case Grocery_Item::Milk:        // this is just Milk in unscoped enumerations, see test2 in UnscopedEnumerations.cpp
            os << "Milk";
            break;
		case Grocery_Item::Bread:
            os << "Bread";
            break;
		case Grocery_Item::Apple:     
            os << "Apple";
            break;
		case Grocery_Item::Orange:    
            os << "Orange";
            break;
		default:        
            os << "Invalid item";
	}
    os << " : " << value;
	return os;
}

// Used for test1
// Returns a boolean depending on whether the Grocery_Item paramter is a valid enumerator or not.
bool is_valid_grocery_item(Grocery_Item grocery_item)
{
	switch (grocery_item) {
	    case Grocery_Item::Milk:  
        case Grocery_Item::Bread:
        case Grocery_Item::Apple:
        case Grocery_Item::Orange:
            return true;
		default:        
            return false; 
	}
}

// Used for test1
// Displays the grocery items in the grocery list
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

// Using a scoped enumeration to model grocery items
void test1() {
	std::cout << "\n--- Test1 --------------------------\n" << std::endl;
	
	std::vector<Grocery_Item> shopping_list;
	
	shopping_list.push_back(Grocery_Item::Apple);
	shopping_list.push_back(Grocery_Item::Milk);
	shopping_list.push_back(Grocery_Item::Orange);
	
    int Helicopter {1000};
 // shopping_list.push_back(Helicopter);                // Compiler error
	shopping_list.push_back(Grocery_Item(Helicopter));  // Invalid item
    shopping_list.push_back(Grocery_Item(350));         // Will add Milk again!
	
	display_grocery_list(shopping_list);
    // displays Apple : 132
    // displays Milk : 350
    // displays Orange : 100
    // displays Invalid item : 1000
    // displays Milk : 350
    // displays Valid items: 4
    // displays Invalid items: 1
    // displays Total items: 5
}

// Used for test2
// A simple class that might model a Player in a game application.
// The player has a name, a mode that they are currently in, and a direction which they are facing.
class Player {
    friend std::ostream &operator<<(std::ostream &os, const Player &p);
public:
    enum class Mode {Attack, Defense, Idle};
    enum class Direction {North, South, East, West};
    
    Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North):
        name{name}, mode{mode}, direction{direction} {}

    std::string get_name() const {
        return name;
    }
    void set_name(std::string name) {
        this->name = name;
    }
    
    Mode get_mode() const {return mode; }
    void set_mode(Mode mode) {
        this->mode = mode;
    }

    Direction get_direction() const {return direction; }
    void set_direction(Direction direction) {
        this->direction = direction;
    }
private:        // Attributes of the player.
    std::string name;
    Mode mode;
    Direction direction;
};

// Used for test2
// A simple function that returns the string representation of the Player::Mode paramter passed into it.
std::string get_player_mode(Player::Mode mode) {
    std::string result;
    switch (mode) {
        case Player::Mode::Attack:
            result = "Attack"; 
            break;
        case Player::Mode::Defense:
            result = "Defense";
            break;
        case Player::Mode::Idle:
            result = "Idle";
            break;
    };
    return result;
}

// Used for test2
// A simple function that returns the string representation of the Player::Direction paramter passed into it.
std::string get_player_direction(Player::Direction direction) {
    std::string result;
     switch (direction) {
        case Player::Direction::North:
            result = "North"; 
            break;
        case Player::Direction::South:
            result = "South"; 
            break;
        case Player::Direction::East:
            result = "East"; 
            break;
        case Player::Direction::West:
            result = "West"; 
            break;
    };
    return result;
}

// Used for test2
// Overloading the output stream insertion operator so we can easily put Player objects on the output stream.
std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << "Player name:      " << p.get_name() << "\n"
       << "Player mode:      " << get_player_mode(p.mode) << "\n"
       << "Player direction: " << get_player_direction(p.direction) 
       << std::endl;
    return os;
}


void test2() {
   	std::cout << "\n--- Test2 --------------------------\n" << std::endl;

    Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::North};      
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};     
    Player p3{"Sephiroth", Player::Mode::Idle, Player::Direction::South};           

    std::cout << p1 << std::endl; 
    // displays Player name:      Cloud Strife
    // displays Player mode:      Attack
    // displays Player direction: North
    std::cout << p2 << std::endl;
    // displays Player name:      Cloud Strife
    // displays Player mode:      Attack
    // displays Player direction: North 
    std::cout << p3 << std::endl;
    // Player name:      Sephiroth
    // Player mode:      Idle
    // Player direction: South
}


int main()
{
    test1();
    test2();
	std::cout << "\n";
	return 0;
}