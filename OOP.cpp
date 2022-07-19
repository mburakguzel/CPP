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

    // DESTRUCTORS
    // Destructors are also special member methods that have the same name as the class. However, destructors have a tilde preceiding their name.
    // Destructors are invoked automatically by C++ when an object is destroyed. Greate please to release memory, closed files and free up any other resources.
    // Makes no sense to allow overloaded destructors means only one destructor is allowed per class, can not be overloaded.
    // If we do not provide any constructor or destructor, c++ will automatically provide a default constructor that are empty.
}