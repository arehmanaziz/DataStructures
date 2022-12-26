#include <iostream>
using namespace std;

int main() {

    int N;
    cout << "Enter number of dimensions: ";
    cin >> N;
    int *S = new int[N];

    for (int i = 0; i < N; i++) {   
        cout << "Enter size of Dimension " << i+1 << ": ";
        cin >> S[i];
    }

    int totalValues = 1;
    for (int i = 0; i < N; i++) {
        totalValues = totalValues * S[i];
    }

    int e;
    int* I = new int[N];
    for (int k = 0; k < N; k++) {
        cout << "Enter Index of Dimension: " << k+1 << endl;
        cin >> e;
        I[k] = e;
    }

    int s = 1;
    int alpha = 0; // require index

    for (int i=0 ; i<N; i++) {   
        for (int j=0 ; j<i; j++) {
            s = s * S[j];   
        }
        alpha += I[i] * s;
        s = 1;         
    }

    int *linearArray = new int[totalValues];
    cout << "Size of Linear Array: " << totalValues << endl;

    int *baseAddress = &linearArray[0];
    const int size_dt = sizeof(linearArray[0]);

    int address = int(baseAddress) + (alpha * size_dt);
    cout << "Base Address: " << baseAddress << endl;
    cout << "Address of given indexes " << address << endl;

    delete S;
    S = nullptr;
    delete I;
    I = nullptr;
    delete linearArray;
    linearArray = nullptr;


    return 0;
}