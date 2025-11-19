#include <iostream>
using namespace std;
int& maxElement(int* arr, int size) {
    int* maxPtr = &arr[0]; 
    for (int i = 1; i < size; ++i) {
        if (arr[i] > *maxPtr) {
            maxPtr = &arr[i];
        }
    }
    return *maxPtr;
}

int& minElement(int* arr, int size) {
    int* minPtr = &arr[0]; 
    for (int i = 1; i < size; ++i) {
        if (arr[i] < *minPtr) {
            minPtr = &arr[i];
        }
    }
    return *minPtr;
}

int main() {
    const int size = 5;
    int arr[size];
    cout << "Vvedite " << size << " celih chisel: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int& maxVal = maxElement(arr, size);
    int& minVal = minElement(arr, size);
    swap(maxVal, minVal);
    cout << "Izmenenniy massiv: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
