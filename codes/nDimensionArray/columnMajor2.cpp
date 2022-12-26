#include <iostream>
using namespace std;
int main()
{   int n;
    cout<<"Enter dimensions :";
    cin>>n;
    int*s = new int[n];
    for (int i = 0; i < n; i++)
    {   
        cout<<"Enter Sizes : ";
        cin>>s[i];
    }
    int size = 1;
    for (int i = 0; i < n; i++)
    {
        size = size * s[i];
    }
    int*arr =new int[size];
    cout<<"TOTAL SIZE OF ARRAY IS "<<size<<endl;
    int *baseAddress = &arr[0];
    const int size_dt = 4;  
    int e;
    int* I =new int[n];
    for (int k = 0; k < n; k++)
    {
        cout << "Enter Index of Dimension " << k + 1 <<" :"<< endl;
        cin >> e;
        I[k] = e;
    }
    int p = 1;
    int q = 0;
    int d = n;
    //k,l variables in for loops are used bcz in wikipedia article they have also use k,l in their formula
    for (int k = 0; k < d; k++)
    {
        for (int l = 0; l < k; l++)
        {
            p = p * s[l];
        }
        q = q + I[k]*p;
        p = 1;
    }
      int  address = int(baseAddress)+(q*size_dt);
        cout<<"The Base Address Is "<<int(baseAddress)<<endl;
        cout<<"The address of Given Indexes "<<address<<endl;
        delete s;
        s = nullptr;
        delete I;
        I = nullptr;
        delete arr;
        arr = nullptr;
    return 0;
}

// [i0 x s1 x s2 x s3 x s4 x s5 + i1 x s2 x s3 x s4 x s5 + i2 x s3 x s4 x s5............] Row Major Address Find!!
// [i0 + S0 x i1 + S0 x S1 x i2 + s0 x s1 x s2 x i3................................]  Column Major Address Find!!