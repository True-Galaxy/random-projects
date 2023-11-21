#include <iostream>
#include <string>
using namespace std;

string cipher(string userin, string key); //forward declarations
unsigned char shiftletter (unsigned char i, int shift);
unsigned char uppercase(char i);

/*    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    */
int main()
{
    string userin, key;
    cout << "Enter a word or phrase to be shifted: "; getline(cin, userin); //gather user phrase
    cout << "\nEnter a key to shift by: "; cin >> key; //gather shift key
    cout << endl << cipher(userin, key); //perform cipher and output result
}
/*    /MAIN    /MAIN    /MAIN    /MAIN    /MAIN    /MAIN    /MAIN    /MAIN    /MAIN    /MAIN    /MAIN */

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
        if (i > 90) {
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
unsigned char uppercase(char i) { //function to convert letter to uppercase. Lowercase not needed.
    if (i > 95) {
        i -= 32;
    }
    return i;
}
