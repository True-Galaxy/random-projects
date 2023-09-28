#include <iostream>
using namespace std;

//forward declarations
double largest(double input);

int main() {
    int userin;
    cout << "Please enter a 3 digit number: "; cin >> userin;
    cout << "Largest is: " << largest(userin);
}

//function defs
double largest(double input) { //function to calculate largest order.
    double d1, d2, d3, final=0;
    d1 = int(input / 100);                  //algorithm thing for getting individual digits
    d2 = int((input / 10) - (10 * d1));
    d3 = int(input - (100 * d1 + 10 * d2));
    if (d1 >= d2 && d1 >= d3) { //d1 largest scenerio
        final = final + 100*d1;
        if (d2 >= d3) {
            final = final + 10 * d2 + d3; }
        else {
            final = final + d2 + 10 * d3; }
    }
    else if (d2 >= d1 && d2 >= d3) { //d2 largest scenerio
        final = final + 100 * d2;
        if (d1 >= d3) {
            final = final + 10 * d1 + d3; }
        else {
            final = final + d1 + 10 * d3; }
    }
    else { //d3 largest scenerio
        final = final + 100 * d3;
        if (d1 >= d2) {
            final = final + 10 * d1 + d2; }
        else {
            final = final + d1 + 10 * d2; }
    }
    return final;
}

