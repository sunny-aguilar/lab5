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
** Description:     first recursive function
*********************************************************************/
void Game::firstRecursive(string userString) {
    if (userString.length() > 1) {
        cout << userString.at(userString.length() - 1);
        userString.pop_back();
        Game::firstRecursive(userString);
    }
    else if (userString.length() == 1) {
        cout << userString.at(userString.length() - 1);
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