/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     LAB5
**                  d
**                  d
**                  d
*********************************************************************/

#ifndef RECURSION_HPP
#define RECURSION_HPP

#include "menu.hpp"

class Game {
public:
    Game();
    void startSim();
    void gameflow();
    void firstRecursive();
    void secondRecursive();
    void thirdRecursive();

private:
    Menu menu;
};

#endif //LAB5_RECURSION_HPP
