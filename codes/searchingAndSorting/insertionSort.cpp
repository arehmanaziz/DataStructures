#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    int temp, j;
    for (int i=1; i < size; i++) {
        temp = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Insertion Sort" << endl;
    int values[] = {23, 1, 7, 3, 12, 5, 22, 11, 9};
    int size = sizeof(values) / sizeof(values[0]);
    cout << "Before Sort: "; printArray(values, size);

    insertionSort(values, size);

    cout << "After Sort: "; printArray(values, size);

	return 0;
}