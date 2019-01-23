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
#include <string>
using std::string;

class Game {
public:
    Game();
    void startSim();
    void gameflow();
    void chooseOption();
    void firstRecursive(std::string userString);
    int secondRecursive(int *intArr, int size);
    void thirdRecursive();

private:
    Menu menu;
    bool keepPlaying;
};

#endif //LAB5_RECURSION_HPP
