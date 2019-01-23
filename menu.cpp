/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     LAB5
**                  d
**                  d
**                  d
*********************************************************************/

#include "menu.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Menu::Menu() {}

/*********************************************************************
** Description:     start menu that prompts user to select an option
*********************************************************************/
void Menu::menuStart() {
    cout << " CHOOSE A RECURSIVE FUNCTION\n"
            "+--------------------------------------------------+\n";
    cout << "  1. Reverse a string     3. A triangular number     \n"
            "  2. Sum of an array      4. Quit                    \n"
            "+--------------------------------------------------+\n\n";
}

/*********************************************************************
** Description:     a
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