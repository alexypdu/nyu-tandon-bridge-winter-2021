#include <iostream>
#include <string>
using namespace std;

bool is_delimiter(char ch);
void update_frequency(int frequency[], char ch);

int main() {
    int letter_count = 0, word_count = 0;
    int frequency[26] = {};
    string line;

    getline(cin, line);

    for (char ch: line) {
        if (is_delimiter(ch)) {
            if (letter_count > 0) {
                word_count++;
            }

            letter_count = 0;
        } else {
            update_frequency(frequency, ch);
            letter_count++;
        }
    }

    cout << word_count << "\twords\n";

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            cout << frequency[i] << "\t" << static_cast<char>('a' + i) << endl;
        }
    }

    return 0;
}

bool is_delimiter(char ch) {
    return (ch == ' ') || (ch == ',') || (ch == '.');
}

void update_frequency(int frequency[], char ch) {
    int diff;

    if (ch >= 'a') {
        diff = ch - 'a';
    } else {
        diff = ch - 'A';
    }

    frequency[diff]++;
}
