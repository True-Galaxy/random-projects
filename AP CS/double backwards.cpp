#include <iostream>
#include <cmath>
using namespace std;
//forward declarations
int64_t domyworkforme(int64_t input);

int main() {
    int64_t number;
    cout << "Please enter a number to be reversed: "; cin >> number;
    domyworkforme(number);
    cout << "Your number reversed is: " << domyworkforme (number) << ", which reversed is: " << domyworkforme (number) * 2; 
}
//function definitions
int64_t domyworkforme (int64_t input) {
    int64_t testnum = 10, digits; double finalout, final=0, doubleinput = input; //declarations
    digits = log10(input)+1; //count digits using logarithms
    while (digits > 0) {
        finalout = ((doubleinput / testnum) - (input / testnum))*10;
        finalout = floor(finalout) * (pow(10,digits)/10);
        final = finalout + final;
        digits = digits - 1;
        testnum = testnum * 10; 
    }
    return final;
}






