#include <iostream>
using namespace std;

int main() {
    int num_1, num_2;

    cout << "Please enter two positive integers, separated by a space:\n";
    cin >> num_1 >> num_2;
    cout << num_1 << " + " << num_2 << " = " << num_1 + num_2 << endl;
    cout << num_1 << " - " << num_2 << " = " << num_1 - num_2 << endl;
    cout << num_1 << " * " << num_2 << " = " << num_1 * num_2 << endl;
    cout << num_1 << " / " << num_2 << " = " << double(num_1) / num_2 << endl;
    cout << num_1 << " div " << num_2 << " = " << num_1 / num_2 << endl;
    cout << num_1 << " mod " << num_2 << " = " << num_1 % num_2 << endl;

    return 0;
}