#include <iostream>
using namespace std;

int main() {
    double price_1, price_2, tax_rate;
    char has_club_card;

    cout << "Enter price of first item: ";
    cin >> price_1;
    cout << "Enter price of second item: ";
    cin >> price_2;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> has_club_card;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax_rate;

    double base_price = price_1 + price_2, discounted_price, total_price;

    if (price_1 < price_2) {
        discounted_price = price_1 / 2 + price_2;
    } else {
        discounted_price = price_1 + price_2 / 2;
    }

    if ((has_club_card == 'Y') || (has_club_card == 'y')) {
        discounted_price *= 0.9;
    }

    total_price = discounted_price * (1 + tax_rate / 100);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Base price: " << base_price <<endl;
    cout << "Price after discounts: " << discounted_price <<endl;
    cout << "Total price: " << total_price <<endl;

    return 0;
}
