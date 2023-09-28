#include <iostream>
using namespace std;
int main()
{
    double amount; int q = 0, d = 0, n = 0, p = 0, change; //define vars
    cout << "Enter amount of change owed in dollars: $"; cin >> amount; //user in
    change = int(amount*100); //convert to int cause I kept getting floating point math errors.

    while (change >= 25) { //test and increment for quarters
        change -= 25;
        q++; }
    cout << "\nQuarters: " << q;
    
    while (change >= 10) { //test and increment for dimes
        change -= 10;
        d++; }
    cout << "\nDimes: " << d;
    
    while (change >= 5) { //test and increment for nickels
        change -= 5;
        n++; }
    cout << "\nNickels: " << n;
    p = change; //remainder must be pennies
    cout << "\nPennies: " << p;

    cout << "\nTotal number of coins: " << q + d + n + p;
}



