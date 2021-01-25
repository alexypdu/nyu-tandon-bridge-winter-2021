#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) { // 0x^2 + 0x + 0 = 0
                cout << "This equation has infinite number of solutions\n";
            } else { // 0x^2 + 0x + c = 0
                cout << "This equation has no solution\n";
            }
        } else { // 0x^2 + bx + c = 0
            double solution = -c / b;
            cout << "This equation has a single real solution x=" << solution << endl;
        }
    } else { // ax^2 + bx + c = 0
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double solution_1 = (-b + sqrt(discriminant)) / (2 * a);
            double solution_2 = (-b - sqrt(discriminant)) / (2 * a);

            cout << "This equation has two real solutions x=" << solution_1 << " and x=" << solution_2 << endl;
        } else if (discriminant == 0) {
            double solution = -b / (2 * a);

            cout << "This equation has a single real solution x=" << solution << endl;
        } else { // discriminant < 0
            cout << "This equation has no real solution\n";
        }
    }

    return 0;
}
