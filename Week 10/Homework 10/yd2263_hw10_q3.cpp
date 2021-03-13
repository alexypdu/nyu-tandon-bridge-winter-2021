#include <iostream>
#include <vector>
using namespace std;

void main_1();
void main_2();
void resize_array(int*& arr, int& size, int new_size);
int* get_search_results(int target, const int lines[], int lines_size, int& search_results_size);
vector<int> get_search_results(int target, const vector<int>& lines);
void print_results(int target, const int search_results[], int search_results_size);
void print_results(int target, const vector<int>& search_results);

int main() {
    cout << "Version 1:\n";
    main_1();
    cout << "\nVersion 2:\n";
    main_2();

    return 0;
}

void main_1() {
    const int INITIAL_SIZE = 10;
    int size = INITIAL_SIZE;
    int* lines = new int[size];
    int lines_size = 0;

    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
         << "End you input by typing -1.\n";

    while (true) {
        int input;

        cin >> input;

        if (input == -1) {
            break;
        } else {
            lines[lines_size++] = input;

            if (lines_size == size) {
                resize_array(lines, size, size * 2);
            }
        }
    }

    int target;

    cout << "Please enter a number you want to search.\n";
    cin >> target;

    int search_results_size;
    int* search_results = get_search_results(target, lines, lines_size, search_results_size);

    print_results(target, search_results, search_results_size);

    delete [] lines;
    delete [] search_results;
}

void main_2() {
    vector<int> lines;

    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
         << "End you input by typing -1.\n";

    while (true) {
        int input;

        cin >> input;

        if (input == -1) {
            break;
        } else {
            lines.push_back(input);
        }
    }

    int target;

    cout << "Please enter a number you want to search.\n";
    cin >> target;

    vector<int> search_results = get_search_results(target, lines);

    print_results(target, search_results);
}

void resize_array(int*& arr, int& size, int new_size) {
    int* temp = new int[new_size];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    delete [] arr;

    arr = temp;
    size = new_size;
}

int* get_search_results(int target, const int lines[], int lines_size, int& search_results_size) {
    int* search_results = new int[lines_size];
    int count = 0;

    for (int i = 0; i < lines_size; i++) {
        if (lines[i] == target) {
            search_results[count++] = i + 1;
        }
    }

    search_results_size = count;

    return search_results;
}

vector<int> get_search_results(int target, const vector<int>& lines) {
    vector<int> search_results;

    for (int i = 0; i < lines.size(); i++) {
        if (lines[i] == target) {
            search_results.push_back(i + 1);
        }
    }

    return search_results;
}

void print_results(int target, const int search_results[], int search_results_size) {
    if (search_results_size == 0) {
        cout << target << " does not show at all in the sequence.\n";
    } else {
        cout << target << " shows in lines ";

        for (int i = 0; i < search_results_size; i++) {
            if (i == search_results_size - 1) {
                cout << search_results[i] << ".\n";
            } else {
                cout << search_results[i] << ", ";
            }
        }
    }
}

void print_results(int target, const vector<int>& search_results) {
    if (search_results.empty()) {
        cout << target << " does not show at all in the sequence.\n";
    } else {
        cout << target << " shows in lines ";

        for (int i = 0; i < search_results.size(); i++) {
            if (i == search_results.size() - 1) {
                cout << search_results[i] << ".\n";
            } else {
                cout << search_results[i] << ", ";
            }
        }
    }
}
