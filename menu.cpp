/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     LAB5
**                  d
**                  d
**                  d
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
    cout << " SUM AN ARRAY - Enter an integer between 1 and 100\n"
            "                for the array at index["<< index << "]\n"
            "+--------------------------------------------------+\n"
            ">> ";
}

/*********************************************************************
** Description:     displays to the user the sum of the array
*********************************************************************/
void Menu::menuArraySum(int sum, int *arr, int size) {
    cout << " SUM AN ARRAY - the sum of the array is " << sum <<"\n"
            "+--------------------------------------------------+\n"
            "array elements {";
            for (int index = 0; index < size; index++) {
                cout << arr[index] << ", ";
            }
    cout << "}";
}

/*********************************************************************
** Description:     prompts user that the program has ended
*********************************************************************/
void Menu::menuEndGame() {
    cout << " Program has ended\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     prompts user that the program has ended
*********************************************************************/
void Menu::menuEnterString() {
    cout << " ENTER A STRING AND I WILL\n"
            " REVERSE IT USING RECURSION\n"
            "+--------------------------------------------------+\n"
            ">> ";
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
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (int i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
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