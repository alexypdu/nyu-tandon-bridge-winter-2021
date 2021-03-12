#include <iostream>
#include <string>
using namespace std;

bool are_anagrams(string str_1, string str_2);
void update_occurrence(int occurrence_arr[], char ch);

int main() {
    string str_1;
    string str_2;

    cout << "Please enter two strings in two lines:\n";
    getline(cin, str_1);
    getline(cin, str_2);

    if (are_anagrams(str_1, str_2)){
        cout << "Two strings are anagrams\n";
    } else {
        cout << "Two strings are not anagrams\n";
    }

    return 0;
}

bool are_anagrams(string str_1, string str_2) {
    const int NUM_OF_ALPHABET = 26;
    int occurrence_arr_1[NUM_OF_ALPHABET] = {};
    int occurrence_arr_2[NUM_OF_ALPHABET] = {};

    for (char ch: str_1) {
        update_occurrence(occurrence_arr_1, ch);
    }

    for (char ch: str_2) {
        update_occurrence(occurrence_arr_2, ch);
    }

    for (int i = 0; i < NUM_OF_ALPHABET; i++) {
        if (occurrence_arr_1[i] != occurrence_arr_2[i]) {
            return false;
        }
    }

    return true;
}

void update_occurrence(int occurrence_arr[], char ch) {
    if (('a' <= ch) && (ch <= 'z')) {
        occurrence_arr[ch - 'a']++;
    } else if (('A' <= ch) && (ch <= 'Z')) {
        occurrence_arr[ch - 'A']++;
    }
}
