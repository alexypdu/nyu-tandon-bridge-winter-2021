#include <iostream>
#include <string>
using namespace std;

const string SATURDAY = "Sa";
const string SUNDAY = "Su";
const int HOUR_TO_MINUTE = 60;
const int EIGHT_AM_IN_MINUTES = 8 * HOUR_TO_MINUTE;
const int SIX_PM_IN_MINUTES = 18 * HOUR_TO_MINUTE;

int main() {
    string day_of_the_week;
    int hours, minutes, call_length;
    char temp;

    cout << "Please enter the day of the week: ";
    cin >> day_of_the_week;
    cout << "Please enter the time the call started: ";
    cin >> hours >> temp >> minutes;
    cout << "Please enter the length of the call (in minutes): ";
    cin >> call_length;

    int starting_time_in_minutes = hours * HOUR_TO_MINUTE + minutes;
    bool is_working_hours = (starting_time_in_minutes >= EIGHT_AM_IN_MINUTES) && (starting_time_in_minutes <= SIX_PM_IN_MINUTES);
    double rate, cost;

    if ((day_of_the_week == SATURDAY) || (day_of_the_week == SUNDAY)) {
        rate = 0.15;
    } else { // weekdays
        if (is_working_hours) {
            rate = 0.40;
        } else {
            rate = 0.25;
        }
    }

    cost = rate * call_length;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The cost of the call is " << cost << " dollars\n";

    return 0;
}
