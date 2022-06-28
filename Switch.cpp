// SWITCH - CASE STATEMENT

    char letter_grade{};
    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letter_grade;

    switch(letter_grade){
    case 'a':
    case 'A':      // We are typing this in order to make our program not case sensitive.
        cout << "You need a 90 or above, study hard!" << endl;
        break;     // If we don add this, program will continue to check other cases! This decrease our program executaion time!
    case 'b':
    case 'B':      // We are typing this in order to make our program not case sensitive.
        cout << "You need a 80-89 for a B, go study!" << endl;
        break;
    case 'c':
    case 'C':      // We are typing this in order to make our program not case sensitive.
        cout << "You need a 70-79 for a C" << endl;
        break;
    case 'd':
    case 'D':      // We are typing this in order to make our program not case sensitive.
        cout << "Hmm, you should strive for a better grade. All you need is 60-69" << endl;
        break;
    case 'f':
    case 'F':      // We are typing this in order to make our program not case sensitive.
        {          // This curly bracets are needed in case you declare a variable inside such as confirm below.
        char confirm{};  // if you declare a variable under case, you have to use curly bracests, otherwise not!
        cout << "Are you sure (Y/N)" << endl;
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y')
            cout << "Ok, I guess you did not study..." << endl;
        else if (confirm == 'n' || confirm == 'N')
            cout << "Good - go study!" << endl;
        else
            cout << "Illegal choice" << endl;
        break;
        }
    default: // Optinal, in case no case is selected. 
        cout << "Sorry, not a valid grade" << endl;
    }

// If you declare a variable under case, you have to use curly bracests, otherwise not!

// SWITCH WITH ENUMARATION TYPE! (Used more often!)

    enum Direction {        // when we declare enum, basically we create new variable type
    left, right, up, down   
    };

    Direction heading {left}; // heading is like type here (e.g int, char)

    switch (heading){
        case left:
            cout << "Going left" << endl;
            break;
        case right:
            cout << "Going right" << endl;
            break;
        default : cout << "OK" << endl;
    }
    cout << endl;

// When the program is built without using declared enums, compiler gives warnings! 
// However, using default statement in switch clears these warnings.