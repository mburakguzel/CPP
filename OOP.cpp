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
        return 0;
    }
}