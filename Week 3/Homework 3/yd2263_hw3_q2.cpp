#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int graduation_year, current_year;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> graduation_year;
    cout << "Please enter current year: ";
    cin >> current_year;

    int difference = graduation_year - current_year;

    if (difference > 4) {
        cout << name << ", you are Not in College Yet\n";
    } else if (difference == 4) {
        cout << name << ", you are a Freshman\n";
    } else if (difference == 3) {
        cout << name << ", you are a Sophomore\n";
    } else if (difference == 2) {
        cout << name << ", you are a Junior\n";
    } else if (difference == 1) {
        cout << name << ", you are a Senior\n";
    } else {
        cout << name << ", you are Graduated\n";
    }

    return 0;
}
