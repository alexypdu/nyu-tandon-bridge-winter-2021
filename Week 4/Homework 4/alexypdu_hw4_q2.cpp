#include <iostream>
using namespace std;

const int ROMAN_DIGIT_M = 1000;
const int ROMAN_DIGIT_D = 500;
const int ROMAN_DIGIT_C = 100;
const int ROMAN_DIGIT_L = 50;
const int ROMAN_DIGIT_X = 10;
const int ROMAN_DIGIT_V = 5;
const int ROMAN_DIGIT_I = 1;

int main() {
    int number;

    cout << "Enter decimal number:\n";
    cin >> number;
    cout << number << " is ";

    while (number >= ROMAN_DIGIT_M) {
        cout << 'M';
        number -= ROMAN_DIGIT_M;
    }

    while (number >= ROMAN_DIGIT_D) {
        cout << 'D';
        number -= ROMAN_DIGIT_D;
    }

    while (number >= ROMAN_DIGIT_C) {
        cout << 'C';
        number -= ROMAN_DIGIT_C;
    }

    while (number >= ROMAN_DIGIT_L) {
        cout << 'L';
        number -= ROMAN_DIGIT_L;
    }

    while (number >= ROMAN_DIGIT_X) {
        cout << 'X';
        number -= ROMAN_DIGIT_X;
    }

    while (number >= ROMAN_DIGIT_V) {
        cout << 'V';
        number -= ROMAN_DIGIT_V;
    }

    while (number >= ROMAN_DIGIT_I) {
        cout << 'I';
        number -= ROMAN_DIGIT_I;
    }

    return 0;
}
