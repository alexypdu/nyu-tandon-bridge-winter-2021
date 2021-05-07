#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

void open_input_file(ifstream& in_file);
bool areSymbolsBalanced(ifstream& in_file);

int main() {
    ifstream in_file;

    open_input_file(in_file);

    if (areSymbolsBalanced(in_file)) {
        cout << "All symbols are balanced!\n";
    } else {
        cout << "The symbols are NOT balanced!\n";
    }

    return 0;
}

void open_input_file(ifstream& in_file) {
    string file_name;

    cout << "Please enter the file name: ";
    cin >> file_name;
    in_file.open(file_name);

    while (in_file.fail()) {
        cout << "Bad file name!\n"
             << "Please enter the file name: ";
        cin >> file_name;
        in_file.open(file_name);
    }
}

bool areSymbolsBalanced(ifstream& in_file) {
    string token;
    stack<char> symbols;
    bool has_begun = false;

    while (in_file >> token) {
        if (token == "begin") {
            has_begun = true;
        } else if (token == "end") {
            return has_begun && symbols.empty();
        } else {
            if (!has_begun) {
                return false;
            }

            for (char c: token) {
                switch (c) {
                    case '(':
                    case '{':
                    case '[':
                        symbols.push(c);
                        break;
                    case ')':
                        if (!symbols.empty() && symbols.top() == '(') {
                            symbols.pop();
                        } else {
                            return false;
                        }
                        break;
                    case '}':
                        if (!symbols.empty() && symbols.top() == '{') {
                            symbols.pop();
                        } else {
                            return false;
                        }
                        break;
                    case ']':
                        if (!symbols.empty() && symbols.top() == '[') {
                            symbols.pop();
                        } else {
                            return false;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return false;
}
