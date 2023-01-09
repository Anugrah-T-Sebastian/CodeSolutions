#include<iostream>

using namespace std;

void countingSort(int input_arr[], int size, int range)
{
    int out_arr[size], count_arr[range];
    for(int i=0; i<range; ++i)
    {
        count_arr[i] = 0;
    }

    for(int i=0; i<size; i++)
    {
        count_arr[input_arr[i]]++;
    }

    for(int i=1; i<range; i++)
    {
        count_arr[i] = count_arr[i] - count_arr[i-1];
    }

    for (int i = 0; i < size; i++)
    {
        out_arr[--count_arr[input_arr[i]]] = input_arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        input_arr[i] = out_arr[i];
    }
    
    
}

int main()
{
    int num, k, A[20], B[20];

    cout<<"Enter the size of the array\n";
    cin>>num;
    cout<<"Enter the elementso of the array\n";
    for(int i=0; i<num; i++)
    {
        cin>>A[i];
    }

    cout<<"Enter the number of the uique element\n";
    cin>>k;
    cout<<"Enter the unique elements of the range\n";
    for(int i=0; i<k; i++)
    {
        cin>>B[i];
    }

    countingSort(A, num, k);                     //Parameters tuple (input array, input size, range)

    cout<<"The sorted array is:\n";
    for(int i=0; i<num; i++)
    {
        cout<<A[i]<<" ";
    }
 
    return 0;
}