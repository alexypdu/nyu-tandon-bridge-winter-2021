#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double userInput;
    int rounding_method;

    cout << "Please enter a Real number:\n";
    cin >> userInput;
    cout << "Choose your rounding method:\n";
    cout << "1. Floor round\n";
    cout << "2. Ceiling round\n";
    cout << "3. Round to the nearest whole number\n";
    cin >> rounding_method;

    int integer_part = userInput;
    double fractional_part = userInput - integer_part;
    bool is_non_negative = (userInput >= 0);
    int result;

    switch (rounding_method) {
        case FLOOR_ROUND:
            if (is_non_negative) {
                result = integer_part;
            } else {
                if (fractional_part == 0) {
                    result = integer_part;
                } else {
                    result = integer_part - 1;
                }
            }
            break;
        case CEILING_ROUND:
            if (is_non_negative) {
                if (fractional_part == 0) {
                    result = integer_part;
                } else {
                    result = integer_part + 1;
                }
            } else {
                result = integer_part;
            }
            break;
        case ROUND:
            if (is_non_negative) {
                if (fractional_part >= 0.5) {
                    result = integer_part + 1;
                } else {
                    result = integer_part;
                }
            } else {
                if (fractional_part <= -0.5) {
                    result = integer_part - 1;
                } else {
                    result = integer_part;
                }
            }
            break;
        default:
            break;
    }

    cout << result << endl;

    return  0;
}
