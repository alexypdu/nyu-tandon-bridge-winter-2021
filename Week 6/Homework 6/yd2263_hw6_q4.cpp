#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int n);

int main() {
    int n;

    cout << "Please enter a positive integer >= 2: ";
    cin >> n;
    printDivisors(n);

    return 0;
}

void printDivisors(int n) {
    double sqrt = pow(n, 0.5);

    for (int i = 1; i < sqrt; i++) {
        if (n % i == 0) {
            cout << i << ' ';
        }
    }

    for (int i = sqrt; i > 1; i--) {
        if (n % i == 0) {
            cout << n / i << ' ';
        }
    }

    cout << n << endl;
}
