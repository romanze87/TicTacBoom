#include <iostream>
//#include <gtkmm.h>
#include "functions.h"
using namespace std;

int main () {
    while (true) {
        resetFunc();
        mainMenu();
        if (choice == 1) {
            Clear();
            theBoard();
            while (gameOn) {
                if ((xTurns > 0) && (oTurns > 0)) {
                    xTurn();
                    Clear();
                    theBoard();
                    if (gameOn) {
                        oTurn();
                        Clear();
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
