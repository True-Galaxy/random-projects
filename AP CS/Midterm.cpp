/*
    A Word of Caution:
    First of all, this code is far from optimized and has a lot of issues still.
    Second of all, while it is a good source to gain inspriation and direction from,
    DO NOT copy direct code or functions. There are a lot of concepts he might ask you to explain.
    If you need any help understand parts of the code, feel free to contact me.
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread; //sleep_for()
using namespace std::chrono; //milliseconds()

void animtext(string input, int speed) {
    for (char i : input) {
        cout << i << flush;
        sleep_for(milliseconds(speed));
    }
}

int dropcheck(int input, int dimension, short int board[6][7][4]) { //Checks for first available vertical space.
    for (int i = 5; i >= 0; i--) {
        if (board[i][input][dimension] == 0) {
            return i;
        }
    }
    cout << "\nInvalid selction. \n\nYour turn has been skipped.";
    return -1;
}

void printgrid(short int board[6][7][4]) {
    system("clear");
    cout << "\n";
    for (int k = 0; k < 4; k++) { //open each dimension 
        for (int l = k; l>0; l--) { //create offset to give 3d effect
            cout << "    ";
        }
        cout << " 0  1  2  3  4  5  6   dimension " << k << "\n"; //column labels
        for (int i = 0; i < 6; i++) { //open each row
            for (int l = k; l>0; l--) { //open each column
                cout << "    ";
            }
            for (int j = 0; j < 7;j++) {
                switch (board[i][j][k]) { //switch for each value at selected point in 3d array
                    case 0: //Empty generic
                        cout << " ~ "; break;
                    case 1: // P1 generic
                        cout << " X "; break;
                    case 2: //P2 generic
                        cout << " O "; break;
                    case 3: // P1/P2 win
                        cout << " # "; break;
                    default: //Any value other than 0-3 should never exist, otherwise the program is immidiately stopped.
                        cout << "Array error detected.";
                        throw range_error("Game Board Value Error Detected.");
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int checkwin(short int board[6][7][4]) {
    int target = 0;
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j][k] > 0) {
                    target = board[i][j][k];
                    
                    //ONE DIMENSIONAL CHECKS
                    if (i >= 3) {  
                        if (board[i-1][j][k] == target) { // Checks from bottom to top. 1D
                            if (board[i-2][j][k] == target) {
                                if (board[i-3][j][k] == target) {
                                    cout << "\nPlayer " << target << " wins! (up / down) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i-1][j][k] = 3; board[i-2][j][k] = 3; board[i-3][j][k] = 3;
                                    return target;
                                }
                            }
                        }
                    }
                    
                    if (j >= 3) {  
                        if (board[i][j-1][k] == target) { // Checks from right to left. 1D
                            if (board[i][j-2][k] == target) {
                                if (board[i][j-3][k] == target) {
                                    cout << "\nPlayer " << target << " wins! (left /right) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i][j-1][k] = 3; board[i][j-2][k] = 3; board[i][j-3][k] = 3;
                                    return target;
                                }
                            }
                        }
                    }
                    
                    //TWO DIMENSIONAL CHECKS
                    if (i >= 3 && j <= 3) {  
                        if (board[i-1][j+1][k] == target) { //diag R 2D
                            if (board[i-2][j+2][k] == target) {
                                if (board[i-3][j+3][k] == target) {
                                    cout << "\nPlayer " << target << " wins! (Diagonal up right) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i-1][j+1][k] = 3; board[i-2][j+2][k] = 3; board[i-3][j+3][k] = 3;
                                    return target;
                                }
                            }
                        }
                    }
                    
                    if (i >=3 && j >= 3) {  
                        if (board[i-1][j-1][k] == target) { //diag L 2D
                            if (board[i-2][j-2][k] == target) {
                                if (board[i-3][j-3][k] == target) {
                                    cout << "\nPlayer " << target << " wins! (Diagonal up left) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i-1][j-1][k] = 3; board[i-2][j-2][k] = 3; board[i-3][j-3][k] = 3;
                                    return target;
                                }
                            }
                        }
                    }
                    
                    //THREE DIMENSIONAL CHECKS
                    if (k == 0) {  
                        if (board[i][j][k+1] == target) { //straight through i, j, k + 1
                            if (board[i][j][k+2] == target) {
                                if (board[i][j][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi-dimensional: Straight through) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i][j][k+1] = 3; board[i][j][k+2] = 3; board[i][j][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }
                    
                    if (k == 0 && j < 4) {  
                        if (board[i][j+1][k+1] == target) { //Horizontal right i, j + 1, k + 1
                            if (board[i][j+2][k+2] == target) {
                                if (board[i][j+3][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Horizontal Right) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i][j+1][k+1] = 3; board[i][j+2][k+2] = 3; board[i][j+3][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }
                    
                    if (k == 0 && j >= 3) {  
                        if (board[i][j-1][k+1] == target) { //Horizontal left i, j - 1, k + 1
                            if (board[i][j-2][k+2] == target) {
                                if (board[i][j-3][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Horizontal left) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i][j-1][k+1] = 3; board[i][j-2][k+2] = 3; board[i][j-3][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }

                    if (k == 0 && i >= 3) {  
                        if (board[i-1][j][k+1] == target) { //Vertical up i - 1, j, k + 1
                            if (board[i-2][j][k+2] == target) {
                                if (board[i-3][j][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Vertical up) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i-1][j][k+1] = 3; board[i-2][j][k+2] = 3; board[i-3][j][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }

                    if (k == 0 && i <= 2) {  
                        if (board[i+1][j][k+1] == target) { //Vertical up i - 1, j, k + 1
                            if (board[i+2][j][k+2] == target) {
                                if (board[i+3][j][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Vertical down) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i+1][j][k+1] = 3; board[i+2][j][k+2] = 3; board[i+3][j][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }

                    if (k == 0 && i >= 3 && j <= 3) {  
                        if (board[i-1][j+1][k+1] == target) { //START DOWN Diagonal right i - 1, j + 1, k + 1
                            if (board[i-2][j+2][k+2] == target) {
                                if (board[i-3][j+3][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Diagonal up right) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i-1][j+1][k+1] = 3; board[i-2][j+2][k+2] = 3; board[i-3][j+3][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }

                    if (k == 0 && i >= 3 && j >= 3) {  
                        if (board[i-1][j-1][k+1] == target) { //START DOWN Diagonal left i - 1, j - 1, k + 1
                            if (board[i-2][j-2][k+2] == target) {
                                if (board[i-3][j-3][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Diagonal up left) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i-1][j-1][k+1] = 3; board[i-2][j-2][k+2] = 3; board[i-3][j-3][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }

                    if (k == 0 && i <= 2 && j <= 3) {  
                        if (board[i+1][j+1][k+1] == target) { //START UP Diagonal right i + 1, j - 1, k + 1
                            if (board[i+2][j+2][k+2] == target) {
                                if (board[i+3][j+3][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Diagonal down right) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i+1][j+1][k+1] = 3; board[i+2][j+2][k+2] = 3; board[i+3][j+3][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }

                    if (k == 0 && i <= 2 && j >= 3) {  
                        if (board[i+1][j-1][k+1] == target) { //START UP Diagonal left i + 1, j - 1, k + 1
                            if (board[i+2][j-2][k+2] == target) {
                                if (board[i+3][j-3][k+3] == target) {
                                    cout << "\nPlayer " << target << " wins! (Multi dimensional: Diagonal down left) Press enter to see the winning patter.";
                                    board[i][j][k] = 3; board[i+1][j-1][k+1] = 3; board[i+2][j-2][k+2] = 3; board[i+3][j-3][k+3] = 3;
                                    return target;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    short int board[6][7][4] = {0}, selection, dimension; //Connect 4 features a 6 row by 7 column board
    bool state = true; //State = true: P1, State=false: P2
    string test;
    string visual = "                  .%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+                               \n                  .%                                               %+                               \n                  .%                                               %+                               \n                  .%     =+++++++++++++++++++++++++++++++++++++++++@#+++++.                         \n                  .%     %=::::::::::::::::::::::::::::::::::::::::::::::@:                         \n                  .%     %-                                             .@:                         \n                  .%     %-                                             .@:                         \n                  .%     %-    *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-                   \n                  .%     %-    *+                                              %-                   \n                  .%     %-    *+                                              %-                   \n                  .%     %-    *+                                              %-                   \n                  .%     %-    *+    +%##############################################@:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .%     %-    *+    ++.                                            :%:             \n                  .######@-    *+    ++.                                            :%:             \n                         %-    *+    ++.                                            :%:             \n                         %-    *+    ++.                                            :%:             \n                         %%####%+    ++.                                            :%:             \n                         ......*+    ++.                                            :%:\n                               *+    ++.                                            :%:\n                               *+....++.                                            :%:\n                               +%%%%%@*.                                            :%:\n                                     ++.                                            :%:\n                                     ++.                                            :%:\n                                     +#=============================================+@:\n                                     .::::::::::::::::::::::::::::::::::::::::::::::::.";
    animtext(visual,1);
    animtext("\nConnect Four^2 is essentially 4 Connect Four boards standing in a line.", 5);
    animtext("\nAll normal Connect 4 rules apply, but in addition to the normal wins, you can win across dimensions.", 5);
    animtext("\nPress Enter to begin.", 1);
    cin.ignore();
    printgrid(board);
    while (true) {
        if (state == true) {
            animtext("\nPlayer 1, Enter a dimension (0-3) and column number (0-6): ", 5);
            if (cin >> dimension) { //cin will return true of false if it works or not. will continue as normal if true, AKA a correct input.
            }
            else {
                cout << "bad input";
                cin.clear();          //clear any pending errors.
                cin.ignore(50, '\n'); //ignore 10 characters, delimit at newline.
                continue;             //restart loop on same player to allow another input.
            }
            if (cin >> selection) {
            }
            else {
                cout << "bad input"; //same as last function
                cin.clear();
                cin.ignore(50, '\n');
                continue;
            }
            
            if (((selection > 6 || selection < 0) || (dimension > 3 || dimension < 0))) {
                cout << "Invalid selection, your turn has been skipped.\n";
                state=false;
                continue;
            }
            board[dropcheck(selection, dimension, board)][selection][dimension] = 1;
            state = false;
        }
        else {
            animtext("\nPlayer 2, Enter a dimension (0-3) and column number (0-6): ", 5);
            if (cin >> dimension) { //cin will return true of false if it works or not. will continue as normal if true, AKA a correct input.
            }
            else {
                cout << "bad input";
                cin.clear();          //clear any pending errors.
                cin.ignore(50, '\n'); //ignore 10 characters, delimit at newline.
                continue;             //restart loop on same player to allow another input.
            }
            if (cin >> selection) {
            }
            else {
                cout << "bad input"; //same as last function
                cin.clear();
                cin.ignore(50, '\n');
                continue;
            }
            if ((selection > 6 || selection < 0) || (dimension > 3 || dimension < 0)) {
                
                cout << "Invalid selection, your turn has been skipped.\n";
                state=true;
                continue;
            }
            board[dropcheck(selection, dimension, board)][selection][dimension] = 2;
            state = true;
        }
        printgrid(board);
        if (checkwin(board) != 0) {
            break;
        }
    }
    
    cin.ignore();
    getline(cin, test);
    printgrid(board);
    cin.ignore();
    getline(cin, test);
}
