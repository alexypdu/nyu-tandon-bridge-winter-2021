#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int LIMIT = 5;

int main() {
    int guesses = LIMIT, left = 1, right = 100, target;

    srand(time(0));
    target = (rand() % 100) + 1;
    cout << "I thought of a number between 1 and 100! Try to guess it.\n";

    while (guesses > 0) {
        int guess;

        cout << "Range: [" << left << ", " << right << "], Number of guesses left: " << guesses << endl
             << "Your guess: ";
        cin >> guess;
        guesses--;

        if (guess == target) {
            cout << "Congrats! You guessed my number in " << LIMIT - guesses << " guesses.\n";
            break;
        } else if (guesses == 0) {
            cout << "Out of guesses! My number is " << target << endl;
        } else if (guess < target) {
            cout << "Wrong! My number is bigger.\n\n";

            if (guess >= left) {
                left = guess + 1;
            }
        } else { // guess > target
            cout << "Wrong! My number is smaller.\n\n";

            if (guess <= right) {
                right = guess - 1;
            }
        }
    }

    return 0;
}
