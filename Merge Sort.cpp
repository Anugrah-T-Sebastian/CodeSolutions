#include<iostream>

using namespace std;

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
}

void merge(int arr[], int l, int m, int r)
{
    int temp[20];
    int i =l;
    int j = m+1;
    int k = l;

    while(i<=m && j<=r)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {  
            temp[k] = arr[j];
            j++;
            k++;
        }
        
    }
    while(j<=r)
    {
        temp[k] = arr[j];
        j++; k++;
    }

    while(i<=m)
    {
        temp[k] = arr[i];
        i++; k++;
    }
    
    for(int p = l; p<=r; p++)
    {
        arr[p] = temp[p];
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

    mergeSort(A, 0, num);

    cout<<"The sorted array is:\n";
    for(int i=0; i<num; i++)
    {
        cout<<A[i]<<" ";
    }
 
    return 0;
}