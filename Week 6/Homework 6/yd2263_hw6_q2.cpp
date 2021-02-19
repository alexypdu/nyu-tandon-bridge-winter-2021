#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

int main() {
    int numOfTriangles;
    char symbol;

    cout << "Please enter the number of triangles: ";
    cin >> numOfTriangles;
    cout << "Please enter a symbol: ";
    cin >> symbol;

    printPineTree(numOfTriangles, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ' ';
        }

        for (int k = 1; k <= n - i; k++) {
            cout << ' ';
        }

        for (int l = 1; l <= 2 * i - 1; l++) {
            cout << symbol;
        }

        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(i + 1, n - i, symbol);
    }
}
