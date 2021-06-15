#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
using namespace std;

class Player {
    public:
        Player(){};
        int turn = 3;
        int bomb = 1;
        int choice;
        string name;

    private:

};

Player x;
Player o;

bool gameOn = true;

string A1 = "1", A2 = "2", A3 = "3";
string B1 = "4", B2 = "5", B3 = "6";
string C1 = "7", C2 = "8", C3 = "9";

void theBoard () {
    if (gameOn) {
        cout << "\x1B[2J\x1B[H";
    };
    cout << x.name << " (X)" << endl;
    cout << " - Bombs: " << x.bomb << endl;
    cout << " - Turns: " << x.turn << endl;
    cout << o.name << " (O)" << endl;
    cout << " - Bombs: " << o.bomb << endl;
    cout << " - Turns: " << o.turn << endl;
    cout << "|_____________________|" << endl << endl;
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

void winningCond(string p, string n) {
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
        theBoard();
        cout << n << " Wins!\n\n";
        gameOn = false;
        cin.get();
    };
}

bool chooseSquareCond (int iChoice, string p, string o, int iTurns, int iBombs) {
    //If Player still has Turns + Bombs
    if ((iTurns > 0) && (iBombs > 0)) {
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
    }
    //If Player still has Turns and no Bombs
    if ((iTurns > 0) && (iBombs == 0)) {
        if (!((isEqualTo(iChoice, p)) &&
        (isEqualTo(iChoice, o))) &&
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
    }
    //If Player still has Bombs and no Turns
    if ((iBombs > 0) && (iTurns == 0)) {
        if (isEqualTo(iChoice, o)) {
            return false;
        } else {
            return true;
        }
    }
};

///X Players Turn/////////////////////////////////
void xTurn () {
    do {
    theBoard();
    cout << x.name << ", Choose a valid square!" << endl;
    cin >> x.choice;
    } while ((chooseSquareCond(x.choice, "X", "O", x.turn, x.bomb)));
    cout << endl;
    x.choice--;
    if (posCheck[x.choice] == 0  && x.bomb> 0) {
        x.bomb--;
    } else {
        x.turn--;
    }
    boardUpdateSwitch(x.choice, "X");
    winningCond("X", x.name);
};
/////////////////////////////////////////////////
///O Players Turn////////////////////////////////
void oTurn () {
    do {
        theBoard();
        cout << o.name << ", Choose a valid square!" << endl;
        cin >> o.choice;
    } while (chooseSquareCond(o.choice, "O", "X", o.turn, o.bomb));
    cout << endl;
    o.choice--;
    if (posCheck[o.choice] == 0  && o.bomb > 0) {
        o.bomb--;
    } else {
        o.turn--;
    }
    boardUpdateSwitch(o.choice, "O");
    winningCond("O", o.name);
};
/////////////////////////////////////////////////
int mainMenuChoice;
void mainMenu (){
    cout << "Tic Tac Boom!" << endl << endl;
    cout << "Enter X Players Name: " << endl << endl;
    cin >> x.name;
    cout << endl << "Enter O Players Name: " << endl << endl;
    cin >> o.name;
	cout << endl << "1. Start A New Game" << endl;
    cout << "2. Show The Rules" << endl;
    cout << "Select: ";
    cin >> mainMenuChoice;
    while (!((mainMenuChoice == 1) || (mainMenuChoice == 2))) {
        cout << "You must choose 1 or 2!\n";
        cin >> mainMenuChoice;
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
    x.turn = 3, o.turn = 3, x.bomb = 1, o.bomb = 1;
    for (int i = 0; i < 9; i++) {
        int arrayVal = 1;
        posCheck[i] = arrayVal;
        arrayVal++;
    }
};

#endif // FUNCTIONS_H_INCLUDED
