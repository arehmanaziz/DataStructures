#include <iostream>
using namespace std;

int liearSearch(int values[], int size, int value) {
    
    for (int i=0; i<size; i++) {
        if (values[i]==value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int values[], int size, int value) {

    int low=0, high=size-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (values[mid] == value)
            return mid;

        if (values[mid] < value)
        low = mid + 1;

        else
        high = mid - 1;
    }

    return -1;
}


int main() {
   
    int values[] = {2, 4, 7, 9, 12, 14, 15, 22, 33};
    int numOfValues = sizeof(values)/sizeof(values[0]);
    cout << binarySearch(values, numOfValues, 2);
    cout << binarySearch(values, numOfValues, 1);
    return 0;
}