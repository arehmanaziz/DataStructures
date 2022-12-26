#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for (int j=low; j<high; j++) {
        if (arr[j] < pivot) 
            swap(arr[++i], arr[j]);
    }

    swap(arr[i++], arr[high]);
    return i;
}

void quickSort(int arr[], int start, int end) {

    if (start<end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
	cout << "Quick Sort" << endl;
	int values[] = {23, 1, 7, 3, 12, 5, 22, 11, 9};
    int size = sizeof(values) / sizeof(values[0]);
    cout << "Before Sort: "; printArray(values, size);

    quickSort(values, 0, size - 1);

    cout << "After Sort: "; printArray(values, size);

	return 0;
}
