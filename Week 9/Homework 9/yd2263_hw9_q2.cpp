#include <iostream>
#include <string>
using namespace std;

const int NUM_OF_LETTER = 26;

bool are_anagrams(string str_1, string str_2);
int* compose_frequency(string str);

int main() {
    string str_1, str_2;

    cout << "Please enter two strings:\n";
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
    int *frequency_1 = compose_frequency(str_1);
    int *frequency_2 = compose_frequency(str_2);
    bool res = true;

    for (int i = 0; i < NUM_OF_LETTER; i++) {
        if (frequency_1[i] != frequency_2[i]) {
            res = false;
            break;
        }
    }

    delete [] frequency_1;
    delete [] frequency_2;
    return res;
}

int* compose_frequency(string str) {
    int *frequency = new int [NUM_OF_LETTER];

    for (char ch: str) {
        if (('a' <= ch) && (ch <= 'z')) {
            frequency[ch - 'a']++;
        } else if (('A' <= ch) && (ch <= 'Z')) {
            frequency[ch - 'A']++;
        }
    }

    return frequency;
}
