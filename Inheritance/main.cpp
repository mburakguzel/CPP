// Inheritance in C++ could be really complex. We will discuss simple examples to make foundation for more advenced consepts.
// What is inheritance and why is it used?
    // Inheritance is process of creating new classes from existing classes. Reuse mechanism.
    // Provides a method for creating new classes from existing classes.
    // The new class contains the data and behaviours of the existing class.
    // Allows us to focus on the common attributes among a set of classes.
    // Allows new classes to modify behaviours of existing cllases to make it unique class, (without actually modifying the original class)
// We can create different classes with same behaviours instead of using inheritance but this causes our code to grow in size and waste of time.

// Terminology of the inheritance
// Single Inheritance: A new class is created from another 'single' class.
// Multiple inheritance: A new class is created from two (or more) other class.
// Base class (parent class, super class): the class being extended or inherited from
// Derived class (child class, sub class): the class being created from the Base class.

// "Is-A" relationship: When we use classic or public inheritance, our derived classes are generally subtypes of their base classes. This implies (ima etmek, gostermek) a "Is-A" relationship.
    // We can use a derived class object wherever we use a base class object.

// Generalization: Combining similar classes into a single, more general class based on common attributes.
// Specialization: This is opposite of generalization. Creating new classes from existing classes proving more specialized attributes or operations.
// Inheritance or Class Hierarchies: Organization of our inhertiance relationship.

// Public Inheritance vs Composition:
// Public Inheritance means "is-a" relationship: Employee 'is-a' person. (Employee derived from Person)
// Compositon "has-a" relatiosnhp. Each class Person 'has-s' account class. But account is not derived from person. 
// If you think composition can be done, use it instead of inheritance since it is more easy to implement.

// C++ supports public, private and protected inheritence. Most of the OOP languages support only public inheritance!
    // Public inheritance: Most common. Establishes "is-a" relationship between Derived and base classes.
    // Private and Protected Inheritance: Will not goo deep into them!
        //  Establishes "derived class has a base class" relationship.
        // "Is implemented in terms of" relationship
        // Different from composition.


