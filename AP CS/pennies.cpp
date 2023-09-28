#include <iostream>
using namespace std;
int main() {
    int64_t repeat, start; //define vars
    cout << "Please input a starting number followed by times doubled: "; cin >> start >> repeat; //gather user input
    uint64_t rolling = start, final = 0;
    if (repeat <= 0 || start < 0) { //catches zero/negative case.
        cout << "Repeat or starting number cannot be zero/negative. Restart program to try again.";
        return 1;
    }
    cout << start; //print starting number
    for (;repeat > 1;repeat--) { //loop and perform necessary increments.
            final += rolling;
            rolling *= 2;
            cout << " + " << rolling;
    }
    
    final = final + rolling; //last repetition
    cout << " = " << final << " pennies.";
    if (rolling == 0 && start != 0) { //catch integer overflow
        cout << "\n\nInteger limit reached. Result may not be accurate.";
        return 1;
    }
    return 0;
}






