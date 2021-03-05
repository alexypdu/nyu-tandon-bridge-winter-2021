#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    string str;

    cout << "Please enter a word: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << str << " is a palindrome\n";
    } else {
        cout << str << " is not a palindrome\n";
    }

    return 0;
}

bool isPalindrome(string str) {
    int l = str.length();

    for (int i = 0; i < l / 2; i++) {
        if (str[i] != str[l - i - 1]) {
            return false;
        }
    }

    return true;
}
