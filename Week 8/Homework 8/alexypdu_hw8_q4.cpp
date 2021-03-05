#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int composeEncryptedPIN(int num[]);

const int PIN[5] = {1, 2 ,3, 4, 5};

int main() {
    int num[10];

    cout << "Please enter your PIN according to the following mapping:\n"
         << "PIN:\t0 1 2 3 4 5 6 7 8 9\n"
         << "Num:\t";
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        num[i] = (rand() % 3) + 1;
        cout << num[i] << ' ';
    }

    cout << endl;

    int userInput;

    cin >> userInput;

    if (userInput == composeEncryptedPIN(num)) {
        cout << "Your PIN is correct\n";
    } else {
        cout << "Your PIN is not correct\n";
    }

    return 0;
}

int composeEncryptedPIN(int num[]) {
    int encryptedPIN = 0;

    for (int i = 0; i < 5; i++) {
        encryptedPIN = 10 * encryptedPIN + num[PIN[i]];
    }

    return encryptedPIN;
}
