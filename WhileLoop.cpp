// WHILE LOOP
// Mostly used for asking inout!
    int number {};

    while (number >= 100) {  // !(number < 100)
        cout << "Enter an integer less than 100: ";
        cin >> number;
    }
    cout << "Thanks" << endl;    
// Another Example!
    int num {};
    cout << "Enter a positive integer - start the countdown :";
    cin >> num;
    
    while (num > 0 ) {
        cout << num << endl;
       --num;
    }
    cout << "Blastoff!" << endl;
// Another Example
    bool done {false};
    int number {0};

    while (!done) {
            cout << "Enter an integer between 1 and 5: ";
            cin >> number;
            if (number <=1 || number >=5)
                cout << "Out of range, try again" << endl;
            else {
                cout << "Thanks!" << endl;
                done = true; // to get out of the loop!
            }
        }
// INFINITE WHILE LOOP
    while (true)
    
// DO-WHILE LOOP
// Program checks if the condition for while loop is true after running statements under do first.
// Basically program checs if the condition is true after running the loop 1 time! 
    char selection {};
    do {
        cout << "\n---------------------" << endl;
        cout << "1. Do this" << endl;
        cout << "2. Do that" << endl;
        cout << "3. Do something else" << endl;
        cout << "Q. Quit" << endl;
        cout << "\nEnter your selection: ";
        cin >> selection;
        
        if (selection == '1')
            cout << "You chose 1 - doing this" << endl;
        else if (selection == '2') 
             cout << "You chose 2 - doing that" << endl;
        else if (selection == '3')
            cout << "You chose 3 - doing something else" << endl;   
        else if (selection == 'Q' || selection == 'q')
            cout << "Goodbye..." << endl;
        else 
            cout << "Unknown option -- try again..." << endl;
    
    } while ( selection != 'q' && selection != 'Q');
    
    cout  << endl;

// CONTINUE
// No further statement in the body of the loop are executed.
// Control immediately goes directly to the beginning of the next iteration.
    continue;
// BREAK
// No further statement in the body of the loop are executed.
// Loop is immediately terminated.
// Control immediately goes directly to the statement following the loop construct.
    break;
