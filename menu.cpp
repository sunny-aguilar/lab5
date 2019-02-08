/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 6, 2019
** Description:     Menu class contains a series of messages and
**                  prompts for the user. Menu class also validates
**                  user's input.
*********************************************************************/
#include "menu.hpp"
#include <iostream>

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Menu::Menu() {}

/*********************************************************************
** Description:     start menu that prompts user to select an option
*********************************************************************/
void Menu::menuStart() {
    cout << " LAB5 - CHOOSE A RECURSIVE FUNCTION\n"
            "+--------------------------------------------------+\n";
    cout << "  1. Reverse a string     3. A triangular number    \n"
            "  2. Sum of an array      4. Quit                   \n"
            "+--------------------------------------------------+\n"
            ">> ";
}

/*********************************************************************
** Description:     prompts user to en
*********************************************************************/
string Menu::menuEnterString() {
    cout << " ENTER A STRING AND I WILL\n"
            " REVERSE IT USING RECURSION\n"
            "+--------------------------------------------------+\n"
            ">> ";
    string userString;
    getline(cin, userString);
    bool askAgain = true;
    do {
        if (userString.length() < 1) {
            cout << "You must enter at least 1 character!\n";
            cout << ">> ";
            getline(cin, userString);
        }
        else {
            askAgain = false;
        }
    } while (askAgain);

    return userString;
}

/*********************************************************************
** Description:     shows user the reversed string
*********************************************************************/
void Menu::menuReversedString() {
    cout << "\n Reversed String Results\n"
            "+--------------------------------------------------+\n";
    cout << " ";
};

/*********************************************************************
** Description:     prompts user to enter the array size
*********************************************************************/
void Menu::menuEnterArraySize() {
    cout << " SUM AN ARRAY - Enter the size of the array\n"
            "+--------------------------------------------------+\n"
            ">> ";
}

/*********************************************************************
** Description:     prompts user to enter the value for the array
*********************************************************************/
void Menu::menuEnterArrayValue(int index) {
    cout << " SUM AN ARRAY - Enter an integer for the array at index["<< index << "]\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     displays to the user the sum of the array as well
**                  as the array values entered
*********************************************************************/
void Menu::menuArraySum(int sum, int *arr, int size) {
    cout << "\n SUM OF ARRAY\n"
            "+--------------------------------------------------+\n"
            ">> the sum of the array is " << sum <<"\n"
            ">> array elements {";
            for (int index = 0; index < size; index++) {
                if (index == size - 1) {
                    cout << arr[index];
                }
                else { cout << arr[index] << ", "; }
            }
    cout << "}\n\n\n\n";
}

/*********************************************************************
** Description:     prompts user to enter a value from 1 to N
*********************************************************************/
void Menu::menuTriangularNumber() {
    cout << " TRIANGULAR NUMBER - Enter a number between 1 and 1000\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     displays results of triangular number
*********************************************************************/
void Menu::menuTriangularResults(int n, int sum) {
    cout << " TRIANGULAR NUMBER - Triangular number for n = " << n << " is " << sum << "\n"
            "+--------------------------------------------------+\n\n\n";
}

/*********************************************************************
** Description:     prompts user that the program has ended
*********************************************************************/
void Menu::menuEndGame() {
    cout << " Program has ended\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "Number length exceeded Try again!\n";
            cout << ">> ";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
            cout << ">> ";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}

/*********************************************************************
** Description:     general integer validator where the parameters are
**                  the min and max numbers acceptable
*********************************************************************/
int Menu::validateInteger(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    bool tooLong = false;
    bool negativeFound = false;
    bool notInRange = true;
    bool characterFound = false;
    long unsigned length = 0;
    std::stringstream convert;

    do {
        cout << "Enter a number from " << min << " to " << max << endl;
        cout << ">> ";
        cin.getline(choice, 100);

        // determine # of digits in max value acceptable
        if (choice[0] == 45) { length = std::to_string(min).length(); }
        else { length = std::to_string(max).length(); }

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "Digits entered are too long!\n";
        }

        // check if a negative character has been found
        negativeFound = false;
        if (choice[0] == 45) { negativeFound = true; }

        // if a value entered is a negative, validate value
        notInRange = true;
        characterFound = false;
        if (negativeFound) {
            for (int index = 1; index < strlen(choice); index++) {
                if (choice[index] >= 48 && choice[index] <= 57) {
                    notInRange = false;
                }
                if (choice[index] < 48 || choice[index] > 57) {
                    characterFound = true;
                }
                if (characterFound) { notInRange = true; }
            }
            if (characterFound) { cout << "Make sure to only enter numbers!\n"; }
        }
        else { // if value entered is positive, validate value
            for (int index = 0; index < strlen(choice); index++) {
                if (choice[index] >= 48 && choice[index] <= 57) {
                    notInRange = false;
                }
                if (choice[index] < 48 || choice[index] > 57) {
                    characterFound = true;
                }
                if (characterFound) { notInRange = true; }
            }
            if (characterFound) { cout << "Make sure to only enter numbers!\n"; }
        }

    } while (tooLong || notInRange);

    convert << choice;
    convert >> validatedChoice;

    return validatedChoice;
}