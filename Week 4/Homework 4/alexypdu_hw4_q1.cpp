#include <iostream>
using namespace std;

int main() {
    cout << "section a\n";

    int number_1, counter_1 = 1;
    cout << "Please enter a positive integer: ";
    cin >> number_1;

    while (counter_1 <= number_1) {
        cout << 2 * counter_1 << endl;
        counter_1++;
    }

    cout << "section b\n";

    int number_2;
    cout << "Please enter a positive integer: ";
    cin >> number_2;

    for (int counter_2 = 1; counter_2 <= number_2; counter_2++) {
        cout << 2 * counter_2 << endl;
    }

    return 0;
}
