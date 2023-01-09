#include<iostream>

using namespace std;

int partition(int arr[], int s, int e);

void quickSort(int arr[], int s, int e)
{
    if(s < e)
    {
        int p = partition(arr, s, e);
        quickSort(arr, s, p);
        quickSort(arr, (p+1), e);
    }
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int p_index = s;
    for(int i = s; i<e; i++)
    {
        if(arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[p_index];
            arr[p_index] =temp;
            p_index++;
        }

        int temp = arr[e];
        arr[e] = arr[p_index];
        arr[p_index] = temp;

        return p_index;
    }
}

int main()
{
    int num, A[20];

    cout<<"Enter the size of the array\n";
    cin>>num;
    cout<<"Enter the elementso of the array\n";
    for(int i=0; i<num; i++)
    {
        cin>>A[i];
    }

    quickSort(A, 0, (num-1));

    cout<<"The sorted array is:\n";
    for(int i=0; i<num; i++)
    {
        cout<<A[i]<<" ";
    }
 
    return 0;
}