#include <iostream>
using namespace std;

void selectiontionSort(int arr[], int size) {
 
    for (int i=0; i < size-1; i++) {
        int minimumIndex = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minimumIndex])
                minimumIndex = j;
        }

        if (minimumIndex!=i) 
            swap(arr[minimumIndex], arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Selection Sort" << endl;
    int values[] = {23, 1, 7, 3, 12, 5, 22, 11, 9};
    int size = sizeof(values) / sizeof(values[0]);
    cout << "Before Sort: "; printArray(values, size);

    selectiontionSort(values, size);

    cout << "After Sort: "; printArray(values, size);

	return 0;
}