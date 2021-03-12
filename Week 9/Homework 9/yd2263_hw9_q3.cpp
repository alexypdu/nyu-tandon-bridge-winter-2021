#include <iostream>
#include <string>
using namespace std;

void print_array(int arr[], int arr_size);
int* get_pos_nums_1(int* arr, int arr_size, int& out_pos_arr_size);
int* get_pos_nums_2(int* arr, int arr_size, int* out_pos_arr_size_ptr);
void get_pos_nums_3(int* arr, int arr_size, int*& out_pos_arr, int& out_pos_arr_size);
void get_pos_nums_4(int* arr, int arr_size, int** out_pos_arr_ptr, int* out_pos_arr_size_ptr);

int main() {
    const int arr_size = 6;
    int arr[arr_size] = { 3, -1, -3, 0, 6, 4 };
    cout << "Original array: ";
    print_array(arr, arr_size);

    int pos_nums_1_size;
    int *pos_nums_1 = get_pos_nums_1(arr, arr_size, pos_nums_1_size);
    cout << "get_pos_nums_1: ";
    print_array(pos_nums_1, pos_nums_1_size);

    int pos_nums_2_size;
    int *pos_nums_2 = get_pos_nums_2(arr, arr_size, &pos_nums_2_size);
    cout << "get_pos_nums_2: ";
    print_array(pos_nums_2, pos_nums_2_size);

    int pos_nums_3_size;
    int *pos_nums_3 = nullptr;
    get_pos_nums_3(arr, arr_size, pos_nums_3, pos_nums_3_size);
    cout << "get_pos_nums_3: ";
    print_array(pos_nums_3, pos_nums_3_size);

    int pos_nums_4_size;
    int *pos_nums_4 = nullptr;
    get_pos_nums_4(arr, arr_size, &pos_nums_4, &pos_nums_4_size);
    cout << "get_pos_nums_4: ";
    print_array(pos_nums_4, pos_nums_4_size);

    return 0;
}

void print_array(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

int* get_pos_nums_1(int* arr, int arr_size, int& out_pos_arr_size) {
    int pos_count = 0;
    int *pos_nums = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > 0) {
            pos_nums[pos_count++] = arr[i];
        }
    }

    out_pos_arr_size = pos_count;

    return pos_nums;
}

int* get_pos_nums_2(int* arr, int arr_size, int* out_pos_arr_size_ptr) {
    int pos_count = 0;
    int *pos_nums = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > 0) {
            pos_nums[pos_count++] = arr[i];
        }
    }

    *out_pos_arr_size_ptr = pos_count;

    return pos_nums;
}

void get_pos_nums_3(int* arr, int arr_size, int*& out_pos_arr, int& out_pos_arr_size) {
    int pos_count = 0;
    int *pos_nums = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > 0) {
            pos_nums[pos_count++] = arr[i];
        }
    }

    out_pos_arr = pos_nums;
    out_pos_arr_size = pos_count;
}

void get_pos_nums_4(int* arr, int arr_size, int** out_pos_arr_ptr, int* out_pos_arr_size_ptr) {
    int pos_count = 0;
    int *pos_nums = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > 0) {
            pos_nums[pos_count++] = arr[i];
        }
    }

    *out_pos_arr_ptr = pos_nums;
    *out_pos_arr_size_ptr = pos_count;
}
