#include <iostream>
using namespace std;

void print_array(const int arr[], int arr_size);
int sum_of_squares(int arr[], int arr_size);
bool is_sorted(int arr[], int arr_size);

int main() {
    int arr_1[] = { 2, -1, 3, 10 };
    int arr_1_size = sizeof(arr_1) / sizeof(*arr_1);

    cout << "arr_1: ";
    print_array(arr_1, arr_1_size);
    cout << "sum_of_squares(arr_1, arr_1_size): " << sum_of_squares(arr_1, arr_1_size) << endl;
    cout << "is_sorted(arr_1, arr_1_size): ";

    if (is_sorted(arr_1, arr_1_size)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    cout << endl;

    int arr_2[6] = { 1, 2, 3, 4, 5, 6 };
    int arr_2_size = sizeof(arr_2) / sizeof(*arr_2);

    cout << "arr_2: ";
    print_array(arr_2, arr_2_size);
    cout << "sum_of_squares(arr_2, arr_2_size): " << sum_of_squares(arr_2, arr_2_size) << endl;
    cout << "is_sorted(arr_2, arr_2_size): ";

    if (is_sorted(arr_2, arr_2_size)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}

void print_array(const int arr[], int arr_size) {
    cout << '[';

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i];

        if (i != arr_size - 1) {
            cout << ", ";
        }
    }

    cout << "]\n";
}

int sum_of_squares(int arr[], int arr_size) {
    if (arr_size == 1) {
        return arr[0] * arr[0];
    } else {
        int last = arr[arr_size - 1];

        return sum_of_squares(arr, arr_size - 1) + last * last;
    }
}

bool is_sorted(int arr[], int arr_size) {
    if (arr_size == 1) {
        return true;
    } else {
        int last = arr[arr_size - 1];
        int one_before_last = arr[arr_size - 2];

        return is_sorted(arr, arr_size - 1) && (one_before_last < last);
    }
}
