#include <iostream> 
#include <vector>
using namespace std; 

int main() 
{

// VECTORS
// In order to define vectors, we need to include vector library. Since vector type is part of the standard library, we need to use either namespace 
// or use stanfard and the scope resultion operator. (:: like std::cout)
    // #include <vector>

// Since the vector is an object-oriented template class, we must include the type of the element of the vector inside the angle brackets!

    // vector <char> wovels;
    // vector <int> test_scores; 
    // vector <int> test_scores(5); // 5 is size of the vector! Unlike arrays all integers will be initialized to 0.
    // vector <int> test_scores {100, 98, 89, 85, 93};
    // vector <int> test_scores {100, 98, 89, 85, 93};

    // cout << test_scores[0] << endl;
    // cout << test_scores[1] << endl;
    // cout << test_scores[2] << endl;

// A C++ vector is part of the c++ standard template library.

// When we create a c++ vector, we create a c++ object.

// Vectors can grow and shrink in size.

// All elements must be in same type!

// When array size is 10, last element`s index will be 9. If you call 10, program will not give error, just behaves strange. No bounds checking as arrays!
// However, there is a method to check bounds as shown below:

// METHODS OF VECTORS
// When we create an object, we can ask them to perform operations. These operations are called "methods" in CPP.
    
    // AT METHOD
    // test_scores.at(0) // 0 is index, "at" is method, . is dot operator
// This checks the bounds an if the index exceeds the bound, gives error!    

    // PUSHBACK METHOD
    // test-scores.pushback(80); adds a new element to the end of the vector, adds 80 in this case!

    // SIZE METHOD
    // test_scores.size() // gives the number of elements in the vector! 
    // cout << "\nThere are " << test_scores.size() << " chars in the vector" << endl;

// MULTIDIMENSIOAL VECTORS
        //second index
        //    0  1  2  3 
//first // 0  3  6  7  9
//index // 1  4  8  1  2   
        // 2  5  10 11 12

    //    vector <vector<int>> movie_ratings
    //    {
    //     { 3, 6, 7, 9},
    //     { 4, 8, 1, 2},
    //     { 2, 5, 10, 11, 12}
    //    };

    //    cout << movie_ratings[1][2] << endl; // shows 5
    //    cout << movie_ratings.at(1).at(2) << endl; // shows 5

// PUSH A VECTOR INSIDE A VECTOR
// Puts a single dimensional vector into multu dimonsional vector horizantally.
    // vector <int> vector1 {10, 20};
    // vector <int> vector2 {100, 200};;

    // vector <vector <int>> vector_2d;
    // vector_2d.push_back(vector1);
    // vector_2d.push_back(vector2);
    // cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    // cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    // vector1.at(0) = 1000;
    // cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    // cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    // cout << "The first element of vector1 is: " << vector1.at(0) << endl;
    // cout << "The second element of vector1 is: " << vector1.at(1) << endl;

// For loop with vectors
    vector<int> nums { 10,20,30,40,50};
    for (unsigned i{0}; i < nums.size(); ++i) // checks size of vector! This code may generate a warning size vector.size is unsigned int and i is int. Change i to unsigned to delete that warning.        cout << nums[i] << endl;



    return 0;
}   
