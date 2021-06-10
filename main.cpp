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
                if ((xTurns > 0) && (oTurns > 0)) {
                    xTurn();
                    theBoard();
                    if (gameOn) {
                        oTurn();
                        theBoard();
                    }
                } else {
                    cout << "It's a draw!\n\n";
                    gameOn = false;
                    cin.get();
                }
            }
        } else {
            theRules();
            cin.get();

        }
    }
    return 0;
}
