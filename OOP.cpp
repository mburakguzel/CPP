#include <iostream>
#include <vector>
#include <string>

using namespace std;     // DO NOT USE THIS IF YOU WANT TO BE A GOOD PROGRAMER!

// DECLARE CLASSES
    // Classes are user defined types.
    // Functions of classes are called methods.
    // Classes can hide data and methods that are only used intenally by the class!
    // Objects are created from class and represent a specific instance of the class they are created from.
    // each object has its own identity and can use any method defined in class! 

class Player {       // best practice is the capitalize first letter of the user defined classes!
                     // If we declare a class in the main, it can be only used in main not in other functions!!!!
public:      // this makes our class public, otherwise can not be reached from main!!!
    // attributes    
    string name {"Player"};
    int health {100};
    int xp {3};
    
    // methods of the class
    void talk(string text_to_say) { cout << name << " says " << text_to_say << endl;  } // easy way to define a method, will be discussed in detail!!
    bool is_dead();
};

class Account {
public:                 // this makes our class public, otherwise can not be reached from main!!!
    // attributes
    string name {"Account"};
    double balance {0.0};
    
    // methods of the class
    bool deposit(double bal) {balance += bal; cout << "In deposit" << endl; }        // easy way to define a method, will be discussed in detail!!
    bool withdraw(double bal) {balance -= bal; cout << "In withdraw" << endl;  }    // easy way to define a method, will be discussed in detail!!
    
};

int main(){
    // Objects of Account
    Account frank_account;
    Account jim_account;
    
    // ACCESS CLASS MEMBERS
    // We can acces class elements by using . operator as we did in strings and vectors!     
    frank_account.name = "Frank's account";  // methods and attributes defined in class can be used by . operator!
    frank_account.balance = 5000.0;
    frank_account.deposit(1000.0);
    frank_account.withdraw(500.0);

    // Objects of player!
    Player frank;
    Player hero;
    Player players[] {frank, hero};

    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");   // Frank says Hi there. refers to talk method in class.     
    
    vector<Player> player_vec {frank};
    player_vec.push_back(hero);    
    
    Player *enemy {nullptr};   // pointer object of player
    enemy = new Player;
    // For pointers, we need to dereference them first by using asteriks operator. Use paranthesis since . opeaor has higher  precedence than asteriks!!!!
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    // Or use the member of pointer operator (arrow operator (->)), it is same with dot operator!
    enemy->xp = 15;
    enemy->talk("I will destroy you!");
    
    delete enemy;               // Always delete pointer from heap (free memory) when you are done with it.

    // Class member access modifiers
        // 1) Public: accessible everywhere. (type public: in class)
        // 2) Private: accessible only by members or friends of the class (type private: in class)
        // 3) Protected: used with inheritance (miras, veraset) -- will be discussed in inheritance section! (type protected: in class)

    class Player {
    private:                // means name, health and xp are private. These are only accesible for the other elements of the class or friends of the class (what is frien of a class?)
        // attributes       // this is how c++ implements information hiding!  
        string name {"Player"};
        int health;
        int xp;
    public:
        // methods    // Accesible for everyone!
        void talk(string text_to_say) { cout << name << " says " << text_to_say << endl;  }
        bool is_dead();
    };

    int main() {
        Player frank;
    //  frank.name = "Frank";                    // Causes error since name is private.
    //  cout << frank.health << endl;            // Causes error since name is private. 
    frank.talk("Hello there");                   // Okay, since talk is public!
    // The reason we use this is that; let`s say max value for health is 100, you do not want someone to change it. You can create a method to change health accordingly. 
    // Since it is private, a method defined in class can access it, causes no error!
    // Also since only these methods can access this private values, if something with wrong with them, we can easily find the error in code just checking the public methods of the class because only they can access them!
    }

    // MEMBER METHODS IN CLASSES!
    // They are implemented in a manner very similar to the way we implement functions.
    // Member methods have access to the classes member attributes.
    // You can define a member method right inside the class declaration. This is okay for small and relatively simple methods.
    // We tend to declare complex methods outside the class decleration.
    // We usually create a header or include file that has a .h or .hpp extension for the class specification and then seperate .cpp file for class implementation.

    // Declare methods inside classes:

    class Account {
    private:
        // attributes
        string name;
        double balance;
        
    public:
        // methods
        // declared inline
        void set_balance(double bal) { balance = bal; }
        double get_balance() { return balance; }
        
        // methods will be declared outside the class declaration
        void set_name(string n);
        string get_name();
        
        bool deposit(double amount);
        bool withdraw(double amount);
    };
    
    // Declare methods outside the classes:

    void Account::set_name(string n) {
        name = n;
    }

    string Account::get_name() {
        return name;
    }

    bool Account::deposit(double amount) {
        // if verify amount
        balance += amount;
        return true;
    }

    bool Account::withdraw(double amount) {
        if (balance-amount >= 0) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
    
    int main() {
    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);
    
    if (frank_account.deposit(200.0))
        cout << "Deposit OK" << endl;
    else 
        cout << "Deposit Not allowed" << endl;
        
    if (frank_account.withdraw(500.0))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
        
    if (frank_account.withdraw(1500.0))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
    
    return 0;
}
    
// Declare methods in a header file:
// Create a file with name Account.h Below code must be in Account.h
// If Account.h header file is included by more than one cpp file, then the compiler will se the declaration for the account class more than once,
// and give us an error about dublicate declerations. In order to solve this we can use an include guard that ensures that the compiler will process this file only once.
// Account.h:
    #ifndef _ACCOUNT_H_    // This checks to see if the preprocessor has a symbol named _Account_h_. This symbol can be anything we want(but must be unique in the program). Best practice is to use some sort of combination of the file name.
    #define _ACCOUNT_H_    // If the preprocessor has that name defined (used in multiple cpp files), then it skips the entire file and goes to the pound end if at the end.
    #include <string>
    // # pragma once   // this is doing the smae thing as include guard given above. However some compiler does not support this directive!  
    
    class Account {
    private:
        // attributes
        std::string name;
        double balance;
        
    public:
        // methods
        // declared inline
        void set_balance(double bal) { balance = bal; }
        double get_balance() { return balance; }
        
        // methods will be declared outside the class declaration
        void set_name(std::string n);
        std::string get_name();
        
        bool deposit(double amount);
        bool withdraw(double amount);
    };

    #endif // _ACCOUNT_H_

    // In order to implement this header file we need to create a seperate cpp file.
    // Account.cpp:
    // #include <iostream> // is used to include system header files and the compiler knows wherethese located.
    #include "Account.h" // is used to include header files that are local to this project. Compiler also knows where those are.
    // Methods of classes should be defined in this cpp file!
    void Account::set_name(std::string n) {
        name = n;
    }

    std::string Account::get_name() {
        return name;
    }

    bool Account::deposit(double amount) {
        // if verify amount
        balance += amount;
        return true;
    }

    bool Account::withdraw(double amount) {
        if (balance-amount >= 0) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    // Use this class in main:

    #include <iostream>
    #include "Account.h"    // never include .cpp files!

    using namespace std;

    int main() {
        Account frank_account;
        frank_account.set_name("Frank's account");
        frank_account.set_balance(1000.0);
        
        if (frank_account.deposit(200.0))
            cout << "Deposit OK" << endl;
        else 
            cout << "Deposit Not allowed" << endl;
            
        if (frank_account.withdraw(500.0))
            cout << "Withdrawal OK" << endl;
        else
            cout << "Not sufficient funds" << endl;
            
        if (frank_account.withdraw(1500.0))
            cout << "Withdraw OK" << endl;
        else
            cout << "Not sufficient funds" << endl; 
        
        return 0;
    }

    // CONSTRUCTORS 
    // Constructors are special member methods that are invoked (yakarmak, cagirmak) during object creatation.
    // They are commonly used for initialization. Constructors are easy to recognize since they have the same name as the class.
    // Constructirs do not specify a return type and like other methods they can be overloaded.
    // Classes can have as many constructors as necessary. The only restriction is that they must each have a unique signature. Program can call them based on the initialization information provided.
    // If there is a ambiguity, compiler will generate a compiler error.
    // Each constructor is actually a way to create object! Overloading constructors are ways to define multiple ways to define an object and initialize it (to prevent them to have garbage data!).

class Player
{
private:
   std::string name;
   int health;
   int xp;
public:
    void set_name(std::string name_val) { 
        name = name_val; 
    }
    // Overloaded (used more than once as shown below) Constructors
    Player() { 
        cout << "No args constructor called"<< endl;
    }
    Player(std::string name) { 
        cout << "String arg constructor called"<< endl;
    }
    Player(std::string name, int health, int xp) {
        cout << "Three args constructor called"<< endl; 
    }
    ~Player() {       // When the block ends destructors will be called automatically. Whatever code we provide in, the destructors will be executed before the objects are destroyed.
        cout << "Destructor called for " << name << endl; 
    }
};

int main() {

    {
        Player slayer;
        slayer.set_name("Slayer");    // When the block ends destructors will be called automatically. Whatever code we provide in, the destructors will be executed before the objects are destroyed.
    }
    
    {
        Player frank;
        frank.set_name("Frank");
        Player hero("Hero");
        hero.set_name("Hero");
        Player villain("Villain", 100, 12);
        villain.set_name("Villain");   // When the block ends destructors will be called automatically. Whatever code we provide in, the destructors will be executed before the objects are destroyed. Goes from buttom to up!
    }
    
    Player *enemy = new Player;
    enemy->set_name("Enemy");
    
    Player *level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Level Boss");
    
    delete enemy;
    delete level_boss;
    
    return 0;
}
    // Another Example to constructors:

    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
        void set_name(std::string name_val) { 
            name = name_val; 
        }
        std::string get_name() {
            return name;
        }
        Player() {
            name = "None";
            health = 100;
            xp = 3;
        }
        Player(std::string name_val, int health_val, int xp_val) {
            name = name_val;
            health = health_val;
            xp = xp_val;
        }
        
    };

    int main() {
        Player hero;
        Player frank {"Frank", 100, 13};
        frank.set_name("Frank");
        cout << frank.get_name() << endl;
        return 0;
    } 
    // DESTRUCTORS
    // Destructors are also special member methods that have the same name as the class. However, destructors have a tilde preceiding their name.
    // Destructors are invoked automatically by C++ when an object is destroyed. Greate please to release memory, closed files and free up any other resources.
    // Makes no sense to allow overloaded destructors means only one destructor is allowed per class, can not be overloaded.
    // If we do not provide any constructor or destructor, c++ will automatically provide a default constructor that are empty.

    // INSTRUCTOR INITIALIZATION LIST
    // So far, we have written our codes so that we initialize our data membet values in the constructor body by assigning values to them. But this is technically not initialization!
    // Because by the time the constructor body is executed, these member attributes have already been created. (Means members are created before constructors.)

    class Player
    {
    private:
    std::string name {"XXXXXXX"};
    int health;
    int xp;
    public:
    // Overloaded Constructors
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
    };

    Player::Player() 
        : name{"None"}, health{0}, xp{0} {      // This is the new way of initializing, before we were actually assigning data not initializing as show below. Order of parameters here is not important. How we define them in class is important!
    }                                           // This happens before the body of the constructor is ever executed!

/*    Player() {                                // So basically, when we use this code in constructor, we initialize and assign another value to parameter. This is unnefficient.
        name = "None";
        health = 100;
        xp = 3;
    } */

    Player::Player(std::string name_val) 
    : name{name_val}, health{0}, xp{0} {
    }
    
    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
        
    }

    int main() {
        
        Player empty;
        Player frank {"Frank"};
        Player villain {"Villain", 100, 55};
        
        return 0;
    }
    // DELEGATING CONSTRUCTORS
    // This feature prevent us to dublicate our code. We use three args constructor (constructor with most constructors!) to build other constructors. 
    // This is the most efficient way of creating constructors! But will be one step further below in default constructor parameters!

    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
    // Overloaded Constructors
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
    };

    Player::Player() 
        : Player {"None",0,0} {         // Here we are delegating (calling) to three args constructor and run it to build this constructor!!!
            cout << "No-args constructor" << endl;
    }

    Player::Player(std::string name_val) 
    : Player {name_val,0, 0}  {
            cout << "One-arg constructor" << endl;
    }
    
    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
                cout << "Three-args constructor" << endl;
    }

    int main() {
        
        Player empty;
        Player frank {"Frank"};
        Player villain {"Villain", 100, 55};
        
        return 0;
    }
    // DEFAULT CONSTRUCTOR PARAMETER
    // Creating all objects with only one constructor.
    // For the above example, if you create an object with two args, this would cause an error. However, for this type of declaration is okay with that.
    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
        Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
    //  Player() {}    // Will cause a compiler error
    };

    
    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
                cout << "Three-args constructor" << endl;
    }


    int main() {
        
        Player empty;
        Player frank {"Frank"};
        Player hero {"Hero", 100};
        Player villain {"Villain", 100, 55};
        
        return 0;
    }
    // COPY CONSTRUCTOR
    // When objects are copied, C++ must be able to create a new object from an existing object. In order to use this, it uses something called a copy constructor.
    // When it is used?
        // 1) passing object by value as a parameter.
        // 2) Returning an object from a function by value.
        // 3) Constructing one object based on another of the same class.
    // We can provide our own copy constructor and we can define exactly the semantics we need for object copying. But if we don`t provide a copy constructor, the c++ compiler will provide a compiler genereated one.
    // If your class has raw pointers as a member, and do not create a copy constructor, compiler generated constructor will copy only adress(pointer) not the data! This is called shallow copy.
    // Therefore always define copy constructors when you use raw pointers. Provide the copy constructor with a const reference parameter.
    // Use STL classes as they alreay provide copy constructors or use smart pointers. Will learn about them later!

    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
        std::string get_name() { return name; }
        int get_health() { return health; }
        int get_xp() {return xp; } 
        
        Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
        // Copy constructor                  // Const avoids us to modify the source, we only copy it without modifying.
        Player(const Player &source);        // if we pass it in by value, then we have to make a copy of it. That`s the whole point of the copy constructor. We would defeat the purpose and end up with never ending recursive calls.
        // Destructor
        ~Player() { cout << "Destructor called for: " << name << endl; }
    };

    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
                cout << "Three-args constructor for " + name << endl;
    }

    Player::Player(const Player &source)
    // : name(source.name), health(source.health), xp{source.xp} {      // Without delegating!
        : Player {source.name, source.health, source.xp}  {             // Using delegating constructor here again!
            cout << "Copy constructor - made copy of: " << source.name << endl; 
    }

    void display_player(Player p) {                       // Copy of object in function. Notice that this is a local object, when function is done the destructor will be called as well.
        cout << "Name: " << p.get_name() << endl;
        cout << "Health: " << p.get_health() << endl;
        cout << "XP: " << p.get_xp() << endl;    
    }

    int main() {    
        Player empty {"XXXXXX", 100, 50};
        
        Player my_new_object {empty};
        
        display_player(empty);
        
        Player frank {"Frank"};
        Player hero {"Hero", 100};
        Player villain {"Villain", 100, 55};
            
        return 0;
    }

    // SHALLOW COPY
    // First we assume that object that wea re copying has a raw pointer. During the contstruction of the pointer, we will allocate storage for the data that pointer is pointing to. And when we are done with the copy, release the allocated memory.
    // Shallow copy: default behaviour of compiler provider copy constructor!
        // Memberwise copy (Newly created object and the object beicg copied both pointing to the same area of storage in the heap.)
        // Each data member is copied from the source object.
        // The pointer is copied NOT what it points to.
        // PROBLEM: when we release the storage in the decustructor, the other object still refers to the released storage!
    
    class Shallow {     // This program crashes to show problem!
    private:
        int *data;
    public:
        void set_data_value(int d) { *data = d; }
        int get_data_value() { return *data; }
        // Constructor
        Shallow(int d);
        // Copy Constructor
        Shallow(const Shallow &source);
        // Destructor
        ~Shallow();
    };

    Shallow::Shallow(int d) {
        data = new int;
        *data = d;
    }

    Shallow::Shallow(const Shallow &source) 
        : data(source.data) {
            cout << "Copy constructor  - shallow copy" << endl;
    }

    Shallow::~Shallow() {
        delete data;
        cout << "Destructor freeing data" << endl;
    }

    void display_shallow(Shallow s) {
        cout << s.get_data_value() << endl;
    }

    int main() {
        
        Shallow obj1 {100};
        display_shallow(obj1);
        
        Shallow obj2 {obj1};
        obj2.set_data_value(1000);         // Sets the value to 1000, since both ponters refer to this are, other pointers value also becomes 1000.
        
        // But this is not the real problem, when the program ends, deconstructors become active to relase the areas. This causes program to crash!!!
        return 0;
    }

    // DEEP COPY
    // Create a copy of the pointed to data.
    // Each copy will have a pointer to unique storage in the heap.
    // Use Deep copy when you have a raw pointer as a class member. 

    class Deep {
    private:
        int *data;
    public:
        void set_data_value(int d) { *data = d; }
        int get_data_value() { return *data; }
        // Constructor
        Deep(int d);
        // Copy Constructor
        Deep(const Deep &source);
        // Destructor
        ~Deep();
    };

    Deep::Deep(int d) {
        data = new int;
        *data = d;
    }

    Deep::Deep(const Deep &source)
        : Deep {*source.data} {
        cout << "Copy constructor  - deep copy" << endl;
    }

    Deep::~Deep() {
        delete data;
        cout << "Destructor freeing data" << endl;
    }

    void display_deep(Deep s) {
        cout << s.get_data_value() << endl;
    }

    int main() {
        
        Deep obj1 {100};
        display_deep(obj1);
        
        Deep obj2 {obj1};
        
        obj2.set_data_value(1000);
    
        return 0;
    }

    // MOVE CONSTRUCTOR
    // Introduced after C++11
    total = 100 + 200 // this statement generates an unnamed temp value and store 300 in this temp value first.
                      // the 300 is then stored in the variable total. then the temp value is discarded. 
    // The same happens with objects, however, with objects there can be a great amount of overhead if copy constructors are called over and over again.
    // When we have raw pointers and we perform deep copies, the overhead is even greater. This is where move semantics and the move constructor comes into picture.
    // Move constructor moves the object rather than copies it, this can be extremely efficient. (copying can be computationally expensive!)
    // Move  constructors are optional, if you do not provide them, then the copy constructors will be called.
    // In debugger when you run a code, if you do not see the move or copy constructor is called, it is normal. This is because of the compiler optimization. (return value optimization)
    // Also called as copy illusion.
    // R-value (right value, the values which are written on the right hand side of the statements.) references are references to R-values (temporary datas or objects that is mentioned above!)
    // R-value reference operator is &&, while l-value reference operator is & as discussed before.

    // Difference between default member-wise copy and the move:
        // What we have with move is that an object who owns the data on the heap and then the original object with a null pointer to that data.
        // In memberewise copy, both pointers were still referring to the data in the heap?????
    
    // No const parameter can be used in move constructor, since we need to modify it in order to null out its pointer.

    class Move {
    private:
        int *data;
    public:
        void set_data_value(int d) { *data = d; }
        int get_data_value() { return *data; }
        // Constructor
        Move(int d);
        // Copy Constructor
        Move(const Move &source);
        // Move Constructor
        Move(Move &&source) noexcept;
        // Destructor
        ~Move();
    };

    Move::Move(int d)  {
        data = new int;
        *data = d;
        cout << "Constructor for: " << d << endl;
    }

    // Copy ctor
    Move::Move(const Move &source)
        : Move {*source.data} {
            cout << "Copy constructor  - deep copy for: " << *data << endl;
    }

    //Move ctor
    Move::Move(Move &&source) noexcept 
        : data {source.data} {
            source.data = nullptr;               // Without this constructor become a copy constructor.
            cout << "Move constructor - moving resource: " << *data << endl;
    }

    Move::~Move() {
        if (data != nullptr) {
            cout << "Destructor freeing data for: " << *data << endl;
        } else {
            cout << "Destructor freeing data for nullptr" << endl;
        }
        delete data;
    }

    int main() {
        vector<Move> vec;

        vec.push_back(Move{10});

        vec.push_back(Move{20});
        vec.push_back(Move{30});
        vec.push_back(Move{40});
        vec.push_back(Move{50});
        vec.push_back(Move{60});
        vec.push_back(Move{70});
        vec.push_back(Move{80});


        return 0;
    }

    // `THIS` POINTER
    // As we have stepped through our code in the debugger, you have seen an identifier named this in the debugger pane (work directory). 
    // 'This' is a reserved keyword that contains the address of the current object. so, it is a pointer to the object that is currently being used by the class member methods.
    // The this keyword can only be used within the scope of the class.
    // In many other OOP languages, we use the word 'self' insead of 'this'.
    // We can use 'this' to explicitly access data members and methods. We can also use it to determine if two objects are the same.

    void Account::set_balance()  {
        balance = bal;   // this->balance is implied (ima edilmek, kastetmek)
    }
    // or comparing two objects
    int Account::compare_balance(const Account &other){
        if (this == &other)
            std::cout << "The same objects" << std::endl;
    }
    
    // USING CONST WITH CLASSES

    class Player
{
private:
    std::string name;
    int health;
     int xp;  
public:
    std::string get_name() const  {         // 4) In order to eliminate errors given below (2), we need to tell compiler that our method will not change the parameter by adding that const there!
        return name;                        // 5) if you modify the object in the body of this method, you would get a compiler error.
    }
    void set_name(std::string name_val)   {
        name = name_val;
    }
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player() 
    : Player {"None",0,0} {
}

Player::Player(std::string name_val) 
   : Player {name_val,0, 0}  {
}
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
}

void display_player_name(const Player &p) {
    cout << p.get_name() << endl;              // 3) Generates error since p.get_name can potentally modify the const parameter p! 
}

int main() {
    
    const Player villain {"Villain", 100, 55};    // We can not change the atributes of this object since it is const!
    Player hero {"Hero", 100, 15};
    
   // villain.set_name("Super villain");   // 1) generates error since object is const!
    cout << villain.get_name() << endl;    // 2) generates also error since object is const and compiler thinks that this function has potential to change the object!!!
    cout << hero.get_name() << endl;   
    
    display_player_name(villain);
    display_player_name(hero);

    
  
    return 0;
}

    }