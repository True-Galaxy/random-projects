#include <iostream>
#include <cmath> //only for circle function. Not used in actual assignment. cos and sin used.
using namespace std;

int rnd(double input);
void left(int input);
void right(int input);
void middle(int input);
void circle(int input);

int main() {   
while (true) {
    char choice; short userin;
    cout << "\n[a]: Circle\n[b]: Left facing triangle\n[c]: Right facing triangle\n[d]: Centered triangle";
    cout << "\nPlease select an option: "; cin >> choice;
    cout << "Enter the height of the triangle/diameter of the circle: "; cin >> userin;
    
    cout << "\n";

    if (choice == 'a') {
        circle(userin);
    }

    else if (choice == 'b') {
        left(userin);
    }

    else if (choice == 'c') {
        right(userin);
    }
    else if (choice == 'd') {
        middle(userin);
    }
    else {
        cout << "Invalid choice.";
        return 1;
    }
}
}
int rnd(double input) {
    double var = input - int(input);
    if (var >= 0.5) {
        return int(input+1);
    }
    else {
        return int(input);
    }
}

void left(int input) {
    short rows = input, count = 1, count2 = 1;
    for (;rows > 0;rows--) {
        for (;count2 > 0;count2--) {
                cout << "*";
        }
        count++;
        count2 = count;
        cout << "\n";
    }
}

void right(int input) {
    
    short rows = input, count = 1, count2 = 1, blank, blank2;
    blank = rows - 1; blank2 = blank;
    for (;rows > 0;rows--) {
        for (;blank2 > 0;blank2--) {
                cout << " ";
        }
        for (;count2 > 0;count2--) {
                cout << "*";
        }
        count++;
        count2 = count;
        blank--;
        blank2 = blank;
        cout << "\n";
    }
}

void middle(int input) {
    short rows = input, count = 1, count2 = 1, blank, blank2;
    blank = rows - 1; blank2 = blank;
    for (;rows > 0;rows--) {
        for (;blank2 > 0;blank2--) {
                cout << " ";
        }
        for (;count2 > 0;count2--) {
                cout << "*";
        }
        cout << " ";
        count2 = count;
        for (;count2 > 0;count2--) {
                cout << "*";
        }
        count++;
        count2 = count;
        blank--;
        blank2 = blank;
        cout << "\n";
    }
}

void circle(int input) {
    double x, y, ang = 0, angdeg = 0;
    int o;
    bool array[input+5][input+5] = {0};
    double pi = 3.141;
    ang = 0;
    angdeg = 0;
    cout << "[";
    for (int repeat = 7200;repeat > 0;repeat--) {
        angdeg += 0.05;
        ang = angdeg * (pi/180);
        x = input/2 * cos(ang);
        y = input/2 * sin(ang);
        o = ((input+5)/2);
        cout << "|";
        //cout << "(" << x << "," << y << ")\n";
        array[o + rnd(x+0.5)][o + rnd(y+0.5)] = 1;
    }
    cout << "\n";
    for (int repeat2 = input+5;repeat2>0;repeat2--) {
        for (int repeat3 = input+5;repeat3>0;repeat3--) {
            if (array[repeat2][repeat3] == 1) {
                cout << "* ";
            }
            // else if (repeat2 == 1 || repeat2 == input+5) {
            //     cout << "■ ";
            // }
            // else if (repeat3 == 1 || repeat3 == input+5) {
            //     cout << "■ ";
            // }
            else {
                cout << "  ";
            }
        }
    cout << "\n";
    }
    cout << "\n\nNote: The larger the circle the more accurate it is.";
}