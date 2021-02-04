#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    cout << "section a\n";

    int length, product_1 = 1;

    cout << "Please enter the length of the sequence: ";
    cin >> length;
    cout << "Please enter your sequence:\n";

    for (int counter = 1; counter <= length; counter++) {
        int user_input;

        cin >> user_input;
        product_1 *= user_input;
    }

    double geometric_mean_1 = pow(product_1, 1 / double(length));

    cout << "The geometric mean is: " << geometric_mean_1 << endl;
    cout << "section b\n";
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. "
         << "End your sequence by typing -1:\n";

    int user_input, counter = 0, product_2 = 1;

    cin >> user_input;

    while (user_input >= 0) {
        product_2 *= user_input;
        counter++;
        cin >> user_input;
    }

    double geometric_mean_2 = pow(product_2, 1 / double(counter));

    cout << "The geometric mean is: " << geometric_mean_2 << endl;

    return 0;
}
