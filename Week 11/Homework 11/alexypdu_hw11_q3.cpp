#include <iostream>
using namespace std;

int min_in_array_1(int arr[], int arr_size);
int min_in_array_2(int arr[], int low, int high);

int main() {
    int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
    int res_1, res_2, res_3, res_4;

    res_1 = min_in_array_1(arr, 10);
    res_2 = min_in_array_2(arr, 0, 9);
    cout << res_1 << ' ' << res_2 << endl;

    res_3 = min_in_array_2(arr, 2, 5);
    res_4 = min_in_array_1(arr + 2, 4);
    cout << res_3 << ' ' << res_4 << endl;

    return 0;
}

int min_in_array_1(int arr[], int arr_size) {
    if (arr_size == 1) {
        return arr[0];
    } else {
        int prev_min = min_in_array_1(arr, arr_size - 1);
        int last = arr[arr_size - 1];

        if (prev_min > last) {
            return last;
        } else {
            return prev_min;
        }
    }
}

int min_in_array_2(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    } else {
        if (arr[low] > arr[high]) {
            return min_in_array_2(arr, low + 1, high);
        } else {
            return min_in_array_2(arr, low, high - 1);
        }
    }
};
