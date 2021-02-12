#include <iostream>
using namespace std;

int main() {
    int user_input;

    cout << "Please enter a positive integer:\n";
    cin >> user_input;

    for (int i = 1; i <= user_input; i++) {
        int j;

        for (j = 1; j < user_input; j++) {
            cout << i * j << '\t';
        }

        cout << i * j << endl;
    }

    return 0;
}
