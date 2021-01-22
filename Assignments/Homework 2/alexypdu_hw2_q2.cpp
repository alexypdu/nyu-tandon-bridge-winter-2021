#include <iostream>
using namespace std;

const int DOLLAR = 100;
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

int main() {
    int dollars, cents;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
    cin >> dollars >> cents;
    cout << dollars << " dollars and " << cents << " cents are:\n";

    int remaining = DOLLAR * dollars + cents;
    int quarters, dimes, nickels, pennies;

    remaining -= QUARTER * (quarters = remaining / QUARTER);
    remaining -= DIME * (dimes = remaining / DIME);
    remaining -= NICKEL * (nickels = remaining / NICKEL);
    pennies = remaining;

    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies\n";

    return 0;
}
