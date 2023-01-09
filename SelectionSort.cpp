#include<iostream>
#include<string>

using namespace std;

void selectionSort(int arr[], int n)
{
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<n; i++)
    {
        int min = arr[i];

        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            //swapping ar[i] and arr[min]
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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

    selectionSort(A, num);
    cout<<"The sorted array is:\n";
    for(int i=0; i<num; i++)
    {
        cout<<A[i]<<" ";
    }
 
    return 0;
}