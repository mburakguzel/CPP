// Best practice for exception handling is:
    // Throwing objects not primitive types.
    // Throw an object by value.
    // Catch an object bu reference (or const reference)
#include <iostream>

class DivideByZeroException {  // we can define constructors, atributes or methods for these classes(user defined exception handling classes) as well, we just keep it ssimple here.
};
class NegativeValueException {
};

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw DivideByZeroException();
    else if (miles < 0 || gallons < 0)
        throw NegativeValueException();
    // if none of the above true, we just return the below value.
    return static_cast<double>(miles) / gallons;
}

int main() {    
    int miles {};
    int gallons {};
    double miles_per_gallon {};   
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (const DivideByZeroException &ex) {  // if we had provided attributes or methods in the exception classes, we would access them here. Also, notice how we are catching the exceptions by const ref.
        std::cerr << "Sorry, you can't divide by zero" << std::endl;
    } catch (const NegativeValueException &ex) {
        std::cerr << "Sorry, one of your parameters is negative" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}

