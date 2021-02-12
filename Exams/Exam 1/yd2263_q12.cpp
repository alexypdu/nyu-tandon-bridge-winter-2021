#include <iostream>
using namespace std;

const int YARD_TO_FEET = 3;
const int FOOT_TO_INCHES = 12;

int main() {
    int cumulative_inches = 0, day_counter = 1, user_input;
    int yards, feet, inches;

    cout << "Enter the number of inches the snail traveled in day #" << day_counter
         << ", or type -1 if they reached their destination:\n";
    cin >> user_input;

    while (user_input != -1) {
        cumulative_inches += user_input;
        day_counter++;
        cout << "Enter the number of inches the snail traveled in day #" << day_counter
             << ", or type -1 if they reached their destination:\n";
        cin >> user_input;
    }

    yards = cumulative_inches / (YARD_TO_FEET * FOOT_TO_INCHES);
    cumulative_inches -= yards * YARD_TO_FEET * FOOT_TO_INCHES;
    feet = cumulative_inches / FOOT_TO_INCHES;
    cumulative_inches -= feet * FOOT_TO_INCHES;
    inches = cumulative_inches;

    cout << "In " << day_counter - 1 << " days, the snail traveled " << yards << " yards, "
         << feet << " feet and " << inches << " inches.\n";

    return 0;
}
