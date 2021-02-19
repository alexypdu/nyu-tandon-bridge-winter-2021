#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int num;

    cout << "Please enter a positive integer: ";
    cin >> num;
    cout << fib(num);

    return 0;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        int f_n, f_n_1 = 1, f_n_2 = 1;

        for (int i = 3; i <= n; i++) {
            f_n = f_n_1 + f_n_2;
            f_n_2 = f_n_1;
            f_n_1 = f_n;
        }

        return f_n;
    }
}
