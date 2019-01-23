/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     LAB5
**                  d
**                  d
**                  d
*********************************************************************/

#include "recursion.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Game::Game() : keepPlaying{true} {}

/*********************************************************************
** Description:     start recursion simulation
*********************************************************************/
void Game::startSim() {
    // start game
    gameflow();
}

/*********************************************************************
** Description:     game flow control shows start menu and keeps
**                  looping until player quits
*********************************************************************/
void Game::gameflow() {
    do {
        // show recursive function menu
        menu.menuStart();
        // process player option chosen
        chooseOption();
    } while (keepPlaying);

    // prompts user that game has ended
    menu.menuEndGame();

}

/*********************************************************************
** Description:     this function calls the recursive function
**                  by the user. User can also quit.
*********************************************************************/
void Game::chooseOption() {
    switch (menu.validateNumber(1,4)) {
        case 1:
            {
                string userString;
                menu.menuEnterString();
                getline(cin, userString);
                menu.menuReversedString();
                firstRecursive(userString);
                cout << endl << endl << endl;
            }
            break;
        case 2:
            secondRecursive();
            break;
        case 3:
            thirdRecursive();
            break;
        case 4:
            keepPlaying = false;
            break;
        default:
            cout << "Unable to make your selection!\n";
    }
}

/*********************************************************************
** Description:     first recursive function. Reverses a string using
**                  recursion. Algorithm - if the string length is
**                  greater than 1, print the last character and
**                  recursively, remove the last character from the
**                  string, and call the function again. If the length
**                  of the string is 1, print it out and function ends.
*********************************************************************/
void Game::firstRecursive(string userString) {
    if (userString.length() == 1) {
        // base case
        cout << userString.at(userString.length() - 1);
    }
    else if (userString.length() > 1) {
        // print last letter in string
        cout << userString.at(userString.length() - 1);

        // remove last letter in string
        userString.pop_back();

        // recursive function call
        Game::firstRecursive(userString);
    }
}

/*********************************************************************
** Description:     second recursive function
*********************************************************************/
void Game::secondRecursive() {
    cout << "Second function called\n";


}

/*********************************************************************
** Description:     third recursive function
*********************************************************************/
void Game::thirdRecursive() {
    cout << "Third function called\n";


}