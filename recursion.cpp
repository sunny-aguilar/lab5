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
Game::Game() : keepPlaying{false} {}

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
            firstRecursive();
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
void Game::firstRecursive() {
    cout << "First function called\n";
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