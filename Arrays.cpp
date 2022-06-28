// All elements of an array must be same type!
// Array size is fixed, can not be altered!
// Array index starts from 0, so first elements index is "0".
// When array size is 10, last element`s index will be 9. If you call 10, program will not give error, just behaves strange. No bounds checking!

// DECLARE ARRAY
    // int test_scores [5]; declares an array with 5 integers
    // const int days_in_year [365]; // array with size 365 but constantt
    
    // int test scores [5] {100, 95, 84, 76, 54}; // 5 is size, others variables
    // int test scores [5] {3,5}; // index 0,1 = 3,5 others 0
    // int test_scores [4] {};     // init all to 0
    // inte test_score [] {1,2,3,4,5} // size is calculated bu program!
    // char vowels[] {'a','e','i','o','u'};
    // double hi_temps[] {90.1,89.8,77.5,81.6};
// MANIPULATE ARRAY
    // cout << test_scores[0]; // shows first element of array
    // cin >> test_scores[3]; // gets 3rd variable from user

    //cout << test_scores[]; // will NOT show the whole array, only shows the memory address of the array!

// MULTI-DIMENSIOANAL ARRAY
        //second index
        //    0  1  2  3 
//first // 0  3  6  7  9
//index // 1  4  8  1  2   
        // 2  5  10 11 12
// Above array can be defined as:
    // int movie_rating [3][4]
    // { 
        // { 3, 6, 7, 9},
        // { 4, 8, 1, 2},
        // { 2, 5, 10, 11, 12}
    // };

// We can add as much as dimensions to an array that  our system can run!

// Since the size of an array van not be altered, we rarely use them, we use vectors instead!

// SHoWING ELEMENTS OF AN ARRAYT
    for (int i{0}; i<=10; i+=1) {
            cout << scores[i] << endl;
    }
// Be careful with the array size, otherwise program may give error!
