/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     LAB5 - this program presents 3 recursive functions
**                  that reverse a string, sum the elements of an
**                  array, and computes a triangular number. A class
**                  called Game is created that owns an instance of
**                  the Recursion class. Recursion class is where the
**                  three functions are located. Dynamic memory is
**                  allocated for the second recursive function and
**                  the memory is deleted after the function has been
**                  called (see chooseOption() function in Game class).
**                  The Menu class shows prompts the user to select
**                  the functions they would like to see and the
**                  menu keeps repeating until the user quits.
*********************************************************************/
#include "recursion.hpp"
#include "menu.hpp"
#include <iostream>

int main() {
    Game rec;
    rec.startSim();
    return 0;
}