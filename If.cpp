// IF
// If there is more than one statement under if, we use curly braces:

    if (num > min){
        cout << "\n============If statement 1 ================" << endl;
        cout << num << " is greater than or " << min << endl;
    
        int diff{num - min};
        cout << num << " is " << diff << " greater than " << min << endl;
    }

// Variables defined in if, can not be used outside of the if statement!

// IF - ELSE IF 
    if (num > min){
        cout << "\n============If statement 1 ================" << endl;
        cout << num << " is greater than or " << min << endl;

        int diff{num - min};
        cout << num << " is " << diff << " greater than " << min << endl;
    }
    else if(num < max){
        cout << "\n============If statement 2 ================" << endl; // when you enter a number less than 10 this part will be active
        cout << num << " is less than " << max << endl;

        int diff{max - num};
        cout << num << " is " << diff << " less than " << max << endl;
    }

// NESTED IF - ELSE
    if (score >= 0 && score <= 100){
        if (score > 90)
            letter_grade = 'A';
        else if (score > 80)
            letter_grade = 'B';
        else if (score > 70)
            letter_grade = 'C';
        else if (score > 60)
            letter_grade = 'D';
        else
            letter_grade = 'F';
 
        cout << "Your letter grade is " << letter_grade << endl;
        if (letter_grade == 'F')
            cout << "Sorry, you failed" << endl;
        else
            cout << "You passed!";
    }
    else {
        cout << "Sorry, " << score << " is not in range" << endl;
    }
// Else belongs to the closest if!