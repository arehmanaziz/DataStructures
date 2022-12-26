#include <iostream>
using namespace std;

bool isPrime(int n) {
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
   
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
   
    return true;
}
 

int nextPrime(int N) {
 
    // Base case
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;
 
    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;
 
        if (isPrime(prime))
            found = true;
    }
 
    return prime;
}


void printList(int* list, int len) {
    cout << "[";
    for (int i=0; i<len; i++) {
        cout << list[i] << ", ";
    }
    cout << "]" << endl;
}



int* closedHashing(int &HS, int *values, int totalValues) {

    int *HT = (int*) malloc(HS * sizeof(int));

    for (int i=0; i<HS; i++) {
        HT[i] = -1;
    }

    int no_of_values = 0;
    float load = 0;

    int HI, key;
    for (int i=0; i<totalValues; i++) {

        if (load >= 0.5) {
            // rehashing
            int val[no_of_values];

            for (int k = 0; k < no_of_values; k++)
            {
                val[k] = values[k];
            }

            free(HT);
            HS = nextPrime(HS * 2);
            HT = closedHashing(HS, val, no_of_values);
        }

        key = values[i];
        HI = key % HS;

        if (HT[HI] == -1) {
            HT[HI] = key;
        }

        else {
            // linear probing
            int j = HI;
            while (HT[j] != -1) {
                j = (j+1) % HS;
            }
            
            // quadratic probing
            // int x = 1;
            // while (HT[j] != -1) {
            //     j = (HI + (x*x)) % HS;
            //     x++;
            // }

            HT[j] = key;
        }

        no_of_values++;
        load = float(no_of_values)/float(HS);
    }

    return HT;
}


bool exists(int* HT, int HS, int val) {
    int HI = val % HS;

    // linear probing
    while (HT[HI]!=-1) {
        if (HT[HI]==val) return true;
        HI = (HI++) % HS;
    }

    // quadratic probing
    // int x = 1, j = HI;
    // while (HT[j] != -1) {
    //     if (HT[j]==val) return true;
    //     j = (HI + (x*x)) % HS;
    //     x++;
    // }

    return false;
}

int main() {
    int sizeOfArray = 10;
    int values[sizeOfArray] = {5, 13, 2, 44, 100, 15, 33, 66, 88, 99};
    cout << "Array: "; printList(values, sizeOfArray);

    int hs = 10, *ht;

    ht = closedHashing(hs, values, sizeOfArray);   

    cout << endl << "Size of Linear Array: " << hs << endl;
    cout << "Linear Probation: "; printList(ht, hs);

    cout << "Exists" << endl;
    cout << exists(ht, hs, 55555) << endl;
    cout << exists(ht, hs, 13) << endl;
    
    return 0;
}
