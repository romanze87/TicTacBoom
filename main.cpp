#include "functions.h"


int main () {
    while (true) {
        resetFunc();
        mainMenu();
        if (mainMenuChoice == 1) {
            theBoard();
            while (gameOn) {
                if (((x.turn > 0) || (x.bomb > 0)) || ((o.turn > 0) || (o.bomb > 0))) {
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
