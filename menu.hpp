/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Menu class contains a series of messages and
**                  prompts for the user. Menu class also validates
**                  user's input.
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
    void menuReversedString();
    void menuEnterArraySize();
    void menuEnterArrayValue(int index);
    void menuArraySum(int sum, int *arr, int size);
    void menuTriangularNumber();
    void menuTriangularResults(int n, int sum);
    int validateNumber(int min, int max);

private:

};

#endif //LAB5_MENU_HPP
