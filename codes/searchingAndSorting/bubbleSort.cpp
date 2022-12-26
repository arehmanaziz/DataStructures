#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {

    int i, j;
    for (i=0; i < size-1; i++) {
        for (j=0; j < size-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Bubble Sort" << endl;
    int values[] = {23, 1, 7, 3, 12, 5, 22, 11, 9};
    int size = sizeof(values) / sizeof(values[0]);
    cout << "Before Sort: "; printArray(values, size);

    bubbleSort(values, size);

    cout << "After Sort: "; printArray(values, size);

	return 0;
}