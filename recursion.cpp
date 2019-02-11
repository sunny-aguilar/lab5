/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 6, 2019
** Description:     This class contains three functions that perform
**                  recursion in order to solve the problem. Function
**                  one reverses a string using recursion. Function
**                  two sums the contents of an array using recursion,
**                  and function three calculates the triangular
**                  number of an integer N.
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
                // recursive function 1 selected
                string userString = menu.menuEnterString();
                menu.menuReversedString();
                firstRecursive(userString);
                cout << endl << endl << endl;
            }
            break;
        case 2:
            {
                // recursive function 2 selected
                menu.menuEnterArraySize();
                int size = menu.validateNumber(1,999);
                // dynamically allocate array
                int *integers = new int[size];
                for (int index = 0; index < size; index++) {
                    menu.menuEnterArrayValue(index);
                    int value = menu.validateInteger(-999999,999999);
                    integers[index] = value;
                    cout << ">> Value stored " << integers[index] << endl << endl;
                }
                int arraySum = 0;
                arraySum = secondRecursive(integers, size);
                menu.menuArraySum(arraySum, integers, size);

                // delete memory for dynamic array
                delete [] integers;
            }
            break;
        case 3:
            {
                // recursive function 3 selected
                menu.menuTriangularNumber();
                int n = menu.validateNumber(1,1000);
                int triangularSum = 0;
                triangularSum = thirdRecursive(n);
                menu.menuTriangularResults(n, triangularSum);
            }
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
        cout << userString.at(userString.length() - 1) << endl;
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
** Description:     second recursive function that returns the sum
**                  of the array. Algorithm - if the array has more
**                  than 1 element, return the value of the last
**                  element and add it to the value that is returned
**                  by calling the same function again all the way
**                  until the base case is reached. Base case is
**                  reached by subtracting 1 from the size of the
**                  array until the last element of the array is
**                  added.
*********************************************************************/
int Game::secondRecursive(int *intArr, int size) {
    // base case
    if (size == 1) {
        return intArr[size-1];
    }
    // recursive call
    else if (size > 1) {
        return intArr[size-1] + secondRecursive(intArr, size - 1);
    }

}

/*********************************************************************
** Description:     third recursive function. Calculates the
**                  number of an integer N. Algorithm - return N
**                  plus the value return by calling the recursive
**                  function again until base case where 1 is returned.
*********************************************************************/
int Game::thirdRecursive(int n) {
    // base case
    if (n == 1) {
        return 1;
    }
    // recursive call
    else if (n > 1) {
        return n + thirdRecursive(n - 1);
    }
}