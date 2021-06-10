#include <iostream>
//#include <gtkmm.h>
#include "functions.h"
using namespace std;

int main () {
    while (true) {
        resetFunc();
        mainMenu();
        if (choice == 1) {
            theBoard();
            while (gameOn) {
                if (((xTurns > 0) || (xBombs > 0)) || ((oTurns > 0) || (oBombs > 0))) {
                    xTurn();
                    if (gameOn) {
                        theBoard();
                    }
                    if (gameOn) {
                        oTurn();
                        if (gameOn) {
                            theBoard();
                        }
                    }
                } else {
                    cout << "It's a draw!\n\n";
                    gameOn = false;
                }
            }
        } else {
            theRules();
            cin.get();
        }
    }
    return 0;
}
