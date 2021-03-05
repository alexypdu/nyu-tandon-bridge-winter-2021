#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void swap(int& left, int& right);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }

    cout<<endl;
}

void swap(int& a, int& b) {
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void reverseArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        swap(arr[i], arr[arrSize - i - 1]);
    }
}

void removeOdd(int arr[], int& arrSize) {
    int count = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            arr[count] = arr[i];
            count++;
        }
    }

    arrSize = count;
}

void splitParity(int arr[], int arrSize) {
    for (int i = 0, j = 0; j < arrSize; j++) {
        if (arr[j] % 2 == 1) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}
