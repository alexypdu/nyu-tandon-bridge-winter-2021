#include <iostream>
#include <string>
using namespace std;

bool isDigit(string word);
string composeTransformedWord(string word);

int main() {
    string line;

    cout << "Please enter a line of text:\n";
    getline(cin, line);

    for (int start = 0, end = 0; end <= line.length(); end++) {
        if ((end == line.length()) || (line[end] == ' ')) {
            string word = line.substr(start, end - start);
            cout << composeTransformedWord(word) << ' ';
            start = end + 1;
        }
    }

    return 0;
}

bool isDigit(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] < '0' || word[i] > '9') {
            return false;
        }
    }

    return true;
}

string composeTransformedWord(string word) {
    if (isDigit(word)) {
        string transformedWord;

        for (int i = 0; i < word.length(); i++) {
            transformedWord += 'x';
        }

        return transformedWord;
    } else {
        return word;
    }
}
