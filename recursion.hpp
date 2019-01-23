/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This class contains three functions that perform
**                  recursion in order to solve the problem. Function
**                  one reverses a string using recursion. Function
**                  two sums the contents of an array using recursion,
**                  and function three calculates the triangular
**                  number of an integer N.
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
    int thirdRecursive(int n);

private:
    Menu menu;
    bool keepPlaying;
};

#endif //LAB5_RECURSION_HPP
