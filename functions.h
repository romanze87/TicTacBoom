#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

bool gameOn = true;
int xTurns = 3, oTurns = 3, xBomb = 1, oBomb = 1, choice;

string A1 = "1", A2 = "2", A3 = "3";
string B1 = "4", B2 = "5", B3 = "6";
string C1 = "7", C2 = "8", C3 = "9";
void theBoard () {
    if (gameOn) {
        cout << "\x1B[2J\x1B[H";
    }
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

bool isEqualTo (int iTurn, string isI) {
    string i;
    switch (iTurn){
        case 1:
            i = A1;
            break;
        case 2:
            i = A2;
            break;
        case 3:
            i = A3;
            break;
        case 4:
            i = B1;
            break;
        case 5:
            i = B2;
            break;
        case 6:
            i = C3;
            break;
        case 7:
            i = C1;
            break;
        case 8:
            i = C2;
            break;
        case 9:
            i = C3;
            break;
        default:
            break;
            return 0;
    }
    if (i == isI) {
        return true;
    } else {
        return false;
    }
};

int posCheck[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void boardUpdateSwitch (int p, string i) {
    switch (p) {
        case 0:
            A1 = i;
            posCheck [0] = 0;
            break;
        case 1:
            A2 = i;
            posCheck [1] = 0;
            break;
        case 2:
            A3 = i;
            posCheck [2] = 0;
            break;
        case 3:
            B1 = i;
            posCheck [3] = 0;
            break;
        case 4:
            B2 = i;
            posCheck [4] = 0;
            break;
        case 5:
            B3 = i;
            posCheck [5] = 0;
            break;
        case 6:
            C1 = i;
            posCheck [6] = 0;
            break;
        case 7:
            C2 = i;
            posCheck [7] = 0;
            break;
        case 8:
            C3 = i;
            posCheck [8] = 0;
            break;
        default:
            break;
    }
};

void winningCond(string p) {
    if ((((A1 == p) &&
        (A2 == p) &&
        (A3 == p)) ||
        ((B1 == p) &&
        (B2 == p) &&
        (B3 == p)) ||
        ((C1 == p) &&
        (C2 == p) &&
        (C3 == p)) ||
        ((A1 == p) &&
        (B1 == p) &&
        (C1 == p)) ||
        ((A2 == p) &&
        (B2 == p) &&
        (C2 == p)) ||
        ((A3 == p) &&
        (B3 == p) &&
        (C3 == p)) ||
        ((A1 == p) &&
        (B2 == p) &&
        (C3 == p)) ||
        ((A3 == p) &&
        (B2 == p) &&
        (C1 == p)))) {
        Clear();
        gameOn = false;
        cout << p << " Player Wins!\n\n";
        cin.get();
    };
}

bool chooseSquareCond (int iChoice, string p) {
    if (!(isEqualTo(iChoice, p)) &&
    (iChoice == 1 ||
    iChoice == 2 ||
    iChoice == 3 ||
    iChoice == 4 ||
    iChoice == 5 ||
    iChoice == 6 ||
    iChoice == 7 ||
    iChoice == 8 ||
    iChoice == 9)) {
        return false;
    } else {
        return true;
    }
};

///X Players Turn/////////////////////////////////
int x1;
void xTurn () {
    do {
    theBoard();
    cout << "X Player, Choose a valid square!" << endl;
    cin >> x1;
    } while ((chooseSquareCond(x1, "X")));
    cout << endl;
    x1--;
    if (posCheck[x1] == 0  && xBomb > 0) {
        xBomb--;
    } else {
        xTurns--;
    }
    boardUpdateSwitch(x1, "X");
    winningCond("X");
};
/////////////////////////////////////////////////
///O Players Turn////////////////////////////////
int o1;
void oTurn () {
    do {
        theBoard();
        cout << "O Player, Choose a valid square!" << endl;
        cin >> o1;
    } while (chooseSquareCond(o1, "O"));
    cout << endl;
    o1--;
    if (posCheck[o1] == 0  && oBomb > 0) {
        oBomb--;
    } else {
        oTurns--;
    }
    boardUpdateSwitch(o1, "O");
    winningCond("O");
};
/////////////////////////////////////////////////
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
