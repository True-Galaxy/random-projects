#include <iostream>
using namespace std;

int main() {
    int dimension, x, y;
    cout << "Please enter the dimension of the grid (Square): "; cin >> dimension;
    bool grid[dimension][dimension] = {0};
    while (true) {
        cout << "\nEnter a coordinate pair, or 0 to exit: ";
        cin >> x;
        if (x == 0) {
            break;
        }
        cin >> y;
        if (grid[x-1][y-1] == true) {
            grid[x-1][y-1] = false;
        }
        
        else {
            grid[x-1][y-1] = true;
        }
        

        for (int i = 0; i < dimension;i++) {
            for (int j = 0; j < dimension; j++) {
                if (grid[i][j] == true) {
                    cout << "   ";
                }
                else {
                    cout << " * ";
                }
            }
            cout << endl;
        }
    }
}