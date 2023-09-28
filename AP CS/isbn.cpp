#include <iostream>
using namespace std;
bool isbn(int64_t input); //forward declaration
int main()
{
    uint64_t userin; //set user input to unsigned 64 bit integer
    cout << "Please enter an ISBN to be tested for validity: "; cin >> userin; //take userinput
    if (isbn(userin) == true && userin != 0) { cout << "Valid ISBN number!"; } //check for bool returned by isbn func
    else { cout << "Invalid ISBN number!"; }
}
bool isbn(int64_t input) { //isbn() function def
    int64_t testnum = 10, divisor = 1, sum = 0, digitout; int repeat = 10; //define variables
    while (repeat > 0) { //initiate loop while repeat is greater than 0 (10 times)
        digitout = int(((input % testnum) / divisor)); //isolate digit
        sum = sum + (digitout * repeat); //total, and multiply by the constant from 1-10 to test ISBN 
        repeat = repeat - 1; divisor = divisor * 10; testnum = testnum * 10; } //increments
    if (sum % 11 == 0) {
        return true; }
    else {
        return false; }
}