#include <iostream>
#include <string>
using namespace std;

const double POUND_TO_KILOGRAM = 0.453592;
const double INCH_TO_METER = 0.0254;

int main() {
    int pounds, inches;

    cout << "Please enter weight (in pounds): ";
    cin >> pounds;
    cout << "Please enter height (in inches): ";
    cin >> inches;

    double kilograms = pounds * POUND_TO_KILOGRAM, meters = inches * INCH_TO_METER;
    double bmi = kilograms / (meters * meters);
    string weight_status;

    if (bmi < 18.5) {
        weight_status = "Underweight";
    } else if (bmi < 25) {
        weight_status = "Normal";
    } else if (bmi < 30) {
        weight_status = "Overweight";
    } else {
        weight_status = "Obese";
    }

    cout << "The weight status is: " << weight_status << endl;

    return 0;
}
