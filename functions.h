#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

bool gameOn = true;
int xTurns = 3, oTurns = 3, xBomb = 1, oBomb = 1, choice;
void Clear()
{
    if (gameOn) {
        cout << "\x1B[2J\x1B[H";
    }
}

string A1 = "1", A2 = "2", A3 = "3";
string B1 = "4", B2 = "5", B3 = "6";
string C1 = "7", C2 = "8", C3 = "9";
void theBoard () {
    cout << "| X Player Bombs Left: " << xBomb << " |" << endl;
    cout << "| O Player Bombs Left: " << oBomb << " |" << endl;
    cout << "|________________________|" << endl << endl;
	cout << A1 << "  | " << A2 << "  | " << A3 << endl;
	cout << "___|____|___" << endl;
	cout << B1 << "  | " << B2 << "  | " << B3 << endl;
	cout << "___|____|___" << endl;
	cout << C1 << "  | " << C2 << "  | " << C3 << endl;
	cout << endl;
}

void printNoSuicide() {
    cout << "You cannot use a bomb on yourself!" << endl;
}

string noSuicide (int iTurn) {
    iTurn++;
    switch (iTurn){
        case 1:
            return A1;
            break;
        case 2:
            return A2;
            break;
        case 3:
            return A3;
            break;
        case 4:
            return B1;
            break;
        case 5:
            return B2;
            break;
        case 6:
            return C3;
            break;
        case 7:
            return C1;
            break;
        case 8:
            return C2;
            break;
        case 9:
            return C3;
            break;
        default:
            break;
            return 0;
    }
    return 0;
};

///X Players Turn
int x1;
int posCheck[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void xTurn () {
    do {
    Clear();
    theBoard();
    cout << "X Player, Choose a valid square!" << endl;
    cin >> x1;
    } while (!((x1 == 1) ||
            (x1 == 2) ||
            (x1 == 3) ||
            (x1 == 4) ||
            (x1 == 5) ||
            (x1 == 6) ||
            (x1 == 7) ||
            (x1 == 8) ||
            (x1 == 9)));
    cout << endl;
    x1--;
    if (posCheck[x1] == 0) {
        if ((xBomb > 0) && (noSuicide(x1) != "X")) {
        x1++;
        xBomb--;
        } else {
        x1 = 0;
        }
    } else {
    xTurns--;
    x1++;
    }

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
            break;
    }

    if ((((A1 == "X") &&
        (A2 == "X") &&
        (A3 == "X")) ||
        ((B1 == "X") &&
        (B2 == "X") &&
        (B3 == "X")) ||
        ((C1 == "X") &&
        (C2 == "X") &&
        (C3 == "X")) ||
        ((A1 == "X") &&
        (B1 == "X") &&
        (C1 == "X")) ||
        ((A2 == "X") &&
        (B2 == "X") &&
        (C2 == "X")) ||
        ((A3 == "X") &&
        (B3 == "X") &&
        (C3 == "X")) ||
        ((A1 == "X") &&
        (B2 == "X") &&
        (C3 == "X")) ||
        ((A3 == "X") &&
        (B2 == "X") &&
        (C1 == "X")))) {
        Clear();
        gameOn = false;
        cout << "X Player Wins!\n\n";
        cin.get();
    };
};

///O Players Turn
int o1;
void oTurn () {
    do {
        Clear();
        theBoard();
        cout << "O Player, Choose a valid square!" << endl;
        cin >> o1;
    } while (!((o1 == 1) ||
            (o1 == 2) ||
            (o1 == 3) ||
            (o1 == 4) ||
            (o1 == 5) ||
            (o1 == 6) ||
            (o1 == 7) ||
            (o1 == 8) ||
            (o1 == 9)));
    cout << endl;
    o1--;
    if (posCheck[o1] == 0) {
        if ((oBomb > 0) && (noSuicide(o1) != "O")) {
        o1++;
        oBomb--;
        } else {
        oTurns--;
        o1 = 0;
        }
    } else {
    o1++;
    }
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
            break;
    };
    if ((((A1 == "O") &&
        (A2 == "O") &&
        (A3 == "O")) ||
        ((B1 == "O") &&
        (B2 == "O") &&
        (B3 == "O")) ||
        ((C1 == "O") &&
        (C2 == "O") &&
        (C3 == "O")) ||
        ((A1 == "O") &&
        (B1 == "O") &&
        (C1 == "O")) ||
        ((A2 == "O") &&
        (B2 == "O") &&
        (C2 == "O")) ||
        ((A3 == "O") &&
        (B3 == "O") &&
        (C3 == "O")) ||
        ((A1 == "O") &&
        (B2 == "O") &&
        (C3 == "O")) ||
        ((A3 == "O") &&
        (B2 == "O") &&
        (C1 == "O")))) {
        Clear();
        gameOn = false;
        cout << "O Player Wins!\n\n";
        cin.get();
    }
};

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

void theRules () {
    cout << "\n\n1. Each player gets to select 3 squares.\n";
    cout << "2. Each player gets 1 bomb, which can destroy a players selection and replace it with their own \n";
    cout << "3. You must get 3 squares in a row to win.\n";
    cout << "4. To use a bomb, just select an opponents square!\n\n";
};

void resetFunc () {
    gameOn = true;
    A1 = "1", A2 = "2", A3 = "3";
    B1 = "4", B2 = "5", B3 = "6";
    C1 = "7", C2 = "8", C3 = "9";
    xTurns = 3, oTurns = 3, xBomb = 1, oBomb = 1;
    for (int i = 0; i < 9; i++) {
        int arrayVal = 1;
        posCheck[i] = arrayVal;
        arrayVal++;
    }
};

#endif // FUNCTIONS_H_INCLUDED
