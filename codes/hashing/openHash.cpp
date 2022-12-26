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


struct HNode {
    int key;
    HNode* next;

    HNode(int x) {
        this->key = x;
        next = NULL;
    }
};


HNode** openHashing(int &HS, int *values, int totalValues) {
    
    HNode **HT = (HNode**) malloc(HS * sizeof(HNode*));
    int numOfValues = 0;
    float load = 0;

    for (int i=0; i<HS; i++) {
        HT[i] = NULL;
    }

    int HI;
    for (int i=0; i<totalValues; i++) {
        
        if (load >= 1) {

            int tempValues[numOfValues];
            for (int j=0; j<numOfValues; j++) {
                tempValues[j] = values[j];
            }

            free(HT);
            HS = nextPrime(HS * 2);
            HT = openHashing(HS, tempValues, numOfValues);
        }

        int key = values[i];
        HNode *hn = new HNode(key);
        HI = key % HS;

        if (HT[HI]==NULL) {
            HT[HI] = hn;
        }

        else {
            HNode *temp = HT[HI];
            HT[HI] = hn;
            HT[HI]->next = temp;
        }

        numOfValues++;
        load = float(numOfValues)/float(HS);

    }

    return HT;
}

void printHash(HNode** array, int len) {
    for (int i=0; i<len; i++) {
        cout << "Index " << i << ": ";
        if (array[i]==NULL) {
            cout << "NULL" << endl;
        }

        else {
            HNode *temp = array[i];
            while (temp!=NULL) {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

void printList(int* list, int len) {
    cout << "[";
    for (int i=0; i<len; i++) {
        cout << list[i] << ", ";
    }
    cout << "]" << endl;
}

bool exists(HNode **HT, int HS, int val) {

    int HI = val % HS;

    HNode *temp = HT[HI];
    while (temp!=NULL) {
        if (temp->key==val) return true;
        temp = temp->next;
    }

    return false;
}

int main() {

    int sizeOfArray = 10;
    int values[sizeOfArray] = {5, 13, 2, 44, 100, 15, 33, 66, 88, 99};
    cout << "Array: "; printList(values, sizeOfArray);

    int hs = 5;
    struct HNode **ht = openHashing(hs, values, sizeOfArray);     

    cout << endl << "HS: " << hs << endl; printHash(ht, hs);

    cout << endl << "searching" << endl;
    cout << exists(ht, hs, 44) << endl;
    
    return 1;
}
