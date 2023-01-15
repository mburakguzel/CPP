// Note: The phrase "instantiating a class" means the same thing as "creating an object." When you create an object, you are creating an "instance" of a class, 
// therefore "instantiating" a class. 

// Abstract Classes:
    // An abstract class is a class that cannot be instantiated (somutlastirmak, kanit gostererek iddiada bulunmak).
    // These classes are used as base classes in inheritance hierarchies.
    // They are often referred to as abstract based classes.
    // These classes are too generic to create objects from but it serves as a parent to be derived from and these derived classes can be concrete class.
    // Example: Account class can be a parent class and we can derive savings account, joint acccount etc. from it. So, the account class can be thought of as a general class that's the parent to all other classes.
    // An abstract class must have at least one pure virtual function.
    // The derived class must override all the pure virtual functions of base class, otherwise derived class also becomes an abstract class. 

// Concrete class: These are the classes that we have been using so far!
    // This classes are classes that you can instantiate objects from.
    // All their member functions must be defined.

// A pure virtual function is a virtual function that's used to make a class abstract.

#include <iostream>
#include <vector>

class Shape {			// Abstract Base class
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	 // pure virtual function are defined like this, by adding a = 0 at the end.
    //   Typically, pure virtual functions do not have any implementation, since it is up to the derived concrete classes to define this behaviour. But it is possible to give them an implementation.
      virtual void rotate() = 0;   // pure virtual function
      virtual ~Shape() { }
};

class Open_Shape: public Shape {    // Abstract class since the pure virtual function is not overriden.
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape {  // Abstract class since the pure virtual function is not overriden.
public:
    virtual ~Closed_Shape() { };
};

class Line: public Open_Shape {     // Concrete class, since pure virtual function is overriden here!
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle: public Closed_Shape {     // Concrete class, since pure virtual function is overriden here!
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};


void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() {
    // Shape s;   // causes error since we can not create objects from abstaract classes // we can not instantiate the class!
    // Shape *p = new Shape();  // causes error since we can not create objects from abstaract classes // we can not instantiate the class!

    Circle c;  // This is all being statically bound. No dynamic polymorphism here.
    c.draw();

// Below code works fine since Circle is not a abstract class.
    Shape *ptr = new Circle();
    ptr->draw();
    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    std::vector<Shape *> shapes {s1,s2,s3};    
    for (const auto p: shapes) 
        p->draw();
        
    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}
