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
Game::Game() {}

/*********************************************************************
** Description:     start recursion simulation
*********************************************************************/
void Game::startSim() {
    // set simulation variables
    menu.menuStart();
    // start game

    gameflow();
}

/*********************************************************************
** Description:     game flow control
*********************************************************************/
void Game::gameflow() {
    do {
        // show recursive function menu
        chooseOption();


    } while (keepPlaying());

    // prompts user that game has ended
    menu.menuEndGame();

}

/*********************************************************************
** Description:     bool function returns true if player keeps
**                  playing, false if player wants to quit
*********************************************************************/
bool Game::keepPlaying() {
    menu.menuQuit();
    if (menu.validateNumber(1,2) == 1) {
        return true;
    }
    else if (menu.validateNumber(1,2) == 2) {
        return false;
    }
}

/*********************************************************************
** Description:     a
*********************************************************************/
void Game::chooseOption() {
    switch (menu.validateNumber(1,3)) {
        case 1:
            firstRecursive();
            break;
        case 2:
            secondRecursive();
            break;
        case 3:
            thirdRecursive();
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