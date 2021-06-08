#include <iostream>
#include "functions.h"
using namespace std;

int main () {
    while (true) {
        mainMenu();
        if (choice == 1) {
            cout << "\n\n";
            while (gameOn) {
                if ((xTurns > 0) && (oTurns > 0)) {
                    xTurn();
                    if (gameOn) {
                        oTurn();
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
