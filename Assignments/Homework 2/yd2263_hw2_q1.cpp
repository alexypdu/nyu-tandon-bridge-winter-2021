#include <iostream>
using namespace std;

const int DOLLAR = 100;
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

int main() {
    int quarters, dimes, nickels, pennies;

    cout << "Please enter number of coins:\n";
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    int total = QUARTER * quarters + DIME * dimes + NICKEL * nickels + pennies;
    int dollars = total / DOLLAR;
    int cents = total % DOLLAR;

    cout << "The total is " << dollars << " dollars and " << cents << " cents\n";

    return 0;
}
