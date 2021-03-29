#include <iostream>
using namespace std;

int* find_missing(int arr[], int n, int& res_arr_size);
void print_array(const int arr[], int arr_size);

int main() {
    const int ARR_SIZE = 6;
    int arr[ARR_SIZE] = { 3, 1, 3, 0, 6, 4 };
    int missing_arr_size;
    int* missing_arr = find_missing(arr, ARR_SIZE, missing_arr_size);

    cout << "Original array: ";
    print_array(arr, ARR_SIZE);
    cout << "Missing array: ";
    print_array(missing_arr, missing_arr_size);

    delete [] missing_arr;

    return 0;
}

int* find_missing(int arr[], int n, int& res_arr_size) {
    int* occurrence = new int[n + 1](); // value-initialize dynamic array

    for (int i = 0; i < n; i++) {
        occurrence[arr[i]]++;
    }

    int* missing = new int[n];
    int count = 0;

    for (int i = 0; i < n + 1; i++) {
        if (occurrence[i] == 0) {
            missing[count++] = i;
        }
    }

    res_arr_size = count;

    delete [] occurrence;

    return missing;
}

void print_array(const int arr[], int arr_size) {
    cout << "[";

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i];

        if (i != arr_size - 1) {
            cout << ", ";
        }
    }

    cout << "]\n";
}
