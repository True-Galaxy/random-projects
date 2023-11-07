// This code ended up getting me a little light-up octopus, and a floppy disk. Total time spent: 23 minutes.

//libraries/namespace
#include <iostream>
#include <string>
using namespace std;

//forward declarations
string cipher(string userin, string key);
unsigned char shiftletter (unsigned char i, int shift);
unsigned char uppercase(char i);

int main()
{
    string userin, key;
    cout << "Enter a word or phrase to be shifted: "; getline(cin, userin);
    cout << "\nEnter a key to shift by: "; cin >> key;
    cout << endl << cipher(userin, key);
    return 0;
}
//function defs
string cipher(string userin, string key) {
    string output; int count = 0;
    for (char i : userin) {
        if (count == key.length()) {
            count = 0;
        }
        output += shiftletter(i, key[count]);
        if (i != shiftletter(i, key[count])) {
            count++;
        }
    }
    return output;
}
unsigned char shiftletter (unsigned char i, int shift) {
    shift = uppercase(shift) - 64; //convert letter to position in the alphabet
    if (i >= 65 && i <= 90) { // uppercase case
        i += shift;
        if (i > 90) { //wraparound
            i = 64 + (i - 90);
        }
    }
    else if (i >= 97 && i <= 122) { // lowercase case
        i += shift;
        if (i > 122) {
            i = 96 + (i - 122);
        }
    }
    return i;
}
unsigned char uppercase(char i) { //make whatever is inputted uppercase
    if (i > 95) {
        i -= 32;
    }
    return i;
}