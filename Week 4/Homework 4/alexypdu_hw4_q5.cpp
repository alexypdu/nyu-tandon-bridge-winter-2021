#include <iostream>
using namespace std;

int main() {
    int user_input;

    cout << "Please enter a positive integer: ";
    cin >> user_input;

    for (int i = 0; i < user_input; i++) {
        int space_length = i, asterisk_length = 2 * (user_input - i) - 1;

        for (int j = 0; j < space_length; j++) {
            cout << ' ';
        }

        for (int k = 0; k < asterisk_length; k++) {
            cout << '*';
        }

        cout << endl;
    }

    for (int i = 0; i < user_input; i++) {
        int space_length = user_input - i - 1, asterisk_length = 2 * i + 1;

        for (int j = 0; j < space_length; j++) {
            cout << ' ';
        }

        for (int k = 0; k < asterisk_length; k++) {
            cout << '*';
        }

        cout << endl;
    }

    return 0;
}
