#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
int getNumOfDaysInFeb(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int year, startingDay;

    cout << "Please enter a year: ";
    cin >> year;
    cout << "Please enter the starting day of the year: ";
    cin >> startingDay;
    printYearCalender(year, startingDay);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";

    for (int i = 1; i < startingDay; i++) {
        cout << '\t';
    }

    for (int i = 1; i <= numOfDays; i++) {
        if (((i + startingDay - 1) % 7 == 0) || i == numOfDays) {
            cout << i << endl;
        } else {
            cout << i << '\t';
        }
    }

    return (numOfDays + startingDay - 1) % 7;
}

bool isLeapYear(int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int getNumOfDaysInFeb(int year) {
  if (isLeapYear(year)) {
    return 29;
  } else {
    return 28;
  }
}

void printYearCalender(int year, int startingDay) {
    cout << "January " << year << endl;
    startingDay = printMonthCalender(31, startingDay) + 1;
    cout << endl;

    cout << "February " << year << endl;
    startingDay = printMonthCalender(getNumOfDaysInFeb(year), startingDay) + 1;
    cout << endl;

    cout << "March " << year << endl;
    startingDay = printMonthCalender(31, startingDay) + 1;
    cout << endl;

    cout << "April " << year << endl;
    startingDay = printMonthCalender(30, startingDay) + 1;
    cout << endl;

    cout << "May " << year << endl;
    startingDay = printMonthCalender(31, startingDay) + 1;
    cout << endl;

    cout << "June " << year << endl;
    startingDay = printMonthCalender(30, startingDay) + 1;
    cout << endl;

    cout << "July " << year << endl;
    startingDay = printMonthCalender(31, startingDay) + 1;
    cout << endl;

    cout << "August " << year << endl;
    startingDay = printMonthCalender(31, startingDay) + 1;
    cout << endl;

    cout << "September " << year << endl;
    startingDay = printMonthCalender(30, startingDay) + 1;
    cout << endl;

    cout << "October " << year << endl;
    startingDay = printMonthCalender(31, startingDay) + 1;
    cout << endl;

    cout << "November " << year << endl;
    startingDay = printMonthCalender(30, startingDay) + 1;
    cout << endl;

    cout << "December " << year << endl;
    printMonthCalender(31, startingDay);
}
