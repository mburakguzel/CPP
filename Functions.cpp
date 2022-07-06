#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Self defined functions! Functions used in main or in other functions must be defined the function defined!!!

const double pi {3.14159};

double calc_area_circle(double radius) {
    return pi * radius * radius;
}

double calc_volume_cylinder(double radius, double height) {
//    return pi * radius * radius * height;
    return calc_area_circle(radius) * height;
}

void area_circle() {
    double radius{};
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

void volume_cylinder() {
    double radius {};
    double height {};
    cout << "\nEnter the radius of the cylinder: ";
    cin >> radius;
    cout << "\nEnter the height of the cylinder: ";
    cin >> height;
    
    cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}

int main() {
    
    area_circle();
    area_circle();
    volume_cylinder();
    
    return 0;
}

// --------------0---------------0-----------------------------0------------

// Function prototypes allows us to define functions after main function!

double calc_volume_cylinder(double radius, double height);
double calc_area_circle(double);
void area_circle();
void volume_cylinder();

const double pi = 3.14159;

int main() {
    area_circle();
    volume_cylinder();
    return 0;
}

double calc_volume_cylinder(double radius, double height) {
   // return pi *radius * radius * height;
   return calc_area_circle(radius) * height;
}

double calc_area_circle(double radius) {
    return pi * radius * radius;
}

void area_circle() {
    double radius {};
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

void volume_cylinder() {
    double radius {};
    double height {};
    cout << "\nEnter the radius of the cylinder: ";
    cin >> radius;
    cout << "Enter the height of the cylinder: ";
    cin >> height;
    cout << "\nThe volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}

//  DEFAULT ARGUMENT
// Means setting a parameter to a value if it is not provided in program, program will use the default value!
double calc_cost(double base_cost = 100.0, double tax_rate = 0.06, double shipping = 3.50);

void greeting(string name,  string prefix = "Mr.", string suffix = "");

double calc_cost(double base_cost, double tax_rate, double shipping) {
    return base_cost += (base_cost * tax_rate) + shipping;
}

void greeting(string name,  string prefix, string suffix) {
    cout << "Hello " << prefix + " " + name + " " + suffix << endl;
}


int main() {
    double cost{ 0 };
    cost = calc_cost(100.0, 0.08, 4.25);        // will use no defaults  100 + 8 + 4.25 
    
    cout << fixed << setprecision(2);
    cout << "Cost is: " << cost << endl;    // 112.25
    
    cost = calc_cost(100.0, 0.08);                  // will use default shipping  100 + 8 + 3.50 
    cout << "Cost is: " << cost << endl;    // 111.50

    cost = calc_cost(200.0);                         // will use default tax and shipping   200 + 12 + 3.50
    cout << "Cost is: " << cost << endl;    // 215.50
    
    cost = calc_cost();
    cout << "Cost is: " << cost << endl;    // 100 + 6 + 3.50
    
    greeting("Glenn Jones", "Dr.", "M.D.");
    greeting("James Rogers", "Professor", "Ph.D.");
    greeting("Frank Miller", "Dr.");
    greeting("William Smith");
    greeting("Mary Howard", "Mrs.", "Ph.D.");

    cout << endl;
    return 0;
}


// OVERLOADING FUNCTIONS
// Let`s say that, you want to use a funtion with different type of variables. You can define it more than one with different type of variables.

void print(int num) {
    cout << "Printing int: " << num << endl;
}

void print(double num) {
    cout << "Printing double: " << num << endl;
}

void print(string s) {
    cout << "Printing string: " << s << endl;
}

void print(string s, string t) {
    cout << "Printing 2 strings: " << s << " and " << t << endl;
}

void print(vector<string> v) {
    cout << "Printing vector of strings: " ;
    for (auto s: v )
        cout << s + " ";
    cout << endl;
}

int main() {
    print(100);    // int
    print('A');     //  character is always promoted to int should print 65 ASCII ('A')
    
    print(123.5);   // double
    print(123.3F);  // Float is promoted to double
    
    print("C-style string");  // C-style string is converted to a C++ string
    
    string s {"C++ string"};    
    print(s);       // C++ string
    
    print("C-style string", s); // First argument is converted to a C++ string
    
    vector<string> three_stooges {"Larry", "Moe", "Curly"};
    print(three_stooges);
    
    cout << endl;
    return 0;
}