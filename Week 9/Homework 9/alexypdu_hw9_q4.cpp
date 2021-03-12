#include <iostream>
#include <string>
using namespace std;

void print_array(int arr[], int arr_size);
void oddsKeepEvensFlip(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);

int main() {
    const int arr_size = 6;
    int arr_1[arr_size] = { 5, 2, 11, 7, 6, 4 };
    int arr_2[arr_size] = { 1, 3, 5, 7, 9, 11 };
    int arr_3[arr_size] = { 0, 2, 4, 6, 8, 10 };
    int arr_4[arr_size] = { 9, 13, 20, 8, 13, 7 };
    int arr_5[arr_size] = { -5, 6, 17, 14, -12, 2 };

    cout << "Original array: ";
    print_array(arr_1, arr_size);
    oddsKeepEvensFlip(arr_1, arr_size);
    cout << "Reordered array: ";
    print_array(arr_1, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_2, arr_size);
    oddsKeepEvensFlip(arr_2, arr_size);
    cout << "Reordered array: ";
    print_array(arr_2, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_3, arr_size);
    oddsKeepEvensFlip(arr_3, arr_size);
    cout << "Reordered array: ";
    print_array(arr_3, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_4, arr_size);
    oddsKeepEvensFlip(arr_4, arr_size);
    cout << "Reordered array: ";
    print_array(arr_4, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_5, arr_size);
    oddsKeepEvensFlip(arr_5, arr_size);
    cout << "Reordered array: ";
    print_array(arr_5, arr_size);

    return 0;
}

void print_array(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

void oddsKeepEvensFlip(int arr[], int arr_size) {
    int odd_count = 0;

    for (int i = 0, j = 0; j < arr_size; j++) {
        if (arr[j] % 2 != 0) {
            swap(arr[i++], arr[j]);
            odd_count++;
        }
    }

    reverseArray(arr + odd_count, arr_size - odd_count);
}

void reverseArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        swap(arr[i], arr[arrSize - i - 1]);
    }
}
