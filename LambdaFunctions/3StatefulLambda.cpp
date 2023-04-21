// STRUCTURE OF LAMDA FUNCTIONS:
    // [] () -> return_type specifiers {};
    // [] => capture list; defines the start of the lambda.
    // () => parameter list; comma separated list of parameters. Every time the lambda executes, whatever parameter we specify in this parameter list will be passed into the lambda.
    //  -> return_type => the type that is returned by the lambda expression. If the return is void (gecersiz, hukumsuz), then we can omit(dahil etmemek) this.
    // specifiers => These are optional. The specifiers are mutable and constexpr.
    // {} => is the body, this is where we define the function.
    // Examples:
        // [] () {std::cout << "Hi";}(); ==> () intantiates a function object from this lambda expression by using overloaded function call operator().
        // [] (int x) {std::cout << x;}; x will be passed to lambda function.
        // [] (int x, int y) {std::cout << x+y;}; x+y will be passed to lambda function.
        // auto l = [] () { std::cout << "Hi";};
            // l() // displays Hi
        // auto l = [] (int x, int y) -> int {return x + y;}; // -> int is optional!
        // or
        // auto l = [] (int x, int y) {return x + y;};
            // std::cout << l(2,3); // displays 5

// STATEFUL LAMBDA EXPRESSIONS:
    // That is a lambda expression that does capture information from its environment. [] => this part not empty!
    // Capturing infromation from its environment means that the lambda is able to use variables declared within its reaching scope, without having to pass them into the lamda as parameters.
    // This is accomplished by simply listing the variables we would like the lambda to use within its capture list. 
    // The variable in the capture list is implemented as a member variable of the class, behind the scenes.
#include <iostream>
#include <vector>
#include <algorithm>

int global_x {1000};        // defining a global variable here. However, we can not capture global and static variables by lambda functions.

// The global variable global_x cannot be captured because it is not within the reaching scope of the lambda. 
// It can however still be accessed from within the lambda using normal name lookup rules.
void test1()
{
	std::cout << "\n---Test1 --------------------------" << std::endl;
	
	int local_x {100};
	
	auto l = [local_x] () {         // capturing variable by value. This is a const value by default and can not be modified within the lambda.
		std::cout << local_x << std::endl;
		std::cout << global_x << std::endl;
	};
	l();        // displays 100, 1000
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by using the mutable keyword.
// Note that this modifiability only pertains to the captured variable within the lambda body and not the actual variable.
void test2()
{
	std::cout << "\n---Test2 --------------------------" << std::endl;
	
	int x {100};
	
	auto l = [x] () mutable {       // we use mutable keyword to modify the parameter in the capture list. x is not const! Capture process happens here!
		x += 100;
		std::cout << x << std::endl;
	};
    
	l();                                // displays 200
	std::cout << x << std::endl;        // displays 100 - since variable was passed by value.
    
    l();                                // displays 300 - because capturing happens only once, the x was captured above and still stored as 200 in lambda body!
    std::cout << x << std::endl;        // displays 100 - since variable was passed by value.
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body will change the actual variable.
void test3()
{
	std::cout << "\n---Test3 --------------------------" << std::endl;
	
	int x {100};
	
	auto l = [&x] () mutable {      // capturing values by reference, we can modify the x's value, not only local x.
		x += 100;
		std::cout << x << std::endl;
	};
    
	l();                            // displays 200 
	std::cout << x << std::endl;    // displays 200 - since variable was passed by reference.
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value. The variable z is not captured by the lambda.
void test4()
{
	std::cout << "\n---Test4 --------------------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};  // Note that z is not captured in the lambda since it is not used.
                      // This should produce an 'unused variable' warning when compiling.
	
	auto l = [=] () mutable {       // = means that: Only variables used within the lambda body are captured by value.
		x += 100;
		y += 100;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
	};
	l();                                // displays 200 - 300 
	
	std::cout << "\n";
	std::cout << x << std::endl;        // displays 100 - since it was captured by value.
	std::cout << y << std::endl;        // displays 200 - since it was captured by value.
}

// Default capture by reference
// This time because all three variables - x,y,z are used within the lambda body, all three of them will be captured by reference.
void test5()
{
	std::cout << "\n---Test5 --------------------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [&] () {           // = captures all variables in this scope default by reference.
		x += 100;
		y += 100;
		z += 100;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	};
	l();                            // displays 200, 300, 400
	
	std::cout << "\n";
	std::cout << x << std::endl;    // displays 100 - since it was captured by reference.
	std::cout << y << std::endl;    // displays 200 - since it was captured by reference.
	std::cout << z << std::endl;    // displays 300 - since it was captured by reference.
}

// Default capture by value, capture y by reference
void test6()
{
	std::cout << "\n---Test6 --------------------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [=, &y] () mutable {       // default capture everything by value but capture x by reference. Always use the default one first.
		x += 100;
		y += 100;
		z += 100;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	};
	l();                                // displays 200, 300, 400 
	
	std::cout << "\n";
	std::cout << x << std::endl;        // displays 100
	std::cout << y << std::endl;        // displays 300 - since it was captured by reference
	std::cout << z << std::endl;        // displays 300
}

// Default capture by reference, capture x and z by value
void test7()
{
	std::cout << "\n---Test7 --------------------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [&, x, z] () mutable {     // default capture everything by reference but capture x and z by value. Always use the default one first.
		x += 100;
		y += 100;
		z += 100;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	};
	l();                                // displays 200, 300, 400 
	
	std::cout << "\n";
	std::cout << x << std::endl;        // displays 100
	std::cout << y << std::endl;        // displays 300 - since it was captured by reference
	std::cout << z << std::endl;        // displays 100
}

// Used for test8
class Person {
	friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person() = default;         // defining default constructor.
    Person(std::string name, int age) : name{name}, age{age} {}     // overloaded constructor
    Person(const Person &p) = default;                              // copy constructor
    ~Person() = default;                // destructor
    std::string get_name() const { return name; }
    void set_name(std::string name) {this->name = name; };
    int get_age() const {return age; }
    void set_age(int age) {this->age = age; }
	
    // Below fucntions expects a new name and new age, sets the objects name as new name and age as new age.
	auto change_person1() {return [this] (std::string new_name, int new_age) {name = new_name; age = new_age;};}    // capturing object, always use this with objects! Do not use below ones.
	auto change_person2() {return [=] (std::string new_name, int new_age) {name = new_name; age = new_age;};}       // capturing by value - not valid after c++20.
	auto change_person3() {return [&] (std::string new_name, int new_age) {name = new_name; age = new_age;};}       // capturing by reference
    
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}

// Default capture by reference of the current object using [this]
// [=], [&], and [this] are equivalent when capturing an object's member variables - all are captured by reference
// Note that capturing this with [=] has been deprecated (kullanim disi ilan etmek, desteklememek) in C++20
// Also, C++20 allows [*this], which captures by value!
void test8()
{
	std::cout << "\n---Test8 --------------------------" << std::endl;

	Person person("Larry", 18);
	std::cout << person << std::endl;                   // displays [Person: Larry : 18]
	
	// Default capture [this]
    // This is the preferred way
	auto change_person1 = person.change_person1();
	change_person1("Moe", 30);                          
	std::cout << person << std::endl;                   // displays [Person: Moe : 30] - since it was captured by reference
	
	// Default capture [=] 
    // This has been deprecated in C++20
	auto change_person2 = person.change_person2();
	change_person2("Curly", 25);                        
	std::cout << person << std::endl;                   // displays [Person: Curly : 25] - since it was captured by reference
	
	// Default capture [&]
	auto change_person3 = person.change_person3();
	change_person3("Frank", 34);
	std::cout << person << std::endl;                   // displays [Person: Frank : 34] - since it was captured by reference
}

// Used for test9
// Below is what happens behind scenes when we define a lamda function.
class Lambda {
private:
	int y;
public:
	Lambda(int y) : y{y} {};
	
	void operator() (int x) const {
		std::cout << x + y << std::endl;
	};
};

// Lambda class equivalence example
void test9()
{
	std::cout << "\n---Test9 --------------------------" << std::endl;
	
	int y {100};    
	
	Lambda lambda1(y);
	auto lambda2 = [y] (int x) {std::cout << x + y << std::endl;};  // this statement is the equivalent of above lambda class
	
	lambda1(200);       // displays 300
	lambda2(200);       // displays 300
}

// Class used in the test10() example
class People {
    std::vector<Person> people;
    int max_people;             // max number of person object we can display.
public:
    People(int max=10) : max_people(max) { }    // constructor sets max_people to 10 by default or expects a value from user.
    People(const People &p) = default;          // copy constructor
    // No destructor is needed since we did not use any pointer in members.
    void add(std::string name, int age) {       // allows us to add a person to our member vector.
        people.emplace_back(name, age);
    }
    void set_max_people(int max) {              // allows us to alter max_people.
        max_people = max;
    }
    int get_max_people() const {
        return max_people;
    }
    
    // This method returns a vector of Person objects in people whose age > max_age AND it limits the number of persons returned to be <= the member variable max_people.
    // Note that the lambda in this example captures this, by reference, and by value
    std::vector<Person> get_people(int max_age) {
        std::vector<Person> result;
        int count{0};
        // std::copiy_if copies variables if the condition given in lambda is statisfied.
        std::copy_if(people.begin(), // from begin
                           people.end(), // to end
                           std::back_inserter(result), // pushes elements back to result
                            [this, &count, max_age](const Person &p){ return p.get_age() > max_age &&  ++count<=max_people;});  // = default capture this object by reference.
        return result;
    }
};


void test10() {
   	std::cout << "\n---Test10 --------------------------" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);
    
    auto result = friends.get_people(17); 
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;        // displays 10 persons who are over 17 years old. So, displays all friends defined above.
        
    friends.set_max_people(3);              // Setting max people to be displayed to 3.
    
    result = friends.get_people(17);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;        // displays 3 persons who are over 17 years old. So, displays [Person: Larry : 18], [Person: Curly : 25], [Person: Moe : 35]
        
    result = friends.get_people(50);        // Setting min age to 50.
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;        // displays 3 persons who are over 50 years old. So, displays [Person: James : 65]
}

int main()
{
    test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
    test10();
	
	std::cout << "\n";
	return 0;
}