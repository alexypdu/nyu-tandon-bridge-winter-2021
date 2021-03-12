#include <iostream>
#include <string>
using namespace std;

bool is_delimiter(char ch);
void update_occurrence(int occurrence_arr[], char ch);

int main() {
    const int NUM_OF_ALPHABET = 26;
    int letter_count = 0;
    int word_count = 0;
    int occurrence_arr[NUM_OF_ALPHABET] = {};
    string line;

    cout << "Please enter a line of text:\n";
    getline(cin, line);

    for (char ch: line) {
        if (is_delimiter(ch)) {
            if (letter_count > 0) {
                word_count++;
            }

            letter_count = 0;
        } else {
            update_occurrence(occurrence_arr, ch);
            letter_count++;
        }
    }

    cout << word_count << "\twords\n";

    for (int i = 0; i < NUM_OF_ALPHABET; i++) {
        if (occurrence_arr[i] > 0) {
            cout << occurrence_arr[i] << "\t" << static_cast<char>('a' + i) << endl;
        }
    }

    return 0;
}

bool is_delimiter(char ch) {
    return (ch == ' ') || (ch == ',') || (ch == '.');
}

void update_occurrence(int occurrence_arr[], char ch) {
    if (('a' <= ch) && (ch <= 'z')) {
        occurrence_arr[ch - 'a']++;
    } else if (('A' <= ch) && (ch <= 'Z')) {
        occurrence_arr[ch - 'A']++;
    }
}
