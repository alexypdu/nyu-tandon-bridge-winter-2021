#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, middleName, lastName;

    cout << "Please enter your name: ";
    cin >> firstName >> middleName >> lastName;
    cout << lastName << ", " << firstName << " " << middleName[0] << ".\n";

    return 0;
}
