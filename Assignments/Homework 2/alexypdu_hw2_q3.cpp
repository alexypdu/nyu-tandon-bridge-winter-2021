#include <iostream>
using namespace std;

const int DAY_TO_HOURS = 24;
const int HOUR_TO_MINUTES = 60;

int main() {
    int john_work_days, john_work_hours, john_work_minutes;

    cout << "Please enter the number of days John has worked: ";
    cin >> john_work_days;
    cout << "Please enter the number of hours John has worked: ";
    cin >> john_work_hours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> john_work_minutes;
    cout << endl;

    int bill_work_days, bill_work_hours, bill_work_minutes;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> bill_work_days;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> bill_work_hours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> bill_work_minutes;
    cout << endl;

    int total_work_days = john_work_days + bill_work_days;
    int total_work_hours = john_work_hours + bill_work_hours;
    int total_work_minutes = john_work_minutes + bill_work_minutes;

    total_work_hours += total_work_minutes / HOUR_TO_MINUTES;
    total_work_minutes %= HOUR_TO_MINUTES;
    total_work_days += total_work_hours / DAY_TO_HOURS;
    total_work_hours %= DAY_TO_HOURS;

    cout << "The total time both of them worked together is: " << total_work_days << " days, " << total_work_hours << " hours and " << total_work_minutes << " minutes.\n";

    return 0;
}