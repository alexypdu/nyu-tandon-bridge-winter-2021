#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int user_input;

    cout << "Enter decimal number:\n";
    cin >> user_input;
    cout << "The binary representation of " << user_input << " is ";

    for (int exponent = log2(user_input); exponent >= 0; exponent--) {
        int power = pow(2, exponent);

        if (user_input >= power) {
            cout << '1';
            user_input -= power;
        } else {
            cout << '0';
        }
    }
    
    cout << endl;

    return 0;
}
