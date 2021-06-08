#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
using namespace std;

//////VARIABLES//////
string A1 = "1", A2 = "2", A3 = "3";
string B1 = "4", B2 = "5", B3 = "6";
string C1 = "7", C2 = "8", C3 = "9";
int x1;
int o1;
int posCheck[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool gameOn = true;
int xTurns = 4, oTurns = 4, xBomb = 1, oBomb = 1, choice;


///////FUNCTIONS///////
void mainMenu (){
    cout << "Tic Tac Boom!" << endl;
	cout << "1. Start A New Game" << endl;
    cout << "2. Show The Rules" << endl;
    cout << "Select: ";
    cin >> choice;
    while (!((choice == 1) || (choice == 2))) {
        cout << "You must choose 1 or 2!\n";
        cin >> choice;
	};
}
void Clear()
{
    cout << "\x1B[2J\x1B[H";
}


void theBoard () {
	cout << A1 << "  | " << A2 << "  | " << A3 << endl;
	cout << "___|____|___" << endl;
	cout << B1 << "  | " << B2 << "  | " << B3 << endl;
	cout << "___|____|___" << endl;
	cout << C1 << "  | " << C2 << "  | " << C3 << endl;
	cout << endl;
}


void xTurn () {
    Clear();
    theBoard();
    cout << "X Player Bombs Left: " << xBomb << endl;
    cout << "X Player, Choose a valid square!" << endl;
    cin >> x1;
    cout << endl;
    x1--;
    if (posCheck[x1] == 0) {
        if (xBomb > 0) {
        x1++;
        xBomb--;
        } else {
        x1 = 0;
        }
    } else {
    x1++;
    }
    if (x1 != 0) {
        switch (x1) {
            case 1:
                A1 = "X";
                posCheck [0] = 0;
                break;
            case 2:
                A2 = "X";
                posCheck [1] = 0;

                break;
            case 3:
                A3 = "X";
                posCheck [2] = 0;
                break;
            case 4:
                B1 = "X";
                posCheck [3] = 0;
                break;
            case 5:
                B2 = "X";
                posCheck [4] = 0;
                break;
            case 6:
                B3 = "X";
                posCheck [5] = 0;
                break;
            case 7:
                C1 = "X";
                posCheck [6] = 0;
                break;
            case 8:
                C2 = "X";
                posCheck [7] = 0;
                break;
            case 9:
                C3 = "X";
                posCheck [8] = 0;
                break;
            default:
                cout << "Oops! That's not a valid selection!" << endl;
                xTurn();
        }
    if ((A1 == "X") &&
        (A2 == "X") &&
        (A3 == "X") ||
        (B1 == "X") &&
        (B2 == "X") &&
        (B3 == "X") ||
        (C1 == "X") &&
        (C2 == "X") &&
        (C3 == "X") ||
        (A1 == "X") &&
        (B1 == "X") &&
        (C1 == "X") ||
        (A2 == "X") &&
        (B2 == "X") &&
        (C2 == "X") ||
        (A3 == "X") &&
        (B3 == "X") &&
        (C3 == "X") ||
        (A1 == "X") &&
        (B2 == "X") &&
        (C3 == "X") ||
        (A3 == "X") &&
        (B2 == "X") &&
        (C1 == "X")) {
        gameOn = false;
        Clear();
        theBoard();
        cout << "X Player Wins!\n\n";
        cin.get();
    };
    } else {
    xTurn();
    }
    //After O Player fully completes their turn, their number of turns is decreased by 1
    xTurns--;
};


void oTurn () {
    Clear();
    theBoard();
    cout << "O Player Bombs Left: " << oBomb << endl;
    cout << "O Player, Choose a valid square!" << endl;
    cin >> o1;
    cout << endl;
    o1--;
    if (posCheck[o1] == 0) {
        if (oBomb > 0) {
        o1++;
        oBomb--;
        } else {
        o1 = 0;
        }
    } else {
    o1++;
    }
    if (o1 != 0) {
        switch (o1) {
            case 1:
                A1 = "O";
                posCheck [0] = 0;
                break;
            case 2:
                A2 = "O";
                posCheck [1] = 0;
                break;
            case 3:
                A3 = "O";
                posCheck [2] = 0;
                break;
            case 4:
                B1 = "O";
                posCheck [3] = 0;
                break;
            case 5:
                B2 = "O";
                posCheck [4] = 0;
                break;
            case 6:
                B3 = "O";
                posCheck [5] = 0;
                break;
            case 7:
                C1 = "O";
                posCheck [6] = 0;
                break;
            case 8:
                C2 = "O";
                posCheck [7] = 0;
                break;
            case 9:
                C3 = "O";
                posCheck [8] = 0;
                break;
            default:
                cout << "Oops! That's not a valid selection!" << endl;
                oTurn();
        };
    if ((A1 == "O") &&
        (A2 == "O") &&
        (A3 == "O") ||
        (B1 == "O") &&
        (B2 == "O") &&
        (B3 == "O") ||
        (C1 == "O") &&
        (C2 == "O") &&
        (C3 == "O") ||
        (A1 == "O") &&
        (B1 == "O") &&
        (C1 == "O") ||
        (A2 == "O") &&
        (B2 == "O") &&
        (C2 == "O") ||
        (A3 == "O") &&
        (B3 == "O") &&
        (C3 == "O") ||
        (A1 == "O") &&
        (B2 == "O") &&
        (C3 == "O") ||
        (A3 == "O") &&
        (B2 == "O") &&
        (C1 == "O")) {
        gameOn = false;
        Clear();
        theBoard();
        cout << "O Player Wins!\n\n";
        cin.get();
    }
    } else {
        oTurn();
    };
    //After O Player fully completes their turn, their number of turns is decreased by 1
    oTurns--;
};


void theRules () {
    cout << "\n\n1. Each player gets to select 3 squares.\n";
    cout << "2. Each player gets 1 bomb, which can destroy a players selection and replace it with their own \n";
    cout << "3. You must get 3 squares in a row to win.\n";
    cout << "To use a bomb, just select an opponents square!\n\n";
};

#endif // FUNCTIONS_H_INCLUDED
