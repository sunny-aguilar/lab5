/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     LAB5
**                  d
**                  d
**                  d
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    Menu();
    void menuStart();
    void menuEndGame();
    void menuEnterString();
    int validateNumber(int min, int max);

private:

};

#endif //LAB5_MENU_HPP
