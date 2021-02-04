#include <iostream>
using namespace std;

int main() {
    int user_input;

    cout << "Please enter a positive integer: ";
    cin >> user_input;

    for (int number = 1; number <= user_input; number++) {
        int curr = number, number_of_odd_digit = 0, number_of_even_digit = 0;

        while (curr > 0) {
            int digit = curr % 10;

            if (digit % 2 == 0) {
                number_of_even_digit += 1;
            } else {
                number_of_odd_digit += 1;
            }

            curr /= 10;
        }

        if (number_of_odd_digit < number_of_even_digit) {
            cout << number << endl;
        }
    }

    return 0;
}
