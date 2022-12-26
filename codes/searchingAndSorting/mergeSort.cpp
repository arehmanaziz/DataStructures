#include <iostream>
using namespace std;


void merge(int arr[], int lower, int mid, int upper) {

    int n1 = mid - lower + 1;
    int n2 = upper - mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[lower + i];

    for (int j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = lower;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } 
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = M[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    cout << "Merge Sort" << endl;
    int values[] = {23, 1, 7, 3, 12, 5, 22, 11, 9};
    int size = sizeof(values) / sizeof(values[0]);
    cout << "Before Sort: "; printArray(values, size);

    mergeSort(values, 0, size - 1);

    cout << "After Sort: "; printArray(values, size);
    return 0;
}