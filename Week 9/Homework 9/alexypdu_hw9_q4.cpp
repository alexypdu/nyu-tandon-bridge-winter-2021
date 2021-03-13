#include <iostream>
using namespace std;

void print_array(int arr[], int arr_size);
void odds_keep_evens_flip(int arr[], int arr_size);

int main() {
    const int arr_size = 6;
    int arr_1[arr_size] = { 5, 2, 11, 7, 6, 4 };
    int arr_2[arr_size] = { 1, 3, 5, 7, 9, 11 };
    int arr_3[arr_size] = { 2, 4, 6, 8, 10, 12 };
    int arr_4[arr_size] = { 1, 3, 5, 2, 4, 6 };
    int arr_5[arr_size] = { 1, 2, 4, 6, 3, 8 };

    cout << "Original array: ";
    print_array(arr_1, arr_size);
    odds_keep_evens_flip(arr_1, arr_size);
    cout << "Reordered array: ";
    print_array(arr_1, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_2, arr_size);
    odds_keep_evens_flip(arr_2, arr_size);
    cout << "Reordered array: ";
    print_array(arr_2, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_3, arr_size);
    odds_keep_evens_flip(arr_3, arr_size);
    cout << "Reordered array: ";
    print_array(arr_3, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_4, arr_size);
    odds_keep_evens_flip(arr_4, arr_size);
    cout << "Reordered array: ";
    print_array(arr_4, arr_size);
    cout << endl;

    cout << "Original array: ";
    print_array(arr_5, arr_size);
    odds_keep_evens_flip(arr_5, arr_size);
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

void odds_keep_evens_flip(int arr[], int arr_size) {
    int left = 0;
    int right = arr_size - 1;
    int* temp = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] % 2 == 0) {
            temp[right--] = arr[i];
        } else {
            temp[left++] = arr[i];
        }
    }

    for (int i = 0; i < arr_size; i++) {
        arr[i] = temp[i];
    }

    delete [] temp;
}
